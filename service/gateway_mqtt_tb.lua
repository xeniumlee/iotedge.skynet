local skynet = require "skynet"
local api = require "api"
local log = require "log"
local seri = require "seri"
local mqtt = require "mqtt"
local text = require("text").mqtt

local client
local running = true

local subsribe_ack_err_code = 128

local sys_uri = ""
local sys_name = ""
local log_prefix = ""
local cocurrency = 5
local keepalive_timeout = 6000

local telemetry_topic = ""
local telemetry_qos = 1
local teleindication_topic = ""
local teleindication_qos = 1
local rpc_topic = ""
local rpc_qos = 1
local attributes_topic = ""
local attributes_qos = 1
local connect_topic = ""
local connect_qos = 1
local disconnect_topic = ""
local disconnect_qos = 1
local gconfig_topic = ""
local gconfig_qos = 1
local gtelemetry_topic = ""
local gtelemetry_qos = 1

local function init_topics(topic)
    telemetry_topic = topic.telemetry.txt
    telemetry_qos = topic.telemetry.qos
    teleindication_topic = topic.teleindication.txt
    teleindication_qos = topic.teleindication.qos
    rpc_topic = topic.rpc.txt
    rpc_qos = topic.rpc.qos
    attributes_topic = topic.attributes.txt
    attributes_qos = topic.attributes.qos
    connect_topic = topic.connect.txt
    connect_qos = topic.connect.qos
    disconnect_topic = topic.disconnect.txt
    disconnect_qos = topic.disconnect.qos
    gconfig_topic = topic.gconfig.txt
    gconfig_qos = topic.gconfig.qos
    gtelemetry_topic = topic.gtelemetry.txt
    gtelemetry_qos = topic.gtelemetry.qos
end

local reconnect_timeout = 200
local sub_retry_count = 3
local sub_retry_timeout = 200

local pub_retry_count
local pub_retry_timeout = 2000

local function init_pub_retry_count(keepalive, pinglimit)
    -- retry till connection issue detected
    local k = keepalive or 6000
    local p = pinglimit or 3
    pub_retry_count = k * (p + 1) // pub_retry_timeout + 1
end

local function ensure_publish(cli, msg, dev)
    local done = false
    local count = 0

    local function puback()
        done = true
        log.debug(log_prefix, text.pub_suc, msg.topic)
    end
    while running and not done do
        if count < pub_retry_count then
            if cli.connection then
                cli:publish {
                    topic = msg.topic,
                    qos = msg.qos,
                    payload = msg.payload,
                    callback = puback,
                    dup = (count ~= 0),
                    retain = false
                }
            end
            count = count + 1
            skynet.sleep(pub_retry_timeout)
        else
            -- only store due to connection issue
            if not cli.connection and dev then
                api.store(dev, msg.payload)
            else
                log.error(log_prefix, text.pub_fail, msg.topic)
            end
        end
    end
end

local function ensure_subscribe(cli, topic, qos)
    local done = false
    local count = 0

    local function suback(ack)
        if ack.rc[1] ~= subsribe_ack_err_code then
            -- Strictly rc[1] >= qos
            done = true
            log.error(log_prefix, text.sub_suc, topic)
        else
            log.error(log_prefix, text.sub_fail, topic)
        end
    end
    while running and not done do
        if count < sub_retry_count then
            if cli.connection then
                cli:subscribe {
                    topic = topic,
                    qos = qos,
                    callback = suback
                }
            end
            count = count + 1
            skynet.sleep(sub_retry_timeout)
        else
            log.error(log_prefix, text.sub_fail, topic)
        end
    end
end

local function ping(cli)
    local check_timeout = keepalive_timeout+200
    while cli.connection do
        if skynet.now()-cli.comm_time >= keepalive_timeout then
            cli:send_pingreq()
        end
        skynet.sleep(check_timeout)
    end
end

