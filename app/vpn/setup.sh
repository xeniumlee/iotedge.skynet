#!/bin/sh

cmd=$1
eth=${2}

br=br0
tap=tap0
vpn=openvpn

install_vpn() {
    which $vpn >/dev/null 2>&1
    if [ $? -ne 0 ]; then
        apt-get -y -q install $vpn
    fi
    which $vpn >/dev/null 2>&1
    if [ $? -ne 0 ]; then
        exit 1
    fi
}

setup_eth() {
    ip link show $eth >/dev/null 2>&1
    if [ $? -ne 0 ]; then
        exit 1
    fi
    ip link set $eth up

    eth_ip=$(ip -4 addr show $eth |grep -Po 'inet \K[\d./]+')
}

setup_tap() {
    ip link show $tap >/dev/null 2>&1
    if [ $? -ne 0 ]; then
        openvpn --mktun --dev $tap >/dev/null 2>&1
    fi
    ip link set $tap up
}

init_bridge() {
    # https://www.spinics.net/lists/linux-omap/msg145772.html
    echo 3 > /sys/class/net/$br/bridge/default_pvid
    ip addr add $eth_ip dev $br
    ip addr del $eth_ip dev $eth
    ip link set $br up

    ip link set $eth master $br
    ip link set $tap master $br
}

setup_bridge() {
    ip link show $br >/dev/null 2>&1
    if [ $? -ne 0 ]; then
        if [ -n "$eth_ip" ]; then
            ip link add $br type bridge
            init_bridge
        else
            exit 1
        fi
    else
        if [ -n "$eth_ip" ]; then
            ip link del $br
            ip link add $br type bridge
            init_bridge
        else
            eth_ip=$(ip -4 addr show $br |grep -Po 'inet \K[\d./]+')
            if [ -n "$eth_ip" ]; then
                ip link del $br
                ip link add $br type bridge
                init_bridge
            else
                exit 1
            fi
        fi
    fi
}

if [ ${cmd} = "start" ]; then

    install_vpn
    setup_tap
    setup_eth
    setup_bridge
    cp -f app/vpn/vpn.conf run/
    echo -n $eth_ip

elif [ ${cmd} = "stop" ]; then

    ip link show $br >/dev/null 2>&1
    if [ $? -eq 0 ]; then
        eth_ip=$(ip -4 addr show $br |grep -Po 'inet \K[\d./]+')
        ip link del $br
        if [ -n "$eth_ip" ]; then
            ip link show $eth >/dev/null 2>&1
            if [ $? -eq 0 ]; then
                ip addr add $eth_ip dev $eth
            fi
        fi
    fi
    openvpn --rmtun --dev $tap >/dev/null 2>&1
fi
