local skynet = require "skynet.manager"
local cluster = require "skynet.cluster"
local crypt = require "skynet.crypt"
local api = require "api"
local md5 = require "md5"
local lfs = require "lfs"
local dump = require "utils.dump"
local http = require "utils.http"
local log = require "log"
local sys = require "sys"
local text = require("text").sysmgr
local strfmt = string.format

local app_root = sys.app_root
local run_root = sys.run_root
local repo_cfg = strfmt("%s/%s", run_root, sys.repo_cfg)
local pipe_cfg = strfmt("%s/%s", run_root, sys.pipe_cfg)
local entry_lua = strfmt(sys.prod() and "%s.luac" or "%s.lua", sys.entry_lua)
local meta_lua = strfmt(sys.prod() and "%s.luac" or "%s.lua", sys.meta_lua)
local gateway_global = sys.gateway_global

local launch_delay = sys.prod() and 6000 or 1

local function backup(from, to)
    local f = io.open(from)
    local conf = f:read("a")
    f:close()

    f = io.open(to, "w")
    f:write(conf)
    f:close()
end

local function bak_file(file)
    return file..".bak"
end

local function save_cfg(file, key, conf)
    local ok, err = pcall(function()
        local t = {}
        t[key] = conf
        local str = dump(t)
        local attr = lfs.attributes(file)
        if attr then
            backup(file, bak_file(file))
        end
        local f = io.open(file, "w")
        f:write(str)
        f:close()
    end)
    if ok then
        log.info(text.config_update_suc, file)
        return ok
    else
        log.error(text.config_update_fail, file, err)
        return ok, err
    end
end

local function load_cfg(file, env)
    local attr = lfs.attributes(file)
    if attr and attr.mode == "file" and attr.size ~= 0 then
        local ok, err =  pcall(function()
            loadfile(file, "t", env)()
        end)
        if ok then
            log.info(text.config_load_suc, file)
        else
            log.error(text.config_load_fail, file, err)
        end
    end
end

local function validate_tpl(tpl)
    local entry = strfmt("%s/%s", tpl, entry_lua)
    local attr = lfs.attributes(entry)
    if attr and attr.mode == "file" and attr.size ~= 0 then
        local meta = strfmt("%s/%s", tpl, meta_lua)
        local env = {}
        load_cfg(meta, env)
        if type(env.conf) == "table" then
            return env.conf
        else
            return false
        end
    else
        return false
    end
end

local function validate_app(app)
    local attr = lfs.attributes(app)
    if attr and attr.mode == "file" and attr.size ~= 0 then
        local env = {}
        load_cfg(app, env)
        if type(env.conf) == "table" then
            return env.conf
        else
            return false
        end
    else
        return false
    end
end

local function app_id_tpl(app)
    local tpl, idstr = app:match("^(.+)_([%d%l]+)$")
    local id = tonumber(idstr)
    return id or idstr, tpl
end

--------------------- cfg ---------------------
local cfg = {
    repo = {},
    pipes = {},
    apps = {},
    tpls = {}
}

local function do_load_tpl(dir, tpls, unique)
    for tpl in lfs.dir(dir) do
        if tpl ~= "." and tpl ~= ".." then
            if tpls[tpl] then
                log.error(text.dup_tpl, tpl)
            else
                local subdir = strfmt("%s/%s", dir, tpl)
                local conf = validate_tpl(subdir)
                if conf then
                    tpls[tpl] = {
                        conf = conf,
                        unique = unique
                    }
                else
                    log.error(text.invalid_meta, tpl)
                end
            end
        end
    end
end

local function load_tpl()
    do_load_tpl(app_root, cfg.tpls, false)
end

local function load_systpl()
    do_load_tpl(sys.sys_root, cfg.tpls, true)
end

