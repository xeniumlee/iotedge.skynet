local skynet = require "skynet"
local basexx = require "utils.basexx"
local madu = require "modbus.adu"
local mpdu = require "modbus.pdu"

local strb = string.byte
local strunpack = string.unpack

local MODBUS_MAX_PDU_LENGTH = 253
local MODBUS_MAX_RESP = 250
local MODBUS_MBAP_HEADER = 7
local MODBUS_RTU_SLAVEID = 1
local MODBUS_ASCII_SLAVEID = 2
local MODBUS_FC = 1
local MODBUS_ASCII_FC = 2
local MODBUS_RTU_CRC = 2
local MODBUS_ASCII_LRC = 2
local MODBUS_ASCII_COLON = 0x3A
local MODBUS_ASCII_CR = 0x0D
local MODBUS_ASCII_LF = 0x0A

local FMT_MODBUS_SLAVEID = 'B'
local FMT_MODBUS_FC = 'B'

local err = {
    timeout = "Response Timeout",
    unknown_fc = "Unknown Function Code",
    invalid_slave = "Invalid Slave ID",
    invalid_pdu = "Invalid PDU Size",
    invalid_crc = "Data Corrupted (CRC)",
    invalid_ascii = "Invalid ASCII Encode",
    invalid_lrc = "Data Corrupted (LRC)",
}

local function tcp_r(so)
    local byte = so:read(1)
    local len = strb(byte)
    assert(len > 0 and len <= MODBUS_MAX_RESP, err.invalid_pdu)
    return so:read(len)
end
local function tcp_w(so)
    return so:read(4)
end
local function tcp_e(so)
    return so:read(1)
end

local tcp_resp = {
    [0x01] = tcp_r,
    [0x02] = tcp_r,
    [0x03] = tcp_r,
    [0x04] = tcp_r,
    [0x05] = tcp_w,
    [0x06] = tcp_w,
    [0x0F] = tcp_w,
    [0x10] = tcp_w,
    [0x81] = tcp_e,
    [0x82] = tcp_e,
    [0x83] = tcp_e,
    [0x84] = tcp_e,
    [0x85] = tcp_e,
    [0x86] = tcp_e,
    [0x8F] = tcp_e,
    [0x90] = tcp_e
}

local function unpack_tcp_be(so)
    local header = so:read(MODBUS_MBAP_HEADER)
    local tid, uid, len = madu.unpack_tcp_be(header)
    assert(len > 0 and len <= MODBUS_MAX_PDU_LENGTH, err.invalid_pdu)
    local s_fc = so:read(MODBUS_FC)
    local fc = strunpack(FMT_MODBUS_FC, s_fc)
    local f = tcp_resp[fc]
    assert(f, err.unknown_fc)
    local data = f(so)
    return tid, true, {uid, mpdu.unpack_be(fc, data)}
end
local function unpack_tcp_le(so)
    local header = so:read(MODBUS_MBAP_HEADER)
    local tid, uid, len = madu.unpack_tcp_le(header)
    assert(len > 0 and len <= MODBUS_MAX_PDU_LENGTH, err.invalid_pdu)
    local s_fc = so:read(MODBUS_FC)
    local fc = strunpack(FMT_MODBUS_FC, s_fc)
    local f = tcp_resp[fc]
    assert(f, err.unknown_fc)
    local data = f(so)
    return tid, true, {uid, mpdu.unpack_le(fc, data)}
end

local function ascii_lrc(so, data)
    local lrc = basexx.from_hex(so:read(MODBUS_ASCII_LRC))
    assert(lrc, err.invalid_ascii)
    local cr = so:read(1)
    assert(strb(cr) == MODBUS_ASCII_CR, err.invalid_ascii)
    local lf = so:read(1)
    assert(strb(lf) == MODBUS_ASCII_LF, err.invalid_ascii)
    assert(madu.validate_lrc(data, lrc), err.invalid_lrc)
