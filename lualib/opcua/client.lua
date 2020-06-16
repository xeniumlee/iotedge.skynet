local skynet = require "skynet"
local opcua = require "opcua"

local function do_connect(self)
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
    end
    return ok
end

local state = {
    [0] = "The client is disconnected",
    [1] = "The client has sent HELLO and waiting",
    [2] = "A TCP connection to the server is open",
    [3] = "A secureChannel to the server is open",
    [4] = "A session with the server is open",
    [5] = "A session with the server is disconnected",
    [6] = "A session with the server is open (renewed)"
}

local function state_changed(s)
    skynet.error("opcua: state changed", state[s])
end

local channel = {}
function channel:info()
    local info = self.__client:info()
    info.url = self.__url
    info.namespace = self.__namespace
    info.state = state[info.state]
    return info
end

function channel:register(node)
    local ok, id, dtidx, dtname = self.__client:register(node.node)
    if ok then
        node.id = id
        node.dtidx = dtidx
        node.dtname = dtname
        self.__nodelist[id] = node.node
        return ok
    else
        return ok, id
    end
end

function channel:read(nodelist)
    return self.__client:read(nodelist)
end

function channel:write(node, val)
    return self.__client:write(node.id, node.dtidx, val)
end

function channel:connect()
    self.__closed = false
    return do_connect(self)
end

function channel:close()
    self.__closed = true
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
    local cli = assert(opcua.client.new(state_changed))

    local self = setmetatable({
        __client = cli,
        __url = desc.url,
        __namespace = desc.namespace,
        __username = desc.username,
        __password = desc.password,
        __closed = true,
        __nodelist = {}
    }, client_meta)

    return self
end

return client
