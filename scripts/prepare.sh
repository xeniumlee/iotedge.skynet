#!/bin/sh
set -e

SSHKEY=$1

if [ -n "${SSHKEY}" ]; then
    AUTHORIZED_KEYS=/root/.ssh/authorized_keys
    echo ${SSHKEY} >> ${AUTHORIZED_KEYS}
    chmod 600 ${AUTHORIZED_KEYS}

    sed -i "/^PasswordAuthentication/d; /PasswordAuthentication/i PasswordAuthentication no" /etc/ssh/sshd_config
    systemctl restart sshd
fi

# NTP
if [ -f /usr/sbin/ntpd ]; then
    chmod -x /usr/sbin/ntpd
fi
systemctl stop ntp
systemctl disable ntp

TIMEZONE="Asia/Shanghai"
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
systemctl stop rsyslog
