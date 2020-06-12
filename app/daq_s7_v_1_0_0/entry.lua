local skynet = require "skynet"
local log = require "log"
local s7txt = require("text").s7
local daqtxt = require("text").daq
local api = require "api"
local validator = require "utils.validator"
local client = require "s7.client"
local s7data = require "s7.data"

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
                        mode = t.mode,
                        area = t.area,
                        dbnumber = t.dbnumber,
                        addr = t.addr,
                        dt = t.dt,
                        opt = t.opt
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
            local ok, ret = cli:read(t.read)
            assert(ok, strfmt("%s:%s", daqtxt.req_fail, ret))

            return t.unpack(1, ret)
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

    local ok, ret = cli:write(t.write(value))
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

local function do_post(t, dname, ts, attr, interval)
    if t.cov then
        gain(t)
        api.post_cov(dname, { [t.name] = t.val })
    else
        if t.poll_cum + interval >= t.poll then
            t.poll_cum = 0
            gain(t)
            if t.mode == "ts" then
                ts[t.name] = t.val
            else
                attr[t.name] = t.val
            end
        else
            t.poll_cum = t.poll_cum + interval
        end
    end
end

local function post(dname, index, interval)
    local ts = {}
    local attr = {}
    for _, t in pairs(index) do
        if t.name then
            do_post(t, dname, ts, attr, interval)
        else
            for _, tag in pairs(t) do
                do_post(tag, dname, ts, attr, interval)
            end
        end
    end
    if next(ts) then
        api.post_data(dname, ts)
    end
    if next(attr) then
        api.post_attr(dname, attr)
    end
end

local function make_poll(dname, area, dbnumber, start, len, interval, index)
    local item = s7data.r_handle(area, dbnumber, start, len)

    local log_prefix
    if dbnumber then
        log_prefix = strfmt("dev(%s) area(%s) db(%d) start(%d) len(%d) words(%d) wordlen(0x%X)",
            dname, area, dbnumber, start, len, item.number, item.wordlen)
    else
        log_prefix = strfmt("dev(%s) area(%s) start(%d) len(%d) words(%d) wordlen(0x%X)",
            dname, area, start, len, item.number, item.wordlen)
    end

    local timeout = interval // 10

    local function poll()
        while running do
            local ok, err = pcall(function()
                local ok, ret = cli:read(item)
                assert(ok, strfmt("%s %s:%s", log_prefix, daqtxt.req_fail, ret))

                for i, t in pairs(index) do
                    if t.unpack then
                        local v = t.unpack(i, ret)
                        t.val = v
                    else
                        for _, tag in pairs(t) do
                            local v = tag.unpack_bool(i, ret)
                            tag.val = v
                        end
                    end
                end
                post(dname, index, interval)
            end)
            if not ok then
                log.error(daqtxt.poll_fail, err)
            end
            skynet.sleep(timeout)
        end
    end
    return poll
end

local function make_polls(dname, addrlist, polls)
    for key, addrinfo in pairs(addrlist) do
        local list = addrinfo.list
        local index, interval

        local start = false
        local dbnumber, len

        if type(key) == "number" then
            dbnumber = key
            key = "DB"
        end

        local function make()
            local poll = make_poll(dname, key, dbnumber,
                start, len, interval, index)
            tblins(polls, poll)
        end

        local function tag_poll(t)
            if t.poll then
                return t.poll
            else
                -- with bit
                local _, tag = next(t)
                return tag.poll
            end
        end

        local function add(t, addr)
            if addr then
                start = addr
                len = 0
                index = {}
                interval = 0xFFFFFFFF
            end
            index[len+1] = t
            len = len + (t.read and t.read.len or 1)

            local i = tag_poll(t)
            if i < interval then
                interval = i
            end
        end

        for a = addrinfo.min, addrinfo.max do
            local t = list[a]
            if type(t) == "table" then
                if start then
                    add(t)
                else
                    add(t, a)
                end
            elseif t == nil then
                if start then
                    make()
                    start = false
                end
            end
        end
        make()
    end
end

local function validate_poll_addr(t, addrlist)
    local addr
    if t.area == "DB" then
        if not addrlist[t.dbnumber] then
            addrlist[t.dbnumber] = {
                list = {},
                min = max_addr,
                max = -1
            }
        end
        addr = addrlist[t.dbnumber]
    else
        if not addrlist[t.area] then
            addrlist[t.area] = {
                list = {},
                min = max_addr,
                max = 0
            }
        end
        addr = addrlist[t.area]
    end

    local list = addr.list

    if t.dt == "bool" then
        local a = t.addr
        if list[a] then
            assert(not list[a].name and not list[a][t.opt],
                daqtxt.invalid_addr_conf)
            list[a][t.opt] = t
        else
            list[a] = { [t.opt] = t }
        end
    else
        for a = t.addr, t.addr+t.read.len-1 do
            assert(not list[a], daqtxt.invalid_addr_conf)
            if a == t.addr then
                list[a] = t
            else
                list[a] = true
            end
        end
    end
    if t.addr < addr.min then
        addr.min = t.addr
    end
    if t.addr > addr.max then
        addr.max = t.addr
    end
