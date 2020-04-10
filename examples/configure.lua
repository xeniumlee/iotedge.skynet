daq_modbus_v_1_0_0_2 = {      -- repo, frp, existing application name
    devices = {
        d1 = {
            unitid = 1,
            attr_poll = 2000, -- ms
            ts_poll = 1000,   -- ms
            batch = 1,        -- optional, integer
            retention = 1,    -- optional, day
            le = false,       -- word order
            tags = {
                t1 = {
                    mode = 'ts',  -- "ts" "attr" "ctrl"
                    fc = 3,
                    addr = 0,
                    number = 2,
                    dt = 'uint',  -- "int" "uint" "string" "float" "boolean"
                    bit = 1,      -- optional, valid for "boolean"
                    poll = 2000,  -- optional, inherit from device, valid for mode "ts" "attr"
                    le = true,    -- optional, inherit from device
                    cov = true,   -- optional, valid for mode "ts" "attr"
                    gain = 1,     -- optional, valid for mode "ts" "attr"
                    offset = 0    -- optional, valid for mode "ts" "attr"
                },
                t2 = {
                    mode = 'ts',  -- "ts" "attr" "ctrl"
                    fc = 3,
                    addr = 2,
                    number = 4,
                    dt = 'uint',  -- "int" "uint" "string" "float" "boolean"
                }
            }
        }
    }
}
