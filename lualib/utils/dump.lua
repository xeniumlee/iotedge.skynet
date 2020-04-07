local tinsert = table.insert
local srep = string.rep

local function print_k(key)
    if type(key) == "number" then
        return "["..key.."] = "
    else
        if key:match("^%d.*") or key:match("[^_%w]+") then
            return "['"..key.."'] = "
        else
            return key.." = "
        end
    end
end

local function print_v(value)
    if type(value) == "boolean" or type(value) == "number" then
        return tostring(value)
    else
        return "'"..value.."'"
    end
end

return function(tbl)
    local lines = {}
    local function dump_table(t, indent)
        local prefix = srep(' ', indent*4)
        for k, v in pairs(t) do
            if type(v) == "table" then
                tinsert(lines, prefix..print_k(k)..'{')
                dump_table(v, indent+1)
                if indent == 0 then
                    tinsert(lines, prefix..'}')
                else
                    tinsert(lines, prefix..'},')
                end
            else
                tinsert(lines, prefix..print_k(k)..print_v(v)..',')
            end
        end
    end
    dump_table(tbl, 0)
    return table.concat(lines, '\n')
end
