local skynet = require "skynet"
local log = require "log"
local api = require "api"
local sys = require "sys"
local http = require "utils.http"

local uri = "http://localhost:9100/metrics"
local start_cmd = "systemctl restart nodeexporter"
local stop_cmd = "systemctl stop nodeexporter"
local running = false

local function start()
    local ok, exit, errno = os.execute(start_cmd)
    if ok and exit == "exit" and errno == 0 then
        log.error("nodeexporter started")
        running = true
        return true
    else
        log.error("start nodeexporter failed")
        return false
    end
end

local function stop()
    local ok, exit, errno = os.execute(stop_cmd)
    if ok and exit == "exit" and errno == 0 then
        log.error("nodeexporter stopped")
    else
        log.error("stop nodeexporter failed")
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
    start()
    local post = api.post_gtelemetry
    while running do
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

local function post_attributes()
    local post = api.post_gattr
    local key = sys.infokey
    while running do
        local info = api.sys_request("info")
        for _, app in pairs(info.apps) do
            app.conf = nil
        end
        post({ [key] = info })
        skynet.sleep(30000)
    end
end

function on_conf(cfg)
    local sys_cfg = api.internal_request("conf_get", "sys")
    local host = cfg[sys_cfg.host] and sys_cfg.host or "general"
    local tags = cfg.common
    for k, v in pairs(cfg[host]) do
        tags[k] = v
    end

    skynet.fork(post_telemetry, tags)
    skynet.fork(post_attributes)
    return true
end

function on_exit()
    running = false
    stop()
end
