#!/bin/sh
set -e

ROOT=$(dirname $0)/..
REVPLAT=$(cat ${ROOT}/PLATFORM)
REV=${REVPLAT%-*}
UNIT=iotedge-${REV}.service
UNIT_FILE=/etc/systemd/system/${UNIT}

systemctl disable ${UNIT}
rm -f ${UNIT_FILE}
systemctl daemon-reload
systemctl stop ${UNIT}
