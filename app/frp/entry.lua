local skynet = require "skynet"
local ini = require "utils.inifile"
local validate = require "utils.validate"
local text = require("text").frp
local log = require "log"
local sys = require "sys"
local api = require "api"

local frpcini = "run/frpc.ini"
local start_cmd = "systemctl restart frpc"
local stop_cmd = "systemctl stop frpc"
local reload_cmd = "systemctl reload frpc"

local frpcconf = {
    common = {
        tls_enable = true,
        log_file = "logs/frpc.log",
        pool_count = 2,
        admin_addr = "127.0.0.1",
        admin_port = 7400
    }
}

local proxylist = {
    ssh = {
        name = "ssh",
        type = "tcp",
        local_ip = "127.0.0.1",
        local_port = 22
    },
    console = {
        name = "console",
        type = "tcp",
        local_ip = "127.0.0.1",
        local_port = sys.console_port
    },
    ws = {
        name = "ws",
        type = "tcp",
        local_ip = "127.0.0.1",
        local_port = sys.ws_port
    },
    vpn = {
        type = "stcp",
        local_ip = "127.0.0.1",
        local_port = 1194
    }
}

local cfg_schema = {
    server_addr = function(v)
        return type(v)=="string" and v:match("^[%d%.]+$")
    end,
    server_port = function(v)
        return math.tointeger(v) and v>0 and v<0xFFFF
    end,
    token = function(v)
        return type(v)=="string" and #v > 0
    end
}

local p_schema = {
    name = function(v)
        return type(v)=="string" and #v > 0
    end,
    type = function(v)
        return v=="tcp" or v=="udp"
    end,
    local_ip = function(v)
        return type(v)=="string" and v:match("^[%d%.]+$")
    end,
    local_port = function(v)
        return math.tointeger(v) and v>0 and v<0xFFFF
    end,
    remote_port = function(v)
        return math.tointeger(v) and v>0 and v<0xFFFF
    end
}

local cmd_desc = {
    open_console = "<remote_port>",
    close_console = "Close console port",
    open_ssh = "<remote_port>",
    close_ssh = "Close ssh port",
    open_ws = "<remote_port>",
    close_ws = "Close websocket port",
    open_vpn = "<token>",
    close_vpn = "<token>",
    open = "{ name=<string>, type=<string>, local_ip=<string>, local_port=<number>, remote_port=<number> }",
    close = "<name>",
    list = "list all opened proxy"
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

local function start()
    local ok, exit, errno = os.execute(start_cmd)
    if ok and exit == "exit" and errno == 0 then
        log.error(text.start_suc)
        return true
    else
        log.error(text.start_fail)
        return false
    end
end

local function stop()
    local ok, exit, errno = os.execute(stop_cmd)
    if ok and exit == "exit" and errno == 0 then
        log.error(text.stop_suc)
    else
        log.error(text.stop_fail)
    end
end

local function reload()
    local ok, exit, errno = os.execute(reload_cmd)
    if ok and exit == "exit" and errno == 0 then
        log.error(text.reload_suc)
        return true
    else
        log.error(text.reload_fail)
        return false
    end
end

local function init_conf(cfg)
    local ok, conf = pcall(ini.parse, frpcini)
    if ok then
        frpcconf = conf
    end
    frpcconf.common.server_addr = cfg.server_addr
    frpcconf.common.server_port = cfg.server_port
    frpcconf.common.token = cfg.token
    ini.save(frpcini, frpcconf)
    ok = start()
    if ok then
        reg_cmd()
    end
    return ok
end

local function update(name, p)
    if (frpcconf[name] and not p) or p then
        frpcconf[name] = p
        ini.save(frpcini, frpcconf)
        return reload()
    else
        return false, text.invalid_arg
    end
end

local function dup(proxy)
    for name, p in pairs(frpcconf) do
        if proxy.name == name or
           (proxy.type == p.type and
           proxy.remote_port == p.remote_port) then
            return true
        end
    end
    return false
end

local function dup_vpn(name)
    for n, _ in pairs(frpcconf) do
        if n == name then
            return true
        end
    end
    return false
end

local function do_open(p)
    return update(p.name, p)
end
local function do_close(name)
    return update(name)
end

function open(proxy)
    local ok = pcall(validate, proxy, p_schema)
    if ok and not dup(proxy) then
        return do_open(proxy)
    else
        return false, text.invalid_arg
    end
end
function close(name)
    if type(name) == "string" then
        return do_close(name)
    else
        return false, text.invalid_arg
    end
end

function open_console(port)
    local p = tonumber(port)
    if p then
        proxylist.console.remote_port = p
        return do_open(proxylist.console)
    else
        return false, text.invalid_arg
    end
end
function close_console()
    return do_close(proxylist.console.name)
end

function open_ssh(port)
    local p = tonumber(port)
    if p then
        proxylist.ssh.remote_port = p
        return do_open(proxylist.ssh)
    else
        return false, text.invalid_arg
    end
end
function close_ssh()
    return do_close(proxylist.ssh.name)
end

function open_ws(port)
    local p = tonumber(port)
    if p then
        proxylist.ws.remote_port = p
        return do_open(proxylist.ws)
    else
        return false, text.invalid_arg
    end
end
function close_ws()
    return do_close(proxylist.ws.name)
end

function open_vpn(token)
    if type(token) == "string" and not dup_vpn(token) then
        proxylist.vpn.name = token
        proxylist.vpn.sk = token
        return do_open(proxylist.vpn)
    else
        return false, text.invalid_arg
    end
end
function close_vpn(token)
    if type(token) == "string" then
        return do_close(token)
    else
        return false, text.invalid_arg
    end
end

function list()
    local ret = {}
    for k, v in pairs(frpcconf) do
        if k ~= "common" then
            ret[k] = v
        end
    end
    return ret
end

function on_conf(cfg)
    local ok = pcall(validate, cfg, cfg_schema)
    if not ok then
        return false, text.invalid_conf
    end
    return init_conf(cfg)
end

function on_exit()
    --stop()
end
