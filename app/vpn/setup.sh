#!/bin/sh

cmd=$1
eth=${2}
eth_ip=${3}

br="br0"
tap="tap0"

if [ ${cmd} = "start" ]; then
    openvpn --mktun --dev $tap

    ip link add $br type bridge
    # https://www.spinics.net/lists/linux-omap/msg145772.html
    echo 3 > /sys/class/net/$br/bridge/default_pvid
    ip link set $eth master $br
    ip link set $tap master $br
    ip addr del $eth_ip dev $eth
    ip addr add $eth_ip dev $br

    ip link set $eth up
    ip link set $tap up
    ip link set $br up

elif [ ${cmd} = "stop" ]; then
    ip link del $br
    openvpn --rmtun --dev $tap
    ip addr add $eth_ip dev $eth
fi
