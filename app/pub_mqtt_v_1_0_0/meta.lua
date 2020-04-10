conf = {
    id = 'MQTT_ID',
    uri = '',
    username = '',
    password = '',
    topic = {
        telemetry = {
            qos = 1,
            txt = 'telemetry/zip',
        },
    },
    version = 'v3.1.1',
    clean = true,
    secure = true,
    keep_alive = 60,
    ping_limit = 3,
    seri = 'json'
}
