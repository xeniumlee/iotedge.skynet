local skynet = require "skynet"

local function call(addr, ...)
    return skynet.call(addr, "lua", ...)
end

local function send(addr, ...)
    skynet.send(addr, "lua", ...)
end

local gateway_addr = ".gateway"
local store_addr = ".store"
local gateway_mqtt_addr
local appname
local devlist = {}

local api = {
    gateway_addr = gateway_addr,
    store_addr = store_addr,
    batch_max = 200,
    ttl_max = 60 -- day
}

function api.datetime(time)
    if time then
        return os.date("%Y-%m-%d %H:%M:%S", time)
    else
        return os.date("%Y-%m-%d %H:%M:%S", math.floor(skynet.time()))
    end
end

function api.reg_cmd(name, desc, internal)
    if not internal and type(_ENV[name]) ~= "function" then
        return
    end
    send(gateway_addr, "reg_cmd", name, desc)
end

local function dev_name(name, app)
    return name.."@"..app
end

function api.reg_dev(name, desc, ttl)
    if desc == true then
        appname = name
        send(gateway_addr, "reg_dev", name, desc)
    else
        if appname and
            type(name) == "string" and
            type(desc) == "string" and
            not devlist[name] then
            devlist[name] = {
                buffer = {},
                cov = {},
                size = 10
            }
            local dev = dev_name(name, appname)
            send(gateway_addr, "reg_dev", dev, desc)

            if math.tointeger(ttl) and ttl>0 then
                if ttl > api.ttl_max then
                    ttl = api.ttl_max
                end
                send(store_addr, "dev_online", dev, ttl)
            end

            if gateway_mqtt_addr then
                send(gateway_mqtt_addr, "post", "online", dev)
            end
        end
    end
end

function api.unreg_dev(name)
    if name == true then
        send(gateway_addr, "unreg_dev", name)
        local dev
        if gateway_mqtt_addr then
            for n, _ in pairs(devlist) do
                dev = dev_name(n, appname)
                send(gateway_mqtt_addr, "post", "offline", dev)
            end
        end
        appname = nil
        devlist = {}
    else
        if appname and devlist[name] then
            devlist[name] = nil
            local dev = dev_name(name, appname)
            send(gateway_addr, "unreg_dev", dev)
            if gateway_mqtt_addr then
                send(gateway_mqtt_addr, "post", "offline", dev)
            end
        end
    end
end

function api.app_init(name, mqtt)
    if mqtt then
        gateway_mqtt_addr = mqtt
    end
    api.reg_dev(name, true)
end

function api.store(dev, data)
    send(store_addr, "payload", dev, data)
end

function api.online()
    send(store_addr, "online")
end

function api.offline()
    send(store_addr, "offline")
end

function api.enable_store()
    send(store_addr, "enable", appname)
end

function api.mqtt_init()
    appname = "mqtt"
    api.enable_store()
end

function api.internal_init(cmd_desc)
    api.reg_dev("internal", true)
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v, true)
    end
end

function api.sys_init(cmd_desc)
    api.reg_dev("sys", true)
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v, true)
    end
end

function api.post_attr(dev, attr)
    if appname and devlist[dev] and gateway_mqtt_addr then
        send(gateway_mqtt_addr, "post", "attributes", dev_name(dev, appname), attr)
    end
end

function api.external_request(...)
    return call(gateway_addr, ...)
end

function api.sys_request(...)
    return call(gateway_addr, "sys", ...)
end

function api.internal_request(...)
    return call(gateway_addr, "internal", ...)
end

------------------------------------------
local r_table = {}

local function do_post(dev, data)
    local d = dev_name(dev, appname)
    for _, targets in pairs(r_table) do
        for t, _ in pairs(targets) do
            send(t, "data", d, data)
        end
    end
end

local function filter_cov(dev, data)
    local c = devlist[dev].cov
    if next(c) then
        local last
        for k, v in pairs(data) do
            last = c[k]
            if last == nil then
                c[k] = v
            end
            if last == v then
                data[k] = nil
            end
        end
    else
        devlist[dev].cov = data
    end
    return data
end

function api.pack_data(data)
    local p = {
        ts = skynet.time()*1000,
        values = data
    }
    return {p}
end

function api.ts_value(data)
    return data.ts
end

function api.data_value(data)
    return data.values
end

function api.post_cov(dev, data)
    if appname and devlist[dev] and
        type(data) == "table" and next(data) then
        data = filter_cov(dev, data)
        if next(data) then
            local p = api.pack_data(data)
            do_post(dev, p)
        end
    end
end
function api.post_data(dev, data)
    if appname and devlist[dev] and
        type(data) == "table" and next(data) then
        local p = api.pack_data(data)
        local b = devlist[dev].buffer
        table.move(p, 1, #p, #b+1, b)
        if #b >= devlist[dev].size then
            do_post(dev, b)
            devlist[dev].buffer = {}
        end
    end
end

function api.batch_size(dev, size)
    if math.tointeger(size) and
        size > 0 and
        size <= api.batch_max and
        devlist[dev] then
        devlist[dev].size = size
    end
end

function api.route_data(dev, data)
    local s = tonumber(dev:match("_(%d+)$"))
    if s and r_table[s] then
        for t, _ in pairs(r_table[s]) do
            send(t, "data", dev, data)
        end
    end
end

function api.route_add(source, target)
    if not r_table[source] then
        r_table[source] = {}
    end
    local v = r_table[source][target]
    if v then
        r_table[source][target] = v + 1
    else
        r_table[source][target] = 1
    end
end

function api.route_del(source, target)
    if r_table[source] then
        local v = r_table[source][target]
        if v == 1 then
            r_table[source][target] = nil
        else
            r_table[source][target] = v - 1
        end
    end
end

------------------------------------------
return setmetatable({}, {
  __index = api,
  __newindex = function(t, k, v)
                 error("Attempt to modify read-only table")
               end,
  __metatable = false
})