local function handle_pinglimit(count, cli)
    log.error(log_prefix, text.connect_fail)
    cli:disconnect()
end

local function handle_connect(connack, cli)
    if connack.rc ~= 0 then
        return
    end
    log.error(log_prefix, text.connect_suc)

    api.online()
    api.sys_request("mqttapp", { uri = sys_uri, id = sys_name })
    skynet.fork(ensure_subscribe, cli, rpc_topic, rpc_qos)
    skynet.fork(ensure_subscribe, cli, gconfig_topic, gconfig_qos)
    skynet.fork(ping, cli)
end

local function handle_error(err)
    log.error(log_prefix, text.error, err)
end

local function handle_close(conn)
    api.offline()
    log.error(log_prefix, text.close, conn.close_reason)
end

--[[
msg = {
    type=ptype,
    dup=dup,
    qos=qos,
    retain=retain,
    packet_id=packet_id,
    topic=topic,
    payload=payload
    }
payload = {"device":"Device A",
           "data":{
             "id":$request_id,
             "method":"toggle_gpio",
             "params":{"pin":1}
             }}
--]]
local function decode_rpc(msg)
    local request = seri.unpack(msg.payload)
    if type(request) ~= "table" then
        log.error(log_prefix, text.unpack_fail)
        return false
    end
    if type(request.device) ~= "string" then
        log.error(log_prefix, text.unknown_dev)
        return false
    end
    if type(request.data) == "table" then
        local data = request.data
        if data.id and data.method and data.params then
            return  request.device, data.method, data.params, data.id
        else
            log.error(log_prefix, text.invalid_req)
            return false
        end
    else
        log.error(log_prefix, text.invalid_req)
        return false
    end
end

--[[
payload = {"device":"Device A",
           "id": $request_id,
           "data":{"success": true}
           }
--]]
local function respond_rpc(cli, dev, ret, session)
    local response = {
        device = dev,
        id = session,
        data = ret
    }
    local payload = seri.pack(response)
    if not payload then
        log.error(log_prefix, text.pack_fail)
        return
    end
    local msg = {}
    msg.topic = rpc_topic
    msg.qos = rpc_qos
    msg.payload = payload
    ensure_publish(cli, msg)
end

local forked = 0
local function busy_rpc()
    if forked < cocurrency then
        forked = forked + 1
        return false
    else
        return true
    end
end
local function done_rpc()
    forked = forked - 1
end

local function handle_rpc(msg, cli)
    if busy_rpc() then
        log.error(log_prefix, text.busy)
    else
        skynet.fork(function()
            local dev, cmd, arg, session = decode_rpc(msg)
            if dev then
                local ok, ret = api.external_request(dev, cmd, arg)
                if ret then
                    respond_rpc(cli, dev, { ok, ret }, session)
                else
                    respond_rpc(cli, dev, ok, session)
                end
            end
            done_rpc()
        end)
    end
end

local function list_to_kv(list, key)
    for i, item in pairs(list) do
        list[i] = { [item[key]] = item }
    end
end

local function decode_config(msg)
    local conf = seri.unpack(msg.payload)
    if type(conf) ~= "table" then
        log.error(log_prefix, text.unpack_fail)
        return false
    end
end

local function handle_config(msg, cli)
    skynet.fork(function()
        local conf = decode_config(msg)
        if conf then
            local ok, err = api.sys_request("configure", conf)
            if ok then
                log.error(log_prefix, text.configure_suc)
            else
                log.error(log_prefix, text.configure_fail, err)
            end
        end
    end)
end

local handler_map = {
    [rpc_topic] = handle_rpc,
    [gconfig_topic] = handle_config
}

local function handle_request(msg, cli)
    cli:acknowledge(msg)
    if msg.dup then
        log.debug(log_prefix, text.dup_req, msg.topic)
    end
    local h = handler_map(msg.topic)
    if h then
        h(msg, cli)
    else
        log.error(log_prefix, text.invalid_req, msg.topic)
    end
