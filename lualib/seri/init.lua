--- https://eng.uber.com/trip-data-squeeze/
local impl = nil
local zlib = require("zlib")

local seri = {}

function seri.init(opt)
    if opt == "msgpack" then
        impl = require("seri.MessagePack")
        impl.set_number("float")
        impl.set_string("string")
    elseif opt == "json" then
        impl = require("cjson")
    else
        error("Not supported")
    end
end

function seri.pack(data)
    local ok, value = pcall(impl.encode, data)
    if ok then
        return value
    else
        return nil
    end
end

function seri.unpack(data)
    local ok, value = pcall(impl.decode, data)
    if ok then
        return value
    else
        return nil
    end
end

function seri.zpack(data)
    local ok, value = pcall(impl.encode, data)
    if not ok then
        return nil
    end

    local deflated = zlib.deflate()(value, 'finish')
    return deflated
end

function seri.zunpack(data)
    local inflated = zlib.inflate()(data)
    if not inflated then
        return nil
    end

    local ok, value = pcall(impl.decode, inflated)
    if ok then
        return value
    else
        return nil
    end
end

-- export module table
return setmetatable({}, {
  __index = seri,
  __newindex = function(t, k, v)
                 error("Attempt to modify read-only table")
               end,
  __metatable = false
})
