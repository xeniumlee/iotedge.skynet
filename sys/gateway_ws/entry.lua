local skynet = require "skynet"
local socket = require "skynet.socket"
local api = require "api"
local websocket = require "http.websocket"

local seri = require "seri"
local log = require "log"
local text = require("text").console

local ip = "127.0.0.1"
local running = false
local auth_enabled = true

local listen_socket = false
local connected = false
local authed = false
local count = 0

local function decode_auth(msg)
    local auth = seri.unpack(msg)
    if type(auth) ~= "table" or
        type(auth.user) ~= "string" or
        type(auth.pass) ~= "string" then
        return false
    end
    return auth.user, auth.pass
end

local function auth_respond(fd, suc)
    local payload
    if suc then
        payload = seri.pack(text.welcome)
    else
        payload = seri.pack(text.not_auth)
    end
    if payload then
        websocket.write(fd, payload)
    end
end

local function decode_request(msg)
    local request = seri.unpack(msg)
    if type(request) ~= "table" or
        type(request.dev) ~= "string" or
        type(request.cmd) ~= "string" then
        return false
    end
    return request.dev, request.cmd, request.arg
end

local function do_respond(fd, dev, cmd, ret)
    local response = {
        dev = dev,
        cmd = cmd,
        ret = ret
    }
    local payload = seri.pack(response)
    if payload then
        websocket.write(fd, payload)
    end
end

local handle = {}

function handle.connect(fd)
end
function handle.ping(fd)
end
function handle.pong(fd)
end
function handle.error(fd)
end
function handle.handshake(fd, header, url)
end

function handle.close(fd, code, reason)
    count = 0
    connected = false
    authed = false
    websocket.close(fd)
    log.info("ws closed:", fd, code, reason)
end

function handle.message(fd, msg)
    if auth_enabled and not authed then
        local user, pass = decode_auth(msg)
        if user then
            authed = api.internal_request("auth", {user, pass})
        end
        auth_respond(fd, authed)
        if authed then
            count = 0
        else
            count = count + 1
            if count >= 3 then
                websocket.write(fd, text.closed)
                handle.close(fd)
            end
        end
    else
        if msg:match("^help") then
            local h = api.external_request(msg)
            local payload = seri.pack(h)
            if payload then
                websocket.write(fd, payload)
            end
        else
            local dev, cmd, arg = decode_request(msg)
            if dev then
                local ok, ret = api.external_request(dev, cmd, arg)
                if ret then
                    do_respond(fd, dev, cmd, { ok, ret })
                else
                    do_respond(fd, dev, cmd, ok)
                end
            else
                websocket.write(fd, text.tip)
            end
        end
    end
end

function on_data(dev, data)
    if connected and authed and
        type(dev) == "string" and type(data) == "table" then
        local payload = seri.pack({[dev] = data})
        if payload then
            websocket.write(connected, payload)
        end
    end
end

function on_exit()
    running = false
    socket.close(listen_socket)
    websocket.close(connected)
end

function on_conf(conf)
    running = true
    auth_enabled = conf.auth_enabled
    seri.init("json")
    listen_socket = socket.listen(ip, conf.port)

    socket.start(listen_socket, function(fd, addr)
        if running and not connected then
            connected = fd
            skynet.fork(websocket.accept, fd, handle, "ws", addr)
        else
            socket.close(fd)
        end
    end)
    return true
end
