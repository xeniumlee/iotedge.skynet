#!/bin/sh
set -e

ROOT=$(dirname $0)/..
LUA=${ROOT}/bin/prebuilt/lua
RET=$(${LUA} ${ROOT}/scripts/configure.lua $@)

install() {
    local UNIT_FILE=/etc/systemd/system/$2
    cp -f $1 ${UNIT_FILE}
    sed -i "s|WORKING_DIR|${PWD}|g" ${UNIT_FILE}
}

start() {
    local REVPLAT=$(cat ${ROOT}/PLATFORM)
    local REV=${REVPLAT%-*}

    local CORE_SERVICE=iotedge-${REV}.service
    local NODE_SERVICE=nodeexporter.service
    local FRP_SERVICE=frpc.service
    local VPN_SERVICE=vpn.service

    install ${ROOT}/scripts/iotedge.service ${CORE_SERVICE}
    install ${ROOT}/sys/host/${NODE_SERVICE} ${NODE_SERVICE}
    install ${ROOT}/sys/frp/${FRP_SERVICE} ${FRP_SERVICE}
    install ${ROOT}/sys/vpn/${VPN_SERVICE} ${VPN_SERVICE}

    systemctl daemon-reload
    systemctl restart ${NODE_SERVICE}
    systemctl restart ${VPN_SERVICE}
    systemctl restart ${FRP_SERVICE}

    systemctl enable ${CORE_SERVICE}
    systemctl restart ${CORE_SERVICE}
}

if [ "${RET}" = "ok" ]; then
    start
    echo "done"
else
    echo ${RET}
    exit 1
fi
