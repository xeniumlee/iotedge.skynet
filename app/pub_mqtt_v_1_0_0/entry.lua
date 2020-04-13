local skynet = require "skynet"
local api = require "api"
local log = require "log"
local seri = require "seri"
local mqtt = require "mqtt"
local text = require("text").mqtt

local client
local running = true
local subsribe_ack_err_code = 128
local log_prefix = ""
local keepalive_timeout = 6000
local reconnect_timeout = 200
local pub_retry_count
local pub_retry_timeout = 2000

local telemetry_topic = ""
local telemetry_qos = 1
local telemetry_pack

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
                local data = seri.pack(msg)
                api.store(dev, data)
            else
                log.error(log_prefix, text.pub_fail, msg.topic)
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
    log.error(log_prefix, text.connect_fail)
    cli:disconnect()
end

local function handle_error(err)
    log.error(log_prefix, text.error, err)
end

local function handle_close(conn)
    api.offline()
    log.error(log_prefix, text.close, conn.close_reason)
end

local function handle_connect(connack, cli)
    if connack.rc ~= 0 then
        return
    end
    log.error(log_prefix, text.connect_suc)

    api.online()
    skynet.fork(ping, cli)
end

local function init_seri(topic)
    if topic:match("^.+/zip$") then
        return seri.zpack
    else
        return seri.pack
    end
end

local function do_publish(dev, data)
    if type(dev) ~= "string" or type(data) ~= "table" then
        log.error(log_prefix, text.invalid_post)
        return
    end
    local payload = telemetry_pack({ [dev] = data })
    if not payload then
        log.error(log_prefix, text.invalid_post)
        return
    end
    local msg = {}
    msg.topic = telemetry_topic
    msg.qos = telemetry_qos
    msg.payload = payload
    ensure_publish(client, msg)
end

local post_map = {
    teleindication = do_publish,
    attributes = do_publish
}

function on_conf(conf)
    math.randomseed(skynet.time())
    log_prefix = "MQTT client "..conf.id.."("..conf.uri..")"
    keepalive_timeout = conf.keep_alive*100
    seri.init(conf.seri)
    init_pub_retry_count(keepalive_timeout, conf.ping_limit)

    api.enable_store()
    telemetry_topic = conf.topic.telemetry.txt
    telemetry_qos = conf.topic.telemetry.qos
    telemetry_pack = init_seri(telemetry_topic)

    client = mqtt.client {
        uri = conf.uri,
        id = conf.id,
        username = conf.username,
        password = conf.password,
        clean = conf.clean,
        secure = conf.secure,
        keep_alive = conf.keep_alive,
        version = conf.version == "v3.1.1" and mqtt.v311 or mqtt.v50,
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

function on_post(t, dev, data)
    local f = post_map[t]
    if f then
        f(dev, data)
    else
        log.error(log_prefix, text.invalid_post)
    end
end

function on_payload(dev, data)
    local msg = seri.unpack(data)
    ensure_publish(client, msg, dev)
end

function on_data(dev, data)
    do_publish(dev, data)
end

function on_exit()
    running = false
    client:close_connection(text.close)
end
