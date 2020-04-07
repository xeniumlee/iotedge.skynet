local httpc = require "http.httpc"
local sys = require "sys"
local regex = require("text").regex

local t = 3000 -- 30s
local http = {}

function http.get(uri, auth, timeout)
    local protocol, hostname, port = uri:match(regex.http_host_port)
    if protocol then
        local ip = sys.resolve(hostname)
        if ip then
            local host
            if port ~= "" then
                host = protocol..ip..":"..port
            else
                host = protocol..ip
            end

            local header
            if type(auth) == "table" then
                header = {}
                for k, v in pairs(auth) do
                    header[k] = v
                end
            end

            local ok, code, body = pcall(httpc.get, host, uri, nil, header)
            if timeout then
                httpc.timeout = timeout
            else
                httpc.timeout = t
            end
            if ok and code == 200 and body then
                httpc.timeout = t
                return body
            else
                httpc.timeout = t
                return false
            end
        else
            return false
        end
    else
        return false
    end
end

return http
