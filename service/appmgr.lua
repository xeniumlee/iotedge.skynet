local skynet = require "skynet"
local core = require "skynet.core"
local api = require "api"
local sys = require "sys"
local log = require "log"
local dump = require "utils.dump"
local text = require("text").appmgr

local interval = 500 -- 5 seconds
local limit = 4 -- 15 seconds
local locked = true

local sysinfo = {}
local applist = {}
local pipelist = {}
local tpllist = {}
local appmonitor = {}
local command = {}

-- https://www.lua.org/manual/5.3/manual.html#3.4.7
local function gen_pipeid()
    return #pipelist + 1
end

local function gen_appid()
    return #applist + 1
end

local function sysapp(tpl)
    return tpllist[tpl].unique
end

local function readonly_app(tpl)
    return tpllist[tpl].read_only
end

local function syspipe(id)
    return not tonumber(id)
end

local function clone(tpl, custom)
    local force = "devices"
    if type(tpl) == "table" then
        local copy = {}
        for k, v in pairs(tpl) do
            if k ~= force then
                if custom[k] ~= nil then
                    copy[k] = clone(v, custom[k])
                else
                    copy[k] = v
                end
            end
        end
        local f = custom[force]
        if f then
            copy[force] = f
        end
        return copy
    else
        return custom
    end
end

--------------------- info ---------------------
local function make_appinfo(app)
    local info = {}
    if app.conf and app.name ~= api.hostappid then
        info.conf = app.conf
    end
    info.load_time = app.load_time
    return info
end

local function make_pipeinfo(pipe)
    local info = {}
    info.start_time = pipe.start_time or nil
    info.stop_time = pipe.stop_time or nil
    info.apps = {}
    for idx, id in ipairs(pipe.apps) do
        info.apps[idx] = applist[id].name
    end
    return info
end

local function refresh_info()
    local apps = {}
    for id, app in pairs(applist) do
        apps[app.name] = make_appinfo(app)
    end

    local pipes = {}
    for id, pipe in pairs(pipelist) do
        pipes[id] = make_pipeinfo(pipe)
    end
    sysinfo.apps = apps
    sysinfo.pipes = pipes
end

--------------------- update ---------------------
local function update_app(id, remove)
    local app = applist[id]
    if remove then
        skynet.send(app.addr, "lua", "exit")
        api.internal_request("update_app", { id, app.tpl, false })
        applist[id] = nil
    else
        api.internal_request("update_app", { id, app.tpl, app.conf })
    end
    refresh_info()
end

local function update_pipes()
    local list = {}
    for k, v in pairs(pipelist) do
        if not syspipe(k) then
            list[k] = {}
            list[k].auto = (v.start_time ~= false)
            list[k].apps = v.apps
        end
    end
    api.internal_request("update_pipes", list)
    refresh_info()
end

--------------------- action ---------------------
local function start_pipe(id)
    local apps = pipelist[id].apps
    for i, appid in ipairs(apps) do
        local r = applist[appid].route[id]
        if r.target then
            if i == 1 then
                skynet.send(applist[appid].addr, "lua", "route_add", r.source, r.target, r.last)
            else
                skynet.send(applist[appid].addr, "lua", "route_add", r.source, r.target)
            end
        end
    end
    pipelist[id].start_time = api.datetime()
    pipelist[id].stop_time = false
    log.info(text.pipe_start_suc, id)
end

local function stop_pipe(id)
    local apps = pipelist[id].apps
    for i, appid in ipairs(apps) do
        local r = applist[appid].route[id]
        if r.target then
            if i == 1 then
                skynet.send(applist[appid].addr, "lua", "route_del", r.source, r.target, r.last)
            else
                skynet.send(applist[appid].addr, "lua", "route_del", r.source, r.target)
            end
        end
    end
    pipelist[id].start_time = false
    pipelist[id].stop_time = api.datetime()
    log.info(text.pipe_stop_suc, id)
end

local function try_start_pipe(id, auto)
    if auto == nil or auto == true then
        start_pipe(id)
    end
end

