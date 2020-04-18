local skynet = require "skynet"
local core = require "skynet.core"
local api = require "api"
local log = require "log"
local text = require("text").appmgr

local interval = 500 -- 5 seconds
local limit = 4 -- 15 seconds
local locked = true

local wsapp_addr, mqttapp_addr = ...
local wsappid = "ws"
local mqttappid = "mqtt"
local hostappid = "host"
local frpappid = "frp"

local sysinfo = {}
local applist = {}
local pipelist = {}
local tpllist = {}
local appmonitor = {}
local command = {}

local function sysapp(id)
    return id == mqttappid or
           id == wsappid or
           id == hostappid or
           id == frpappid
end

local function syspipe(id)
    return id == hostappid
end

local function make_appinfo(id, app)
    local info = {}
    if id ~= hostappid then
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
    local name
    for id, app in pairs(applist) do
        apps[app.name] = make_appinfo(id, app)
    end

    local pipes = {}
    for id, pipe in pairs(pipelist) do
        pipes[id] = make_pipeinfo(pipe)
    end
    sysinfo.apps = apps
    sysinfo.pipes = pipes
end

local function update_app(id)
    local app = applist[id]
    api.internal_request("update_app", { id, app.tpl, app.conf })
    refresh_info()
end

local function remove_app(id)
    local app = applist[id]
    skynet.send(app.addr, "lua", "exit")
    api.internal_request("update_app", { id, app.tpl, false })
    applist[id] = nil
    refresh_info()
end

local function update_pipes()
    refresh_info()
    local list = {}
    for k, v in pairs(pipelist) do
        if not syspipe(k) then
            list[k] = {}
            list[k].auto = (v.start_time ~= false)
            list[k].apps = v.apps
        end
    end
    api.internal_request("update_pipes", list)
end

local function validate_repo(repo)
    if repo then
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
        elseif type(repo.auth) == "table" then
            local k, v = next(repo.auth)
            if type(k) == "string" and type(v) == "string" then
                auth = repo.auth
            end
        end
        assert(auth, text.invalid_repo)
        local ok, err = api.internal_request("update_repo", { repo.uri, auth })
        if ok then
            sysinfo.sys.repo = repo.uri
        else
            error(err)
        end
    end
    assert(sysinfo.sys.repo, text.invalid_repo)
end

local function validate_appname(name)
    if sysapp(name) then
        return name, name
    elseif type(name) == "string" then
        local tpl, id = name:match("^(.+)_(%d+)$")
        local i = tonumber(id)
        if tpllist[tpl] and applist[i] then
            return i, tpl
        else
            error(text.unknown_app)
        end
    else
        error(text.unknown_app)
    end
end

local function validate_pipe_with_apps(pipe, apps)
    assert(type(pipe) == "table" and
        type(pipe.apps) == "table" and #(pipe.apps) > 1 and
        (pipe.auto == nil or type(pipe.auto) == "boolean"),
        text.invalid_arg)
    for _, name in pairs(pipe.apps) do
        if sysapp(name) then
            assert(applist[name], text.unknown_app)
        else
            assert(apps[name], text.unknown_app)
        end
    end
end

local function validate_pipe(pipe)
    assert(type(pipe) == "table" and
        type(pipe.apps) == "table" and #(pipe.apps) > 1 and
        (pipe.auto == nil or type(pipe.auto) == "boolean"),
        text.invalid_arg)
    local id
    for i, name in pairs(pipe.apps) do
        id = validate_appname(name)
        pipe.apps[i] = id
    end
end

local function install_tpl(tpl)
    if not tpllist[tpl] then
        validate_repo()
        local ok, ret = api.internal_request("install_tpl", tpl)
        if ok then
            tpllist[tpl] = ret
        else
            error(ret)
        end
    end
end

local function clone(tpl, custom)
    local force = "devices"
    if type(tpl) == "table" then
        local copy = {}
        for k, v in pairs(tpl) do
            if k ~= force then
                if custom[k] then
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

local function validate_appconf(arg)
    assert(type(arg) == "table", text.invalid_arg)
    local tpl, conf = next(arg)
    assert(type(tpl) == "string" and
        tpl:match("^[%l%d_]+$") and
        type(conf) == "table", text.invalid_arg)
    install_tpl(tpl)
    return tpl, clone(tpllist[tpl], conf)
end

local function validate_fullconf(arg)
    assert((arg.pipes == nil and arg.apps == nil) or
           (arg.pipes == nil and type(arg.apps) == "table") or
           (type(arg.pipes) == "table" and type(arg.apps) == "table"),
           text.invalid_arg)

    if arg.repo then
        validate_repo(arg.repo)
    end

    for _, pipe in pairs(arg.pipes) do
        validate_pipe_with_apps(pipe, arg.apps)
    end

    local tpl, conf
    for _, app in pairs(arg.apps) do
        tpl, conf = validate_appconf(app)
        app[tpl] = conf
    end
end

local function validate_conf(arg)
    if arg.repo then
        validate_repo(arg.repo)
    else
        local name, conf = next(arg)
        assert(type(conf) == "table", text.invalid_arg)
        local id, tpl = validate_appname(name)
        return id, clone(tpllist[tpl], conf)
    end
end

local function load_app(id, tpl)
    -- to reserve id
    applist[id] = {}

    local name = sysapp(id) and id or tpl.."_"..id
    local ok, addr = pcall(skynet.newservice, "appcell", tpl, name)
    if ok then
        applist[id] = {
            name = name,
            addr = addr,
            load_time = api.datetime(),
            tpl = tpl,
            route = {}
        }
        appmonitor[addr] = {
            id = name,
            counter = 0
        }
        log.error(text.load_suc, name)
        return true
    else
        applist[id] = nil
        log.error(text.load_fail, tpl, addr)
        return false, text.load_fail
    end
