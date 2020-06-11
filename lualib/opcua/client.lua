local skynet = require "skynet"
local opcua = require "opcua"

local function do_connect(self)
    if not self.__connecting then
        self.__connecting = true
        local ok, err
        if self.__username ~= '' and self.__password ~= '' then
            ok, err = self.__client:connect(self.__url, self.__namespace, self.__username, self.__password)
        else
            ok, err = self.__client:connect(self.__url, self.__namespace)
        end

        if ok then
            skynet.error("opcua: connected to", self.__url, self.__namespace)
        else
            skynet.error("opcua: connect failed", self.__url, self.__namespace, err)
            skynet.sleep(1000)
        end
        self.__connecting = false
        return ok
    else
        return true
    end
end

local channel = {}
function channel:info()
    local info = self.__client:info()
    info.url = self.__url
    info.namespace = self.__namespace
    return info
end

function channel:register(nodename)
    local ok, id, t = self.__client:register(nodename)
    return ok, id, t
end

function channel:read(node)
    local ok, err = self.__client:read(node)
    return ok, err
end

function channel:write(node, val)
    local ok, err = self.__client:write(node, val)
    return ok, err
end

function channel:connect()
    return do_connect(self)
end

function channel:close()
    local ok, err = self.__client:disconnect()
    if ok then
        skynet.error("opcua: disconnected", self.__url, self.__namespace)
    else
        skynet.error("opcua: disconnect failed", self.__url, self.__namespace, err)
    end
    return ok
end

local client_meta = {
    __index = channel
}

local client = {}
function client.new(desc)
    assert(desc.url and desc.namespace)
    local cli = assert(opcua.client.new())

    local self = setmetatable({
        __client = cli,
        __url = desc.url,
        __namespace = desc.namespace,
        __username = desc.username,
        __password = desc.password,
        __connecting = false,
    }, client_meta)
    skynet.fork(do_connect, self)

    return self
end

return client
