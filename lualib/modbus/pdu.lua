local strpack = string.pack
local strunpack = string.unpack
local strrep = string.rep
local strfmt = string.format
local strb = string.byte
local tblunpack = table.unpack
local tblins = table.insert
local tblcon = table.concat
local tblremove = table.remove

local MODBUS_MAX_READ_BITS = 2000
local MODBUS_MAX_WRITE_BITS = 1968
local MODBUS_MAX_READ_REGISTERS = 125
local MODBUS_MAX_WRITE_REGISTERS = 123

local MODBUS_ADDR_MIN = 0x0000
local MODBUS_ADDR_MAX = 0x270E

local MODBUS_BIT_ON = 0xFF00
local MODBUS_BIT_OFF = 0x0000
local MODBUS_REG_MIN = 0x0000
local MODBUS_REG_MAX = 0xFFFF

local FMT_BE_R = '>'
local FMT_LE_R = '<'
local FMT_BE_W = '>I2I2'
local FMT_LE_W = '<I2I2'
local FMT_EXCEPTION = 'I1'
local FMT_BE_SINGLE = '>I1I2I2'
local FMT_LE_SINGLE = '<I1I2I2'
local FMT_BE_MULTI = '>I1I2I2I1'
local FMT_LE_MULTI = '<I1I2I2I1'


local err = {
    unknown_fc = "Unknown Function Code",
    invalid_addr = "Invalid Address",
    invalid_number = "Invalid Number",
    invalid_value = "Invalid Value"
}

local function validate_addr(addr)
    local i_addr = math.tointeger(addr)
    assert(i_addr and i_addr >= MODBUS_ADDR_MIN and i_addr <= MODBUS_ADDR_MAX, err.invalid_addr)
end
local function validate_bit_number(n)
    local i_n = math.tointeger(n)
    assert(i_n and i_n > 0 and i_n <= MODBUS_MAX_READ_BITS, err.invalid_number)
end
local function validate_reg_number(n)
    local i_n = math.tointeger(n)
    assert(i_n and i_n > 0 and i_n <= MODBUS_MAX_READ_REGISTERS, err.invalid_number)
end
local function validate_bit_val(val)
    assert(type(val) == "boolean", err.invalid_value)
end
local function validate_reg_val(val)
    local i_val = math.tointeger(val)
    assert(i_val and i_val >= MODBUS_REG_MIN and i_val <= MODBUS_REG_MAX, err.invalid_value)
