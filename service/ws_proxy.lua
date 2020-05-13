local skynet = require "skynet"
local socket = require "skynet.socket"
local socketchannel = require "skynet.socketchannel"
local websocket = require "http.websocket"
local log = require "log"
local text = require("text").wsproxy
local dump = require "utils.dump"

local ip = "127.0.0.1"
local port = ...
local timeout = 50 -- 0.5 second

local protocol = "ws"
local fds = {}

local err = {
    stopped = { code = 4000, reason = "server stopped" },
    notarget = { code = 4001, reason = "unknown target" },
}

local function close(fd, e)
    fds[fd] = nil
    websocket.close(fd, e.code, e.reason)
end

local function close_all()
    for fd, _ in pairs(fds) do
        close(fd, err.stopped)
    end
end

local function handle_resp(so)
    return true, socket.read(so)
end

local handle = {}
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
    local h, p = url:match("^.+target/([%d%.]+):(%d+)$")
    if h and p then
        log.info(text.handshake, h, p, dump(header))

        local ch = socketchannel.channel {
            host = h,
            port = p,
            nodelay = true
        }
        fds[fd] = ch
    else
        log.error(text.invalid_target, url, dump(header))
        close(fd, err.notarget)
    end
end

function handle.close(fd, code, reason)
    log.info(text.closed, tostring(code), reason)
end

function handle.message(fd, msg)
    local ch = fds[fd]
    if not ch then
        log.error(text.invalid_request)
        close(fd, err.notarget)
        return
    end

    local ok, resp, drop
    local co = coroutine.running()
    skynet.fork(function()
        ok, resp = pcall(ch.request, ch, msg, handle_resp)
        if not drop then
            skynet.wakeup(co)
        end
    end)
    skynet.sleep(timeout)
    if resp then
        if ok then
            websocket.write(fd, resp)
        else
            log.error(text.target_error, ch.__host, ch.__port)
        end
    else
        drop = true
        log.error(text.target_timeout, ch.__host, ch.__port)
    end
end

skynet.start(function()
    local running = true
    local listen_socket = socket.listen(ip, port)

    socket.start(listen_socket, function(fd, addr)
        if running then
            fds[fd] = false
            skynet.fork(websocket.accept, fd, handle, protocol, addr)
        else
            socket.close(fd)
        end
    end)
    skynet.dispatch("lua", function(_, _, cmd, ...)
        if cmd == "stop" then
            running = false
            socket.close(listen_socket)
            close_all()
        end
    end)
end)
