local skynet = require "skynet"
local api = require "api"
local log = require "log"
local text = require("text").app

local tpl, name = ...
local command = {}

local memlimit = require("sys").memlimit()
if memlimit then
    skynet.memlimit(memlimit)
end

local function load_app()
    --local cache = require "skynet.codecache"
    --cache.mode("OFF")
    require(tpl)
    --cache.mode("ON")
end

function command.route_add(...)
    api.route_add(...)
end

function command.route_del(...)
    api.route_del(...)
end

setmetatable(command, { __index = function(t, cmd)
    local f
    if cmd == "conf" then
        local conf_f = _ENV.on_conf
        if type(conf_f) == "function" then
            f = function(conf)
                skynet.ret(skynet.pack(conf_f(conf)))
            end
        else
            f = function()
                skynet.ret(skynet.pack(false, text.no_conf_handler))
            end
        end
    elseif cmd == "data" then
        local data_f = _ENV.on_data
        if type(data_f) == "function" then
            f = data_f
        end
    elseif cmd == "payload" then
        local payload_f = _ENV.on_payload
        if type(payload_f) == "function" then
            f = payload_f
        end
    elseif cmd == "post" then
        local post_f = _ENV.on_post
        if type(post_f) == "function" then
            f = post_f
        end
    elseif cmd == "exit" then
        local exit_f = _ENV.on_exit
        if type(exit_f) == "function" then
            f = function()
                exit_f()
                api.unreg_dev(true)
                skynet.exit()
            end
        else
            f = function()
                api.unreg_dev(true)
                skynet.exit()
            end
        end
    else
        local cmd_f = _ENV[cmd]
        if type(cmd_f) == "function" then
            f = function(dev, arg)
                local d = string.match(dev, "^(.+)@")
                if d then
                    skynet.ret(skynet.pack(cmd_f(d, arg)))
                else
                    skynet.ret(skynet.pack(cmd_f(arg)))
                end
            end
        else
            f = function()
                skynet.ret(skynet.pack(false, text.unknown_cmd))
            end
        end
    end
    t[cmd] = f
    return f
end})

skynet.start(function()
    load_app()
    api.app_init(name)
    skynet.dispatch("lua", function(_, _, cmd, ...)
        command[cmd](...)
    end)
end)
