local skynet = require "skynet"
local api = require "api"
local log = require "log"
local text = require("text").gateway

local sysmgr_addr = ...

local command = {}
local devlist = {}
local applist = {}

local audit = false
local flowcontrol = false
local rpctimeout = 6000 -- 1 min
local req_num = 0
local req_fmt = "[%s] from [%s] to [%s] total [%d]"

local function log_req(cmd, from, dev)
    if audit then
        local req_from = applist[from] and applist[from].name or "EXTERNAL"
        log.info(text.new_request, string.format(req_fmt, cmd, req_from, dev, req_num))
    end
end

local function help()
    local ret = {}
    for k, v in pairs(devlist) do
        if k ~= api.internalappid and not v.appname then
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
    log.info(text.cmd_registered, name)
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
    log.info(text.dev_registered, name)
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
        log.info(text.dev_unregistered, app.name)
    else
        devlist[name] = nil
        app.sublist[name] = nil
        invalidate_cache(name)
        log.info(text.dev_unregistered, name)
    end
end

local function timeout_call(addr, cmd, dev, arg)
    local ok, ret, err, drop
    local co = coroutine.running()
    skynet.fork(function()
        ok, ret, err = pcall(skynet.call, addr, "lua", cmd, dev, arg)
        if not drop then
            skynet.wakeup(co)
        end
    end)
    skynet.sleep(rpctimeout)
    if ok ~= nil then
        return ok, ret, err
    else
        drop = true
        return false, text.timeout
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
                        log_req(cmd, addr, dev)
                        local ok, ret, err = timeout_call(d.addr, cmd, dev, arg)
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
        audit = conf.audit
        flowcontrol = conf.flowcontrol
        if math.tointeger(flowcontrol) and flowcontrol>0 then
            skynet.dispatch("lua", function(_, addr, cmd, ...)
                if applist[addr] then
                    command[cmd](addr, ...)
                elseif req_num < flowcontrol then
                    req_num = req_num + 1
                    command[cmd](addr, ...)
                    req_num = req_num - 1
                else
                    skynet.ret(skynet.pack(false, text.busy))
                end
            end)
        else
            skynet.dispatch("lua", function(_, addr, cmd, ...)
                command[cmd](addr, ...)
            end)
        end
    else
        log.error(text.no_conf)
    end
end)
