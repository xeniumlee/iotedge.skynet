-- Copyright (C) Dejiang Zhu(doujiang24)
local skynet = require "skynet"
local crc32 = require "utils.crc32"

local setmetatable = setmetatable
local concat = table.concat
local strpack = string.pack

local _M = {}
local req = {}
local mt = { __index = req }

local MESSAGE_VERSION_0 = 0
local MESSAGE_VERSION_1 = 1

local API_VERSION_V0 = 0
local API_VERSION_V1 = 1
local API_VERSION_V2 = 2

_M.ProduceRequest = 0
_M.FetchRequest = 1
_M.OffsetRequest = 2
_M.MetadataRequest = 3
_M.OffsetCommitRequest = 8
_M.OffsetFetchRequest = 9
_M.ConsumerMetadataRequest = 10

local function str_int8(int)
    return strpack('I1', int)
end

local function str_int16(int)
    return strpack('>I2', int)
end

local function str_int32(int)
    return strpack('>I4', int)
end

local function str_int64(int)
    return strpack('>I8', int)
end

function _M.new(apikey, correlation_id, client_id, api_version)
    local c_len = #client_id
    api_version = api_version or API_VERSION_V0

    local r = {
        0,   -- request size: int32
        str_int16(apikey),
        str_int16(api_version),
        str_int32(correlation_id),
        str_int16(c_len),
        client_id,
    }
    return setmetatable({
        _req = r,
        api_key = apikey,
        api_version = api_version,
        offset = 7,
        len = c_len + 10,
    }, mt)
end

function req:int16(int)
    local r = self._req
    local offset = self.offset
    r[offset] = str_int16(int)
    self.offset = offset + 1
    self.len = self.len + 2
end

function req:int32(int)
    local r = self._req
    local offset = self.offset
    r[offset] = str_int32(int)
    self.offset = offset + 1
    self.len = self.len + 4
end

function req:int64(int)
    local r = self._req
    local offset = self.offset
    r[offset] = str_int64(int)
    self.offset = offset + 1
    self.len = self.len + 8
end

function req:string(str)
    local r = self._req
    local offset = self.offset
    local str_len = #str
    r[offset] = str_int16(str_len)
    r[offset + 1] = str
    self.offset = offset + 2
    self.len = self.len + 2 + str_len
end

function req:bytes(str)
    local r = self._req
    local offset = self.offset
    local str_len = #str
    r[offset] = str_int32(str_len)
    r[offset + 1] = str
    self.offset = offset + 2
    self.len = self.len + 4 + str_len
end

local function message_package(key, msg, message_version)
    local k = key or ""
    local key_len = #k
    local len = #msg

    local r
    local head_len
    if message_version == MESSAGE_VERSION_1 then
        r = {
            -- MagicByte
            str_int8(1),
            -- XX hard code no Compression
            str_int8(0),
            str_int64(math.floor(skynet.time())), -- timestamp
            str_int32(key_len),
            k,
            str_int32(len),
            msg,
        }
        head_len = 22
    else
        r = {
            -- MagicByte
            str_int8(0),
            -- XX hard code no Compression
            str_int8(0),
            str_int32(key_len),
            k,
            str_int32(len),
            msg,
        }
        head_len = 14
    end

    local str = concat(r)
    return crc32(str), str, key_len + len + head_len
end

function req:message_set(messages, index)
    local r = self._req
    local off = self.offset
    local msg_set_size = 0
    local idx = index or #messages

    local message_version = MESSAGE_VERSION_0
    if self.api_key == _M.ProduceRequest and self.api_version == API_VERSION_V2 then
        message_version = MESSAGE_VERSION_1
    end

    for i = 1, idx, 2 do
        local crc, str, msg_len = message_package(messages[i], messages[i + 1], message_version)

        r[off + 1] = str_int64(0) -- offset
        r[off + 2] = str_int32(msg_len) -- include the crc32 length
        r[off + 3] = str_int32(crc)
        r[off + 4] = str

        off = off + 4
        msg_set_size = msg_set_size + msg_len + 12
    end

    r[self.offset] = str_int32(msg_set_size) -- MessageSetSize

    self.offset = off + 1
    self.len = self.len + 4 + msg_set_size
end

function req:package()
    local r = self._req
    r[1] = str_int32(self.len)
    return r
end

return _M
