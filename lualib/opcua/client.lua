local skynet = require "skynet"
local opcua = require "opcua"

local state = {
    [0] = "The client is disconnected",
    [1] = "The client has sent HELLO and waiting",
    [2] = "A TCP connection to the server is open",
    [3] = "A secureChannel to the server is open",
    [4] = "A session with the server is open",
    [5] = "A session with the server is disconnected",
    [6] = "A session with the server is open (renewed)"
}

local errinfo = {
    not_registered = "node not registered",
    invalid_datatype = "invalid datatype"
}

local function do_connect(self)
    local ok, err
    if self.__username ~= '' and self.__password ~= '' then
        ok, err = self.__client:connect(self.__info.url, self.__info.namespace, self.__username, self.__password)
    else
        ok, err = self.__client:connect(self.__info.url, self.__info.namespace)
    end

    if ok then
        skynet.error("opcua: connected to", self.__info.url, self.__info.namespace)
    else
        skynet.error("opcua: connect failed", self.__info.url, self.__info.namespace, err)
    end
    return ok
end

local function register_node(self)
    for _, node in pairs(self.__nodelist) do
        local ok, id, dtidx, dtname = self.__client:register(node.node)
        if ok then
            node.id = id
            node.dtidx = dtidx
            node.dtname = dtname
        else
            skynet.error("opcua: register node failed", node.name, id)
        end
    end
end

local function try_connect(self, retry)
    if retry then
        while not self.__closed do
            local ok = do_connect(self)
            if ok then
                register_node(self)
                return ok
            else
                skynet.sleep(200)
            end
        end
    else
        return do_connect(self)
    end
end

local function write_boolean(cli, id, dt, val)
    if id then
        if type(val) == "boolean" then
            return cli:write_boolean(id, dt, val)
        else
            return false, errinfo.invalid_datatype
        end
    else
        return false, errinfo.not_registered
    end
end

local function write_integer(cli, id, dt, val)
    if id then
        if math.tointeger(val) then
            return cli:write_integer(id, dt, val)
        else
            return false, errinfo.invalid_datatype
        end
    else
        return false, errinfo.not_registered
    end
end

local function write_double(cli, id, dt, val)
    if id then
        if type(val) == "number" then
            return cli:write_double(id, dt, val)
        else
            return false, errinfo.invalid_datatype
        end
    else
        return false, errinfo.not_registered
    end
end

local function write_string(cli, id, dt, val)
    if id then
        if type(val) == "string" then
            return cli:write_string(id, dt, val)
        else
            return false, errinfo.invalid_datatype
        end
    else
        return false, errinfo.not_registered
    end
end

local dt_map = {
    [0] = write_boolean,
    [1] = write_integer,
    [2] = write_integer,
    [3] = write_integer,
    [4] = write_integer,
    [5] = write_integer,
    [6] = write_integer,
    [7] = write_integer,
    [8] = write_integer,
    [9] = write_double,
    [10] = write_double,
    [11] = write_string,
}

local cli = {}
function cli:info()
    return self.__info
end

function cli:register(node)
    local ok, id, dtidx, dtname = self.__client:register(node.node)
    if ok then
        node.id = id
        node.dtidx = dtidx
        node.dtname = dtname
        self.__nodelist[node.name] = node
        return ok
    else
        return ok, id
    end
end

function cli:read(nodelist)
    return self.__client:read(nodelist)
end

function cli:write(node, val)
    local f = dt_map[node.dtidx]
    if f then
        return f(self.__client, node.id, node.dtidx, val)
    else
        return errinfo.invalid_datatype
    end
end

function cli:connect()
    self.__closed = false
    return try_connect(self)
end

function cli:close()
    self.__closed = true
    local ok, err = self.__client:disconnect()
    if ok then
        skynet.error("opcua: disconnected", self.__info.url, self.__info.namespace)
    else
        skynet.error("opcua: disconnect failed", self.__info.url, self.__info.namespace, err)
    end
    return ok
end

local client_meta = {
    __index = cli
}

local client = {}
function client.new(desc)
    assert(desc.url and desc.namespace)

    local self
    local function state_changed(s)
        self.__info.state = state[s]
        skynet.error("opcua: state changed", self.__info.state)
        if s == 0 then
            skynet.timeout(0, function() try_connect(self, true) end)
        end
    end

    local c = assert(opcua.client.new(state_changed))
    local info = c:info()

    self = setmetatable({
        __client = c,
        __info = info,
        __username = desc.username,
        __password = desc.password,
        __closed = true,
        __nodelist = {}
    }, client_meta)

    self.__info.url = desc.url
    self.__info.namespace = desc.namespace

    return self
end

return client