end

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
    log.error(text.pipe_start_suc, id)
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
    log.error(text.pipe_stop_suc, id)
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
    log.error(text.pipe_load_suc, id)
    return true
end

local function configure_app(id, conf, nosave)
    local a = applist[id]
    local ok, ret, err = pcall(skynet.call, a.addr, "lua", "conf", conf)
    if ok then
        if ret then
            a.conf = conf
            if not nosave and not a.read_only then
                update_app(id)
            end
            return ret
        else
            return ret, err
        end
    else
        return ok, ret
    end
end

local function configure_all(arg, nosave)
    local ok, err, tpl, conf
    for id, app in pairs(arg.apps) do
        tpl, conf = next(app)
        if sysapp(id) then
            ok, err = configure_app(id, conf, nosave)
            if not ok then
                return ok, err
            end
        else
            ok, err = load_app(id, tpl)
            if ok then
                ok, err = configure_app(id, conf, nosave)
                if not ok then
                    return ok, err
                end
            else
                return ok, err
            end
        end
    end
    for id, pipe in pairs(arg.pipes) do
        ok, err = load_pipe(id, pipe.apps)
        if ok then
            try_start_pipe(id, pipe.auto)
            if not nosave then
                update_pipes()
            end
        else
            return ok, err
        end
    end
    return true
end

local function load_hostapp()
    local tpl = hostappid
    local ok = load_app(hostappid, tpl)
    if ok then
        applist[hostappid].read_only = true
        local conf = clone(tpllist[tpl], {})
        ok = configure_app(hostappid, conf)
        if ok then
            local pipe = { hostappid, mqttappid }
            ok = load_pipe(hostappid, pipe)
            if ok then
                start_pipe(hostappid)
            end
        end
    end
end

local function load_frpapp()
    local tpl = frpappid
    load_app(frpappid, tpl)
end

local function load_sysapp()
    local now = api.datetime()
    applist[wsappid] = {
        name = wsappid,
        addr = wsapp_addr,
        load_time = now,
        app = "gateway_websocket",
        conf = 30001,
        read_only = true,
        route = {}
    }
    if mqttapp_addr then
        applist[mqttappid] = {
            name = mqttappid,
            addr = mqttapp_addr,
            load_time = now,
            app = "gateway_mqtt",
            read_only = true,
            route = {}
        }
        load_hostapp()
    end
    load_frpapp()
end

local cmd_desc = {
    mqttapp = true,
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

    sysinfo.sys = api.internal_request("conf_get", "sys")
    sysinfo.sys.cluster = nil
    sysinfo.sys.up = api.datetime(skynet.starttime())
    sysinfo.sys.repo = false
    sysinfo.apps = {}
    sysinfo.pipes = {}

    tpllist = api.internal_request("conf_get", "tpls")

    load_sysapp()

    local total = api.internal_request("conf_get", "total")
    local ok, err = pcall(validate_fullconf, total)
    if ok then
        ok, err = configure_all(total, true)
        if not ok then
            log.error(text.conf_fail, err)
        end
    else
        log.error(text.conf_fail, err)
    end
    refresh_info()

    locked = false
end

function command.apps()
    return tpllist
end

function command.clean()
    for id, _ in pairs(pipelist) do
        if not syspipe(id) then
            stop_pipe(id)
            pipelist[id] = nil
        end
    end
    update_pipes()

    for id, _ in pairs(applist) do
        if not sysapp(id) then
            remove_app(id)
        end
    end
    log.error(text.cleaned)
    return true
end

function command.configure(arg)
    if locked then
        return false, text.locked
    end
    if type(arg) ~= "table" then
        return false, text.invalid_arg
    end
    local ok, err
    locked = true
    if type(arg.pipes) == "table" then
        ok, err = pcall(validate_fullconf, arg)
        if ok then
            command.clean()
            skynet.sleep(3000)
            ok, err = configure_all(arg)
        end
    else
        local conf
        ok, err, conf = pcall(validate_conf, arg)
        if ok and err then
            local id = err
            if applist[id].read_only then
                ok, err = false, text.app_readonly
            else
                ok, err = configure_app(id, conf)
            end
        end
    end
    locked = false
    return ok, err
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
    local ok, err = pcall(validate_repo)
    if not ok then
        return ok, err
    end
    locked = true
    ok, err = api.internal_request("upgrade", version)
    if not ok then
        locked = false
    end
    return ok, err
end

function command.mqttapp(conf)
    local m = applist[mqttappid]
    m.conf = conf
    return true
end

function command.app_new(arg)
    if locked then
        return false, text.locked
    end
    local ok, tpl, conf = pcall(validate_appconf, arg)
    if not ok then
        return ok, tpl
    end

    if sysapp(tpl) then
        return false, text.sysapp_create
    end

    local id = #applist+1
    local err
    ok, err = load_app(id, tpl)
    if ok then
        return configure_app(id, conf)
    else
        return ok, err
    end
end
function command.app_remove(name)
    if locked then
        return false, text.locked
    end
    if sysapp(name) then
        return false, text.sysapp_remove
    end
    local ok, id = pcall(validate_appname, name)
    if not ok then
        return ok, id
    end
    if next(applist[id].route) ~= nil then
        return false, text.app_inuse
    end

    remove_app(id)
    return true
end

function command.pipe_new(pipe)
    if locked then
        return false, text.locked
    end
    local ok, err = pcall(validate_pipe, pipe)
    if not ok then
        return ok, err
    end
    local id = #pipelist+1
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
    sysinfo.sys.uptime = string.format("%d seconds", math.floor(skynet.now()/100))
    return sysinfo
end

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
