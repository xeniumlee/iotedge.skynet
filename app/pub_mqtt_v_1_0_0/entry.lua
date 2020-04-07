local skynet = require "skynet"
local api = require "api"
local log = require "log"
local seri = require "seri"
local mqtt = require "mqtt"
local text = require("text").mqtt

local subsribe_ack_err_code = 128

local client
local running = true

local log_prefix = ""
local keepalive_timeout = 6000
local telemetry_topic = ""
local telemetry_qos = 1

local reconnect_timeout = 200
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
        log.debug(log_prefix, "published to", msg.topic, "QoS", msg.qos)
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
                log.error(log_prefix, "publish to", msg.topic, "failed")
            end
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
    log.error(log_prefix, text.conn_fail)
    cli:disconnect()
end

local function handle_connect(connack, cli)
    if connack.rc ~= 0 then
        return
    end
    log.error(log_prefix, "connected")

    api.online()
    skynet.fork(ping, cli)
end

local function handle_error(err)
    log.error(log_prefix, "err:", err)
end

local function handle_close(conn)
    api.offline()
    log.error(log_prefix, "closed:", conn.close_reason)
end

function on_conf(conf)
    math.randomseed(skynet.time())
    api.enable_store()

    log_prefix = "MQTT client "..conf.id.."("..conf.uri..")"
    keepalive_timeout = conf.keep_alive*100
    telemetry_topic = conf.topic.telemetry.txt
    telemetry_qos = conf.topic.telemetry.qos

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
    return true
end

local function publish_payload(dev, payload)
    local msg = {}
    msg.topic = telemetry_topic
    msg.qos = telemetry_qos
    msg.payload = payload
    ensure_publish(client, msg, dev)
end

function on_payload(dev, payload)
    publish_payload(dev, payload)
end

function on_data(dev, data)
    if type(dev) ~= "string" or type(data) ~= "table" then
        log.error(log_prefix, "telemetry publish failed")
        return
    end
    local payload = seri.pack({[dev] = data})
    if not payload then
        log.error(log_prefix, "telemetry publish failed", text.pack_fail)
        return
    end
    publish_payload(dev, payload)
end

function on_exit()
    running = false
    client:close_connection(text.client_closed)
end