end
local function validate_bit_table(t)
    assert(#t > 0 and #t <= MODBUS_MAX_WRITE_BITS, err.invalid_number)
    for _, v in pairs(t) do
        validate_bit_val(v)
    end
end
local function validate_reg_table(t)
    assert(#t > 0 and #t <= MODBUS_MAX_WRITE_REGISTERS, err.invalid_number)
    for _, v in pairs(t) do
        validate_reg_val(v)
    end
end

local function pack_bit_table(t)
    local ret = {}
    local b = 0
    for i, v in ipairs(t) do
        if v then
            b = b | (1<<((i-1)%8))
        end
        if i % 8 == 0 then
            tblins(ret, strpack('B', b))
            b = 0
        end
    end
    if #t % 8 ~= 0 then
        tblins(ret, strpack('B', b))
    end
    return tblcon(ret)
end
local function p_read_bits(fmt)
    return function(fc, addr, n)
        validate_addr(addr)
        validate_bit_number(n)
        return strpack(fmt, fc, addr, n)
    end
end
local function p_read_registers(fmt)
    return function(fc, addr, n)
        validate_addr(addr)
        validate_reg_number(n)
        return strpack(fmt, fc, addr, n)
    end
end
local function p_write_bit(fmt)
    return function(fc, addr, val)
        validate_addr(addr)
        validate_bit_val(val)
        local v = val and MODBUS_BIT_ON or MODBUS_BIT_OFF
        return strpack(fmt, fc, addr, v)
    end
end
local function p_write_register(fmt)
    return function(fc, addr, val)
        validate_addr(addr)
        validate_reg_val(val)
        return strpack(fmt, fc, addr, val)
    end
end
local function p_write_bits(prefix)
    return function(fc, addr, val)
        validate_addr(addr)
        validate_bit_table(val)
        local n = #val
        local nb = n // 8 + 1
        local fmt = prefix .. strfmt('c%d', nb)
        return strpack(fmt, fc, addr, n, nb, pack_bit_table(val))
    end
end
local function p_write_registers(prefix)
    return function(fc, addr, val)
        validate_addr(addr)
        validate_reg_table(val)
        local n = #val
        local nb = n * 2
        local fmt = prefix .. strrep('I2', n)
        return strpack(fmt, fc, addr, n, nb, tblunpack(val))
    end
end

local function u_exception(data)
    local e = strunpack(FMT_EXCEPTION, data)
    return e
end
local function u_read_bits(data)
    local ret = {}
    local b, v
    for c in data:gmatch('.') do
        b = strb(c)
        for i=0, 7 do
            v = (b & (1<<i)) ~= 0
            tblins(ret, v)
        end
    end
    return ret
end
local function u_read_registers(prefix)
    return function(data)
        local n = #data // 2
        local fmt = prefix .. strrep('I2', n)
        local t = { strunpack(fmt, data) }
        tblremove(t, n+1)
        return t
    end
end
local function u_write_bit(fmt)
    return function(data)
        local a, b = strunpack(fmt, data)
        return a, b == MODBUS_BIT_ON
    end
end
local function u_write(fmt)
    return function(data)
        local a, b = strunpack(fmt, data)
        return a, b
    end
end

local p_be = {
    [0x01] = p_read_bits(FMT_BE_SINGLE),
    [0x02] = p_read_bits(FMT_BE_SINGLE),
    [0x03] = p_read_registers(FMT_BE_SINGLE),
    [0x04] = p_read_registers(FMT_BE_SINGLE),
    [0x05] = p_write_bit(FMT_BE_SINGLE),
    [0x06] = p_write_register(FMT_BE_SINGLE),
    [0x0F] = p_write_bits(FMT_BE_MULTI),
    [0x10] = p_write_registers(FMT_BE_MULTI)
}

local p_le = {
    [0x01] = p_read_bits(FMT_LE_SINGLE),
    [0x02] = p_read_bits(FMT_LE_SINGLE),
    [0x03] = p_read_registers(FMT_LE_SINGLE),
    [0x04] = p_read_registers(FMT_LE_SINGLE),
    [0x05] = p_write_bit(FMT_LE_SINGLE),
    [0x06] = p_write_register(FMT_LE_SINGLE),
    [0x0F] = p_write_bits(FMT_LE_MULTI),
    [0x10] = p_write_registers(FMT_LE_MULTI)
}

local u_be = {
    [0x01] = u_read_bits,
    [0x02] = u_read_bits,
    [0x03] = u_read_registers(FMT_BE_R),
    [0x04] = u_read_registers(FMT_BE_R),
    [0x05] = u_write_bit(FMT_BE_W),
    [0x06] = u_write(FMT_BE_W),
    [0x0F] = u_write(FMT_BE_W),
    [0x10] = u_write(FMT_BE_W),
    [0x81] = u_exception,
    [0x82] = u_exception,
    [0x83] = u_exception,
    [0x84] = u_exception,
    [0x85] = u_exception,
    [0x86] = u_exception,
    [0x8F] = u_exception,
    [0x90] = u_exception
}

local u_le = {
    [0x01] = u_read_bits,
    [0x02] = u_read_bits,
    [0x03] = u_read_registers(FMT_LE_R),
    [0x04] = u_read_registers(FMT_LE_R),
    [0x05] = u_write_bit(FMT_LE_W),
    [0x06] = u_write(FMT_LE_W),
    [0x0F] = u_write(FMT_LE_W),
    [0x10] = u_write(FMT_LE_W),
    [0x81] = u_exception,
    [0x82] = u_exception,
    [0x83] = u_exception,
    [0x84] = u_exception,
    [0x85] = u_exception,
    [0x86] = u_exception,
    [0x8F] = u_exception,
    [0x90] = u_exception
}

local pdu = {}
function pdu.pack(le)
    if le then
        return function(fc, ...)
            local f = p_le[fc]
            assert(f, err.unknown_fc)
            return f(fc, ...)
        end
    else
        return function(fc, ...)
            local f = p_be[fc]
            assert(f, err.unknown_fc)
            return f(fc, ...)
        end
    end
end

function pdu.unpack_be(fc, data)
    local f = u_be[fc]
    assert(f, err.unknown_fc)
    return fc, f(data)
end

function pdu.unpack_le(fc, data)
    local f = u_le[fc]
    assert(f, err.unknown_fc)
    return fc, f(data)
end

return pdu
