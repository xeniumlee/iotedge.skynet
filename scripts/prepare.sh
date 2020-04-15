#!/bin/sh
set -e

SSHKEY=$1
TIMEZONE=$2

if [ -z "${SSHKEY}" ]; then
	echo "$0 <sshkey> <timezone>"
	exit 1
fi

# SSH
AUTHORIZED_KEYS=/root/.ssh/authorized_keys
echo ${SSHKEY} >> ${AUTHORIZED_KEYS}
chmod 600 ${AUTHORIZED_KEYS}

sed -i "/^PasswordAuthentication/d; /PasswordAuthentication/i PasswordAuthentication no" /etc/ssh/sshd_config
systemctl restart sshd

# NTP
if [ -z "${TIMEZONE}" ]; then
	TIMEZONE="Asia/Shanghai"
fi
NTPSERVER="ntp1.aliyun.com ntp2.aliyun.com ntp3.aliyun.com ntp4.aliyun.com"

if [ -f /usr/sbin/ntpd ]; then
    chmod -x /usr/sbin/ntpd
fi
systemctl stop ntp
systemctl disable ntp

sed -i "/^NTP=/d; /Time/a NTP=${NTPSERVER}" /etc/systemd/timesyncd.conf
timedatectl set-timezone ${TIMEZONE}
systemctl restart systemd-timesyncd

# /etc/resolv.conf
RESOLV_CONF=/etc/resolv.conf
systemctl stop systemd-resolved
systemctl disable systemd-resolved
rm -f ${RESOLV_CONF}
echo "nameserver 202.96.209.5" > ${RESOLV_CONF}
echo "nameserver 202.96.209.133" >> ${RESOLV_CONF}

# /etc/systemd/journald.conf
sed -i "/^Storage=/d; /Journal/a Storage=persistent" /etc/systemd/journald.conf
systemctl restart systemd-journald
systemctl stop rsyslog

# Moxa
if [ -f /usr/sbin/cell_mgmt ]; then
    sed -i "/exit/i cell_mgmt start APN=internet" /etc/rc.local
    chmod +x /etc/rc.local
fi

# Clean
clean_svc() {
    SVC=$1
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
systemctl daemon-reload

# Update
apt-get update && sudo apt-get -y upgrade

# Restart
reboot