local function load_app()
    local dir = run_root
    local apps = cfg.apps
    for app in lfs.dir(dir) do
        local id, tpl = app_id_tpl(app)
        if id and tpl then
            if apps[id] then
                log.error(text.dup_app, app)
            else
                local f = strfmt("%s/%s", dir, app)
                local conf = validate_app(f)
                if conf then
                    apps[id] = { [tpl] = conf }
                else
                    log.error(text.invalid_app, app)
                end
            end
        end
    end
end

local function load_sysapp()
    local apps = cfg.apps
    local tpls = cfg.tpls
    local auth_enabled = cfg.auth.enabled
    for id, app in pairs(cfg.sysapp) do
        tpls[app.tpl].read_only = app.read_only

        if app.enabled and not apps[id] then
            apps[id] = { [app.tpl] = app.conf or {} }
        end
    end
end

local function load_syspipe()
    local pipes = cfg.pipes
    for id, apps in pairs(cfg.syspipe) do
        pipes[id] = { apps = apps }
    end
end

local function load_auth()
    local auth = cfg.auth
    auth.salt = crypt.randomkey()
    auth.password = crypt.hmac_sha1(auth.password, auth.salt)
end

local function load_all()
    pcall(lfs.mkdir, app_root)
    pcall(lfs.mkdir, run_root)

    load_cfg(sys.sys_cfg, cfg)
    load_cfg(repo_cfg, cfg)
    load_cfg(pipe_cfg, cfg)

    load_tpl()
    load_app()

    load_systpl()
    load_sysapp()
    load_syspipe()

    load_auth()
end

--------------------- command ---------------------
local command = {}

function command.auth(arg)
    local username = arg[1]
    local password = arg[2]
    if type(username) == "string" and type(password) == "string" then
        return md5.sumhexa(username) == cfg.auth.username and
        crypt.hmac_sha1(md5.sumhexa(password), cfg.auth.salt) == cfg.auth.password
    else
        return false
    end
end

function command.update_app(arg)
    local id = arg[1]
    local tpl = arg[2]
    local conf = arg[3]
    local f = strfmt("%s/%s_%s", run_root, tpl, id)
    if conf then
        local ok, err = save_cfg(f, "conf", conf)
        if ok then
            cfg.apps[id] = { [tpl] = conf }
            return ok
        else
            return ok, err
        end
    else
        local app = cfg.apps[id]
        if app then
            os.remove(f)
            os.remove(bak_file(f))
            cfg.apps[id] = nil
            log.info(text.config_removed, f)
            return true
        else
            return false
        end
    end
end

function command.update_pipe(list)
    if next(list) then
        local ok, err = save_cfg(pipe_cfg, "pipes", list)
        if ok then
            cfg.pipes = list
            return ok
        else
            return ok, err
        end
    else
        os.remove(pipe_cfg)
        os.remove(bak_file(pipe_cfg))
        cfg.pipes = {}
        log.info(text.config_removed, pipe_cfg)
        return true
    end
end

function command.get_conf(key)
    return cfg[key]
end

function command.install_tpl(name)
    local tarball = sys.app_tarball(name)
    local tar = http.get(sys.app_uri(cfg.repo.uri, cfg.sys.platform, name)..tarball, cfg.repo.auth, 6000)
    if not tar then
        return false, text.download_fail
    end
    return pcall(function()
        local dir = strfmt("%s/%s", app_root, name)
        local attr = lfs.attributes(dir)
        if attr then
            os.remove(dir)
        end

        local f = io.open(tarball, "w")
        f:write(tar)
        f:close()

        local ok = sys.unzip(tarball)
        os.remove(tarball)

        attr = lfs.attributes(dir)
        if not ok or not attr then
            os.remove(dir)
            error(text.unzip_fail)
        end

        local conf = validate_tpl(dir)
        if not conf then
            os.remove(dir)
            error(text.invalid_meta)
        end

        return { conf = conf }
    end)
end