end
local function ascii_r(so, prefix)
    local byte = basexx.from_hex(so:read(2))
    assert(byte, err.invalid_ascii)
    local len = strb(byte)
    assert(len > 0 and len <= MODBUS_MAX_RESP, err.invalid_pdu)
    local data = basexx.from_hex(so:read(len*2))
    assert(data, err.invalid_ascii)
    ascii_lrc(so, prefix..byte..data)
    return data
end
local function ascii_w(so, prefix)
    local data = basexx.from_hex(so:read(8))
    assert(data, err.invalid_ascii)
    ascii_lrc(so, prefix..data)
    return data
end
local function ascii_e(so, prefix)
    local data = basexx.from_hex(so:read(2))
    assert(data, err.invalid_ascii)
    ascii_lrc(so, prefix..data)
    return data
end

local ascii_resp = {
    [0x01] = ascii_r,
    [0x02] = ascii_r,
    [0x03] = ascii_r,
    [0x04] = ascii_r,
    [0x05] = ascii_w,
    [0x06] = ascii_w,
    [0x0F] = ascii_w,
    [0x10] = ascii_w,
    [0x81] = ascii_e,
    [0x82] = ascii_e,
    [0x83] = ascii_e,
    [0x84] = ascii_e,
    [0x85] = ascii_e,
    [0x86] = ascii_e,
    [0x8F] = ascii_e,
    [0x90] = ascii_e
}

local function unpack_ascii(so)
    local colon = so:read(1)
    assert(strb(colon) == MODBUS_ASCII_COLON, err.invalid_ascii)
    local s_slave = basexx.from_hex(so:read(MODBUS_ASCII_SLAVEID))
    assert(s_slave, err.invalid_slave)
    local s_fc = basexx.from_hex(so:read(MODBUS_ASCII_FC))
    assert(s_fc, err.unknown_fc)
    local slave = strunpack(FMT_MODBUS_SLAVEID, s_slave)
    local fc = strunpack(FMT_MODBUS_FC, s_fc)
    local f = ascii_resp[fc]
    assert(f, err.unknown_fc)
    return slave, fc, f(so, s_slave..s_fc)
end

local function unpack_ascii_be(so)
    local slave, fc, data = unpack_ascii(so)
    return true, {slave, mpdu.unpack_be(fc, data)}
end
local function unpack_ascii_le(so)
    local slave, fc, data = unpack_ascii(so)
    return true, {slave, mpdu.unpack_le(fc, data)}
end

local function rtu_crc(so, data)
    local crc = so:read(MODBUS_RTU_CRC)
    assert(madu.validate_crc(data, crc), err.invalid_crc)
end
local function rtu_r(so, prefix)
    local byte = so:read(1)
    local len = strb(byte)
    assert(len > 0 and len <= MODBUS_MAX_RESP, err.invalid_pdu)
    local data = so:read(len)
    rtu_crc(so, prefix..byte..data)
    return data
end
local function rtu_w(so, prefix)
    local data = so:read(4)
    rtu_crc(so, prefix..data)
    return data
end
local function rtu_e(so, prefix)
    local data = so:read(1)
    rtu_crc(so, prefix..data)
    return data
end

local rtu_resp = {
    [0x01] = rtu_r,
    [0x02] = rtu_r,
    [0x03] = rtu_r,
    [0x04] = rtu_r,
    [0x05] = rtu_w,
    [0x06] = rtu_w,
    [0x0F] = rtu_w,
    [0x10] = rtu_w,
    [0x81] = rtu_e,
    [0x82] = rtu_e,
    [0x83] = rtu_e,
    [0x84] = rtu_e,
    [0x85] = rtu_e,
    [0x86] = rtu_e,
    [0x8F] = rtu_e,
    [0x90] = rtu_e
}

local function unpack_rtu(so)
    local s_slave = so:read(MODBUS_RTU_SLAVEID)
    local s_fc = so:read(MODBUS_FC)
    local slave = strunpack(FMT_MODBUS_SLAVEID, s_slave)
    local fc = strunpack(FMT_MODBUS_FC, s_fc)
    local f = rtu_resp[fc]
    assert(f, err.unknown_fc)
    return slave, fc, f(so, s_slave..s_fc)
