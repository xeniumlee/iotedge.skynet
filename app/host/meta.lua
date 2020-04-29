conf = {
    common = {
        node_memory_MemAvailable_bytes = {
            t = 'gauge',
            p = 'node_memory_MemAvailable_bytes%s+([^\n]+)\n'
        },
        node_memory_MemTotal_bytes = {
            t = 'gauge',
            p = 'node_memory_MemTotal_bytes%s+([^\n]+)\n'
        },
        node_filesystem_avail_bytes = {
            t = 'gauge',
            p = 'node_filesystem_avail_bytes%g+mountpoint="/"%g+%s+([^\n]+)\n'
        },
        node_filesystem_size_bytes = {
            t = 'gauge',
            p = 'node_filesystem_size_bytes%g+mountpoint="/"%g+%s+([^\n]+)\n'
        },
        frpc = {
            t = 'gauge',
            p = 'node_systemd_unit_state{name="frpc%.service",state="active"%g+%s+([^\n]+)\n'
        },
        vpn = {
            t = 'gauge',
            p = 'node_systemd_unit_state{name="vpn%.service",state="active"%g+%s+([^\n]+)\n'
        },
        ntp = {
            t = 'gauge',
            p = 'node_systemd_unit_state{name="systemd%-timesyncd%.service",state="active"%g+%s+([^\n]+)\n'
        }
    },
    general = {
        node_cpu_seconds_total_0 = {
            t = 'counter',
            p = 'node_cpu_seconds_total{cpu="0",mode="idle"}%s+([^\n]+)\n'
        },
        node_cpu_seconds_total_1 = {
            t = 'counter',
            p = 'node_cpu_seconds_total{cpu="1",mode="idle"}%s+([^\n]+)\n'
        }
    },
    moxa = {
        operator = {
            t = 'string',
            p = 'cell_mgmt operator'
        },
        cell_type = {
            t = 'string',
            p = 'cell_mgmt signal |cut -f1 -d" "'
        },
        cell_signal = {
            t = 'string',
            p = 'cell_mgmt signal |cut -f2 -d" "'
        },
        node_cpu_seconds_total_0 = {
            t = 'counter',
            p = 'node_cpu_seconds_total{cpu="0",mode="idle"}%s+([^\n]+)\n'
        },
        node_network_transmit_bytes_total = {
            t = 'counter',
            p = 'node_network_transmit_bytes_total{device="wwan0"}%s+([^\n]+)\n'
        }
    }
}
