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

local security_policy_prefix = "http://opcfoundation.org/UA/SecurityPolicy#"
local security_policy = {
    none = security_policy_prefix.."None",
    basic128rsa15 = security_policy_prefix.."Basic128Rsa15",
    basic256 = security_policy_prefix.."Basic256",
    basic256sha256 = security_policy_prefix.."Basic256Sha256"
}

local security_mode = {
    none = 1,
    sign = 2,
    signandencrypt = 3
}

local errinfo = {
    not_registered = "node not registered",
    invalid_datatype = "invalid datatype"
}

local uri = "urn:iotedge:opcua:opcua-client"
local root = "./lualib/opcua/"
local cert = root.."client.crt.der"
local key = root.."client.key.der"

local function read_file(file)
    local f = io.open(file, "rb")
    local ret = f:read("a")
    f:close()
    return ret
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

local function do_connect(self)
    if not self.__connecting then
        self.__connecting = true

        local ok, err
        if self.__username ~= '' and self.__password ~= '' then
            ok, err = self.__client:connect_username(self.__config.url, self.__config.namespace, self.__username, self.__password)
        else
            ok, err = self.__client:connect(self.__config.url, self.__config.namespace)
        end

        if ok then
            register_node(self)
            skynet.error("opcua: connected to", self.__config.url, self.__config.namespace)
        else
            skynet.error("opcua: connect failed", self.__config.url, self.__config.namespace, err)
            skynet.sleep(1000)
        end

        self.__connecting = false
        return ok
    else
        return true
    end
end

local function write_boolean(cli, id, dt, val)
    if type(val) == "boolean" then
        return cli:write_boolean(id, dt, val)
    else
        return false, errinfo.invalid_datatype
    end
end

local function write_integer(cli, id, dt, val)
    if math.tointeger(val) then
        return cli:write_integer(id, dt, val)
    else
        return false, errinfo.invalid_datatype
    end
end

local function write_float(cli, id, dt, val)
    if type(val) == "number" then
        return cli:write_float(id, dt, val)
    else
        return false, errinfo.invalid_datatype
    end
end

local function write_double(cli, id, dt, val)
    if type(val) == "number" then
        return cli:write_double(id, dt, val)
    else
        return false, errinfo.invalid_datatype
    end
end

local function write_string(cli, id, dt, val)
    if type(val) == "string" then
        return cli:write_string(id, dt, val)
    else
        return false, errinfo.invalid_datatype
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
    local channel, session, connection = self.__client:state()
    self.__state.connection = connection
    self.__state.channel = channel_state[channel]
    self.__state.session = session_state[session]
    return { state = self.__state, config = self.__config }
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
    local ok, ret = self.__client:read(nodelist)
    if not ok then
        skynet.timeout(0, function() do_connect(self) end)
    end
    return ok, ret
end

function cli:write(node, val)
    if node.id then
        local f = dt_map[node.dtidx]
        if f then
            local ok, ret = f(self.__client, node.id, node.dtidx, val)
            if not ok and ret ~= errinfo.invalid_datatype then
                skynet.timeout(0, function() do_connect(self) end)
            end
            return ok, ret
        else
            return false, errinfo.invalid_datatype
        end
    else
        return false, errinfo.not_registered
    end
end

function cli:connect()
    return do_connect(self)
end

function cli:close()
    local ok, err = self.__client:disconnect()
    if ok then
        skynet.error("opcua: disconnected", self.__config.url, self.__config.namespace)
    else
        skynet.error("opcua: disconnect failed", self.__config.url, self.__config.namespace, err)
    end
    return ok
end

local client_meta = {
    __index = cli
}

local client = {}
function client.new(desc)
    assert(desc.url and desc.namespace)

    local c = assert(read_file(cert))
    local k = assert(read_file(key))

    local s_mode = assert(security_mode[desc.security_mode])
    local s_policy = assert(security_policy[desc.security_policy])

    local opcua_c = assert(opcua.client.new(uri, s_mode, s_policy, c, k))
    local config = opcua_c:configuration()
    config.security_mode = desc.security_mode
    config.security_policy = desc.security_policy
    config.url = desc.url
    config.namespace = desc.namespace

    return setmetatable({
        __client = opcua_c,
        __username = desc.username,
        __password = desc.password,
        __nodelist = {},
        __state = {},
        __config = config,
        __connecting = false
    }, client_meta)
end

return client
