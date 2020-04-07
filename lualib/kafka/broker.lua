-- Copyright (C) Dejiang Zhu(doujiang24)
local socketchannel = require "skynet.socketchannel"
local response = require "kafka.response"
local to_int32 = response.to_int32

local setmetatable = setmetatable

local _M = {}
local broker = {}
local mt = { __index = broker,
             __tostring = function(bk) return bk[1].__host..":"..bk[1].__port end }

local function dispatch_reply(so)
    local len_reply = so:read(4)
    local data = so:read(to_int32(len_reply))
    return to_int32(data), true, data
end

function _M.new(host, port)
    local ip = require("sys").resolve(host)
    if not ip then
        error("cannot resolve uri")
    end
    local ch = socketchannel.channel {
        host = ip,
        port = port,
        response = dispatch_reply,
        nodelay = true
    }
    return setmetatable({ch}, mt)
end

function broker:send_receive(request, correlation_id)
    local ch = self[1]
    local ok, data = pcall(ch.request, ch, request:package(), correlation_id)
    if ok then
        return response.new(data, request.api_version), nil
    else
        return nil, data
    end
end

return _M
