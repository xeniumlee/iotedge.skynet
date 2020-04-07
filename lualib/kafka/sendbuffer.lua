-- Copyright (C) Dejiang Zhu(doujiang24)
local setmetatable = setmetatable
local pairs = pairs
local next = next

local MAX_REUSE = 10000

local _M = {}
local sb = {}
local mt = { __index = sb }

function _M.new(batch_num, batch_size)
    return setmetatable({
        topics = {},
        queue_num = 0,
        batch_num = batch_num * 2,
        batch_size = batch_size,
    }, mt)
end

function sb:add(topic, partition_id, key, msg)
    local topics = self.topics
    if not topics[topic] then
        topics[topic] = {}
    end
    if not topics[topic][partition_id] then
        topics[topic][partition_id] = {
            queue = {},
            index = 0,
            used = 0,
            size = 0,
        }
    end

    local buffer = topics[topic][partition_id]
    local index = buffer.index
    local queue = buffer.queue

    if index == 0 then
        self.queue_num = self.queue_num + 1
    end

    queue[index + 1] = key
    queue[index + 2] = msg
    buffer.index = index + 2
    buffer.size = buffer.size + #msg + (key and #key or 0)

    if (buffer.size >= self.batch_size) or (buffer.index >= self.batch_num) then
        return true
    end
end

function sb:clear(topic, partition_id)
    local buffer = self.topics[topic][partition_id]
    buffer.index = 0
    buffer.size = 0
    buffer.used = buffer.used + 1
    if buffer.used >= MAX_REUSE then
        buffer.queue = {}
        buffer.used = 0
    end

    if self.queue_num ~= 0 then
        self.queue_num = self.queue_num - 1
    end
end

function sb:done()
    return self.queue_num == 0
end

function sb:loop()
    local topics, t, p = self.topics
    return function ()
        if t then
            for partition_id, queue in next, topics[t], p do
                p = partition_id
                if queue.index > 0 then
                    return t, partition_id, queue
                end
            end
        end
        for topic, partitions in next, topics, t do
            t = topic
            p = nil
            for partition_id, queue in next, partitions, p do
                p = partition_id
                if queue.index > 0 then
                    return topic, partition_id, queue
                end
            end
        end
    end
end

function sb:aggregator(client)
    local num = 0
    local sendbroker = {}
    local brokers = {}

    for topic, partition_id, queue in self:loop() do
        local bk = client:choose_broker(topic, partition_id)
        if bk then
            if not brokers[bk] then
                brokers[bk] = {
                    topics = {},
                    topic_num = 0,
                    size = 0,
                }
            end

            local broker = brokers[bk]
            if not broker.topics[topic] then
                brokers[bk].topics[topic] = {
                    partitions = {},
                    partition_num = 0,
                }
                broker.topic_num = broker.topic_num + 1
            end

            local broker_topic = broker.topics[topic]
            broker_topic.partitions[partition_id] = queue
            broker_topic.partition_num = broker_topic.partition_num + 1
            broker.size = broker.size + queue.size

            if broker.size >= self.batch_size then
                sendbroker[num + 1] = bk
                sendbroker[num + 2] = broker
                num = num + 2
                brokers[bk] = nil
            end
        end
    end

    for bk, broker in pairs(brokers) do
        sendbroker[num + 1] = bk
        sendbroker[num + 2] = broker
        num = num + 2
    end

    return num, sendbroker
end

return _M
