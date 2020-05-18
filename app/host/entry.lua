local skynet = require "skynet"
local log = require "log"
local api = require "api"
local sys = require "sys"
local http = require "utils.http"

local uri = "http://localhost:9100/metrics"
local svc = "nodeexporter"

local cmd_desc = {
    post_attr = "Post attributes",
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

local function fetch()
    local m = http.get(uri)
    if m then
        -- remove comments
        m = m:gsub("#[^#\n]+\n", "")
        return m
    else
        return false
    end
end

local function post_telemetry(tags)
    local post = api.post_gtelemetry
    skynet.sleep(api.post_delay)
    while true do
        local data = {}
        local m = fetch()
        local v
        for name, val in pairs(tags) do
            if val.t == "string" then
                v = sys.exec_with_return(val.p)
                if v then
                    data[name] = v
                end
            else
                if m then
                    v = m:match(val.p)
                    if v then
                        data[name] = tonumber(v)
                    end
                end
            end
        end
        post(data)
        skynet.sleep(6000)
    end
end

local function do_post_attr()
    local info = api.sys_request("info")
    if info then
        for _, app in pairs(info.apps) do
            app.conf = nil
        end
        info.frp = api.external_request(api.frpappid, "list_proxy")
        local vpn = api.external_request(api.vpnappid, "vpn_info")
        if type(vpn) == "table" and
            vpn.interfaces and
            vpn.interfaces.br0 then
            local addr = vpn.interfaces.br0.addr
            if addr then
                info.host = addr:match("^([%d%.]+)")
            end
        end

        api.post_gattr({ [api.infokey] = info })
    end
end

local function post_attributes()
    skynet.sleep(api.post_delay)
    while true do
        do_post_attr()
        skynet.sleep(30000)
    end
end

function post_attr()
    skynet.fork(do_post_attr)
    return true
end

function on_conf(cfg)
    local sys_cfg = api.internal_request("conf_get", "sys")
    local host = cfg[sys_cfg.host] and sys_cfg.host or "general"
    local tags = cfg.common
    for k, v in pairs(cfg[host]) do
        tags[k] = v
    end

    local ok, err = sys.start_svc(svc)
    log.info(err)

    if ok then
        _, err = sys.enable_svc(svc)
        log.info(err)

        skynet.fork(post_telemetry, tags)
        skynet.fork(post_attributes)
    end
    return ok
end

reg_cmd()
