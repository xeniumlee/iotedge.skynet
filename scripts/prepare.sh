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

# NTP
if [ -z "${TIMEZONE}" ]; then
	TIMEZONE="Asia/Shanghai"
fi

NTPSERVER="ntp1.aliyun.com ntp2.aliyun.com ntp3.aliyun.com ntp4.aliyun.com"

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

# Update
apt-get update && sudo apt-get -y upgrade
