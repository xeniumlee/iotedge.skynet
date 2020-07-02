package.path = "lualib/?.lua"
package.cpath = "bin/prebuilt/?.so"

local lfs = require "lfs"
local dump = require "utils.dump"

local strfmt = string.format
local c_root = lfs.currentdir()
local c_run = strfmt("%s/run", c_root)
local f_frpc = strfmt("%s/run/frpc.ini", c_root)
local f_platform = strfmt("%s/PLATFORM", c_root)
local f_config = strfmt("%s/config", c_root)

local function parse_platform()
    local f = io.open(f_platform)
    local p = f:read()
    f:close()
    return p:match("^([%d%l]+)%-(.+)$")
end

local function parse_config(file)
    local env = {}
    loadfile(file, "t", env)()
    return env
end

local function save_config(conf)
    local f = io.open(f_config, "w")
    f:write(dump(conf))
    f:close()
end

local function copy(from, to)
    local f = io.open(from)
    local conf = f:read("a")
    f:close()

    f = io.open(to, "w")
    f:write(conf)
    f:close()
end

local function init_sys(conf, host, id, port)
    local rev, platform = parse_platform()
    assert(rev and platform)

    local sys_conf = conf.sys
    sys_conf.release = rev
    sys_conf.platform = platform
    sys_conf.host = host
    if id then
        sys_conf.id = id
    end
    if port then
        sys_conf.cluster = port
    end
end

local function init_mqtt(conf, mqtt_conf)
    if mqtt_conf then
        conf.sysapp.mqtt.conf = mqtt_conf
    end
end

local function upgrade(config, from_dir, port)

    local file = strfmt("%s/config", from_dir)
    local from_conf = parse_config(file)
    assert(from_conf)

    file = strfmt("%s/%s", c_root, config)
    local c_conf = parse_config(file)
    assert(c_conf)

    init_sys(c_conf, from_conf.sys.host, from_conf.sys.id, port)
    init_mqtt(c_conf, from_conf.sysapps.mqtt and from_conf.sysapp.mqtt.conf or nil)
    save_config(c_conf)

    file = strfmt("%s/run/frpc.ini", from_dir)
    local attr = lfs.attributes(file)
    if attr then
        lfs.mkdir(c_run)
        copy(file, f_frpc)
    end
end

local function install(config, host, mqtt_conf)

    local file = strfmt("%s/%s", c_root, config)
    local c_conf = parse_config(file)
    assert(c_conf)

    init_sys(c_conf, host, mqtt_conf and mqtt_conf.id or nil)
    init_mqtt(c_conf, mqtt_conf)
    save_config(c_conf)
end

local action, config = ...
if action == "install" then
    if config == "config.tb" then
        local host, mqtt_id, mqtt_uri, mqtt_username = select(2, ...)
        if mqtt_id and mqtt_uri and mqtt_username then
            local mqtt_conf = {
                id = mqtt_id,
                uri = mqtt_uri,
                username = mqtt_username
            }
            local ok, err = pcall(install, config, host, mqtt_conf)
            if ok then
                print("ok")
            else
                print(strfmt("error: %s %s %s", action, config, err))
            end
        else
            print(strfmt("invalid arguments: %s %s", action, config))
        end
    elseif config == "config.local" then
        local host = select(2, ...)
        if host then
            local ok, err = pcall(install, config, host)
            if ok then
                print("ok")
            else
                print(strfmt("error: %s %s %s", action, config, err))
            end
        else
            print(strfmt("invalid arguments: %s %s", action, config))
        end
    else
        print(strfmt("unknown config: %s %s", action, config))
    end

elseif action == "upgrade" then
    local from_dir, port = select(2, ...)
    if config and from_dir and port then
        local ok, err = pcall(upgrade, config, from_dir, port)
        if ok then
            print("ok")
        else
            print(strfmt("error: %s %s %s", action, config, err))
        end
    else
        print(strfmt("invalid arguments: %s %s", action, config))
    end

else
    print(strfmt("unknown action: %s", action))
end
