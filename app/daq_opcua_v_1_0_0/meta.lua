conf = {
    transport = {
        url = '',
        namespace = '',
        username = '',
        password = '',
        model = 'S7_PLC_1200_1500'
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
                    node = '', -- "node id"
                    poll = 2000,  -- optional, inherit from device, valid for mode "ts" "attr"
                    cov = false,   -- optional, valid for mode "ts" "attr"
                    gain = 1,     -- optional, valid for mode "ts" "attr"
                    offset = 0    -- optional, valid for mode "ts" "attr"
                }
            }
        }
    }
}
