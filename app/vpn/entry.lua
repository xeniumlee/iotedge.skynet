local skynet = require "skynet"
local validate = require "utils.validate"
local text = require("text").app
local log = require "log"
local sys = require "sys"
local api = require "api"

local vpnconf = "run/vpn.conf"
local install_cmd = "app/vpn/setup.sh"
local cacrt = "app/vpn/ca.crt"
local servercrt = "app/vpn/server.crt"
local serverkey = "app/vpn/server.key"
local takey = "app/vpn/ta.key"

local svc = "vpn"

local cfg_schema = {
    eth = function(v)
        return type(v)=="string" and #v > 0
    end,
    ipaddr = function(v)
        return type(v)=="string" and v:match("^[%d%.]+$")
    end,
    netmask = function(v)
        return math.tointeger(v) and v>0 and v<32
    end,
    proto = function(v)
        return v=="tcp4" or v=="udp4"
    end,
    ca = function(v)
        return type(v)=="string" and #v > 0
    end,
    cert = function(v)
        return type(v)=="string" and #v > 0
    end,
    key = function(v)
        return type(v)=="string" and #v > 0
    end,
    tlsauth = function(v)
        return type(v)=="string" and #v > 0
    end,
    serverbridge = function(v)
        return type(v)=="string" and #v > 0
    end
}

local function install(start, eth, ipaddr, netmask)
    local action = start and "start" or "stop"
    local cmd = string.format("%s %s %s %s/%d", install_cmd, action, eth, ipaddr, netmask)
    return sys.exec(cmd)
end

local function write_conf(file, conf)
    local f = io.open(file, "w")
    f:write(conf)
    f:close()
end

local function append_conf(file, conf)
    local f = io.open(file, "a")
    f:write(conf..'\n')
    f:close()
end

local conf_map = {
    proto = function(v) append_conf(vpnconf, "proto "..v) end,
    serverbridge = function(v) append_conf(vpnconf, "server-bridge "..v) end,
    ca = function(v) write_conf(cacrt, v) end,
    cert = function(v) write_conf(servercrt, v) end,
    key = function(v) write_conf(serverkey, v) end,
    tlsauth = function(v) write_conf(takey, v) end
}

local function gen_conf(cfg)
    for k, v in pairs(cfg) do
        local f = conf_map[k]
        if f then
            f(v)
        end
    end
end

local function init_conf(cfg)
    local ok = install(true, cfg.eth, cfg.ipaddr, cfg.netmask)
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
            return ok
        else
            return false, text.conf_fail
        end
    else
        return false, text.install_fail
    end
end

function on_conf(cfg)
    if cfg.auto then
        local ok = pcall(validate, cfg, cfg_schema)
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

        return ok
    end
end