end

local command = {}

function command.stop()
    running = false
    local ok, err = client:disconnect()
    if ok then
        log.error(log_prefix, text.stop_suc)
    else
        log.error(log_prefix, text.stop_fail, err)
    end
end

function command.payload(dev, payload)
    local msg = {}
    msg.topic = telemetry_topic
    msg.qos = telemetry_qos
    msg.payload = payload
    ensure_publish(client, msg, dev)
end

function command.data(dev, data)
    if type(dev) ~= "string" or type(data) ~= "table" then
        log.error(log_prefix, text.invalid_post, "telemetry")
        return
    end
    local payload = seri.pack({[dev] = data})
    if not payload then
        log.error(log_prefix, text.invalid_post, "telemetry")
        return
    end
    command.payload(dev, payload)
end

local post_map = {
    online = function(dev)
        if type(dev) ~= "string" then
            log.error(log_prefix, text.invalid_post, "online")
            return
        end
        local payload = seri.pack({device = dev})
        if not payload then
            log.error(log_prefix, text.invalid_post, "online")
            return
        end
        local msg = {}
        msg.topic = connect_topic
        msg.qos = connect_qos
        msg.payload = payload
        ensure_publish(client, msg)
    end,
    offline = function(dev)
        if type(dev) ~= "string" then
            log.error(log_prefix, text.invalid_post, "offline")
            return
        end
        local payload = seri.pack({device = dev})
        if not payload then
            log.error(log_prefix, text.invalid_post, "offline")
            return
        end
        local msg = {}
        msg.topic = disconnect_topic
        msg.qos = disconnect_qos
        msg.payload = payload
        ensure_publish(client, msg)
    end,
    attributes = function(dev, attr)
        if type(dev) ~= "string" or type(attr) ~= "table" then
            log.error(log_prefix, text.invalid_post, "attributes")
            return
        end
        local payload = seri.pack({[dev] = attr})
        if not payload then
            log.error(log_prefix, text.invalid_post, "attributes")
            return
        end
        local msg = {}
        msg.topic = attributes_topic
        msg.qos = attributes_qos
        msg.payload = payload
        ensure_publish(client, msg)
    end
}

function command.post(k, ...)
    local f = post_map[k]
    if f then
        f(...)
    else
        log.error(log_prefix, text.invalid_post)
    end
end

local function init()
    local conf = api.internal_request("conf_get", "gateway_mqtt")
    if not conf then
        log.error(text.no_conf)
    else
        api.mqtt_init()
        math.randomseed(skynet.time())

        sys_uri = conf.uri
        sys_name = conf.username
        log_prefix = "MQTT client "..conf.id.."("..conf.uri..")"
        cocurrency = conf.cocurrency
        keepalive_timeout = conf.keep_alive*100

        init_topics(conf.topic)
        seri.init(conf.seri)
        init_pub_retry_count(keepalive_timeout, conf.ping_limit)

        local version_map = {
            ["v3.1.1"] = mqtt.v311,
            ["v5.0"] = mqtt.v50
        }
        client = mqtt.client {
            uri = conf.uri,
            id = conf.id,
            username = conf.username,
            password = conf.password,
            clean = conf.clean,
            secure = conf.secure,
            keep_alive = conf.keep_alive,
            version = version_map[conf.version],
            ping_limit = conf.ping_limit
        }
        local mqtt_callback = {
            connect = handle_connect,
            message = handle_request,
            error = handle_error,
            close = handle_close,
            pinglimit = handle_pinglimit
        }
        client:on(mqtt_callback)

        skynet.fork(function()
            while running do
                if client.connection then
                    client:iteration()
                else
                    skynet.sleep(reconnect_timeout)
                    client:start_connecting()
                end
            end
        end)

        skynet.dispatch("lua", function(_, _, cmd, ...)
            local f = command[cmd]
            if f then
                f(...)
            end
        end)
    end
end

skynet.start(init)
