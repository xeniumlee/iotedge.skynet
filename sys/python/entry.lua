local skynet = require "skynet"
local log = require "log"
local lfs = require "lfs"
local text = require("text").app
local validator = require "utils.validator"
local sys = require "sys"
local api = require "api"
local python = require "python"

local list_cmd = string.format("python3 -m pip list --format json")
local install_cmd

local cfg_schema = {
    pip = validator.httpurl,
    private = function(v)
        return v=='' or validator.httpurl(v)
    end
}

local cmd_desc = {
    list_packages = "List all packages",
    install_package = "Install a package: <string>}",
    run_function = "Run a function: {module=<string>,func=<string>,args={}}",
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

function list_packages()
    return sys.exec(list_cmd)
end

function install_package(arg)
    if type(arg) == "string" then
        local cmd = string.format(install_cmd, arg)
        return sys.exec(cmd)
    else
        return false, text.invalid_arg
    end
end

function run_function(arg)
    if type(arg.module) == "string" and
        type(arg.func) == "string" and
        type(arg.args) == "table" then
        return python.run(arg.module, arg.func, arg.args)
    else
        return false, text.invalid_arg
    end
end

function on_conf(cfg)
    local ok = pcall(validator.check, cfg, cfg_schema)
    if ok then
        install_cmd = string.format("python3 -m pip install -i %s --extra-index-url %s -U %%s", cfg.pip, cfg.private)
        python.init(lfs.currentdir())
        return ok
    else
        return ok, text.invalid_conf
    end
end

reg_cmd()
