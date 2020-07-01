#!/bin/sh
set -e

DIR=$1
CONFIG=$2
PORT=$3

REVPLAT=$(cat PLATFORM)
REV=${REVPLAT%-*}
PLAT=${REVPLAT#*-}

mkdir -p ./run
rm -rf ./run/*
cp -rf ${DIR}/run/db ./run/
if [ -f ${DIR}/run/frpc.ini ]; then
    cp -f ${DIR}/run/frpc.ini ./run/
fi

LUA=$(dirname $0)/../skynet/3rd/lua/lua

if [ ${CONFIG} = "config.tb" ]; then
    STAT="local env = {} \
          loadfile('${DIR}/${CONFIG}', 't', env)() \
          local conf = env.sysapp.mqtt.conf
          print(string.format('%s %s %s %s', \
                              env.sys.host, \
                              conf.id, \
                              conf.uri, \
                              conf.username))"
    RET=$(${LUA} -e "${STAT}")
    HOST=$(echo $RET | cut -f1 -d' ')
    NAME=$(echo $RET | cut -f2 -d' ')
    URI=$(echo $RET | cut -f3 -d' ')
    TOKEN=$(echo $RET | cut -f4 -d' ')

    sed -i "s|SYS_VERSION|${REV}|; \
            s|SYS_PLAT|${PLAT}|; \
            s|30002|${PORT}|; \
            s|SYS_HOST|${HOST}|; \
            s|SYS_ID|${NAME}|; \
            s|MQTT_ID|${NAME}|; \
            s|MQTT_USERNAME|${TOKEN}|; \
            s|MQTT_URI|${URI}|" ${CONFIG}
elif [ ${CONFIG} = "config.local" ]; then
    sed -i "s|SYS_VERSION|${REV}|; \
            s|SYS_PLAT|${PLAT}|; \
            s|30002|${PORT}|" ${CONFIG}
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
install ./sys/host/${NODE_SERVICE} ${NODE_SERVICE}
install ./sys/frp/${FRP_SERVICE} ${FRP_SERVICE}
install ./sys/vpn/${VPN_SERVICE} ${VPN_SERVICE}

systemctl daemon-reload
systemctl enable ${CORE_SERVICE}
systemctl restart ${CORE_SERVICE}
