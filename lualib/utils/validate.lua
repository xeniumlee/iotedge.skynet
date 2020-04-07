local function validate(t, schema)
    for k, f in pairs(schema) do
        if type(f) == "function" then
            assert(f(t[k]))
        else
            validate(t[k], schema[k])
        end
    end
end

return validate