end

local function unpack_rtu_be(so)
    local slave, fc, data = unpack_rtu(so)
    return true, {slave, mpdu.unpack_be(fc, data)}
end
local function unpack_rtu_le(so)
    local slave, fc, data = unpack_rtu(so)
    return true, {slave, mpdu.unpack_le(fc, data)}
end

local mt_tcp = {}
mt_tcp.__index = mt_tcp

local function gen_tid(self)
    local id = (self.tid + 1) & 0xFFFF
    self.tid = id
    return id
end

function mt_tcp:request(uid, pdu)
    local tid = gen_tid(self)
    local ok, data = pcall(self.pack, tid, uid, pdu)
    if ok then
        local resp, drop
        local co = coroutine.running()
        local ch = self.channel
        skynet.fork(function()
            ok, resp = pcall(ch.request, ch, data, tid)
            if not drop then
                skynet.wakeup(co)
            end
        end)
        skynet.sleep(self.timeout)
        if resp then
            return ok, resp
        else
            drop = true
            return false, err.timeout
        end
    else
        return ok, data
    end
end

local client = {}
function client.new_tcp(conf)
    local le = conf.le or false
    local timeout = conf.timeout // 10
    if timeout == 0 then
        timeout = 50 -- 0.5s
    end
    local packfunc, unpackfunc
    if le then
        packfunc = madu.pack_tcp_le
        unpackfunc = unpack_tcp_le
    else
        packfunc = madu.pack_tcp_be
        unpackfunc = unpack_tcp_be
    end
    local ch = require("skynet.socketchannel").channel {
        host = conf.host,
        port = conf.port,
        response = unpackfunc,
        nodelay = true
    }
    return setmetatable(
    { channel = ch, tid = 0, pack = packfunc, timeout = timeout }, mt_tcp)
end

local mt_rtu = {}
mt_rtu.__index = mt_rtu

function mt_rtu:request(slave, pdu)
    local ok, data = pcall(self.pack, slave, pdu)
    if ok then
        local resp, drop
        local co = coroutine.running()
        local ch = self.channel
        local unpack = self.unpack
        skynet.fork(function()
            ok, resp = pcall(ch.request, ch, data, unpack)
            if not drop then
                skynet.wakeup(co)
            end
        end)
        skynet.sleep(self.timeout)
        if resp then
            return ok, resp
        else
            drop = true
            return false, err.timeout
        end
    else
        return ok, data
    end
end

local function new_rtu(ch, conf)
    local le = conf.le or false
    local ascii = conf.ascii or false
    local timeout = conf.timeout // 10
    if timeout == 0 then
        timeout = 50 -- 0.5s
    end
    local packfunc, unpackfunc
    if le then
        if ascii then
            unpackfunc = unpack_ascii_le
        else
            unpackfunc = unpack_rtu_le
        end
    else
        if ascii then
            unpackfunc = unpack_ascii_be
        else
            unpackfunc = unpack_rtu_be
        end
    end
    if ascii then
        packfunc = madu.pack_ascii
    else
        packfunc = madu.pack_rtu
    end
    return setmetatable(
    { channel = ch, pack = packfunc, unpack = unpackfunc, timeout = timeout }, mt_rtu)
end

function client.new_rtu_tcp(conf)
    local ch = require("skynet.socketchannel").channel {
        host = conf.host,
        port = conf.port,
        nodelay = true
    }
    return new_rtu(ch, conf)
end

-- 1 Byte = start + 8 bits + parity + stop = 11 bits
-- 1.5 t = 16 bits
function client.new_rtu(conf)
    local ch = require("utils.serialchannel").channel {
        device = conf.port,
        baudrate = conf.baudrate,
        mode = conf.mode,
        databits = conf.databits,
        parity = conf.parity,
        stopbits = conf.stopbits,
        r_timeout = conf.r_timeout, -- ms
        b_timeout = conf.b_timeout * 1000, -- us
        rtscts = conf.rtscts
    }
    return new_rtu(ch, conf)
end

return client
