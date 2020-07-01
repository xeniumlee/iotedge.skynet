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
local localhost = "127.0.0.1"

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
        local_port = sys.ssh_port
    },
    console = {
        name = "console",
        type = "tcp",
        local_port = sys.console_port
    },
    ws = {
        name = "ws",
        type = "tcp",
        local_port = sys.ws_port
    },
    vnc = {
        name = "vnc",
        type = "tcp",
    },
    vpn = {
        name = "vpn",
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

local vnc_schema = {
    local_ip = validator.ipv4,
    local_port = validator.port,
    remote_port = validator.port
}

local vpn_type = {
    tcp = "stcp",
    udp = "sudp"
}
local default_vpn_type = "sudp"

local cmd_desc = {
    open_console = "<remote_port>",
    close_console = "Close console port",
    open_ssh = "<remote_port>",
    close_ssh = "Close ssh port",
    open_ws = "<remote_port>",
    close_ws = "Close websocket port",
    open_vpn = "<token>",
    close_vpn = "<token>",
    open_vnc = "{ local_ip=<string>, local_port=<number>, remote_port=<number> }",
    close_vnc = "<remote_port>",
    open_proxy = "{ name=<string>, type=<string>, local_ip=<string>, local_port=<number>, remote_port=<number> }",
    close_proxy = "<name>",
    list_proxy = "list all opened proxy"
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

local function init_proxylist(conf)
    for k, v in pairs(conf) do
        if v.name ~= "vpn" then
            local p = proxylist[v.name]
            if p then
                p.remote_port = v.remote_port
            end
        end
    end
end

local function init_conf(cfg)
    local ok, conf = pcall(ini.parse, frpcini)
    if ok then
        frpcconf = conf
        init_proxylist(conf)
    end
    frpcconf.common.server_addr = cfg.server_addr
    frpcconf.common.server_port = cfg.server_port
    frpcconf.common.token = cfg.token
    frpcconf.common.protocol = cfg.protocol

    local err
    ok, err = pcall(ini.save, frpcini, frpcconf)
    if not ok then
        log.error(err)
        return ok
    end

    ok, err = sys.start_svc(svc)
    if ok then
        log.info(err)
    else
        log.error(err)
    end

    if ok then
        ok, err = sys.enable_svc(svc)
        if ok then
            log.info(err)
        else
            log.error(err)
        end

        running = true
    end
    return ok
end

local function dup(proxy)
    for name, p in pairs(frpcconf) do
        if proxy.name == name or
           (proxy.type == p.type and proxy.remote_port == p.remote_port) then
            return true
        end
    end
    return false
end

local function get_vpninfo()
    return api.external_request(api.vpnappid, "vpn_info")
end

local function reload()
    ini.save(frpcini, frpcconf)
    local ok, err = sys.reload_svc(svc)
    if ok then
        log.info(err)
    else
        log.error(err)
    end
    return ok, err
end

local function make_name(prefix, remote_port)
    return string.format("%s-%d", prefix, remote_port)
end

local function do_open(proxy, remote_port)
    if not running then
        return false, text.app_stopped
    end

    local p = tonumber(remote_port)
    if not p then
        return false, text.invalid_arg
    end

    local name = make_name(proxy.name, p)
    if frpcconf[name] then
        return false, text.invalid_arg
    end

    proxy.local_ip = localhost
    proxy.remote_port = p
    frpcconf[name] = proxy
    return reload()
end
local function do_close(proxy)
    if not running then
        return false, text.app_stopped
    end

    local name
    if type(proxy) == "string" then
        name = proxy
    else
        name = make_name(proxy.name, proxy.remote_port)
    end
    if frpcconf[name] then
        frpcconf[name] = nil
        return reload()
    else
        return false, text.invalid_arg
    end
end

function open_console(port)
    return do_open(proxylist.console, port)
end
function close_console()
    return do_close(proxylist.console)
end

function open_ssh(port)
    return do_open(proxylist.ssh, port)
end
function close_ssh()
    return do_close(proxylist.ssh)
end

function open_ws(port)
    return do_open(proxylist.ws, port)
end
function close_ws()
    return do_close(proxylist.ws)
end

function open_vnc(vnc)
    if not running then
        return false, text.app_stopped
    end
    local ok = pcall(validator.check, vnc, vnc_schema)
    vnc.name = make_name(proxylist.vnc.name, vnc.remote_port)
    vnc.type = proxylist.vnc.type

    if ok and not dup(vnc) then
        local k = vnc.name
        vnc.name = proxylist.vnc.name
        frpcconf[k] = vnc
        return reload()
    else
        return false, text.invalid_arg
    end
end
function close_vnc(port)
    local p = tonumber(port)
    if p then
        local name = make_name(proxylist.vnc.name, p)
        return do_close(name)
    else
        return false, text.invalid_arg
    end
end

function open_proxy(proxy)
    if not running then
        return false, text.app_stopped
    end
    local ok = pcall(validator.check, proxy, p_schema)
    if ok and not dup(proxy) then
        frpcconf[proxy.name] = proxy
        return reload()
    else
        return false, text.invalid_arg
    end
end
function close_proxy(name)
    if type(name) == "string" then
        return do_close(name)
    else
        return false, text.invalid_arg
    end
end

function open_vpn(token)
    if not running then
        return false, text.app_stopped
    end
    if type(token) == "string" then
        local vpn = get_vpninfo()
        if vpn.running then
            frpcconf[token] = {
                local_port = vpn.listenport,
                name = proxylist.vpn.name,
                local_ip = localhost,
                type = vpn_type[vpn.proto] or default_vpn_type,
                sk = token
            }
            return reload()
        else
            return false, text.app_stopped
        end
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
