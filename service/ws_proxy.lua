local skynet = require "skynet"
local socket = require "skynet.socket"
local sockethelper = require "http.sockethelper"
local websocket = require "http.websocket"
local log = require "log"
local text = require("text").wsproxy
local dump = require "utils.dump"

local listen_ip = "127.0.0.1"
local listen_port = ...

if listen_port == "agent" then

local ws_err = {
    socket_error = { code = 4000, reason = "socket_error" },
    no_target = { code = 4001, reason = "unknown target" },
    target_offline = { code = 4002, reason = "can't connect to target" },
}

local fds = {}
local handle = {}

local function close_target(fd)
    local t = fds[fd]
    if t then
        t.close()
        fds[fd] = nil
    end
end

local function close(fd, e)
    websocket.close(fd, e.code, e.reason)
    close_target(fd)
end

local function do_proxy(fd, host, port, fmt)
    local timeout = 500
    local ok, id = pcall(sockethelper.connect, host, port, timeout)
    if ok then
        local target = {
            host = host,
            port = port,
            write = sockethelper.writefunc(id),
            read = sockethelper.readfunc(id),
            close = function () sockethelper.close(id) end
        }
        fds[fd] = target
        while true do
            local msg
            ok, msg = pcall(target.read)
            if ok then
                ok = pcall(websocket.write, fd, msg, fmt)
                if not ok then
                    log.error(text.target_error, err)
                end
            else
                log.error(text.error, err)
                close(fd, ws_err.socket_error)
                break
            end
        end
    else
        log.error(text.target_offline, host, port)
        close(fd, ws_err.target_offline)
    end
end

function handle.connect(fd)
    log.info(text.connect, tostring(fd))
end
function handle.error(fd)
    log.error(text.error, tostring(fd))
end
function handle.ping(fd)
end
function handle.pong(fd)
end

function handle.handshake(fd, header, url)
    local h, p, fmt = url:match("^.+target/([%d%.]+):(%d+)%?fmt=([^&]+)$")
    if h and p and (fmt == "text" or fmt == "binary") then
        log.info(text.handshake, h, p, dump(header))
        skynet.fork(do_proxy, fd, h, p, fmt)
    else
        log.error(text.invalid_url, url, dump(header))
        close(fd, ws_err.no_target)
    end
end

function handle.close(fd, code, reason)
    log.info(text.closed, tostring(code), reason)
    close_target(fd)
end

function handle.message(fd, msg)
    local t = fds[fd]
    if not t then
        log.error(text.invalid_request)
        close(fd, ws_err.no_target)
        return
    end
    local ok, err = pcall(t.write, msg)
    if not ok then
        log.error(text.target_error, err)
        close(fd, ws_err.socket_error)
    end
end

skynet.start(function ()
    skynet.dispatch("lua", function (_, _, fd, protocol, addr)
        local ok, err = websocket.accept(fd, handle, protocol, addr)
        if not ok then
            log.error(text.error, tostring(fd), err)
        end
    end)
end)

else

skynet.start(function()
    local agent = {}
    for i= 1, 5 do
        agent[i] = skynet.newservice(SERVICE_NAME, "agent")
    end

    local running = true
    local balance = 1
    local protocol = "ws"
    local listen_socket = socket.listen(listen_ip, listen_port)

    socket.start(listen_socket, function(fd, addr)
        if running then
            skynet.send(agent[balance], "lua", fd, protocol, addr)
            balance = balance + 1
            if balance > #agent then
                balance = 1
            end
        else
            socket.close(fd)
        end
    end)
    skynet.dispatch("lua", function(_, _, cmd, ...)
        if cmd == "stop" then
            running = false
            socket.close(listen_socket)
        end
    end)
end)

end
