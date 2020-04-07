local skynet = require "skynet"
local api = require "api"
local client = require "s7.client"

local cli
local cmd_desc = {
    info = "Show info",
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
    local item = {}
    item.area = 0x84
    item.dbnumber = arg.db
    item.start = arg.addr
    item.amount = arg.amount
    item.wordlen = 0x02
    local ok, ret = cli:read(item)
    if ok then
        local fmt = string.rep("B", arg.amount)
        ret = { string.unpack(fmt, ret) }
        table.remove(ret)
        return ok, ret
    else
        return ok, ret
    end
end

function write(arg)
    local item = {}
    item.area = 0x84
    item.dbnumber = arg.db
    item.start = arg.addr
    item.amount = arg.amount
    item.wordlen = 0x02
    local t = {}
    for i=1, arg.amount do
        table.insert(t, arg.value)
    end
    local fmt = string.rep("B", arg.amount)
    item.data = string.pack(fmt, table.unpack(t))
    return cli:write(item)
end

function on_conf(conf)
    cli = client.new(conf)
    reg_cmd()
end
