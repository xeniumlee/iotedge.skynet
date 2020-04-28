local skynet = require "skynet"
local api = require "api"
local client = require "s7.client"
local data = require "s7.data"

local cli
local handle = {}
local cmd_desc = {
    info = "Show info",
    readmulti = "Read Multi",
    read = "{ db=<db>,addr=<addr>,amount=<a> }",
    write = "{ db=<db>,addr=<addr>,amount=<a>,value=<v> }",
}

local function reg_cmd()
    for k, v in pairs(cmd_desc) do
        api.reg_cmd(k, v)
    end
end

function info()
    return cli:info()
end

function read(arg)
    local p = handle[arg].read
    local ok, ret = cli:read(p)
    if ok then
        return ok, handle[arg].unpack(p.value)
    else
        return ok, ret
    end
end

function readmulti(arg)
    local list = {}
    local unpack = {}
    local read
    for _, item in pairs(arg) do
        read = handle[item].read
        table.insert(list, read)
        table.insert(unpack, handle[item].unpack)
    end

    local ok, ret = cli:readmulti(list)
    if ok then
        ret = {}
        for k, item in pairs(list) do
            local val = unpack[k](item.value)
            table.insert(ret, val)
        end
        return ok, ret
    else
        return ok, ret
    end
end

function write(arg)
    local t = arg[1]
    local v = arg[2]
    local p = handle[t].write(v)
    return cli:write(p)
end

function on_conf(conf)
    cli = client.new(conf.transport)
    reg_cmd()
    local area = "DB"
    handle.bool = data(area, 21, 0, "bool", 3)
    handle.string = data(area, 21, 0, "string", 10)
    handle.byte = data(area, 21, 0, "byte")
    handle.char = data(area, 21, 0, "char")
    handle.word = data(area, 21, 0, "word")
    handle.int = data(area, 21, 0, "int")
    handle.dword = data(area, 21, 0, "dword")
    handle.dint = data(area, 21, 0, "dint")
    handle.lword = data(area, 21, 0, "lword")
    handle.lint = data(area, 21, 0, "lint")
    handle.float = data(area, 21, 0, "float")
    handle.double = data(area, 21, 0, "double")
    return true
end
