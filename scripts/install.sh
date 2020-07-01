#!/bin/sh
set -e

CONFIG=$1
HOST=$2
NAME=$3
TOKEN=$4
URI=$5

if [ ! -f ${CONFIG} ]; then
    echo "${CONFIG} does not exist"
    exit 1
fi

REVPLAT=$(cat PLATFORM)
REV=${REVPLAT%-*}
PLAT=${REVPLAT#*-}

if [ ${CONFIG} = "config.tb" ]; then
    if [ -z "${HOST}" ] || \
       [ -z "${NAME}" ] || \
       [ -z "${TOKEN}" ] || \
       [ -z "${URI}" ]; then
        echo "$0 <config> <host> <name> <token> <uri>"
        exit 1
    fi
    sed -i "s|SYS_ID|${NAME}|; \
            s|SYS_VERSION|${REV}|; \
            s|SYS_PLAT|${PLAT}|; \
            s|SYS_HOST|${HOST}|; \
            s|MQTT_ID|${NAME}|; \
            s|MQTT_USERNAME|${TOKEN}|; \
            s|MQTT_URI|${URI}|" ${CONFIG}
elif [ ${CONFIG} = "config.local" ]; then
    sed -i "s|SYS_VERSION|${REV}|; \
            s|SYS_PLAT|${PLAT}|" ${CONFIG}
fi


sed -i "s|config|${CONFIG}|" iotedge.config.prod

install() {
    local UNIT_FILE=/etc/systemd/system/$2
    cp -f $1 ${UNIT_FILE}
    sed -i "s|WORKING_DIR|${PWD}|g" ${UNIT_FILE}
}

CORE_SERVICE=iotedge-${REV}.service
NODE_SERVICE=nodeexporter.service
FRP_SERVICE=frpc.service
VPN_SERVICE=vpn.service

install ./scripts/iotedge.service ${CORE_SERVICE}
install ./app/host/${NODE_SERVICE} ${NODE_SERVICE}
install ./app/frp/${FRP_SERVICE} ${FRP_SERVICE}
install ./app/vpn/${VPN_SERVICE} ${VPN_SERVICE}

systemctl daemon-reload
systemctl enable ${CORE_SERVICE}
systemctl restart ${CORE_SERVICE}
