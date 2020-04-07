local skynet = require "skynet"

local LOG_LEVEL = {
    DEBUG   = 1,
    INFO    = 2,
    WARN    = 3,
    ERROR   = 4,
    FATAL   = 5
}

local LOG_LEVEL_DESC = {
    [1] = "DEBUG",
    [2] = "INFO",
    [3] = "WARN",
    [4] = "ERROR",
    [5] = "FATAL",
}

local OUT_PUT_LEVEL = LOG_LEVEL.ERROR
local OUT_PUT_LEVEL_STRING = skynet.getenv("loglevel")
for k, v in pairs(LOG_LEVEL_DESC) do
    if OUT_PUT_LEVEL_STRING == v then
        OUT_PUT_LEVEL = k
    end
end

local function send_log(level, ...)
    if level < OUT_PUT_LEVEL then
        return
    end
    local str
    str = table.concat({...}, ' ')
    local info = debug.getinfo(3)
    if info then
        str = string.format("[%s:%d] %s", info.short_src, info.currentline, str)
    end
    skynet.send(".logger", "lua", "logging", LOG_LEVEL_DESC[level], str)
end

local log = {}
function log.debug(...)
    send_log(LOG_LEVEL.DEBUG, ...)
end

function log.info(...)
    send_log(LOG_LEVEL.INFO, ...)
end

function log.warn(...)
    send_log(LOG_LEVEL.WARN, ...)
end

function log.error(...)
    send_log(LOG_LEVEL.ERROR, ...)
end

function log.fatal(...)
    send_log(LOG_LEVEL.FATAL, ...)
end

return setmetatable({}, {
  __index = log,
  __newindex = function(t, k, v)
                 error("Attempt to modify read-only table")
               end,
  __metatable = false
})
