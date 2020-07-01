local validator = {}

local function do_check(t, schema)
    for k, f in pairs(schema) do
        if type(f) == "function" then
            assert(f(t[k]))
        else
            do_check(t[k], schema[k])
        end
    end
end

function validator.check(t, schema)
    do_check(t, schema)
end

function validator.port(v)
    return math.tointeger(v) and v>0 and v<0xFFFF
end

function validator.ipv4(v)
    return type(v)=="string" and v:match("^[%d%.]+$")
end

function validator.httpurl(v)
    return type(v)=="string" and v:match("^https?://[%w%.%-%/]+$")
end

function validator.opcurl(v)
    return type(v)=="string" and v:match("^opc%.tcp://[%d%.]+:%d+$")
end

function validator.string(v)
    return type(v)=="string" and #v>0
end

function validator.posint(v)
    return math.tointeger(v) and v>0
end

function validator.minint(min)
    return function(v)
        return math.tointeger(v) and v>=min
    end
end

function validator.minmaxint(min, max)
    return function(v)
        return math.tointeger(v) and v>=min and v<=max
    end
end

function validator.boolean(v)
    return type(v)=="boolean"
end

function validator.number(v)
    return type(v)=="number"
end

function validator.vals(...)
    local vals = {...}
    return function(v)
        for _, val in pairs(vals) do
            if v == val then
                return true
            end
        end
        return false
    end
end

return validator
