local strpack = string.pack
local strunpack = string.unpack
local strrep = string.rep
local strsub = string.sub

local err = {
    invalid_area = "invalid area",
    invalid_dbnumber = "invalid dbnumber",
    invalid_datatype = "invalid datatype",
    invalid_number = "invalid number",
    invalid_bit = "invalid bit",
    invalid_string = "invalid string"
}

local area_map = {
    PE = {
        id = 0x81,
        wl = 0x02
    },
    PA = {
        id = 0x82,
        wl = 0x02
    },
    MK = {
        id = 0x83,
        wl = 0x02
    },
    DB = {
        id = 0x84,
        wl = 0x02
    },
    CT = {
        id = 0x1C,
        wl = 0x1C
    },
    TM = {
        id = 0x1D,
        wl = 0x1D
    }
}

local dt_map = {
    bool = {
        fmt = 'B',
        len = 1,
        wl = 0x01
    },
    string = {
        fmt = 'z'
    },
    byte = {
        fmt = 'B',
        len = 1
    },
    char = {
        fmt = 'b',
        len = 1
    },
    word = {
        fmt = '>I2',
        len = 2
    },
    int = {
        fmt = '>i2',
        len = 2
    },
    dword = {
        fmt = '>I4',
        len = 4
    },
    dint = {
        fmt = '>i4',
        len = 4
    },
    lword = {
        fmt = '>I8',
        len = 8
    },
    lint = {
        fmt = '>i8',
        len = 8
    },
    float = {
        fmt = '>f',
        len = 4
    },
    double = {
        fmt = '>d',
        len = 8
    }
}

local function calc_start(addr, dt, opt)
    if dt == "bool" then
        assert(math.tointeger(opt) and opt >= 0 and opt <= 7,
            err.invalid_bit)
        return addr*8 + opt
    else
        return addr
    end
end

local function calc_len(dt, opt)
    if dt == "string" then
        assert(math.tointeger(opt) and opt > 0,
            err.invalid_string)
        return opt
    else
        return dt_map[dt].len
    end
end

local function calc_number(area, len)
    if area == "TM" or area == "CT" then
        return math.ceil(len/2)
    else
        return len
    end
end

return function(area, dbnumber, addr, dt, opt)
    if area == "DB" then
        assert(dbnumber, err.invalid_dbnumber)
    end
    local a = assert(area_map[area], err.invalid_area)
    local d = assert(dt_map[dt], err.invalid_datatype)
    local l = calc_len(dt, opt)
    local r = {
        area = a.id,
        dbnumber = dbnumber or 0,
        start = calc_start(addr, dt, opt),
        len = l,
        number = calc_number(area, l),
        wordlen = d.wl or a.wl
    }

    local w
    if dt == "bool" then
        w = function(val)
            assert(type(val) == "boolean", err.invalid_bit)
            local v = val and 1 or 0
            return {
                area = r.area,
                dbnumber = r.dbnumber,
                start = r.start,
                number = r.number,
                wordlen = r.wordlen,
                data = strpack(d.fmt, v)
            }
        end
    elseif dt == "string" then
        w = function(val)
            assert(type(val) == "string", err.invalid_string)
            return {
                area = r.area,
                dbnumber = r.dbnumber,
                start = r.start,
                number = r.number,
                wordlen = r.wordlen,
                data = strpack(d.fmt, val)
            }
        end
    else
        w = function(val)
            assert(type(val) == "number", err.invalid_number)
            return {
                area = r.area,
                dbnumber = r.dbnumber,
                start = r.start,
                number = r.number,
                wordlen = r.wordlen,
                data = strpack(d.fmt, val)
            }
        end
    end

    local u, u_bool
    if dt == "bool" then
        u = function(index, val)
            local v = strunpack(d.fmt, strsub(val, index, index+l-1))
            return v == 1
        end
        u_bool = function(index, val)
            local v = strunpack(d.fmt, strsub(val, index, index+l-1))
            return ((1<<opt) & v) ~= 0
        end
    else
        u = function(index, val)
            local v = strunpack(d.fmt, strsub(val, index, index+l-1))
            return v
        end
    end
    return r, w, u, u_bool
end
