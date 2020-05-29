local skynet = require "skynet"
local ini = require "utils.inifile"
local validator = require "utils.validator"
local text = require("text").app
local log = require "log"
local sys = require "sys"
local api = require "api"

local svc = "vpn"
local interface = "wg0"
local publickey = string.format("%s/public.key", sys.run_root)
local privatekey = string.format("%s/private.key", sys.run_root)
local show_cmd = string.format("wg show %s", interface)
local genkey_cmd = string.format("wg genkey | tee %s | wg pubkey > %s", privatekey, publickey)
local open_cmd = string.format("wg set %s peer %%s allowed-ips %%s/32", interface)
local close_cmd = string.format("wg set %s peer %%s remove", interface)
local vpnini = string.format("%s/%s.conf", sys.run_root, interface)
local info = {}

local vpnconf = {
    Interface = {}
}

local cfg_schema = {
    address = validator.string,
    listenport = validator.port,
    eth = function(v)
        if type(v) == "table" then
            for _, e in ipairs(v) do
                if type(e) ~= "string" or e == "" then
                    return false
                end
            end
            return true
        else
            return false
        end
    end
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
    local cmd = { "sysctl -w net.ipv4.ip_forward=1" }
    for _, e in ipairs(eth) do
        table.insert(cmd, string.format("iptables -t nat -A POSTROUTING -o %s -j MASQUERADE", e))
    end
    return table.concat(cmd, ";")
end

local function gen_postdown(eth)
    local cmd = {}
    for _, e in ipairs(eth) do
        table.insert(cmd, string.format("iptables -t nat -D POSTROUTING -o %s -j MASQUERADE", e))
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

local function init_info(cfg)
    info = {}
    info.running = cfg.auto
    if cfg.auto then
        info.listenport = cfg.listenport

        local ok, key = pcall(read_file, publickey)
        if ok then
            info.publickey = key
        end

        if type(cfg.address) == "string" then
            local host = cfg.address:match("^([%d%.]+)/%d+$")
            if host then
                info.host = host
            end
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

function open_peer(arg)
    if type(arg) == "table" and
        type(arg.publickey) == "string" and
        type(arg.ip) == "string" and arg.ip:match("^[%d%.]+$") then
        local cmd = string.format(open_cmd, arg.publickey, arg.ip)
        return sys.exec(cmd)
    else
        return false, text.invalid_arg
    end
end

function close_peer(arg)
    if type(arg) == "table" and
        type(arg.publickey) == "string" then
        local cmd = string.format(close_cmd, arg.publickey)
        return sys.exec(cmd)
    else
        return false, text.invalid_arg
    end
end

function vpn_info()
    if info.running then
        local peers = sys.exec_with_return(show_cmd)
        if peers then
            info.peers = {}
            for p in string.gmatch(peers, "allowed ips:%s+([%d%.]+)") do
                table.insert(info.peers, p)
            end
        end
    end
    return info
end

function on_conf(cfg)
    if cfg.auto then
        local ok = pcall(validator.check, cfg, cfg_schema)
        if ok then
            return start(cfg)
        else
            return ok, text.invalid_conf
        end
    else
        init_info(cfg)
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

        os.remove(vpnini)

        return ok
    end
end

reg_cmd()