function command.update_repo(arg)
    local uri = arg[1]
    local auth = arg[2]
    local conf = { uri = uri, auth = auth }
    local ok, err = save_cfg(repo_cfg, "repo", conf)
    if ok then
        cfg.repo = conf
        return ok
    else
        return ok, err
    end
end

local function cluster_port()
    return cfg.sys.cluster
end

local function cluster_reload(c, port)
    local n = "iotedge"
    c.reload({ [n] = "127.0.0.1:"..port })
    return n
end

local function configure(port, conf)
    return pcall(function()
        local peer = cluster_reload(cluster, port)
        local g = "@"..gateway_global

        local ok, err = cluster.call(peer, g, "sys", "info")
        if ok then
            ok, err = cluster.call(peer, g, "sys", "configure", conf)
            if ok then
                return ok
            else
                error(err)
            end
        else
            error(err)
        end
    end)
end

local function clean_delay()
    skynet.sleep(3000)
end

local function upgrade_delay()
    skynet.sleep(7000)
end

function command.upgrade(version)
    local tarball = sys.app_tarball(version)
    local tar = http.get(sys.app_uri(cfg.repo.uri, cfg.sys.platform)..tarball, cfg.repo.auth, 60000)
    if not tar then
        return false, text.download_fail
    end

    local t_dir = strfmt("../%s", sys.core_name(version))
    local ok, err = pcall(function()
        local f = io.open(tarball, "w")
        f:write(tar)
        f:close()

        local attr = lfs.attributes(t_dir)
        if attr then
            log.info(text.core_replace)
            os.remove(t_dir)
        end

        local ok = sys.unzip(tarball, "..")
        os.remove(tarball)
        if not ok then
            os.remove(t_dir)
            error(text.unzip_fail)
        end
    end)
    if ok then
        skynet.timeout(0, function()
            local c_dir = lfs.currentdir()
            local t_port = cluster_port() + 1

            api.sys_request("stop")
            skynet.send(cfg.store, "lua", "stop")

            clean_delay()

            lfs.chdir(t_dir)
            ok = sys.upgrade(cfg.sys.config, c_dir, t_port)
            lfs.chdir(c_dir)
            if not ok then
                log.error(text.install_fail)
                return
            end

            upgrade_delay()

            local c_total = { repo = cfg.repo, apps = cfg.apps, pipes = cfg.pipes }
            ok, err = configure(t_port, c_total)
            if ok then
                log.info(text.sys_exit)
            else
                log.error(text.configure_fail, err)
            end

            skynet.sleep(100) -- for log above msg
            sys.quit()
            end)
        return ok
    else
        return ok, err
    end
end

local cmd_desc = {
    update_pipe = true,
    update_app = true,
    update_repo = true,
    install_tpl = true,
    get_conf = true,
    upgrade = true,
    auth = true
}

local function launch()
    log.info("System starting")
    load_all()

    local g = skynet.uniqueservice("gateway", cfg.gateway.flowcontrol, tostring(cfg.gateway.audit))
    skynet.name(api.gateway_addr, g)
    cluster.register(gateway_global, g)
    cluster.open(cluster_reload(cluster, cluster_port()))
    log.info("Gateway started")

    api.internal_init(cmd_desc)

    cfg.store = skynet.uniqueservice("datastore")
    skynet.name(api.store_addr, cfg.store)
    log.info("Store started")

    cfg.appmgr = skynet.uniqueservice(true, "appmgr")
    skynet.monitor("appmgr", true)
    log.info("Monitor started")

    log.info("System started:", cfg.sys.id, cfg.sys.version)
end

skynet.start(function()
    skynet.dispatch("lua", function(_, _, cmd, dev, arg)
        local f = command[cmd]
        if f then
            skynet.ret(skynet.pack(f(arg)))
        else
            skynet.ret(skynet.pack(false, text.unknown_cmd))
        end
    end)
    skynet.timeout(launch_delay, launch)
end)