end

local function validate_write_addr(t, addrlist)
    local list
    if t.dbnumber then
        if not addrlist[t.dbnumber] then
            addrlist[t.dbnumber] = {}
        end
        list = addrlist[t.dbnumber]
    else
        if not addrlist[t.area] then
            addrlist[t.area] = {}
        end
        list = addrlist[t.area]
    end

    if t.dt == "bool" then
        local a = t.addr
        if list[a] then
            assert(not list[a].name and not list[a][t.opt],
                daqtxt.invalid_addr_conf)
            list[a][t.opt] = t
        else
            list[a] = { [t.opt] = t }
        end
    else
        for a = t.addr, t.addr+t.read.len-1 do
            assert(not list[a], daqtxt.invalid_addr_conf)
            if a == t.addr then
                list[a] = t
            else
                list[a] = true
            end
        end
    end
end

local function same_dt(t1, t2)
    assert(t1.dt == t2.dt and
        t1.opt == t2.opt,
        daqtxt.invalid_addr_conf)
end

local function validate_addr(polllist, writelist)
    for k, list in pairs(writelist) do
        if polllist[k] then
            local poll = polllist[k].list
            for a, t in pairs(list) do
                local poll_t = type(poll[a])
                assert(poll_t == "nil" or poll_t == type(t),
                    daqtxt.invalid_addr_conf)

                if type(poll[a]) == "table" then
                    if poll[a].name then
                        assert(t.name, daqtxt.invalid_addr_conf)
                        same_dt(poll[a], t)
                    else
                        -- bool
                        assert(not t.name, daqtxt.invalid_addr_conf)
                    end
                end
            end
        end
    end
end

local function fill_tag(t, name, dev)
    t.name = name
    if t.mode == "ts" then
        t.poll_cum = 0
        t.poll = t.poll or dev.ts_poll
    elseif t.mode == "attr" then
        t.poll_cum = 0
        t.poll = t.poll or dev.attr_poll
    end
    t.read, t.write, t.unpack, t.unpack_bool =
        s7data.dt_handle(t.area, t.dbnumber, t.addr, t.dt, t.opt)
end

local model_map = {
    S7_PLC_1200_1500 = {
        area = { "PE", "PA", "MK", "DB" },
        maxdbnumber = 65535,
        maxaddr = 65535
    },
    S7_PLC_300_400 = {
        area = { "PE", "PA", "MK", "TM", "CT", "DB" },
        maxdbnumber = 16000,
        maxaddr = 65535
    }
}

local function validate_model(tag, model)
    local ok = false
    for _, a in pairs(model.area) do
        if tag.area == a then
            ok = true
            break
        end
    end
    assert(ok, s7txt.invalid_area_conf)

    if tag.area == "TM" or tag.area == "CT" then
        assert(tag.dt == "word", s7txt.invalid_dt_conf)
    end

    local n = tag.dbnumber
    if tag.area == "DB" then
        assert(math.tointeger(n) and n>0 and n<=model.maxdbnumber,
            s7txt.invalid_dbnumber_conf)
    end

    local a = tag.addr
    assert(math.tointeger(a) and a>=0, daqtxt.invalid_addr_conf)
    if tag.area == "DB" then
        assert(a<=model.maxaddr, daqtxt.invalid_addr_conf)
    else
        assert(a<=max_addr, daqtxt.invalid_addr_conf)
    end
end

local tag_schema = {
    dt = validator.vals("bool", "byte", "char", "string", "float", "double",
                      "word", "dword", "lword", "int", "dint", "lint"),
    mode = validator.vals("ts", "attr", "ctrl"),
    opt = function(v)
        return v==nil or validator.minmaxint(1, 16)(v)
    end,
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
    local polllist = {}
    local writelist = {}
    local max_poll = 0

    local m = model_map[model]
    for name, t in pairs(dev.tags) do
        assert(type(name)=="string", daqtxt.invalid_tag_conf)
        local ok = pcall(validator.check, t, tag_schema)
        assert(ok, daqtxt.invalid_tag_conf)
        validate_model(t, m)

        if t.gain then
            assert(t.dt ~= "string" and t.dt ~= "bool", daqtxt.invalid_tag_conf)
        end

        fill_tag(t, name, dev)

        if t.mode == "ctrl" then
            validate_write_addr(t, writelist)
        else
            validate_poll_addr(t, polllist)
            if t.poll > max_poll then
                max_poll = t.poll
            end
        end
    end
    validate_addr(polllist, writelist)
    return polllist, max_poll
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

        local addrlist, max_poll = validate_tags(dev, model)
        if max_poll > max then
            max = max_poll
        end
        make_polls(name, addrlist, polls)
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
    host = validator.ipv4,
    rack = validator.minmaxint(0, 7),
    slot = validator.minmaxint(0, 31),
    model = validator.vals("S7_PLC_1200_1500", "S7_PLC_300_400")
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
