-- Copyright (C) Dejiang Zhu(doujiang24)
local request = require "kafka.request"
local client = require "kafka.client"
local Errors = require "kafka.errors"
local sendbuffer = require "kafka.sendbuffer"
local ringbuffer = require "kafka.ringbuffer"
local crc32 = require "utils.crc32"
local skynet = require "skynet"
local log = require "log"

local setmetatable = setmetatable
local pairs = pairs

local API_VERSION_V0 = 0
local API_VERSION_V1 = 1
local API_VERSION_V2 = 2

local _M = {}
local producer = { _VERSION = "0.07" }
local mt = { __index = producer }

local function produce_encode(self, correlation_id, topic_partitions)
    local req = request.new(request.ProduceRequest,
                            correlation_id, self.client.client_id, self.api_version)

    req:int16(self.required_acks)
    req:int32(self.request_timeout)
    req:int32(topic_partitions.topic_num)

    for topic, partitions in pairs(topic_partitions.topics) do
        req:string(topic)
        req:int32(partitions.partition_num)

        for partition_id, buffer in pairs(partitions.partitions) do
            req:int32(partition_id)

            -- MessageSetSize and MessageSet
            req:message_set(buffer.queue, buffer.index)
        end
    end

    return req
end

local function produce_decode(resp)
    local topic_num = resp:int32()
    local ret = {}
    local api_version = resp.api_version

    for i = 1, topic_num do
        local topic = resp:string()
        local partition_num = resp:int32()

        ret[topic] = {}

        -- ignore ThrottleTime
        for j = 1, partition_num do
            local partition = resp:int32()

            if api_version == API_VERSION_V0 or api_version == API_VERSION_V1 then
                ret[topic][partition] = {
                    errcode = resp:int16(),
                    offset = resp:int64(),
                }

            elseif api_version == API_VERSION_V2 then
                ret[topic][partition] = {
                    errcode = resp:int16(),
                    offset = resp:int64(),
                    timestamp = resp:int64(), -- If CreateTime is used, this field is always -1
                }
            end
        end
    end

    return ret
end

local function choose_partition(self, topic, key)
    local brokers, partitions = self.client:fetch_metadata(topic)
    -- partition_id is continuous and start from 0
    if brokers then
        local id = key and crc32(key) or math.random(0xffffffff)
        return id % partitions.num
    else
        return 0
    end
end

local function _send(self, bk, topic_partitions)
    local sb = self.sendbuffer
    local correlation_id = self.client:gen_id()
    local req = produce_encode(self, correlation_id, topic_partitions)
    local resp, err = bk:send_receive(req, correlation_id)
    if resp then
        local result = produce_decode(resp)
        for topic, partitions in pairs(result) do
            for partition_id, r in pairs(partitions) do
                local errcode = r.errcode
                if errcode == 0 then
                    sb:clear(topic, partition_id)
                else
                    err = Errors[errcode]
                    -- XX: only 3, 5, 6 can retry
                    if errcode == 3 or errcode == 5 or errcode == 6 then
                        log.error("send retry later:", err, "topic:", topic, "partition_id:", partition_id)
                    else
                        log.error("send err:", err, "topic:", topic, "partition_id:", partition_id)
                        sb:clear(topic, partition_id)
                    end
                end
            end
        end
    else
        log.error("send retry later:", tostring(err), tostring(bk))
    end
end

local function _batch_send(self)
    local sb = self.sendbuffer
    local cli = self.client

    for try = 1, self.max_retry do
        local send_num, sendbroker = sb:aggregator(cli)
        for i = 1, send_num, 2 do
            local bk, topic_partitions = sendbroker[i], sendbroker[i + 1]
            _send(self, bk, topic_partitions)
        end

        if sb:done() then
            return
        else
            if try ~= self.max_retry then
                cli:refresh()
                skynet.sleep(self.retry_backoff)
            end
        end
    end

    for topic, partition_id in sb:loop() do
        log.error("send err, topic:", topic, "partition_id:", partition_id)
        sb:clear(topic, partition_id)
    end
end

local function _flush(self)
    local rb = self.ringbuffer
    local sb = self.sendbuffer

    while true do
        if rb:empty() then
            self.flushing = false
            skynet.sleep(100)
        end
        self.flushing = true
        while true do
            local topic, key, msg = rb:pop()
            if not topic then
                break
            end

            local partition_id = choose_partition(self, topic, key)
            local overflow = sb:add(topic, partition_id, key, msg)
            if overflow then
                break
            end
        end
        _batch_send(self)
    end
end

function _M.new(broker_list, producer_config)
    local opts = producer_config or {}
    local p = setmetatable({
        client = client.new(broker_list, opts),
        request_timeout = 2000,
        required_acks = 1,
        api_version = opts.api_version or API_VERSION_V0,
        retry_backoff = 10,
        max_retry = 3,
        batch = opts.batch,
        flush_co = false,
        flushing = false,
        ringbuffer = ringbuffer.new(200, 50000),
        sendbuffer = sendbuffer.new(200, 1048576)
        -- batch_size should less than (MaxRequestSize / 2 - 10KiB)
        -- config in the kafka server, default 100M
    }, mt)
    p.flush_co = skynet.fork(_flush, p)
    return p
end

function producer:send(topic, key, message)
    local rb = self.ringbuffer
    local ok = rb:add(topic, key, message)
    if not ok then
        return false
    end
    if self.batch then
        if rb:need_send() then
            self:flush()
        end
    else
        self:flush()
    end
    return true
end

function producer:flush()
    if not self.flushing then
        skynet.wakeup(self.flush_co)
    end
end

return _M
