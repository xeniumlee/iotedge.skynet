-- DOC: https://github.com/cloudwu/skynet/wiki/Socket
local sockethelper = require "http.sockethelper"
local skynet = require "skynet"
local regex = require("text").regex

local M = {}

local function init(conn, socket_id)
    if conn.secure then
        local tls = require "http.tlshelper"
        local ctx = tls.newctx()
        local cert = conn.secure_params.certificate
        local key = conn.secure_params.key
        if cert and key then
            ctx:set_cert(cert, key)
        end
        local tls_ctx = tls.newtls("client", ctx)
        tls.init_requestfunc(socket_id, tls_ctx)()

        conn.close = function ()
            sockethelper.close(socket_id)
            tls.closefunc(tls_ctx)()
        end
        conn.read = tls.readfunc(socket_id, tls_ctx)
        conn.write = tls.writefunc(socket_id, tls_ctx)
        conn.readall = tls.readallfunc(socket_id, tls_ctx)
    else
        conn.close = function ()
            sockethelper.close(socket_id)
        end
        conn.read = sockethelper.readfunc(socket_id)
        conn.write = sockethelper.writefunc(socket_id)
        conn.readall = function ()
            return sockethelper.readall(socket_id)
        end
    end

    if conn.websocket then
        local ws = require "mqtt.wshelper"
        local mqtt_header = { ["Sec-Websocket-Protocol"] = "mqtt" }
        ws.write_handshake(conn, conn.ws_host, conn.ws_uri, mqtt_header)

        conn.send = ws.sendfunc(conn)
        conn.receive = ws.receivefunc(conn)
        conn.shutdown = ws.shutdownfunc(conn)
    else
        conn.send = conn.write
        conn.receive = conn.read
        conn.shutdown = conn.close
    end
end

local function parse_uri(conn)
    -- try websocket first
    local protocol, host, uri = conn.uri:match(regex.websocket)
    if protocol and not host then
        error(string.format("invalid uri: %s", conn.uri))
    end
    if not protocol then
        host = conn.uri
    end

    local hostname, port = host:match(regex.host_port)
    if not hostname then
        error(string.format("invalid uri: %s", conn.uri))
    end

    -- port
    if port == "" then
        if protocol then
            if protocol == "ws" then
                port = 80
            else
                port = 443
            end
        else
            if conn.secure then
                port = 8883
            else
                port = 1883
            end
        end
    else
        port = tonumber(port)
    end
    conn.port = port

    -- dns
    local ip = require("sys").resolve(hostname)
    if ip then
        conn.host = ip
    else
        error("cannot resolve uri")
    end

    -- websocket
    if protocol then
        conn.websocket = true
        conn.ws_host = hostname
        conn.ws_uri = uri == "" and "/" or uri
        -- force secure
        if protocol == "wss" and not conn.secure then
            conn.secure = true
        end
        if protocol == "ws" then
            conn.secure = false
        end
    end
end

function M.connect(conn)
    local ok, err = pcall(function()
        -- Do DNS anyway
        parse_uri(conn)

        local timeout = 500
        local socket_id = sockethelper.connect(conn.host, conn.port, timeout)

        init(conn, socket_id)
    end)
    if ok then
        return ok
    else
        return ok, tostring(err)
    end
end

function M.shutdown(conn)
    local ok, err = pcall(conn.shutdown)
    if not ok then
        skynet.error(err)
    end
end

function M.send(conn, data)
    local ok, err = pcall(conn.send, data)
    if not ok then
        skynet.error(err)
    end
    return ok
end

function M.receive(conn, size)
    local ok, data = pcall(conn.receive, size)
    if ok then
        if data then
            return data
        else
            return false, "closed"
        end
    else
        return false, tostring(data)
    end
end

return M
