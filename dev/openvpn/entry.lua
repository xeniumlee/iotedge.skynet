local skynet = require "skynet"
local validator = require "utils.validator"
local text = require("text").app
local log = require "log"
local sys = require "sys"
local api = require "api"

local vpnconf = sys.run_root.."/vpn.conf"
local install_cmd = sys.app_root.."/vpn/setup.sh"
local route_cmd = "ip route"
local interface_cmd = "ip addr"
local svc = "vpn"
local info = { running = false }

local cfg_schema = {
    eth = validator.string,
    proto = validator.vals("tcp4", "udp4"),
    ca = validator.string,
    cert = validator.string,
    key = validator.string,
    serverbridge = validator.string
}

local cmd_desc = {
    vpn_info = "Show VPN configuration & status",
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

local function install(start, eth)
    local action = start and "start" or "stop"
    local cmd = string.format("%s %s %s", install_cmd, action, eth)
    return sys.exec_with_return(cmd)
end

local function append_pem(k)
    return function(pem)
        return string.format("<%s>\n%s\n</%s>\n", k, pem, k)
    end
end

local function append_kv(k)
    return function(v)
        return string.format("%s %s\n", k, v)
    end
end

local conf_map = {
    proto = append_kv("proto"),
    serverbridge = append_kv("server-bridge"),
    ca = append_pem("ca"),
    cert = append_pem("cert"),
    key = append_pem("key")
}

local function gen_conf(cfg)
    local file = io.open(vpnconf, "a")
    local conf = ""
    for k, v in pairs(cfg) do
        local f = conf_map[k]
        if f then
            conf = conf..f(v)
        end
    end
    file:write(conf)
    file:close()
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

local function gen_route()
    local r = sys.exec_with_return(route_cmd)
    local ret = {}
    if r then
        for s in r:gmatch("[^\n]+") do
            table.insert(ret, s)
        end
    end
    return ret
end

local function gen_interface()
    local i = sys.exec_with_return(interface_cmd)
    local ret = {}
    if i then
        local key
        for s in i:gmatch("[^\n]+") do
            local eth, state = s:match("^%d+:%s+([^:]+):%s+(.+)$")
            if eth and state then
                key = eth
                ret[eth] = {}
                ret[eth].state = state
            else
                local ip = s:match("^%s+inet%s+(%g+)")
                if ip then
                    ret[key].addr = ip
                end
            end
        end
    end
    return ret
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
                log.info(err)

                if ok then
                    _, err = sys.enable_svc(svc)
                    log.info(err)
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
    info.routes = gen_route()
    info.interfaces = gen_interface()
    return info
end

function on_conf(cfg)
    if cfg.auto then
        local ok = pcall(validator.check, cfg, cfg_schema)
        if ok then
            return init_conf(cfg)
        else
            return false, text.invalid_conf
        end
    else
        local ok, err = sys.stop_svc(svc)
        log.info(err)

        _, err = sys.disable_svc(svc)
        log.info(err)

        refresh_info(cfg)
        return ok
    end
end

reg_cmd()
