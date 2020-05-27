local skynet = require "skynet"
local ini = require "utils.inifile"
local validator = require "utils.validator"
local text = require("text").app
local log = require "log"
local sys = require "sys"
local api = require "api"

local svc = "vpn"
local interface = "wg0"
local show_cmd = "wg show "..interface
local publickey = string.format("%s/public.key", sys.run_root)
local privatekey = string.format("%s/private.key", sys.run_root)
local genkey_cmd = string.format("wg genkey | tee %s | wg pubkey > %s", privatekey, publickey)
local vpnini = string.format("%s/%s.conf", sys.run_root, interface)
local info = { running = false }

local vpnconf = {
    Interface = {},
    Peer = {}
}

local cfg_schema = {
    eth = validator.string,
    address = validator.string,
    listenport = validator.port,
    publickey = validator.string
}

local cmd_desc = {
    vpn_info = "Show VPN configuration & status",
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

local function gen_subnet(addr)
    local a, b, c, d, mask = addr:match("^(%d+).(%d+).(%d+).(%d+)/(%d+)$")
    assert(a and b and c and d and mask, text.invalid_conf)
    mask = tonumber(mask)
    assert(mask > 0 and mask < 32, text.invalid_conf)
    local max = 0xffffffff
    local m = (max << (32 - mask)) & max
    return string.format(
        "%d.%d.%d.%d/%d",
        (m >> 24) & tonumber(a),
        (m >> 16) & tonumber(b),
        (m >> 8) & tonumber(c),
        m & tonumber(d),
        mask
        )
end

local function read_file(file)
    local f = io.open(file)
    local ret = f:read()
    f:close()
    assert(ret and ret ~= "", text.invalid_conf)
    return ret
end

local function gen_postup(eth)
    return string.format("iptables -t nat -A POSTROUTING -o %s -j MASQUERADE; sysctl -w net.ipv4.ip_forward=1", eth)
end

local function gen_postdown(eth)
    return string.format("iptables -t nat -D POSTROUTING -o %s -j MASQUERADE; sysctl -w net.ipv4.ip_forward=0", eth)
end

local function gen_conf(cfg)
    local i = vpnconf.Interface
    i.Address = cfg.address
    i.ListenPort = cfg.listenport
    i.PrivateKey = read_file(privatekey)
    i.PostUp = gen_postup(cfg.eth)
    i.PostDown = gen_postdown(cfg.eth)

    local p = vpnconf.Peer
    p.AllowedIPs = gen_subnet(cfg.address)
    p.PublicKey = cfg.publickey

    ini.save(vpnini, vpnconf)
end

local function gen_key()
    local ok = pcall(read_file, privatekey)
    if ok then
        return ok
    else
        return sys.exec(genkey_cmd)
    end
end

local function start(cfg)
    if not gen_key() then
        return false, text.conf_fail
    end
    local ok, key = pcall(read_file, publickey)
    if ok then
        info.publickey = key
    end

    local err
    ok, err = pcall(gen_conf, cfg)
    if ok then
        ok, err = sys.start_svc(svc)
        if ok then
            info.running = cfg.auto
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

function vpn_info()
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
        local ok, err = sys.stop_svc(svc)
        if ok then
            info.running = cfg.auto
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

        return ok
    end
end

reg_cmd()
