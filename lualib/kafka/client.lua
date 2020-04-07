-- Copyright (C) Dejiang Zhu(doujiang24)
local broker = require "kafka.broker"
local request = require "kafka.request"
local skynet = require "skynet"
local log = require "log"

local setmetatable = setmetatable
local pairs = pairs

local API_VERSION_V0 = 0
local API_VERSION_V1 = 1
local API_VERSION_V2 = 2

local _M = {}
local client = { _VERSION = "0.07" }
local mt = { __index = client }

local function metadata_encode(id, client_id, api_version, topics, num)
    local req = request.new(request.MetadataRequest, id, client_id, api_version)
    req:int32(num)
    for i = 1, num do
        req:string(topics[i])
    end
    return req
end

local function metadata_decode(resp)
    local bk_num = resp:int32()
    local brokers = {}

    for i = 1, bk_num do
        local nodeid = resp:int32()
        local host = resp:string()
        local port = resp:int32()
        brokers[nodeid] = broker.new(host, port)
    end

    local topic_num = resp:int32()
    local topics = {}

    for i = 1, topic_num do
        local tp_errcode = resp:int16()
        local topic = resp:string()

        local partition_num = resp:int32()
        local topic_info = {}

        topic_info.errcode = tp_errcode
        topic_info.num = partition_num

        for j = 1, partition_num do
            local partition_info = {}

            partition_info.errcode = resp:int16()
            partition_info.id = resp:int32()
            partition_info.leader = resp:int32()

            local repl_num = resp:int32()
            local replicas = {}
            for m = 1, repl_num do
                replicas[m] = resp:int32()
            end
            partition_info.replicas = replicas

            local isr_num = resp:int32()
            local isr = {}
            for m = 1, isr_num do
                isr[m] = resp:int32()
            end
            partition_info.isr = isr

            topic_info[partition_info.id] = partition_info
        end
        topics[topic] = topic_info
    end

    return brokers, topics
end

local function _fetch_metadata(self, new_topic)
    local topics, num = {}, 0
    for tp, _ in pairs(self.topic_partitions) do
        num = num + 1
        topics[num] = tp
    end

    if new_topic and not self.topic_partitions[new_topic] then
        num = num + 1
        topics[num] = new_topic
    end

    if num == 0 then
        return
    end

    local id = self:gen_id()
    local req = metadata_encode(id, self.client_id, self.api_version, topics, num)

    local bk_list = next(self.brokers) and self.brokers or self.init_brokers
    for _, bk in pairs(bk_list) do
        local resp, err = bk:send_receive(req, id)
        if not resp then
            log.error("fetch metadata failed:", tostring(err), tostring(bk))
        else
            local brokers, topic_partitions = metadata_decode(resp)
            self.brokers, self.topic_partitions = brokers, topic_partitions
            self.init_brokers = nil
            return
        end
    end
end

local function _metadata_cache(self, topic)
    local partitions = self.topic_partitions[topic]
    if partitions and partitions.num and partitions.num > 0 then
        return self.brokers, partitions
    else
        return
    end
end

function _M.new(broker_list, client_config)
    local opts = client_config or {}
    local bk_list = {}
    for _, bk in pairs(broker_list) do
        table.insert(bk_list, broker.new(bk.host, bk.port))
    end
    return setmetatable({
        correlation_id = 1,
        init_brokers = bk_list,
        topic_partitions = {},
        brokers = {},
        client_id = opts.id or skynet.self().."@skynet",
        -- hard-coded for metadata
        api_version = API_VERSION_V0
    }, mt)
end

function client:gen_id()
    local id = (self.correlation_id + 1) & 0xffffffff
    self.correlation_id = id
    return id
end

function client:refresh()
    _fetch_metadata(self)
end

function client:fetch_metadata(topic)
    local brokers, partitions = _metadata_cache(self, topic)
    if brokers then
        return brokers, partitions
    end
    _fetch_metadata(self, topic)
    return _metadata_cache(self, topic)
end

function client:choose_broker(topic, partition_id)
    local brokers, partitions = self:fetch_metadata(topic)
    if not brokers then
        return
    end
    local partition = partitions[partition_id]
    if not partition then
        return
    end
    local bk = brokers[partition.leader]
    if not bk then
        return
    end
    return bk
end

return _M
