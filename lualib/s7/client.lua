local skynet = require "skynet"
local snap7 = require "snap7"

local function try_connect(self, once)
    local t = 0
    while not self.__closed do
        local ok, err = self.__client:connect()
        if ok then
            skynet.error("s7: connected to", self.__host, self.__rack, self.__slot)
            return
        else
            skynet.error("s7: connect failed", self.__host, self.__rack, self.__slot, err)
            if once then
                return
            end
        end
        if t > 1000 then
            skynet.error("s7: try to reconnect", self.__host, self.__rack, self.__slot)
            skynet.sleep(t)
            t = 0
        else
            skynet.sleep(t)
        end
        t = t + 100
    end
end

local function check_connection(self)
    if self.__closed  then
        return false
    else
        return self.__client:connected()
    end
end

local function block_connect(self, once)
    if check_connection(self) then
        return true
    end

    if #self.__connecting > 0 then
        -- connecting in other coroutine
        local co = coroutine.running()
        table.insert(self.__connecting, co)
        skynet.wait(co)
    else
        self.__connecting[1] = true
        try_connect(self, once)
        self.__connecting[1] = nil
        for i=2, #self.__connecting do
            local co = self.__connecting[i]
            self.__connecting[i] = nil
            skynet.wakeup(co)
        end
    end

    return check_connection(self)
end

local socket_error = "PLC disconnected"

local channel = {}
function channel:info()
    if not block_connect(self, true) then
        return false, socket_error
    end
    return self.__client:info()
end

function channel:read(dataitem)
    -- validate dataitem
    if not block_connect(self, true) then
        return false, socket_error
    end
    return self.__client:read(dataitem)
end

function channel:write(dataitem)
    -- validate dataitem
    if not block_connect(self, true) then
        return false, socket_error
    end
    return self.__client:write(dataitem)
end

function channel:connect(once)
    self.__closed = false
    return block_connect(self, once)
end

function channel:close()
    if not self.__closed then
        self.__closed = true
        local ok, err = self.__client:disconnect()
        if ok then
            skynet.error("s7: disconnected", self.__host, self.__rack, self.__slot)
        else
            skynet.error("s7: disconnect failed", self.__host, self.__rack, self.__slot, err)
        end
    end
end

local client_meta = {
    __index = channel,
    __gc = channel.close
}

local client = {}
function client.new(desc)
    assert(desc.host)
    local rack = desc.rack or 0
    local slot = desc.slot or 0
    local pdusize = desc.pdusize or 480
    local cli = assert(snap7.client.new())
    cli:connectto(desc.host, rack, slot)
    cli:setpdusize(pdusize)

    return setmetatable({
        __client = cli,
        __host = desc.host,
        __rack = rack,
        __slot = slot,
        __connecting = {},
        __closed = false,
    }, client_meta)
end

return client
