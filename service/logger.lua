local skynet = require "skynet"
local lfs = require "lfs"

local log_file
local count = 0
local max_count = 10000
local file_c = 0
local max_f = 10
local oldest_f = 0
local newest_f = 0
local log_path  = skynet.getenv("logpath")
local do_print = skynet.getenv("loglevel"):match("DEBUG")
local current_f = string.format("%s/%s.log", log_path, "latest")

local function file_path(i)
    return string.format("%s/%d.log", log_path, i)
end

local function file_index(file)
    local i = file:match("^(%d+).log$")
    return tonumber(i)
end

local function init()
    lfs.mkdir(log_path)
    local attr, i, t, oldest, newest
    for f in lfs.dir(log_path) do
        i = file_index(f)
        if i then
            attr = lfs.attributes(log_path.."/"..f)
            if attr and attr.access then
                file_c = file_c + 1
                t = attr.access
                if oldest then
                    if t < oldest then
                        oldest = t
                        oldest_f = i
                    end
                else
                    oldest = t
                    oldest_f = i
                end
                if newest then
                    if t > newest then
                        newest = t
                        newest_f = i
                    end
                else
                    newest = t
                    newest_f = i
                end
            end
        end
    end
    local f = io.open(current_f)
    if f then
        for _ in f:lines() do
            count = count + 1
        end
        f:close()
    end
    log_file = io.open(current_f, "a")
end

local function new_file()
    if log_file then
        log_file:flush()
        log_file:close()
    end
    if file_c >= max_f then
        os.remove(file_path(oldest_f))
        oldest_f = (oldest_f + 1) % max_f
    else
        file_c = file_c + 1
    end
    os.rename(current_f, file_path(newest_f))
    newest_f = (newest_f + 1) % max_f
    log_file = io.open(current_f, "a")
end

local command = {}
function command.logging(addr, type, str)
    local t = os.date("%Y-%m-%d %H:%M:%S", math.floor(skynet.time()))
    str = string.format("[%08x] [%-6s] [%s] %s\n", addr, type, t, str)
    count = count + 1
    log_file:write(str)
    log_file:flush()
    if do_print then
        io.write(str)
    end
    if count >= max_count then
        count = 0
        new_file()
    end
end

skynet.register_protocol {
    name = "text",
    id = skynet.PTYPE_TEXT,
    unpack = skynet.tostring,
    dispatch = function(_, addr, msg)
        command.logging(addr, "SKYNET", msg)
    end
}

skynet.register_protocol {
    name = "system",
    id = skynet.PTYPE_SYSTEM,
    unpack = function(...) return ... end,
    dispatch = function(_, addr)
        command.logging(addr, "INFO", "SIGHUP SA_RESTART")
    end
}

init()
skynet.start(function()
    skynet.dispatch("lua", function(session, addr, cmd, ...)
        local f = command[cmd]
        if f then
            f(addr, ...)
        end
    end)
end)
