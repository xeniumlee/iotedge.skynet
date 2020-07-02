#!/bin/sh
set -e

UNIT=iotedge.service
UNIT_FILE=/etc/systemd/system/${UNIT}

systemctl disable ${UNIT}
rm -f ${UNIT_FILE}
systemctl daemon-reload
systemctl stop ${UNIT}
