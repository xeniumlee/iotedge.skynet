local crc = require "modbus.crc16"
local basexx = require "utils.basexx"

local strpack = string.pack
local strunpack = string.unpack
local strb = string.byte
local strc = string.char

local MODBUS_MAX_PDU_LENGTH = 253
local MODBUS_SLAVE_MIN = 1
local MODBUS_SLAVE_MAX = 247
local MODBUS_TID_MIN = 0x0000
local MODBUS_TID_MAX = 0xFFFF
local MODBUS_PROTOID = 0x0000
local MODBUS_ASCII_COLON = 0x3A
local MODBUS_ASCII_CR = 0x0D
local MODBUS_ASCII_LF = 0x0A

local FMT_RTU_HEADER = 'I1'
local FMT_CRC = '<I2'
local FMT_LRC = 'I1'
local FMT_TCP_HEADER_BE = '>I2I2I2I1'
local FMT_TCP_HEADER_LE = '<I2I2I2I1'

local err = {
    invalid_pdu = "Invalid PDU Size",
    invalid_slave = "Invalid Slave ID",
    invalid_tid = "Invalid Transaction Identifier"
}

local function lrc(bytes)
    local l = 0
    for i=1, #bytes do
        l = l - strb(bytes, i, i)
    end
    return l & 0xFF
end

local function validate_tid(tid)
    local i_tid = math.tointeger(tid)
    assert(i_tid and i_tid >= MODBUS_TID_MIN and i_tid <= MODBUS_TID_MAX, err.invalid_tid)
end

local function validate_slave(slave)
    local i_s = math.tointeger(slave)
    assert(i_s and i_s >= MODBUS_SLAVE_MIN and i_s <= MODBUS_SLAVE_MAX, err.invalid_slave)
end

local function validate_pdu(pdu)
    local l = #pdu
    assert(l and l > 0 and l <= MODBUS_MAX_PDU_LENGTH, err.invalid_pdu)
end

local function pack_rtu(slave, pdu)
    validate_slave(slave)
    validate_pdu(pdu)
    return strpack(FMT_RTU_HEADER, slave) .. pdu
end

local function pack_tcp(fmt, tid, uid, pdu)
    validate_tid(tid)
    validate_slave(uid)
    validate_pdu(pdu)
    return strpack(fmt, tid, MODBUS_PROTOID, #pdu+1, uid) .. pdu
end

local function unpack_tcp(fmt, header)
    local tid, pid, len, uid = strunpack(fmt, header)
    return tid, uid, len-1
end

local adu = {}
function adu.pack_rtu(slave, pdu)
    local data = pack_rtu(slave, pdu)
    local checksum = strpack(FMT_CRC, crc(data))
    return data .. checksum
end

function adu.pack_ascii(slave, pdu)
    local data = pack_rtu(slave, pdu)
    local checksum = strpack(FMT_LRC, lrc(data))
    return strc(MODBUS_ASCII_COLON)
            .. basexx.to_hex(data .. checksum)
            .. strc(MODBUS_ASCII_CR, MODBUS_ASCII_LF)
end

function adu.pack_tcp_be(tid, uid, pdu)
    return pack_tcp(FMT_TCP_HEADER_BE, tid, uid, pdu)
end
function adu.pack_tcp_le(tid, uid, pdu)
    return pack_tcp(FMT_TCP_HEADER_LE, tid, uid, pdu)
end

function adu.unpack_tcp_be(header)
    return unpack_tcp(FMT_TCP_HEADER_BE, header)
end
function adu.unpack_tcp_le(header)
    return unpack_tcp(FMT_TCP_HEADER_LE, header)
end

function adu.validate_crc(data, target)
    local checksum = strunpack(FMT_CRC, target)
    return checksum == crc(data)
end
function adu.validate_lrc(data, target)
    local checksum = strunpack(FMT_LRC, target)
    return checksum == lrc(data)
end

return adu
