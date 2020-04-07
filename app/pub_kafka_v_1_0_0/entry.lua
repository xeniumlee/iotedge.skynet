local seri = require "seri"
local log = require "log"
local producer = require "kafka.producer"
local text = require("text").app

local p
local log_prefix = ""
local topic

function on_conf(conf)
    log_prefix = "Kafka client "..conf.producer.id.."("..conf.producer.topic..")"
    seri.init(conf.seri)
    topic = conf.producer.topic
    local ok, ret = pcall(producer.new, conf.broker, conf.producer)
    if ok then
        p = ret
        p.client:fetch_metadata(topic)
        return true
    else
        return false, ret
    end
end

function on_data(dev, data)
    if type(dev) ~= "string" or type(data) ~= "table" then
        log.error(log_prefix, text.invalid_arg)
        return
    end
    local payload = seri.pack({[dev] = data})
    if not payload then
        log.error(log_prefix, text.pack_fail)
        return
    end
    p:send(topic, nil, payload)
end
