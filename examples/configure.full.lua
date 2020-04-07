repo = {
    auth = "",
    uri = ""
}
apps = {
    [1] = { host_v_1_0_0 = {} },
    [2] = { daq_modbus_v_1_0_0 = {
            transport = {
                ascii = false,    -- optional, default false
                le = false,       -- byte order
                timeout = 500,    -- response timeout, ms
                mode = 'tcp',     -- "tcp" "rtu" "rtu_tcp"
                tcp = {
                    host = '',
                    port = 30000,
                },
                rtu = {
                    port = '',
                    baudrate = 19200,
                    mode = 'rs232',    -- "rs232" "rs485"
                    databits = 8,
                    parity = 'none',   -- "none" "odd" "even"
                    stopbits = 1,
                    rtscts = false,    -- hardware flow control
                    r_timeout = 300,   -- response timeout, ms
                    b_timeout = 300    -- byte timeout, ms
                }
            },
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
                        }
                    }
                }
            }
        }}
}
pipes = {
    [1] = {
        apps = { 1, "mqtt" },
        auto = true
    },
    [2] = {
        apps = { 2, "mqtt" },
        auto = false
    }
}
