conf = {
    id = '',
    uri = '',
    username = '',
    password = '',
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
            txt = 'v1/gatewayhub/telemetry/zip'
        },
        teleindication = {
            qos = 1,
            txt = 'v1/gatewayhub/teleindication'
        },
        attributes = {
            qos = 1,
            txt = 'v1/gatewayhub/attributes/zip'
        },
        gattributes = {
            qos = 1,
            txt = 'v1/devicehub/attributes'
        },
        gtelemetry = {
            qos = 1,
            txt = 'v1/devicehub/telemetry/zip'
        },
        greq = {
            qos = 1,
            txt = 'v1/devicehub/rpc/request/+'
        },
        gresp = {
            qos = 1,
            txt = 'v1/devicehub/rpc/response'
        }
    },
    version = 'v3.1.1',
    clean = true,
    secure = true,
    keep_alive = 60,
    ping_limit = 3,
    seri = 'json',
    cocurrency = 5
}
