local skynet = require "skynet"
local ini = require "utils.inifile"
local validator = require "utils.validator"
local basexx = require "utils.basexx"
local text = require("text").vpn
local log = require "log"
local sys = require "sys"
local api = require "api"

local svc = "vpn"
local interface = "wg0"
local ip_suffix = 32
local max_idle = 60*60

local interface_address = "^([%d%.]+)/%d+$"
local peer_address = "^[%d%.]+$"
local peer_ip = string.format("(%%g+)%%s+([%%d%%.]+)/%d", ip_suffix)
local peer_handshake = "(%g+)%s+(%d+)"

local publickey = string.format("%s/public.key", sys.run_root)
local privatekey = string.format("%s/private.key", sys.run_root)
local vpnini = string.format("%s/%s.conf", sys.run_root, interface)

local ip_forward_cmd = "sysctl -w net.ipv4.ip_forward=1"
local route_add_cmd = "iptables -t nat -A POSTROUTING -o %s -j MASQUERADE"
local route_del_cmd = "iptables -t nat -D POSTROUTING -o %s -j MASQUERADE"

local peer_ip_cmd = string.format("wg show %s allowed-ips", interface)
local peer_handshake_cmd = string.format("wg show %s latest-handshakes", interface)
local genkey_cmd = string.format("wg genkey | tee %s | wg pubkey > %s", privatekey, publickey)
local open_cmd = string.format("wg set %s peer %%s allowed-ips %%s/%d", interface, ip_suffix)
local close_cmd = string.format("wg set %s peer %%s remove", interface)

local info = {}
local peers = {}

local vpnconf = {
    Interface = {}
}

local cfg_schema = {
    eth = validator.string,
    address = validator.string,
    listenport = validator.port,
    max_idle = validator.posint
}

local cmd_desc = {
    open_peer = "{ publickey=<>, ip=<x.x.x.x> }",
    close_peer = "{ publickey=<> }",
    vpn_info = "Show VPN configuration & status",
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

local function gen_postup(eth)
    local cmd = { ip_forward_cmd }
    for e in string.gmatch(eth, "%g+") do
        table.insert(cmd, string.format(route_add_cmd, e))
    end
    return table.concat(cmd, ";")
end

local function gen_postdown(eth)
    local cmd = {}
    for e in string.gmatch(eth, "%g+") do
        table.insert(cmd, string.format(route_del_cmd, e))
    end
    return table.concat(cmd, ";")
end

local function read_file(file)
    local f = io.open(file)
    local ret = f:read()
    f:close()
    assert(ret and ret ~= "", text.invalid_conf)
    return ret
end

local function gen_key()
    local private = pcall(read_file, privatekey)
    local public = pcall(read_file, publickey)
    if private and public then
        return true
    else
        return sys.exec(genkey_cmd)
    end
end

local function gen_conf(cfg)
    local i = vpnconf.Interface
    i.Address = cfg.address
    i.ListenPort = cfg.listenport
    i.PrivateKey = read_file(privatekey)
    i.PostUp = gen_postup(cfg.eth)
    i.PostDown = gen_postdown(cfg.eth)
    i.SaveConfig = "true"

    ini.save(vpnini, vpnconf)
end

local function do_close_peer(key)
    peers[key] = nil
    local cmd = string.format(close_cmd, key)
    return sys.exec(cmd)
end

local function refresh_peer()
    local now = math.floor(skynet.time())

    local list = sys.exec_with_return(peer_ip_cmd)
    if list then
        for key, ip in string.gmatch(list, peer_ip) do
            local peer = peers[key]
            if peer then
                peer.ip = ip
            else
                peers[key] = { ip = ip, last = now }
            end
        end
    end

    list = sys.exec_with_return(peer_handshake_cmd)
    if list then
        for key, last in string.gmatch(list, peer_handshake) do
            local peer = peers[key]
            if peer then
                local t = math.tointeger(last)
                if t ~= 0 then
                    peer.last = t
                end
            end
        end
    end

    for key, peer in pairs(peers) do
        if now - peer.last > info.max_idle then
            do_close_peer(key)
            log.info(text.peer_expired, key)
        end
    end
end

local function init_info(cfg)
    info = { running = false }

    info.proto = "udp"
    info.listenport = cfg.listenport
    info.max_idle = cfg.max_idle

    local ok, key = pcall(read_file, publickey)
    if ok then
        info.publickey = key
        info.token = basexx.to_hex(key)
    end

    local host = cfg.address:match(interface_address)
    if host then
        info.host = host
    end

    info.peers = peers
end

local function open_frp()
    if info.token then
        local ok, err = api.external_request(api.frpappid, "open_vpn", info.token)
        if not ok then
            log.error(err)
        end
    end
end

local function close_frp()
    if info.token then
        local ok, err = api.external_request(api.frpappid, "close_vpn", info.token)
        if not ok then
            log.error(err)
        end
    end
end

local function start(cfg)
    if not gen_key() then
        return false, text.conf_fail
    end
    init_info(cfg)

    local ok, err = pcall(gen_conf, cfg)
    if ok then
        ok, err = sys.start_svc(svc)
        if ok then
            refresh_peer()
            info.running = true

            skynet.timeout(500, open_frp)
            ok, err = sys.enable_svc(svc)
            if ok then
                log.info(err)
            else
                log.error(err)
            end
        else
            log.error(err)
        end

        return ok
    else
        return ok, err
    end
end

local function stop()
    --close_frp()
    --peers = {}
    --init_info(cfg)

    local ok, err = sys.stop_svc(svc)
    if ok then
        log.info(err)
    else
        log.error(err)
    end

    ok, err = sys.disable_svc(svc)
    if ok then
        log.info(err)
    else
        log.error(err)
    end

    --os.remove(vpnini)

    return ok
end

function open_peer(arg)
    if info.running then
        if type(arg) == "table" and
            type(arg.publickey) == "string" and
            type(arg.ip) == "string" and arg.ip:match(peer_address) then

            refresh_peer()

            for k, p in pairs(peers) do
                if k ~= arg.publickey and p.ip == arg.ip then
                    return false, text.peer_dup
                end
            end

            local peer = peers[arg.publickey]
            if peer then
                if peer.ip == arg.ip then
                    return true, text.peer_opened
                else
                    log.info(text.peer_update, arg.publickey)
                end
            end
            local cmd = string.format(open_cmd, arg.publickey, arg.ip)
            return sys.exec(cmd)
        else
            return false, text.invalid_arg
        end
    else
        return false, text.vpn_stopped
    end
end

function close_peer(arg)
    if info.running then
        if type(arg) == "table" and
            type(arg.publickey) == "string" then

            refresh_peer()

            if peers[arg.publickey] then
                return do_close_peer(arg.publickey)
            else
                return true, text.peer_closed
            end
        else
            return false, text.invalid_arg
        end
    else
        return false, text.vpn_stopped
    end
end

function vpn_info()
    if info.running then
        refresh_peer()
    end
    return info
end

function on_conf(cfg)
    local ok = pcall(validator.check, cfg, cfg_schema)
    if ok then
        return start(cfg)
    else
        return ok, text.invalid_conf
    end
end

function on_exit()
    stop()
end

reg_cmd()
