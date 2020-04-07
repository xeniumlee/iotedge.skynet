#!/bin/sh
set -e

REV=$(cat VERSION)
UNIT=iotedge-${REV}.service
UNIT_FILE=/etc/systemd/system/${UNIT}

systemctl stop ${UNIT}
systemctl disable ${UNIT}
rm -f ${UNIT_FILE}
systemctl daemon-reload
