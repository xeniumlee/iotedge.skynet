local skynet = require "skynet"
local validate = require "utils.validate"
local text = require("text").vpn
local log = require "log"
local sys = require "sys"
local api = require "api"

local vpnconf = "run/vpn.conf"
local vpnconf_tpl = "app/vpn/vpn.conf"
local cacrt = "app/vpn/ca.crt"
local servercrt = "app/vpn/server.crt"
local serverkey = "app/vpn/server.key"
local takey = "app/vpn/ta.key"

local setup_cmd = "app/vpn/setup.sh"
local start_cmd = "systemctl restart vpn"
local stop_cmd = "systemctl stop vpn"

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

local function setup(start, eth, ipaddr, netmask)
    local s = start and "start" or "stop"
    local cmd = string.format("%s %s %s %s/%d", setup_cmd, s, eth, ipaddr, netmask)
    local ok  = sys.exec(cmd)
    if ok then
        log.error(text.setup_suc)
    else
        log.error(text.setup_fail)
    end
    return ok
end

local function start()
    local ok  = sys.exec(start_cmd)
    if ok then
        log.error(text.start_suc)
    else
        log.error(text.start_fail)
    end
    return ok
end

local function stop()
    local ok  = sys.exec(stop_cmd)
    if ok then
        log.error(text.stop_suc)
    else
        log.error(text.stop_fail)
    end
    return ok
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
    local ok = setup(true, cfg.eth, cfg.ipaddr, cfg.netmask)
    if ok then
        ok = pcall(gen_conf, cfg)
        if ok then
            return start()
        else
            return false, text.conf_fail
        end
    else
        return false, text.setup_fail
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
        return stop()
    end
end
