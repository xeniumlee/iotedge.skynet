local skynet = require "skynet"

local function call(addr, ...)
    return skynet.call(addr, "lua", ...)
end

local function send(addr, ...)
    skynet.send(addr, "lua", ...)
end

local gateway_addr = ".gateway"
local store_addr = ".store"
local appname
local devlist = {}
local r_table = {}
local internal_cmd = {
    route_add = true,
    route_del = true,
    data = true,
    payload = true,
    post = true,
    conf = true,
    exit = true
}

local api = {
    internalappid = "internal",
    sysappid = "sys",
    wsappid = "ws",
    mqttappid = "mqtt",
    hostappid = "host",
    frpappid = "frp",
    vpnappid = "vpn",
    infokey = "edgeinfo",
    iotedgedev = "iotedge",
    gateway_addr = gateway_addr,
    store_addr = store_addr,
    post_delay = 500, -- 5 seconds
    batch_max = 200,
    ttl_max = 60 -- day
}

local function dev_name(name, app)
    return name.."@"..app
end

local function pack_data(data)
    local p = {
        ts = skynet.time()*1000,
        values = data
    }
    return {p}
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

local function direct_post(t, dev, data)
    local d = dev_name(dev, appname)
    for _, r in pairs(r_table) do
        for l, _ in pairs(r.lasthop) do
            send(l, "post", t, d, data)
        end
    end
end

function api.datetime(time)
    if time then
        return os.date("%Y-%m-%d %H:%M:%S", time)
    else
        return os.date("%Y-%m-%d %H:%M:%S", math.floor(skynet.time()))
    end
end

function api.reg_cmd(name, desc, internal)
    if type(name) ~= "string" or
        (type(desc) ~= "string" and type(desc) ~= "boolean") or
        internal_cmd[name] or
        (not internal and type(_ENV[name]) ~= "function") then
        return
    end
    send(gateway_addr, "reg_cmd", name, desc)
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
            direct_post("online", name)

            if math.tointeger(ttl) and ttl>0 then
                if ttl > api.ttl_max then
                    ttl = api.ttl_max
                end
                send(store_addr, "dev_online", dev, ttl)
            end
        end
    end
end

function api.unreg_dev(name)
    if name == true then
        send(gateway_addr, "unreg_dev", name)
        for n, _ in pairs(devlist) do
            direct_post("offline", n)
        end
        appname = nil
        devlist = {}
    else
        if appname and devlist[name] then
            devlist[name] = nil
            local dev = dev_name(name, appname)
            send(gateway_addr, "unreg_dev", dev)
            direct_post("offline", name)
        end
    end
end

function api.post_gtelemetry(data)
    direct_post("gtelemetry", api.iotedgedev, pack_data(data))
end

function api.post_gattr(attr)
    direct_post("gattributes", api.iotedgedev, attr)
end

function api.post_attr(dev, attr)
    if appname and devlist[dev] and
        type(attr) == "table" and next(attr) then
        direct_post("attributes", dev, attr)
    end
end

function api.post_cov(dev, data)
    if appname and devlist[dev] and
        type(data) == "table" and next(data) then
        data = filter_cov(dev, data)
        if next(data) then
            direct_post("teleindication", dev, pack_data(data))
        end
    end
end

function api.post_data(dev, data)
    if appname and devlist[dev] and
        type(data) == "table" and next(data) then
        local p = pack_data(data)
        local b = devlist[dev].buffer
        table.move(p, 1, #p, #b+1, b)
        if #b >= devlist[dev].size then
            local d = dev_name(dev, appname)
            for _, r in pairs(r_table) do
                for n, _ in pairs(r.nexthop) do
                    send(n, "data", d, b)
                end
            end
            devlist[dev].buffer = {}
        end
    end
end

function api.route_data(dev, data)
    local s = tonumber(dev:match("_(%d+)$"))
    if s and r_table[s] then
        for n, _ in pairs(r_table[s].nexthop) do
            send(n, "data", dev, data)
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

function api.ts_value(data)
    return data.ts
end

function api.data_value(data)
    return data.values
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

function api.app_init(name)
    api.reg_dev(name, true)
end

function api.mqtt_init()
    appname = "mqtt"
    api.enable_store()
end

function api.internal_init(cmd_desc)
    api.reg_dev(api.internalappid, true)
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v, true)
    end
end

function api.sys_init(cmd_desc)
    api.reg_dev(api.sysappid, true)
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v, true)
    end
end

function api.external_request(...)
    return call(gateway_addr, ...)
end

function api.sys_request(...)
    return call(gateway_addr, api.sysappid, ...)
end

function api.internal_request(...)
    return call(gateway_addr, api.internalappid, ...)
end

function api.route_add(source, target, last)
    if not r_table[source] then
        r_table[source] = {
            lasthop = {},
            nexthop = {}
        }
    end
    local r = r_table[source]
    if last then
        local l = r.lasthop
        l[last] = l[last] and l[last] + 1 or 1
    end
    local n = r.nexthop
    n[target] = n[target] and n[target] + 1 or 1
end

function api.route_del(source, target, last)
    local r = r_table[source]
    if r then
        if last then
            local l = r.lasthop
            l[last] = l[last]==1 and nil or l[last]-1
        end
        local n = r.nexthop
        n[target] = n[target]==1 and nil or n[target]-1
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
