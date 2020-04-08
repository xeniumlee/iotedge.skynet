sys = {
    id = 'SYS_ID',
    version = 'SYS_VERSION',
    platform = 'SYS_PLAT',
    host = 'SYS_HOST',
    cluster = 30002
}
auth = {
    username = '9c1d55b6274a7456540ec64bb39cd604',
    password = 'c41441edb82f7d3461925a3385c98501',
}
gateway = {
    flowcontrol = false,
    audit = false
}
gateway_mqtt = {
    tpl = 'gateway_mqtt_tb',
    id = 'MQTT_ID',
    uri = 'MQTT_URI',
    username = 'MQTT_USERNAME',
    password = 'MQTT_PASSWORD',
    topic = {
        connect = {
            qos = 1,
            txt = 'v1/gatewayhub/connect'
        },
        disconnect = {
            qos = 1,
            txt = 'v1/gatewayhub/disconnect'
        },
        rpc = {
            qos = 1,
            txt = 'v1/gatewayhub/rpc'
        },
        telemetry = {
            qos = 1,
            txt = 'v1/gatewayhub/telemetry'
        },
        teleindication = {
            qos = 1,
            txt = 'v1/gatewayhub/teleindication'
        },
        attributes = {
            qos = 1,
            txt = 'v1/gatewayhub/attributes'
        },
        gattributes = {
            qos = 1,
            txt = 'v1/devicehub/attributes'
        },
        gtelemetry = {
            qos = 1,
            txt = 'v1/devicehub/telemetry'
        }
    },
    version = 'v3.1.1',
    clean = true,
    secure = false,
    keep_alive = 60,
    ping_limit = 3,
    seri = 'json',
    cocurrency = 5
}
