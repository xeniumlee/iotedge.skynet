local skynet = require "skynet"
local log = require "log"
local daqtxt = require("text").daq
local api = require "api"
local validator = require "utils.validator"
local client = require "opcua.client"

local tblins = table.insert
local strfmt = string.format

local cli
local running = false
local max_wait = 100 * 60 -- 1 min
local max_read = 200
local poll_min = 10 -- ms
local poll_max = 1000 * 60 * 60 -- 1 hour
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
                        mode = t.mode,
                        node = t.node,
                        dt = t.dtname
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

            -- all tag can be read, no check here
            local ok, ret = cli:read({t})
            assert(ok, strfmt("%s:%s", daqtxt.req_fail, ret))
            assert(t.ok, strfmt("%s:%s", daqtxt.req_fail, t.val))

            return t.val
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

    local ok, ret = cli:write(t, value)
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
    if t.ok then
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
    else
        log.error(strfmt("dev(%s) tag(%s) %s:%s", dname, t.name, daqtxt.req_fail, t.val))
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
                local ok, ret = cli:read(taglist)
                assert(ok, strfmt("dev(%s) %s:%s", dname, daqtxt.req_fail, ret))
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
    local list = {}
    for _, t in pairs(taglist) do
        if t.mode ~= "ctrl" then
            local p = t.poll
            if not list[p] then
                list[p] = { idx = 1, size = 0, list = {{}} }
            end
            local tbl = list[p]
            tblins(tbl.list[tbl.idx], t)
            tbl.size = tbl.size + 1
            if tbl.size == max_read then
                tbl.idx = tbl.idx + 1
                tbl.size = 0
                tbl.list[tbl.idx] = {}
            end
        end
    end
    for interval, l in pairs(list) do
        for _, tags in pairs(l.list) do
            if #tags ~= 0 then
                local poll = make_poll(dname, tags, interval)
                tblins(polls, poll)
            end
        end
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

local function validate_tags(dev)
    local max_poll = 0
    local ts_poll = dev.ts_poll
    local attr_poll = dev.attr_poll
    for name, t in pairs(dev.tags) do
        assert(type(name)=="string", daqtxt.invalid_tag_conf)

        local ok = pcall(validator.check, t, tag_schema)
        assert(ok, daqtxt.invalid_tag_conf)

        if t.gain then
            assert(t.dt ~= "string" and t.dt ~= "bool", daqtxt.invalid_tag_conf)
        end

        local err
        t.name = name
        ok, err = cli:register(t)
        assert(ok, err)

        if t.mode == "ts" then
            t.poll = t.poll or ts_poll
            if t.poll > max_poll then
                max_poll = t.poll
            end
        elseif t.mode == "attr" then
            t.poll = t.poll or attr_poll
            if t.poll > max_poll then
                max_poll = t.poll
            end
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

local function validate_devices(d)
    local polls = {}
    local max = 0
    for name, dev in pairs(d) do
        assert(type(name)=="string", daqtxt.invalid_device_conf)
        local ok = pcall(validator.check, dev, d_schema)
        assert(ok, daqtxt.invalid_device_conf)

        local max_poll = validate_tags(dev)
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

local function config_devices(d, model)
    local ok, polls, max = pcall(validate_devices, d)
    if ok then
        max_wait = max // 10
        skynet.timeout(api.post_delay, function()
            running = true
            regdev(d, model)
            math.randomseed(math.floor(skynet.time()))
            for _, poll in pairs(polls) do
                skynet.timeout(math.random(100, 200), poll)
            end
        end)
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
    model = validator.string,
    security_mode = validator.vals("none", "sign", "signandencrypt"),
    security_policy = validator.vals("none", "basic128rsa15", "basic256", "basic256sha256")
}

local function config_transport(t)
    local ok = pcall(validator.check, t, t_schema)
    if not ok then
        return ok
    else
        stop()
        ok, cli = pcall(client.new, t)
        if ok then
            return cli:connect()
        else
            return ok
        end
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
