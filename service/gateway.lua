local skynet = require "skynet"
local api = require "api"
local log = require "log"
local text = require("text").gateway

local sysmgr_addr = ...

local command = {}
local devlist = {}
local applist = {}
local internal = {
    route_add = true,
    route_del = true,
    data = true,
    payload = true,
    conf = true,
    exit = true
}

local function help()
    local ret = {}
    for k, v in pairs(devlist) do
        if k ~= "internal" and not v.appname then
            ret[k] = {}
            ret[k].devices = v.sublist
            local cmd = {}
            for c, d in pairs(v.cmdlist) do
                if type(d) == "string" then
                    cmd[c] = d
                end
            end
            ret[k].cmd = cmd
        end
    end
    return ret
end

local function invalidate_cache(name)
    command[name] = nil
end

function command.reg_cmd(addr, name, desc)
    if type(name) ~= "string" or
        (type(desc) ~= "string" and type(desc) ~= "boolean") or
        internal[name] then
        log.error(text.invalid_cmd)
        return
    end
    local app = applist[addr]
    if not app then
        log.error(text.unknown_app)
        return
    end
    if app.cmdlist[name] then
        log.error(text.dup_cmd)
        return
    end
    app.cmdlist[name] = desc
    log.error(text.cmd_registered, name)
end

function command.reg_dev(addr, name, desc)
    if type(name) ~= "string" or
        (type(desc) ~= "boolean" and type(desc) ~= "string") then
        log.error(text.invalid_dev)
        return
    end
    if desc == true then
        if devlist[name] then
            log.error(text.dup_dev, name)
            return
        end
        devlist[name] = {
            addr = addr,
            name = name,
            cmdlist = {},
            sublist = {}
        }
        applist[addr] = devlist[name]
        invalidate_cache("help")
        invalidate_cache(name)
    else
        if devlist[name] then
            log.error(text.dup_dev, name)
            return
        end
        local app = applist[addr]
        if not app then
            log.error(text.unknown_app)
            return
        end
        devlist[name] = {
            addr = addr,
            appname = app.name
        }
        app.sublist[name] = desc
        invalidate_cache(name)
    end
    log.error(text.dev_registered, name)
end

function command.unreg_dev(addr, name)
    if type(name) ~= "string" and type(name) ~= "boolean" then
        log.error(text.invalid_dev)
        return
    end
    local app = applist[addr]
    if not app then
        log.error(text.unknown_app)
        return
    end
    if name == true then
        for dev, _ in pairs(app.sublist) do
            devlist[dev] = nil
            invalidate_cache(dev)
        end
        devlist[app.name] = nil
        applist[addr] = nil
        invalidate_cache("help")
        invalidate_cache(app.name)
        log.error(text.dev_unregistered, app.name)
    else
        devlist[name] = nil
        app.sublist[name] = nil
        invalidate_cache(name)
        log.error(text.dev_unregistered, name)
    end
end

setmetatable(command, { __index = function(t, dev)
    local f
    if dev == "help" then
        local info = help()
        f = function(addr)
            skynet.ret(skynet.pack(info))
        end
    else
        local d = devlist[dev]
        if d then
            local cmdlist
            if d.cmdlist then
                cmdlist = d.cmdlist
            elseif d.appname and devlist[d.appname].cmdlist then
                cmdlist = devlist[d.appname].cmdlist
            end
            if cmdlist then
                f = function(addr, cmd, arg)
                    if cmdlist[cmd] then
                        local ok, ret, err = pcall(skynet.call, d.addr, "lua", cmd, dev, arg)
                        if ok then
                            if err ~= nil then
                                skynet.ret(skynet.pack(ret, err))
                            else
                                skynet.ret(skynet.pack(ret))
                            end
                        else
                            skynet.ret(skynet.pack(false, ret))
                        end
                    else
                        skynet.ret(skynet.pack(false, text.unknown_request))
                    end
                end
            else
                f = function(...)
                    skynet.ret(skynet.pack(false, text.unknown_request))
                end
            end
        else
            f = function(...)
                skynet.ret(skynet.pack(false, text.unknown_request))
            end
        end
    end
    t[dev] = f
    return f
end})

skynet.start(function()
    local conf = skynet.call(sysmgr_addr, "lua", "conf_get", "internal", "gateway")
    if conf then
        skynet.dispatch("lua", function(_, addr, cmd, ...)
            command[cmd](addr, ...)
        end)
    else
        log.error(text.no_conf)
    end
end)
