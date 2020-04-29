local skynet = require "skynet"
local ini = require "utils.inifile"
local validator = require "utils.validator"
local text = require("text").app
local log = require "log"
local sys = require "sys"
local api = require "api"

local running = false
local frpcini = sys.run_root.."/frpc.ini"
local svc = "frpc"

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
        local_ip = "127.0.0.1",
        local_port = sys.vpn_port
    }
}

local cfg_schema = {
    server_addr = validator.ipv4,
    server_port = validator.port,
    token = validator.string,
    protocol = validator.vals("tcp", "kcp")
}

local p_schema = {
    name = validator.string,
    type = validator.vals("tcp", "udp"),
    local_ip = validator.ipv4,
    local_port = validator.port,
    remote_port = validator.port
}

local vpn_type = {
    tcp4 = "stcp",
    udp4 = "sudp"
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
    open_proxy = "{ name=<string>, type=<string>, local_ip=<string>, local_port=<number>, remote_port=<number> }",
    close_proxy = "<name>",
    list_proxy = "list all opened proxy"
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

local function get_vpninfo()
    return api.external_request(sys.vpnappid, "vpn_info")
end

local function init_conf(cfg)
    local ok, conf = pcall(ini.parse, frpcini)
    if ok then
        frpcconf = conf
    end
    frpcconf.common.server_addr = cfg.server_addr
    frpcconf.common.server_port = cfg.server_port
    frpcconf.common.token = cfg.token
    frpcconf.common.protocol = cfg.protocol
    ini.save(frpcini, frpcconf)

    local err
    ok, err = sys.start_svc(svc)
    log.info(err)

    if ok then
        _, err = sys.enable_svc(svc)
        log.info(err)

        running = true
    end
    return ok
end

local function update(name, p)
    if (frpcconf[name] and not p) or p then
        frpcconf[name] = p
        ini.save(frpcini, frpcconf)
        local ok, err = sys.reload_svc(svc)
        log.info(err)
        return ok
    else
        return false, text.invalid_arg
    end
end

local function dup(proxy)
    for name, p in pairs(frpcconf) do
        if proxy.name == name or
           (proxy.type == p.type and
           (proxy.remote_port == p.remote_port or
            (proxy.local_ip == p.local_ip and proxy.local_port == p.local_port)
            )) then
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

function open_proxy(proxy)
    if not running then
        return false, text.app_stopped
    end
    local ok = pcall(validator.check, proxy, p_schema)
    if ok and not dup(proxy) then
        return do_open(proxy)
    else
        return false, text.invalid_arg
    end
end
function close_proxy(name)
    if not running then
        return false, text.app_stopped
    end
    if type(name) == "string" then
        return do_close(name)
    else
        return false, text.invalid_arg
    end
end

function open_console(port)
    if not running then
        return false, text.app_stopped
    end
    local p = tonumber(port)
    if p then
        proxylist.console.remote_port = p
        return do_open(proxylist.console)
    else
        return false, text.invalid_arg
    end
end
function close_console()
    if not running then
        return false, text.app_stopped
    end
    return do_close(proxylist.console.name)
end

function open_ssh(port)
    if not running then
        return false, text.app_stopped
    end
    local p = tonumber(port)
    if p then
        proxylist.ssh.remote_port = p
        return do_open(proxylist.ssh)
    else
        return false, text.invalid_arg
    end
end
function close_ssh()
    if not running then
        return false, text.app_stopped
    end
    return do_close(proxylist.ssh.name)
end

function open_ws(port)
    if not running then
        return false, text.app_stopped
    end
    local p = tonumber(port)
    if p then
        proxylist.ws.remote_port = p
        return do_open(proxylist.ws)
    else
        return false, text.invalid_arg
    end
end
function close_ws()
    if not running then
        return false, text.app_stopped
    end
    return do_close(proxylist.ws.name)
end

function open_vpn(token)
    if not running then
        return false, text.app_stopped
    end
    if type(token) == "string" and not dup_vpn(token) then
        local vpn = get_vpninfo()
        if vpn.running then
            proxylist.vpn.type = vpn_type[vpn.proto]
            proxylist.vpn.name = token
            proxylist.vpn.sk = token
            return do_open(proxylist.vpn)
        else
            return false, text.vpn_stopped
        end
    else
        return false, text.invalid_arg
    end
end
function close_vpn(token)
    if not running then
        return false, text.app_stopped
    end
    if type(token) == "string" then
        return do_close(token)
    else
        return false, text.invalid_arg
    end
end

function list_proxy()
    if not running then
        return false, text.app_stopped
    end
    local ret = {}
    for k, v in pairs(frpcconf) do
        if k ~= "common" then
            ret[k] = v
        end
    end
    return ret
end

function on_conf(cfg)
    local ok = pcall(validator.check, cfg, cfg_schema)
    if ok then
        return init_conf(cfg)
    else
        return false, text.invalid_conf
    end
end

reg_cmd()