local function load_pipe(id, apps)
    local source = apps[1]
    local lastid = apps[#apps]
    for i, appid in ipairs(apps) do
        local nextid = apps[i+1]
        if nextid then
            if i == 1 then
                applist[appid].route[id] = {
                    source = source,
                    target = applist[nextid].addr,
                    last = applist[lastid].addr
                }
            else
                applist[appid].route[id] = {
                    source = source,
                    target = applist[nextid].addr
                }
            end
        else
            applist[appid].route[id] = {
                source = source
            }
        end
    end
    pipelist[id] = {
        start_time = false,
        stop_time = api.datetime(),
        apps = apps,
    }
    log.info(text.pipe_load_suc, id)
    return true
end

local function load_app(id, tpl)
    local app = {
        name = sysapp(tpl) and id or string.format("%s_%s", tpl, id),
        tpl = tpl,
        conf = false,
        route = {}
    }
    -- to reserve id
    applist[id] = app

    local ok, addr = pcall(skynet.newservice, "appcell", app.tpl, app.name)
    if ok then
        app.addr = addr
        app.load_time = api.datetime()

        appmonitor[addr] = {
            id = app.name,
            counter = 0
        }
        log.info(text.load_suc, app.name)
        return true
    else
        applist[id] = nil
        log.error(text.load_fail, tpl, addr)
        return false, text.load_fail
    end
end

local function configure_app(id, conf)
    local app = applist[id]
    log.info(text.app_conf, app.name, "\n", dump(conf))

    local ok, ret, err = pcall(skynet.call, app.addr, "lua", "conf", conf)
    if ok and ret then
        app.conf = conf
        return true
    else
        err = string.format("%s(%s)", ok and err or ret, app.name)
        log.error(text.conf_fail, err)
        return false, err
    end
end

local function do_clean()
    for id, _ in pairs(pipelist) do
        if not syspipe(id) then
            stop_pipe(id)
            pipelist[id] = nil
        end
    end
    update_pipes()

    for id, app in pairs(applist) do
        if not sysapp(app.tpl) then
            update_app(id, true)
        end
    end
    log.info(text.cleaned)
end

local function configure_external(c)
    do_clean()
    skynet.sleep(3000)

    local ok, err
    for id, app in pairs(c.apps) do
        local tpl, conf = next(app)

        if applist[id] then
            if not readonly_app(tpl) then
                conf = clone(applist[id].conf, conf)
                ok, err = configure_app(id, conf)
                if ok then
                    update_app(id)
                else
                    return ok, err
                end
            end
        else
            ok, err = load_app(id, tpl)
            if ok then
                conf = clone(tpllist[tpl].conf, conf)
                ok, err = configure_app(id, conf)
                if ok then
                    update_app(id)
                else
                    return ok, err
                end
            else
                return ok, err
            end
        end
    end

    for id, pipe in pairs(c.pipes) do
        if not pipelist[id] then
            ok, err = load_pipe(id, pipe.apps)
            if ok then
                try_start_pipe(id, pipe.auto)
                update_pipes()
            else
                return ok, err
            end
        end
    end

    return true
end

local function configure_internal(c)
    for id, app in pairs(c.apps) do
        local tpl, conf = next(app)
        local ok = load_app(id, tpl)
        if ok then
            conf = clone(tpllist[tpl].conf, conf)
            configure_app(id, conf)
        end
    end
    for id, pipe in pairs(c.pipes) do
        local ok = load_pipe(id, pipe.apps)
        if ok then
            try_start_pipe(id, pipe.auto)
        end
    end
end

local cmd_desc = {
    stop = "Stop all APPs",
    configure = "System configure: {}",
    upgrade = "System upgrade: <string>",
    info = "Show system info",
    apps = "Show all APP template",
    app_new = "New a APP: {<app>=<conf>}",
    app_remove = "Remove a APP: <id>",
    pipe_new = "New a PIPE: {apps={},auto=<boolean>}",
    pipe_remove = "Remove a PIPE: <id>",
    pipe_start = "Start a PIPE: <id>",
    pipe_stop = "Stop a PIPE: <id>",
}

local function load_all()
    api.sys_init(cmd_desc)

    sysinfo.sys = api.internal_request("get_conf", "sys")
    sysinfo.sys.up = api.datetime(skynet.starttime())

    tpllist = api.internal_request("get_conf", "tpls")
    local total = api.internal_request("get_conf", "total")
    sysinfo.sys.repo = total.repo.uri

    configure_internal(total)

    refresh_info()
    locked = false
end

--------------------- command ---------------------
function command.apps()
    local ret = {}
    for k, v in pairs(tpllist) do
        if not v.unique then
            ret[k] = v
        end
    end
    return ret
end

function command.stop()
    for _, app in pairs(applist) do
        skynet.send(app.addr, "lua", "exit")
    end
    log.info(text.cleaned)
    return true
end

local function validate_repo(repo)
    return pcall(function()
        assert(type(repo) == "table" and
            type(repo.uri) == "string" and
            (type(repo.auth) == "string" or type(repo.auth) == "table"),
            text.invalid_repo)

        local auth
        if type(repo.auth) == "string" then
            local k, v = repo.auth:match("^([%g%s]+):([%g%s]+)$")
            if k and v then
                auth = { [k] = v }
            end
        else
            local k, v = next(repo.auth)
            if type(k) == "string" and type(v) == "string" then
                auth = repo.auth
            end
        end
        assert(auth, text.invalid_repo)

        local ok, err = api.internal_request("update_repo", { repo.uri, auth })
        assert(ok, err)

        sysinfo.sys.repo = repo.uri
    end)
end

local function validate_appname(name)
    if applist[name] then
        return true, name, applist[name].tpl
    else
        if type(name) == "string" then
            local tpl, id = name:match("^(.+)_(%d+)$")
            id = tonumber(id)
            if tpllist[tpl] and applist[id] then
                return true, id, tpl
            else
                return false, text.unknown_app
            end
        else
            return false, text.unknown_app
        end
    end
end

local function validate_appconf(arg)
    return pcall(function()
        assert(type(arg) == "table", text.invalid_arg)
        local tpl, conf = next(arg)
        assert(type(tpl) == "string" and
            tpl:match("^[%l%d_]+$") and
            type(conf) == "table", text.invalid_arg)

        if not tpllist[tpl] then
            assert(sysinfo.sys.repo, text.invalid_repo)
            local ok, ret = api.internal_request("install_tpl", tpl)
            assert(ok, ret)
            tpllist[tpl] = ret
        end
        return tpl, conf
    end)
end

local function validate_full_conf(arg)
    if type(arg.pipes) ~= "table" or type(arg.apps) ~= "table" then
        return false, text.invalid_arg
    end

    if arg.repo then
        local ok, err = validate_repo(arg.repo)
        if not ok then
            return false, err
        end
    end

    local apps = arg.apps
    for _, pipe in pairs(arg.pipes) do
        if type(pipe) == "table" and
            type(pipe.apps) == "table" and #(pipe.apps) > 1 and
            (pipe.auto == nil or type(pipe.auto) == "boolean") then

            for _, id in pairs(pipe.apps) do
                if not apps[id] then
                    return false, text.unknown_app
                end
            end
        else
            return false, text.invalid_arg
        end
    end

    for _, app in pairs(apps) do
        local ok, err = validate_appconf(app)
        if not ok then
            return ok, err
        end
    end

    return true
end

function command.configure(arg)
    if locked then
        return false, text.locked
    end
    if type(arg) ~= "table" then
        return false, text.invalid_arg
    end

    locked = true
    local ok, err

    if type(arg.pipes) == "table" then
        ok, err = validate_full_conf(arg)
        if ok then
            ok, err = configure_external(arg)
        end
    else
        if arg.repo then
            ok, err = validate_repo(arg.repo)
        else
            local name, conf = next(arg)
            if type(conf) ~= "table" then
                ok, err = false, text.invalid_arg
            else
                local id, tpl
                ok, id, tpl = validate_appname(name)
                if ok then
                    if readonly_app(tpl) then
                        ok, err = false, text.app_readonly
                    else
                        conf = clone(applist[id].conf, conf)
                        ok, err = configure_app(id, conf)
                    end
                else
                    ok, err = false, id
                end
            end
        end
    end

    locked = false
    if ok then
        return ok
    else
        return ok, err
    end
end

function command.upgrade(version)
    if locked then
        return false, text.locked
    end
    if type(version) ~= "string" or
        not version:match("^[%d%l]+$") then
        return false, text.invalid_version
    end
    if version == sysinfo.sys.version then
        return false, text.dup_upgrade_version
    end
    if not sysinfo.sys.repo then
        return false, text.invalid_repo
    end

    locked = true

    local ok, err = api.internal_request("upgrade", version)
    if not ok then
        locked = false
    end
    return ok, err
end

function command.app_new(arg)
    if locked then
        return false, text.locked
    end
    local ok, tpl, conf = validate_appconf(arg)
    if not ok then
        return ok, tpl
    end

    if sysapp(tpl) then
        return false, text.sysapp_create
    end

    local id = gen_appid()
    local err
    ok, err = load_app(id, tpl)
    if ok then
        conf = clone(tpllist[tpl].conf, conf)
        ok, err = configure_app(id, conf)
        if ok then
            update_app(id)
            return ok
        else
            return ok, err
        end
    else
        return ok, err
    end
end

function command.app_remove(name)
    if locked then
        return false, text.locked
    end
    local ok, id, tpl = validate_appname(name)
    if not ok then
        return ok, id
    end
    if sysapp(tpl) then
        return false, text.sysapp_remove
    end
    if next(applist[id].route) ~= nil then
        return false, text.app_inuse
    end

    update_app(id, true)
    return true
end

local function validate_pipe(pipe)
    if type(pipe) == "table" and
        type(pipe.apps) == "table" and #(pipe.apps) > 1 and
        (pipe.auto == nil or type(pipe.auto) == "boolean") then

        for i, app in pairs(pipe.apps) do
            local ok, id = validate_appname(app)
            if ok then
                -- app name to id
                pipe.apps[i] = id
            else
                return ok, id
            end
        end
        return true
    else
        return false, text.invalid_arg
    end
end

function command.pipe_new(pipe)
    if locked then
        return false, text.locked
    end
    local ok, err = validate_pipe(pipe)
    if not ok then
        return ok, err
    end
    local id = gen_pipeid()
    ok, err = load_pipe(id, pipe.apps)
    if ok then
        try_start_pipe(id, pipe.auto)
        update_pipes()
        return ok, id
    else
        return ok, err
    end
end

function command.pipe_remove(arg)
    if locked then
        return false, text.locked
    end
    if syspipe(arg) then
        return false, text.syspipe_remove
    end

    local id = tonumber(arg)
    local pipe = pipelist[id]
    if not pipe then
        return false, text.unknown_pipe
    end
    if pipe.start_time ~= false then
        return false, text.pipe_running
    end

    for _, appid in pairs(pipe.apps) do
        applist[appid].route[id] = nil
    end
    pipelist[id] = nil
    update_pipes()
    return true
end

function command.pipe_start(arg)
    if locked then
        return false, text.locked
    end
    if syspipe(arg) then
        return false, text.pipe_running
    end

    local id = tonumber(arg)
    local pipe = pipelist[id]
    if not pipe then
        return false, text.unknown_pipe
    end
    if pipe.start_time ~= false then
        return false, text.pipe_running
    end

    start_pipe(id)
    update_pipes()
    return true
end

function command.pipe_stop(arg)
    if locked then
        return false, text.locked
    end
    if syspipe(arg) then
        return false, text.syspipe_stop
    end

    local id = tonumber(arg)
    local pipe = pipelist[id]
    if not pipe then
        return false, text.unknown_pipe
    end
    if pipe.stop_time ~= false then
        return false, text.pipe_stopped
    end

    stop_pipe(id)
    update_pipes()
    return true
end

function command.info()
    sysinfo.sys.uptime = skynet.now()//100
    return sysinfo
end

--------------------- monitor ---------------------
local function signal(addr)
    core.command("SIGNAL", skynet.address(addr))
end

local function check()
    for addr, app in pairs(appmonitor) do
        if app.counter == 0 then
            app.counter = 1
            skynet.fork(function()
                skynet.call(addr, "debug", "PING")
                if appmonitor[addr] then
                    appmonitor[addr].counter = 0
                end
            end)
        elseif app.counter == limit then
            log.error(text.loop, app.id)
            signal(addr)
        else
            app.counter = app.counter + 1
        end
    end
    skynet.timeout(interval, check)
end

--------------------- service ---------------------
skynet.start(function()
    skynet.register_protocol {
        name = "client",
        id = skynet.PTYPE_CLIENT,
        unpack = function() end,
        dispatch = function(_, addr)
            if appmonitor[addr] then
                log.error(text.app_exit, appmonitor[addr].id)
                appmonitor[addr] = nil
            end
        end
    }
    skynet.timeout(interval, check)
    skynet.dispatch("lua", function(_, _, cmd, dev, arg)
        local f = command[cmd]
        if f then
            skynet.ret(skynet.pack(f(arg)))
        else
            skynet.ret(skynet.pack(false, text.unknown_cmd))
        end
    end)
    skynet.fork(load_all)
end)
