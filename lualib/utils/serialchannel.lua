local skynet = require "skynet"
local serial = require "serial"

local function close_port(self)
    self.__port:close()
    self.__opened = false
    skynet.error("serial port closed:", self.__conf.device, self.__conf.mode)
end

local function open_port(self)
    if not self.__opened then
        local ok, ret = self.__port:open(self.__conf)
        if ok then
            skynet.error("serial port opened:", self.__conf.device, self.__conf.mode)
            self.__opened = true
        else
            skynet.error("serial port open failed:", self.__conf.device, self.__conf.mode)
            error(ret)
        end
    end
end

local channel = {}
function channel:request(request, response)
    open_port(self)
    local ok, err = self.__port:write(request)
    if ok then
        local data
        ok, err, data = pcall(response, self.__port_wrapper)
        if ok then
            if err then
                return data
            else
                close_port(self)
                error(data)
            end
        else
            close_port(self)
            error(err)
        end
    else
        close_port(self)
        error(err)
    end
end

function channel:close()
    if self.__opened then
        close_port(self)
    end
end

local channel_meta = {
    __index = channel,
    __gc = channel.close
}

local serial_channel = {}
local p_map = {
    none = 0,
    odd = 1,
    even = 2
}
function serial_channel.channel(conf)
    local port
    if conf.mode == "rs485" then
        port = serial.rs485.new()
    else
        port = serial.rs232.new()
    end
    conf.parity = p_map[conf.parity]
    local port_wrapper = {}
    function port_wrapper:read(len)
        local ok, ret = port:read(len)
        if ok then
            return ret
        else
            error(ret)
        end
    end
    local c = {
        __port = port,
        __port_wrapper = port_wrapper,
        __conf = conf,
        __opened = false
    }
    return setmetatable(c, channel_meta)
end

return serial_channel
