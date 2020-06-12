local skynet = require "skynet"
local log = require "log"
local opcuatxt = require("text").opcua
local daqtxt = require("text").daq
local api = require "api"
local validator = require "utils.validator"
local client = require "opcua.client"

local tblins = table.insert
local strfmt = string.format

local cli
local running = false
local max_wait = 100 * 60 -- 1 min
local poll_min = 10 -- ms
local poll_max = 1000 * 60 * 60 -- 1 hour
local max_addr = 0xFFFFFF -- TReqFunReadItem  byte    Address[3]
local devlist = {}

local cmd_desc = {
    info = "show info",
    list = "list tags",
    read = "<tag>",
    write = "{<tag>,<val>}",
    write_multi = "{ taglist = { {tag = <tag>, value = <val>} ... } }"
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

function info()
    if cli then
        return cli:info()
    else
        return false, daqtxt.not_online
    end
end

function list(dev)
    if cli then
        local d = devlist[dev]
        if d then
            if not d.help then
                local h = {}
                for name, t in pairs(d.tags) do
                    h[name] = {
                        node = t.node,
                        dt = t.dt
                    }
                end
                d.help = h
            end
            return d.help
        else
            return false, daqtxt.invalid_dev
        end
    else
        return false, daqtxt.not_online
    end
end

function read(dev, tag)
    if cli then
        return pcall(function()
            assert(devlist[dev], daqtxt.invalid_dev)
            assert(devlist[dev].tags[tag], daqtxt.invalid_tag)

            local t = devlist[dev].tags[tag]
            local item = { id = t.id }

            -- all tag can be read, no check here
            local ok, ret = cli:read(item)
            assert(ok, strfmt("%s:%s", daqtxt.req_fail, ret))
            assert(item.ok, strfmt("%s:%s", daqtxt.req_fail, item.ret))

            return item.ret
        end)
    else
        return false, daqtxt.not_online
    end
end

local function do_write(dev, tag, value)
    assert(devlist[dev].tags[tag], daqtxt.invalid_arg)
    local vt = type(value)
    assert(vt == "number" or vt == "boolean" or vt == "string", daqtxt.invalid_arg)

    local t = devlist[dev].tags[tag]
    assert(t.mode == "ctrl", daqtxt.read_only)

    local ok, ret = cli:write(t.id, value)
    assert(ok, strfmt("%s:%s", daqtxt.req_fail, ret))

    log.info(daqtxt.write_suc, dev, tag, tostring(value))
end

function write(dev, arg)
    if cli then
        return pcall(function()
            assert(devlist[dev], daqtxt.invalid_dev)
            assert(type(arg) == "table", daqtxt.invalid_arg)
            do_write(dev, arg[1], arg[2])
        end)
    else
        return false, daqtxt.not_online
    end
end

function write_multi(dev, arg)
    if cli then
        return pcall(function()
            assert(devlist[dev], daqtxt.invalid_dev)
            assert(type(arg) == "table" and
                type(arg.taglist) == "table", daqtxt.invalid_arg)

            local taglist = arg.taglist
            local ok, err
            for i, tag in pairs(taglist) do
                assert(type(tag) == "table", daqtxt.invalid_arg)
                ok, err = pcall(do_write, dev, tag.tag, tag.value)
                if ok then
                    taglist[i] = ok
                else
                    taglist[i] = { ok, err }
                end
            end
            return arg
        end)
    else
        return false, daqtxt.not_online
    end
end

local function gain(t)
    if t.gain then
        t.val = t.val * t.gain + t.offset
    end
end

local function do_post(t, dname, ts, attr)
    if t.cov then
        gain(t)
        api.post_cov(dname, { [t.name] = t.val })
    else
        gain(t)
        if t.mode == "ts" then
            ts[t.name] = t.val
        else
            attr[t.name] = t.val
        end
    end
end

local function post(dname, taglist)
    local ts = {}
    local attr = {}
    for _, t in pairs(taglist) do
        do_post(t, dname, ts, attr)
    end
    if next(ts) then
        api.post_data(dname, ts)
    end
    if next(attr) then
        api.post_attr(dname, attr)
    end
end

local function make_poll(dname, taglist, interval)
    local timeout = interval // 10
    local function poll()
        while running do
            local ok, err = pcall(function()
                for _, t in pairs(taglist) do
                    local ok, ret = cli:read(t.id)
                    assert(ok, strfmt("dev(%s) tag(%s) %s:%s", dname, t.name, daqtxt.req_fail, ret))
                    t.val = ret
                end
                post(dname, taglist)
            end)
            if not ok then
                log.error(daqtxt.poll_fail, err)
            end
            skynet.sleep(timeout)
        end
    end
    return poll
end

local function make_polls(dname, taglist, polls)
    for _, t in pairs(taglist) do

        local function make()
            local poll = make_poll(dname, key, dbnumber,
                start, len, interval, index)
            tblins(polls, poll)
        end
    end
end

local function fill_tag(t, name, id, dt, dev)
    t.name = name
    t.id = id
    t.dt = dt
    if t.mode == "ts" then
        t.poll = t.poll or dev.ts_poll
    elseif t.mode == "attr" then
        t.poll = t.poll or dev.attr_poll
    end
end

local tag_schema = {
    mode = validator.vals("ts", "attr", "ctrl"),
    node = validator.string,
    cov = function(v)
        return v==nil or validator.boolean(v)
    end,
    poll = function(v)
        return v==nil or validator.minmaxint(poll_min, poll_max)(v)
    end,
    gain = function(v)
        return v==nil or validator.number(v)
    end,
    offset = function(v)
        return v==nil or validator.number(v)
    end
}

local function validate_tags(dev, model)
    local max_poll = 0
    for name, t in pairs(dev.tags) do
        assert(type(name)=="string", daqtxt.invalid_tag_conf)
        local ok = pcall(validator.check, t, tag_schema)
        assert(ok, daqtxt.invalid_tag_conf)

        if t.gain then
            assert(t.dt ~= "string" and t.dt ~= "bool", daqtxt.invalid_tag_conf)
        end

        local ok, id, dt = cli:register(t.node)
        assert(ok, id)
        fill_tag(t, name, id, dt, dev)

        if t.poll > max_poll then
            max_poll = t.poll
        end
    end
    return max_poll
end

local d_schema = {
    attr_poll = validator.minmaxint(poll_min, poll_max),
    ts_poll = validator.minmaxint(poll_min, poll_max),
    retention = function(v)
        return v==nil or (validator.minmaxint(0, api.ttl_max)(v) and v~=0)
    end,
    batch = function(v)
        return v==nil or (validator.minmaxint(0, api.batch_max)(v) and v~=0)
    end
}

local function validate_devices(d, model)
    local polls = {}
    local max = 0
    for name, dev in pairs(d) do
        assert(type(name)=="string", daqtxt.invalid_device_conf)
        local ok = pcall(validator.check, dev, d_schema)
        assert(ok, daqtxt.invalid_device_conf)

        local max_poll = validate_tags(dev, model)
        if max_poll > max then
            max = max_poll
        end
        make_polls(name, dev.tags, polls)
    end
    return polls, max
end

local function unregdev()
    for name, _ in pairs(devlist) do
        api.unreg_dev(name)
    end
    devlist = {}
end

local function regdev(d, model)
    devlist = {}
    for name, dev in pairs(d) do
        api.reg_dev(name, model, dev.retention)
        if dev.batch then
            api.batch_size(name, dev.batch)
        end
        devlist[name] = dev
    end
end

local function stop()
    if cli then
        cli:close()
    end
    if running then
        log.info(daqtxt.poll_stop)
        running = false
        unregdev()
        skynet.sleep(max_wait)
    end
end

local function start(d, polls, model)
    running = true
    skynet.sleep(api.post_delay)
    regdev(d, model)
    math.randomseed(skynet.time())
    for _, poll in pairs(polls) do
        skynet.timeout(math.random(100, 200), poll)
    end
end

local function config_devices(d, model)
    local ok, polls, max = pcall(validate_devices, d, model)
    if ok then
        max_wait = max // 10
        skynet.fork(start, d, polls, model)
        log.info(strfmt("%s: total(%d), max interval(%ds)",
                daqtxt.poll_start, #polls, max // 1000))
        return ok
    else
        return ok, polls
    end
end

local t_schema = {
    url = validator.opcurl,
    namespace = validator.httpurl,
    username = function(v)
        return v=='' or validator.string(v)
    end,
    password = function(v)
        return v=='' or validator.string(v)
    end,
    model = validator.vals("S7_PLC_1200_1500")
}

local function config_transport(t)
    local ok = pcall(validator.check, t, t_schema)
    if not ok then
        return ok
    else
        stop()
        ok, cli = pcall(client.new, t)
        return ok
    end
end

function on_conf(conf)
    if config_transport(conf.transport) then
        if type(conf.devices) == "table"  then
            local ok, err = config_devices(conf.devices, conf.transport.model)
            if ok then
                return ok
            else
                return ok, err
            end
        else
            return false, daqtxt.invalid_device_conf
        end
    else
        return false, daqtxt.invalid_transport_conf
    end
end

function on_exit()
    stop()
end

reg_cmd()
