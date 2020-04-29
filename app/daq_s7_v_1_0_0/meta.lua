conf = {
    transport = {
        host = '',
        rack = 0,
        slot = 0,
        model = 'S7_PLC_1200_1500' -- S7_PLC_300_400
    },
    devices = {
        d1 = {
            attr_poll = 2000, -- ms
            ts_poll = 1000,   -- ms
            batch = 1,        -- optional, integer
            retention = 1,    -- optional, day
            tags = {
                t1 = {
                    mode = 'ts',  -- "ts" "attr" "ctrl"
                    area = 'DB', -- "PE" "PA" "MK" "TM" "CT"
                    addr = 0,
                    dbnumber = 1,
                    dt = 'int',  -- "byte" "char" "word" "int" "dword" "dint" "lword" "lint" "string" "float" "double" "bool"
                    opt = 1,      -- optional, valid for "bool"(0-7), or "string"(length)
                    poll = 2000,  -- optional, inherit from device, valid for mode "ts" "attr"
                    cov = false,   -- optional, valid for mode "ts" "attr"
                    gain = 1,     -- optional, valid for mode "ts" "attr"
                    offset = 0    -- optional, valid for mode "ts" "attr"
                }
            }
        }
    }
}
