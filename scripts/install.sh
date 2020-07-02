#!/bin/sh
set -e

install() {
    local UNIT_FILE=/etc/systemd/system/$2
    cp -f $1/$2 ${UNIT_FILE}
    sed -i "s|WORKING_DIR|${PWD}|g" ${UNIT_FILE}
}

start() {
    local CORE_SERVICE=iotedge.service
    local NODE_SERVICE=nodeexporter.service
    local FRP_SERVICE=frpc.service
    local VPN_SERVICE=vpn.service

    install ${ROOT}/scripts ${CORE_SERVICE}
    install ${ROOT}/sys/host ${NODE_SERVICE}
    install ${ROOT}/sys/frp ${FRP_SERVICE}
    install ${ROOT}/sys/vpn ${VPN_SERVICE}

    systemctl daemon-reload
    systemctl enable ${CORE_SERVICE}
    systemctl restart ${CORE_SERVICE}
}

ROOT=$(dirname $0)/..
LUA=${ROOT}/bin/prebuilt/lua

RET=$(${LUA} ${ROOT}/scripts/configure.lua $@)

if [ "${RET}" = "ok" ]; then
    start
    echo "done"
else
    echo ${RET}
    exit 1
fi
