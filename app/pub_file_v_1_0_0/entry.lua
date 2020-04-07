local api = require "api"
local tinsert = table.insert

local f = false

function on_data(dev, data)
    if f then
        local t = {}
        for _, d in ipairs(data) do
            tinsert(t, "\ntime: "..api.datetime(math.floor(api.ts_value(d)/1000)))
            local vlist = api.data_value(d)
            for k, v in pairs(vlist) do
                tinsert(t, " "..k..": "..v)
            end
        end
        f:write(table.concat(t, "\n"))
        f:flush()
    end
end

function on_conf(conf)
    if f then
        f:close()
    end
    f = io.open(conf.file, "a")
    return true
end

function on_exit()
    if f then
        f:close()
    end
end
