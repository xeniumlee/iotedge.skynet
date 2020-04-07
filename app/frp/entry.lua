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
        name = "vpn",
        type = "udp",
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
    open_vpn = "<remote_port>",
    close_vpn = "Close VPN server",
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

local function open_vpn_server()
    return true
end

local function close_vpn_server()
    return true
end

local function init_conf(cfg)
    frpcconf.common.server_addr = cfg.server_addr
    frpcconf.common.server_port = cfg.server_port
    frpcconf.common.token = cfg.token
    ini.save(frpcini, frpcconf)
    local ok = start()
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
           proxy.remote_port == p.remote_port) or
           (proxy.type == p.type and
            proxy.local_ip == p.local_ip and
            proxy.local_port == p.local_port) then
            return true
        end
    end
    return false
end

local function do_open(p)
    local ok = pcall(validate, p, p_schema)
    if ok and not dup(p) then
        return update(p.name, p)
    else
        return false, text.invalid_arg
    end
end

function open(arg)
    return do_open(arg)
end
function close(name)
    return update(name)
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
    return update(proxylist.console.name)
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
    return update(proxylist.ssh.name)
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
    return update(proxylist.ws.name)
end

function open_vpn(port)
    local p = tonumber(port)
    if p then
        proxylist.vpn.remote_port = p
        local ok = do_open(proxylist.vpn)
        if ok then
            return open_vpn_server()
        else
            return ok
        end
    else
        return false, text.invalid_arg
    end
end
function close_vpn()
    update(proxylist.vpn.name)
    return close_vpn_server()
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
    stop()
end
