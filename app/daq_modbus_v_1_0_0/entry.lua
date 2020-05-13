local skynet = require "skynet"
local log = require "log"
local modbustxt = require("text").modbus
local daqtxt = require("text").daq
local api = require "api"
local validator = require "utils.validator"
local client = require "modbus.client"
local mpdu = require "modbus.pdu"
local mdata = require "modbus.data"

local tblins = table.insert
local strfmt = string.format

local MODBUS_SLAVE_MIN = 1
local MODBUS_SLAVE_MAX = 247
local MODBUS_ADDR_MIN = 0x0000
local MODBUS_ADDR_MAX = 0x270E
local MODBUS_MAX_READ_BITS = 2000
local MODBUS_MAX_READ_REGISTERS = 125

local cli
local cli_pack
local running = false
local max_wait = 100 * 60 -- 1 min
local poll_min = 10 -- ms
local poll_max = 1000 * 60 * 60 -- 1 hour
local devlist = {}

local cmd_desc = {
    read = "<tag>",
    write = "{<tag>,<val>}",
    write_multi = "{ taglist = { {tag = <tag>, value = <val>} ... } }",
    list = "list tags"
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

function list(dev)
    if cli then
        local d = devlist[dev]
        if d then
            if not d.help then
                local h = {
                    unitid = d.unitid,
                    write = {},
                    read = {}
                }
                for name, t in pairs(d.tags) do
                    if t.read then
                        h.read[name] = {
                            fc = t.fc,
                            dtype = t.dt,
                            addr = t.addr,
                            number = t.number
                        }
                    end
                    if t.write then
                        h.write[name] = {
                            fc = t.wfc,
                            dtype = t.dt,
                            addr = t.addr,
                            number = t.number
                        }
                    end
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
            local u = devlist[dev].unitid
            local t = devlist[dev].tags[tag]

            -- all tag can be read, no check here
            local ok, ret = cli:request(u, t.read)
            assert(ok, strfmt("%s:%s", daqtxt.req_fail, ret))

            local uid = ret[1]
            assert(uid==u, strfmt("%s:%s:%s", modbustxt.invalid_unit, u, uid))

            local fc = ret[2]
            assert(fc==t.fc, strfmt("%s:%s:%s", modbustxt.invalid_fc, t.fc, fc))

            local data = ret[3]
            assert(type(data)=="table", strfmt("%s:%s", modbustxt.exception, data))

            if t.fc == 3 or t.fc == 4 then
                local n = #data
                assert(n==t.number, strfmt("%s:%s:%s", modbustxt.invalid_num, t.number, n))
            end
            return t.unpack(1, data)
        end)
    else
        return false, daqtxt.not_online
    end
end

local function do_write(dev, tag, value)
    assert(devlist[dev].tags[tag], daqtxt.invalid_arg)
    local vt = type(value)
    assert(vt == "number" or vt == "boolean" or vt == "string", daqtxt.invalid_arg)

    local u = devlist[dev].unitid
    local t = devlist[dev].tags[tag]

    assert(t.mode == "ctrl", daqtxt.read_only)
    local p = t.write(value)

    local ok, ret = cli:request(u, p)
    assert(ok, strfmt("%s:%s", daqtxt.req_fail, ret))
    local uid = ret[1]
    assert(uid==u, strfmt("%s:%s:%s", modbustxt.invalid_unit, u, uid))
    local fc = ret[2]
    assert(fc==t.wfc, strfmt("%s:%s:%s", modbustxt.invalid_fc, t.wfc, fc))
    local addr = ret[3]
    local data = ret[4]
    assert(data ~= nil, strfmt("%s:%s", modbustxt.exception, addr))
    assert(addr==t.addr, strfmt("%s:%s:%s", modbustxt.invalid_addr, t.addr, addr))
    if fc == 5 or fc == 6 then
        local v = t.unpack(1, {data})
        assert(value==v, strfmt("%s:%s:%s", modbustxt.invalid_write, value, v))
    else
        assert(data==t.number, strfmt("%s:%s:%s", modbustxt.invalid_num, t.number, data))
    end
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

