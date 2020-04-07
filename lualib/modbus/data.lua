local strpack = string.pack
local strunpack = string.unpack
local strrep = string.rep
local tblunpack = table.unpack
local tblremove = table.remove

local err = {
    invalid_fc = "invalid function code",
    invalid_le = "invalid endian",
    invalid_num = "invalid coin/register number",
    invalid_datatype = "invalid datatype",
    invalid_val = "invalid value"
}

local MODBUS_MAX_READ_REGISTERS = 125
local MODBUS_MAX_WRITE_REGISTERS = 123

local fmt_map = {
    int = {
        [1] = 'i2',
        [2] = 'i4',
        [3] = 'i6',
        [4] = 'i8'
    },
    uint = {
        [1] = 'I2',
        [2] = 'I4',
        [3] = 'I6',
        [4] = 'I8'
    },
    float = {
        [2] = 'f',
        [4] = 'd'
    }
}

local fc_r = { [1]=true, [2]=true, [3]=true, [4]=true }
local fc_w = { [5]=true, [6]=true, [15]=true, [16]=true }

local data = {}
function data.pack(fc, dt, num, tle, le, bit)
    assert(fc_w[fc], err.invalid_fc)
    assert(math.tointeger(num) and
        num > 0 and num <= MODBUS_MAX_WRITE_REGISTERS,
        err.invalid_num)
    assert(type(tle)=="boolean" and type(le)=="boolean", err.invalid_le)

    if dt == "boolean" then
        assert(num == 1, err.invalid_num)
        assert(fc == 5 or fc == 6, err.invalid_fc)
        if fc == 6 then
            assert(bit >= 1 and bit <= 16, err.invalid_datatype)
            local b = bit-1
            return function(val)
                assert(type(val) == "boolean", err.invalid_val)
                if val then
                    return 1<<b
                else
                    return 0
                end
            end
        else
            return function(val)
                assert(type(val) == "boolean", err.invalid_val)
                return val
            end
        end
    else
        assert(fc == 6 or fc == 16, err.invalid_fc)
        local fmt_p, t
        if dt == "string" then
            t = "string"
            fmt_p = 'z'
        else
            t = "number"
            assert(fmt_map[dt], err.invalid_datatype)
            fmt_p = assert(fmt_map[dt][num], err.invalid_datatype)
            if le then
                fmt_p = '<'..fmt_p
            else
                fmt_p = '>'..fmt_p
            end
        end
        local fmt_u
        if tle then
            fmt_u = '<'..strrep('I2', num)
        else
            fmt_u = '>'..strrep('I2', num)
        end
        if fc == 6 then
            assert(num == 1, err.invalid_num)
            return function(val)
                assert(type(val) == t,  err.invalid_val)
                local v = strunpack(fmt_u, strpack(fmt_p, val))
                return v
            end
        else
            return function(val)
                assert(type(val) == t, err.invalid_val)
                local v = { strunpack(fmt_u, strpack(fmt_p, val)) }
                tblremove(v, num+1)
                return v
            end
        end
    end
end

function data.unpack(fc, dt, num, tle, le, bit)
    assert(fc_r[fc], err.invalid_fc)
    assert(math.tointeger(num) and
        num > 0 and num <= MODBUS_MAX_READ_REGISTERS,
        err.invalid_num)
    assert(type(tle)=="boolean" and type(le)=="boolean", err.invalid_le)

    if dt == "boolean" then
        assert(num == 1, err.invalid_num)
        if fc == 3 or fc == 4 then
            assert(bit >= 1 and bit <= 16, err.invalid_datatype)
            local v = 1<<(bit-1)
            return function(index, datalist)
                return (datalist[index] & v) ~= 0
            end
        else
            return function(index, datalist)
                return datalist[index]
            end
        end
    else
        assert(fc == 3 or fc == 4, err.invalid_fc)
        local fmt_u
        if dt == "string" then
            fmt_u = 'z'
        else
            assert(fmt_map[dt], err.invalid_datatype)
            fmt_u = assert(fmt_map[dt][num], err.invalid_datatype)
            if le then
                fmt_u = '<'..fmt_u
            else
                fmt_u = '>'..fmt_u
            end
        end

        local fmt_p
        if tle then
            fmt_p = '<'..strrep('I2', num)
        else
            fmt_p = '>'..strrep('I2', num)
        end
        local n = num-1
        return function(index, datalist)
            local v = strunpack(fmt_u, strpack(fmt_p, tblunpack(datalist, index, index+n)))
            return v
        end
    end
end

return data
