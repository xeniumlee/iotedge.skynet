#!/bin/sh
set -e

clean_svc() {
    local SVC=$1
    systemctl stop ${SVC}
    systemctl disable ${SVC}
}

clean_svc system-agent.service
clean_svc docker.service
clean_svc containerd.service
clean_svc openvpn.service
clean_svc cgmanager.service
clean_svc cgproxy.service
clean_svc rpcbind.service
clean_svc rsync.service
clean_svc lightdm.service
systemctl daemon-reload

if [ -f /usr/sbin/cell_mgmt ]; then
    sed -i "/^cell_mgmt/d; /exit/i cell_mgmt start APN=internet" /etc/rc.local
    chmod +x /etc/rc.local
fi
if [ -d /var/lib/docker ]; then
    rm -rf /var/lib/docker
fi

# Update
apt-get update && apt-get -y upgrade && apt-get -y install telnet rlwrap arping
