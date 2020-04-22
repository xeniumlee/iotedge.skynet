#!/bin/sh
set -e

DIR=$1
CONFIG=$2
PORT=$3

REVPLAT=$(cat PLATFORM)
REV=${REVPLAT%-*}

cp -f $DIR/${CONFIG} ./
cp -rf $DIR/db ./
if [ -f $DIR/run/frpc.ini ]; then
    mkdir run
    cp -f $DIR/run/frpc.ini ./run/
fi

sed -i "s|.*release.*|    release = '${REV}',|; \
        s|.*cluster.*|    cluster = ${PORT},|" ${CONFIG}


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
