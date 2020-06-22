local skynet = require "skynet"
local snap7 = require "snap7"

local function do_connect(self)
    if not self.__connecting then
        self.__connecting = true
        os.execute(self.__arping)
        local ok, err = self.__client:connect()
        if ok then
            skynet.error("s7: connected to", self.__host, self.__rack, self.__slot)
        else
            skynet.error("s7: connect failed", self.__host, self.__rack, self.__slot, err)
            skynet.sleep(1000)
        end
        self.__connecting = false
        return ok
    else
        return true
    end
end

local channel = {}
function channel:info()
    return self.__client:info()
end

function channel:read(dataitem)
    local ok, err = self.__client:read(dataitem)
    if not ok then
        skynet.timeout(0, function() do_connect(self) end)
    end
    return ok, err
end

function channel:write(dataitem)
    local ok, err = self.__client:write(dataitem)
    if not ok then
        skynet.timeout(0, function() do_connect(self) end)
    end
    return ok, err
end

function channel:connect()
    return do_connect(self)
end

function channel:close()
    local ok, err = self.__client:disconnect()
    if ok then
        skynet.error("s7: disconnected", self.__host, self.__rack, self.__slot)
    else
        skynet.error("s7: disconnect failed", self.__host, self.__rack, self.__slot, err)
    end
    return ok
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
    local cli = assert(snap7.client.new())
    cli:connectto(desc.host, rack, slot)

    local self = setmetatable({
        __client = cli,
        __host = desc.host,
        __rack = rack,
        __slot = slot,
        __arping = "arping -c 3 -q "..desc.host,
        __connecting = false,
    }, client_meta)
    skynet.timeout(0, function() do_connect(self) end)

    return self
end

return client
