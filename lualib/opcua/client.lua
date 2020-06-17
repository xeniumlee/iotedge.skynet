local skynet = require "skynet"
local opcua = require "opcua"

local session_state = {
    [0] = "Closed",
    [1] = "Create requested",
    [2] = "Created",
    [3] = "Activate requested",
    [4] = "Activated",
    [5] = "Closing"
}

local channel_state = {
    [0] = "Closed",
    [1] = "Hello sent",
    [2] = "Hello received",
    [3] = "Ack sent",
    [4] = "Ack received",
    [5] = "Open sent",
    [6] = "Open",
    [7] = "Closing"
}

local errinfo = {
    not_registered = "node not registered",
    invalid_datatype = "invalid datatype"
}

local function do_connect(self)
    local ok, err
    if self.__username ~= '' and self.__password ~= '' then
        ok, err = self.__client:connect_username(self.__info.url, self.__info.namespace, self.__username, self.__password)
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

local function write_float(cli, id, dt, val)
    if id then
        if type(val) == "number" then
            return cli:write_float(id, dt, val)
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
    [9] = write_float,
    [10] = write_double,
    [11] = write_string,
}

local cli = {}
function cli:info()
    local s1, s2, s3 = self.__client:state()
    self.__info.state.connection = s3
    self.__info.state.channel = channel_state[s1]
    self.__info.state.session = session_state[s2]
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

    local opcua_c = assert(opcua.client.new())
    local config = opcua_c:configuration()
    return setmetatable({
        __client = opcua_c,
        __username = desc.username,
        __password = desc.password,
        __closed = true,
        __nodelist = {},
        __info = {
            state = {},
            config = config,
            url = desc.url,
            namespace = desc.namespace
        }
    }, client_meta)
end

return client
