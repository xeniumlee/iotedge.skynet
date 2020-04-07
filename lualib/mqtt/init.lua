--- MQTT module
-- @module mqtt

--[[
MQTT protocol DOC: http://docs.oasis-open.org/mqtt/mqtt/v3.1.1/errata01/os/mqtt-v3.1.1-errata01-os-complete.html

CONVENTIONS:

    * errors:
        * passing invalid arguments to function in this library will raise exception
        * all other errors will be returned in format: false, "error-text"
            * you can wrap function call into standard lua assert() to raise exception

]]

--- Module table
-- @field v311 MQTT v3.1.1 protocol version constant
-- @field v50  MQTT v5.0   protocol version constant
-- @field _VERSION luamqtt version string
-- @table mqtt
local mqtt = {
    -- supported MQTT protocol versions
    v311 = 4,       -- supported protocol version, MQTT v3.1.1
    v50 = 5,        -- supported protocol version, MQTT v5.0

    -- mqtt library version
    _VERSION = "3.1.0"
}

-- load required stuff
local client = require("mqtt.client")

--- Create new MQTT client instance
-- @param ... Same as for mqtt.client.create(...)
-- @see mqtt.client.client_mt:__init
function mqtt.client(...)
    return client.create(...)
end

-- export module table
return setmetatable({}, {
  __index = mqtt,
  __newindex = function(t, k, v)
                 error("Attempt to modify read-only table")
               end,
  __metatable = false
})
