#!/bin/sh
set -e

DIR=$1
CONFIG=$2
PORT=$3

REVPLAT=$(cat PLATFORM)
REV=${REVPLAT%-*}

cp -f $DIR/${CONFIG} ./
cp -rf $DIR/db ./

sed -i "s|.*version.*|    version = '${REV}',|; \
        s|.*cluster.*|    cluster = ${PORT},|" ${CONFIG}
sed -i "s|config.lua|${CONFIG}|" skynet.config.prod

install() {
    UNIT_FILE=/etc/systemd/system/$2
    cp -f ./scripts/$1 ${UNIT_FILE}
    sed -i "s|WORKING_DIR|${PWD}|g" ${UNIT_FILE}
}

CORE_SERVICE=iotedge-${REV}.service
NODE_SERVICE=nodeexporter.service
FRP_SERVICE=frpc.service

set +e
systemctl stop ${NODE_SERVICE}
systemctl stop ${FRP_SERVICE}
set -e
install iotedge.service ${CORE_SERVICE}
install ${NODE_SERVICE} ${NODE_SERVICE}
install ${FRP_SERVICE} ${FRP_SERVICE}

systemctl daemon-reload
#systemctl enable ${CORE_SERVICE}
systemctl restart ${CORE_SERVICE}
