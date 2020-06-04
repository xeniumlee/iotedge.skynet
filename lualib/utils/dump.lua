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
        return "'"..string.gsub(value, "\n", "\\n").."'"
    end
end

local function dump_table(t, indent, lines)
    local prefix = srep(' ', indent*4)
    for k, v in pairs(t) do
        if type(v) == "table" then
            tinsert(lines, prefix..print_k(k)..'{')
            dump_table(v, indent+1, lines)
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

return function(tbl)
    if type(tbl) == "table" then
        local lines = {}
        dump_table(tbl, 0, lines)
        return table.concat(lines, '\n')
    else
        return tostring(tbl)
    end
end
