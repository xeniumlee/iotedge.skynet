local skynet = require "skynet"
local validator = require "utils.validator"
local text = require("text").app
local log = require "log"
local sys = require "sys"
local api = require "api"

local registered = false
local vpnconf = "run/vpn.conf"
local install_cmd = "app/vpn/setup.sh"
local svc = "vpn"
local info = {}

local cfg_schema = {
    eth = validator.string,
    proto = function(v) return v=="tcp4" or v=="udp4" end,
    ca = validator.string,
    cert = validator.string,
    key = validator.string,
    tlsauth = validator.string,
    serverbridge = validator.string
}

local cmd_desc = {
    vpn_info = "Show VPN configuration & status",
}

local function reg_cmd()
    if not registered then
        for k, v in pairs(cmd_desc) do
            api.reg_cmd(k, v)
        end
        registered = true
    end
end

local function install(start, eth)
    local action = start and "start" or "stop"
    local cmd = string.format("%s %s %s", install_cmd, action, eth)
    return sys.exec_with_return(cmd)
end

local function append_conf(conf)
    local f = io.open(vpnconf, "a")
    f:write(conf..'\n')
    f:close()
end

local function append_pem(key)
    return function(pem)
        local conf = string.format("<%s>\n%s\n</%s>", key, pem, key)
        append_conf(conf)
    end
end

local conf_map = {
    proto = function(v) append_conf("proto "..v) end,
    serverbridge = function(v) append_conf("server-bridge "..v) end,
    ca = append_pem("ca"),
    cert = append_pem("cert"),
    key = append_pem("key"),
    tlsauth = append_pem("tls-auth")
}

local function gen_conf(cfg)
    for k, v in pairs(cfg) do
        local f = conf_map[k]
        if f then
            f(v)
        end
    end
end

local function gen_server_bridge(cfg, ipaddr)
    local ip, mask = ipaddr:match("^([.%d]+)/(%d+)$")
    mask = math.tointeger(mask)
    if ip and mask then
        mask = (0xffffffff << (32-mask)) & 0xffffffff
        mask = string.format(
            "%d.%d.%d.%d",
            (mask>>24)&0xff,
            (mask>>16)&0xff,
            (mask>>8)&0xff,
            mask&0xff
            )
        cfg.serverbridge = string.format(
            "%s %s %s",
            ip,
            mask,
            cfg.serverbridge
            )
        return true
    else
        return false
    end
end

local function refresh_info(cfg)
    info.running = cfg.auto
    info.proto = cfg.proto
    info.eth = cfg.eth
    info.pool = cfg.serverbridge
end

local function init_conf(cfg)
    local ipaddr = install(true, cfg.eth)
    if ipaddr then
        local ok = gen_server_bridge(cfg, ipaddr)
        if ok then
            ok = pcall(gen_conf, cfg)
            if ok then
                local err
                ok, err = sys.start_svc(svc)
                log.error(err)

                if ok then
                    _, err = sys.enable_svc(svc)
                    log.error(err)
                end
                refresh_info(cfg)

                return ok
            else
                return false, text.conf_fail
            end
        else
            return false, text.invalid_conf
        end
    else
        return false, text.install_fail
    end
end

function vpn_info()
    return info
end

function on_conf(cfg)
    reg_cmd()
    if cfg.auto then
        local ok = pcall(validator.check, cfg, cfg_schema)
        if ok then
            return init_conf(cfg)
        else
            return false, text.invalid_conf
        end
    else
        local ok, err = sys.stop_svc(svc)
        log.error(err)

        _, err = sys.disable_svc(svc)
        log.error(err)

        refresh_info(cfg)
        return ok
    end
end