local function make_poll(dname, unitid, fc, start, number, interval, index)
    local p = cli_pack(fc, start, number)
    local log_prefix = string.format("dev(%s) slave(%d) fc(%d), start(%d) number(%d)",
        dname, unitid, fc, start, number)
    local timeout = interval // 10

    local function poll()
        while running do
            local ok, err = pcall(function()
                local ok, ret = cli:request(unitid, p)
                assert(ok, strfmt("%s %s:%s", log_prefix, daqtxt.req_fail, ret))
                local uid = ret[1]
                assert(uid==unitid, strfmt("%s %s:%s:%s", log_prefix, modbustxt.invalid_unit, unitid, uid))
                local c = ret[2]
                assert(c==fc, strfmt("%s %s:%s:%s", log_prefix, modbustxt.invalid_fc, fc, c))
                local data = ret[3]
                assert(type(data)=="table", strfmt("%s %s:%s", log_prefix, modbustxt.exception, data))
                if fc == 3 or fc == 4 then
                    local n = #data
                    assert(n==number, strfmt("%s %s:%s:%s", log_prefix, modbustxt.invalid_num, number, n))
                end
                for i, t in pairs(index) do
                    if t.unpack then
                        local v = t.unpack(i, data)
                        t.val = v
                    else
                        for _, tag in pairs(t) do
                            local v = tag.unpack(i, data)
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

local maxnumber = {
    [1] = MODBUS_MAX_READ_BITS,
    [2] = MODBUS_MAX_READ_BITS,
    [3] = MODBUS_MAX_READ_REGISTERS,
    [4] = MODBUS_MAX_READ_REGISTERS
}

local function make_polls(dname, unitid, addrlist, polls)
    for fc, addrinfo in pairs(addrlist) do
        local list = addrinfo.list
        local index, interval

        local start = false
        local number
        local max = maxnumber[fc]

        local function make()
            local poll = make_poll(dname, unitid, fc, start, number, interval, index)
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
                number = 0
                index = {}
                interval = 0xFFFFFFFF
            end
            index[number+1] = t
            number = number + (t.number or 1)

            local i = tag_poll(t)
            if i < interval then
                interval = i
            end
        end

        for a = addrinfo.min, addrinfo.max do
            local t = list[a]
            if type(t) == "table" then
                if start then
                    if number + (t.number or 1) <= max then
                        add(t)
                    else
                        make()
                        add(t, a)
                    end
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
    if not addrlist[t.fc] then
        addrlist[t.fc] = {
            list = {},
            min = MODBUS_ADDR_MAX,
            max = MODBUS_ADDR_MIN
        }
    end
    local addr = addrlist[t.fc]
    local list = addr.list
    if t.bit then
        local a = t.addr
        if list[a] then
            assert(not list[a].name and not list[a][t.bit],
                daqtxt.invalid_addr_conf)
            list[a][t.bit] = t
        else
            list[a] = { [t.bit] = t }
        end
    else
        for a = t.addr, t.addr+t.number-1 do
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
    if not addrlist[t.fc] then
        addrlist[t.fc] = {}
    end
    local list = addrlist[t.fc]
    -- DO NOT support multiple boolean tags share the same address
    for a = t.addr, t.addr+t.number-1 do
        assert(not list[a], daqtxt.invalid_addr_conf)
        if a == t.addr then
            list[a] = t
        else
            list[a] = true
        end
    end
end

local function same_dt(t1, t2)
    assert(t1.number == t2.number and
        t1.dt == t2.dt and
        t1.le == t2.le and
        t1.bit == t2.bit,
        daqtxt.invalid_addr_conf)
end

local function validate_addr(polllist, writelist)
    for fc, list in pairs(writelist) do
        if polllist[fc] then
            local poll = polllist[fc].list
            for a, t in pairs(list) do
                local poll_t = type(poll[a])
                assert(poll_t == "nil" or poll_t == type(t),
                    daqtxt.invalid_addr_conf)

                if poll_t == "table" then
                    assert(poll[a].name and t.name,
                           daqtxt.invalid_addr_conf)
                    same_dt(poll[a], t)
                end
            end
        end
    end
end

local fc_map = {
    [5] = 1,
    [15] = 1,
    [6] = 3,
    [16] = 3
}

local tag_schema = {
    fc = validator.vals(1, 2, 3, 4, 5, 15, 6, 16),
    dt = validator.vals("int", "uint", "string", "float", "boolean"),
    mode = validator.vals("ts", "attr", "ctrl"),
    addr = validator.minmaxint(MODBUS_ADDR_MIN, MODBUS_ADDR_MAX),
    number = validator.posint,
    bit = function(v)
        return v==nil or validator.minmaxint(1, 16)(v)
    end,
    cov = function(v)
        return v==nil or validator.boolean(v)
    end,
    le = function(v)
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

local function fill_tag(t, name, dev)
    t.name = name
    if t.le == nil then
        t.le = dev.le
    end
    if t.mode == "ts" then
        t.poll_cum = 0
        t.poll = t.poll or dev.ts_poll
    elseif t.mode == "attr" then
        t.poll_cum = 0
        t.poll = t.poll or dev.attr_poll
    end
end

local function validate_tags(dev, tle)
    local polllist = {}
    local writelist = {}
    local max_poll = 0

    for name, t in pairs(dev.tags) do
        assert(type(name)=="string", daqtxt.invalid_tag_conf)
        local ok = pcall(validator.check, t, tag_schema)
        assert(ok, daqtxt.invalid_tag_conf)

        if t.gain then
            assert(t.dt ~= "string" and t.dt ~= "boolean", daqtxt.invalid_tag_conf)
        end

        fill_tag(t, name, dev)

        if t.mode == "ctrl" then
            t.wfc = t.fc
            t.fc = assert(fc_map[t.fc], modbustxt.invalid_fc_conf)
            validate_write_addr(t, writelist)

            local pack = mdata.pack(t.wfc, t.dt, t.number, tle, t.le, t.bit)
            t.write = function(val)
                local v = pack(val)
                return cli_pack(t.wfc, t.addr, v)
            end
        else
            validate_poll_addr(t, polllist)
            if t.poll > max_poll then
                max_poll = t.poll
            end
        end

        t.read = cli_pack(t.fc, t.addr, t.number)
        t.unpack = mdata.unpack(t.fc, t.dt, t.number, tle, t.le, t.bit)
    end
    validate_addr(polllist, writelist)
    return polllist, max_poll
end

local d_schema = {
    unitid = validator.minmaxint(MODBUS_SLAVE_MIN, MODBUS_SLAVE_MAX),
    attr_poll = validator.minmaxint(poll_min, poll_max),
    ts_poll = validator.minmaxint(poll_min, poll_max),
    le = validator.boolean,
    retention = function(v)
        return v==nil or (validator.minmaxint(0, api.ttl_max)(v) and v~=0)
    end,
    batch = function(v)
        return v==nil or (validator.minmaxint(0, api.batch_max)(v) and v~=0)
    end
}

local function validate_devices(d, tle)
    local polls = {}
    local max = 0
    for name, dev in pairs(d) do
        assert(type(name)=="string", daqtxt.invalid_device_conf)
        local ok = pcall(validator.check, dev, d_schema)
        assert(ok, daqtxt.invalid_device_conf)

        local addrlist, max_poll = validate_tags(dev, tle)
        if max_poll > max then
            max = max_poll
        end
        make_polls(name, dev.unitid, addrlist, polls)
    end
    return polls, max
end

local function unregdev()
    for name, _ in pairs(devlist) do
        api.unreg_dev(name)
    end
    devlist = {}
end

local function regdev(d)
    devlist = {}
    for name, dev in pairs(d) do
        local desc = string.format("unitid(%d)", dev.unitid)
        api.reg_dev(name, desc, dev.retention)
        if dev.batch then
            api.batch_size(name, dev.batch)
        end
        devlist[name] = dev
    end
end

local function stop()
    if cli then
        cli.channel:close()
    end
    if running then
        log.info(daqtxt.poll_stop)
        running = false
        unregdev()
        skynet.sleep(max_wait)
    end
end

local function start(d, polls)
    running = true
    skynet.sleep(api.post_delay)
    regdev(d)
    math.randomseed(skynet.time())
    for _, poll in pairs(polls) do
        skynet.timeout(math.random(100, 200), poll)
    end
end

local function config_devices(d, tle)
    local ok, polls, max = pcall(validate_devices, d, tle)
    if ok then
        max_wait = max // 10
        skynet.fork(start, d, polls)
        log.info(strfmt("%s: total(%d), max interval(%ds)",
                daqtxt.poll_start, #polls, max // 1000))
        return ok
    else
        return ok, polls
    end
end

local t_schema = {
    mode = validator.vals("rtu", "rtu_tcp", "tcp"),
    le = validator.boolean,
    timeout = validator.minint(poll_min),
    ascii = validator.boolean,
    tcp = {
        host = validator.ipv4,
        port = validator.port
    },
    rtu = {
        port = validator.string,
        baudrate = validator.posint,
        databits = validator.posint,
        stopbits = validator.minint(0),
        rtscts = validator.boolean,
        r_timeout = validator.posint,
        b_timeout = validator.posint,
        mode = validator.vals("rs232", "rs485"),
        parity = validator.vals("none", "odd", "even")
    }
}

local function config_transport(t)
    local ok = pcall(validator.check, t, t_schema)
    if not ok then
        return false
    else
        stop()
        local mode = t.mode
        local arg
        if mode == 'rtu' then
            arg = t.rtu
            arg.ascii = t.ascii
            arg.le = t.le
            arg.timeout = t.timeout
            cli = client.new_rtu(arg)
            cli_pack = mpdu.pack(t.le)
        elseif mode == 'rtu_tcp' then
            arg = t.tcp
            arg.ascii = t.ascii
            arg.le = t.le
            arg.timeout = t.timeout
            cli = client.new_rtu_tcp(arg)
            cli_pack = mpdu.pack(t.le)
        elseif mode == 'tcp' then
            arg = t.tcp
            arg.le = t.le
            arg.timeout = t.timeout
            cli = client.new_tcp(arg)
            cli_pack = mpdu.pack(t.le)
        end
        return true
    end
end

function on_conf(conf)
    if config_transport(conf.transport) then
        if type(conf.devices) == "table"  then
            local ok, err = config_devices(conf.devices, conf.transport.le)
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
