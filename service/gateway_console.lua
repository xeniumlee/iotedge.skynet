local skynet = require "skynet"
local socket = require "skynet.socket"
local api = require "api"
local text = require("text").console
local regex = require("text").regex

local ip = "127.0.0.1"
local port = ...
local connections = 0
local max = 1
local fds = {}

local function do_dump(pf, info)
    local function dump_table(t, indent)
        local prefix = string.rep(" ", indent*2)
        for k, v in pairs(t) do
            if type(v) == "table" then
                if next(v) then
                    pf(prefix..tostring(k)..":")
                    dump_table(v, indent+1)
                else
                    pf(prefix..tostring(k)..": {}")
                end
            else
                pf(prefix..tostring(k)..": "..tostring(v))
            end
            if indent == 1 then
                pf(text.sep)
            end
        end
    end
    local t = type(info)
    if t == "string" or t == "boolean" or t == "number" then
        pf(tostring(info))
    elseif t == "table" then
        dump_table(info, 1)
    end
end

local function split_cmdline(cmdline)
    local dev, cmd, arg = cmdline:match(regex.cmd_with_table_arg)
    if dev then
        local env = {}
        local f = load("arg="..arg, "@", "t", env)
        if f then
            f()
            return dev, cmd, env.arg
        else
            return false
        end
    else
        dev, cmd, arg = cmdline:match(regex.cmd_with_arg)
        if dev then
            return dev, cmd, arg
        else
            return false
        end
    end
end

local function docmd(cmdline)
    if cmdline:match("^help") then
        return api.external_request(cmdline)
    elseif cmdline == "quit" then
        return cmdline
    else
        local dev, cmd, arg = split_cmdline(cmdline)
        if dev then
            return api.external_request(dev, cmd, arg)
        else
            return text.tip
        end
    end
end

local function console_main_loop(fd)
    local function pf(i)
        socket.write(fd, i.."\n")
    end
    local function dump(info)
        do_dump(pf, info)
    end
    dump(text.welcome)
    dump(text.sep)

    pcall(function()
        while true do
            socket.write(fd, text.prompt)
            local cmdline = socket.readline(fd, "\r\n")
            if cmdline:match(regex.valid_cmd) then
                local ok, ret = docmd(cmdline)
                if ok == true then
                    if ret ~= nil then
                        dump(ret)
                    else
                        dump(text.ok)
                    end
                    dump(text.sep)
                elseif ok == false then
                    dump(text.nok)
                    dump(ret)
                    dump(text.sep)
                elseif ok == "quit" then
                    break
                else
                    dump(ok)
                end
            end
        end
    end)
    socket.close(fd)
    fds[fd] = nil
    connections = connections - 1
end

local function auth(fd)
    socket.write(fd, text.username)
    local u = socket.readline(fd, "\r\n")
    socket.write(fd, text.password)
    local p = socket.readline(fd, "\r\n")
    return api.internal_request("auth", {u, p})
end

skynet.start(function()
    local running = true
    local listen_socket = socket.listen(ip, port)
    socket.start(listen_socket, function(fd, addr)
        if running then
            if connections < max then
                socket.start(fd)
                if auth(fd) then
                    fds[fd] = true
                    connections = connections + 1
                    skynet.fork(console_main_loop, fd)
                else
                    socket.write(fd, text.not_auth.."\n")
                    socket.close(fd)
                end
            else
                socket.start(fd)
                socket.write(fd, text.max.."\n")
                socket.close(fd)
            end
        else
            socket.close(fd)
        end
    end)
    skynet.dispatch("lua", function(_, _, cmd, ...)
        if cmd == "stop" then
            running = false
            socket.close(listen_socket)
            for fd, _ in pairs(fds) do
                socket.close(fd)
            end
        end
    end)
end)
