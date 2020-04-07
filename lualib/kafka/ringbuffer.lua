-- Copyright (C) Dejiang Zhu(doujiang24)
local setmetatable = setmetatable

local _M = {}
local rb = {}
local mt = { __index = rb }

local s = 3
function _M.new(batch_num, max_num)
    return setmetatable({
        queue = {},
        batch_num = batch_num*s,
        max_num = max_num*s,
        head = 1,
        tail = 1,
        num = 0,
    }, mt)
end

function rb:add(topic, key, message)
    local num = self.num
    local max_num = self.max_num
    if num == max_num then
        return
    end

    local queue = self.queue
    local tail = self.tail
    queue[tail] = topic
    queue[tail+1] = key
    queue[tail+2] = message
    self.num = num + s
    self.tail = (tail+s) % max_num
    return true
end

function rb:pop()
    local num = self.num
    if num == 0 then
        return
    end

    local queue = self.queue
    local head = self.head
    local max_num = self.max_num
    self.num = num - s
    self.head = (head+s) % max_num
    return queue[head], queue[head+1], queue[head+2]
end

function rb:need_send()
    return self.num >= self.batch_num
end

function rb:empty()
    return self.num == 0
end

return _M
