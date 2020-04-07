-- Copyright (C) Dejiang Zhu(doujiang24)
local setmetatable = setmetatable
local strsub = string.sub
local strunpack = string.unpack

local _M = {}
local resp = {}
local mt = { __index = resp }

function _M.new(str, api_version)
    local r = setmetatable({
        str = str,
        offset = 1,
        correlation_id = 0,
        api_version = api_version,
    }, mt)
    r.correlation_id = resp:int32()
    return r
end

local function to_int32(str, offset)
    local o = offset or 1
    local ret = strunpack('>I4', str, o)
    return ret
end
_M.to_int32 = to_int32

function resp:int16()
    local offset = self.offset
    self.offset = offset + 2
    local ret = strunpack('>I2', self.str, offset)
    return ret
end

function resp:int32()
    local offset = self.offset
    self.offset = offset + 4
    return to_int32(self.str, offset)
end

function resp:int64()
    local offset = self.offset
    self.offset = offset + 8
    local ret = strunpack('>I8', self.str, offset)
    return ret
end

function resp:string()
    local len = self:int16()
    local offset = self.offset
    self.offset = offset + len
    return strsub(self.str, offset, offset + len - 1)
end

function resp:bytes()
    local len = self:int32()
    local offset = self.offset
    self.offset = offset + len
    return strsub(self.str, offset, offset + len - 1)
end

function resp:correlation_id()
    return self.correlation_id
end

return _M
