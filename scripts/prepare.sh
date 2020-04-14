#!/bin/sh
set -e

TIMEZONE="Asia/Shanghai"
NTPSERVER="ntp1.aliyun.com ntp2.aliyun.com ntp3.aliyun.com ntp4.aliyun.com"
TIMESYNCD_CONF=/etc/systemd/timesyncd.conf

sed -i "|^NTP=|d; |^[Time]|a NTP=${NTPSERVER}" ${TIMESYNCD_CONF}

timedatectl set-timezone ${TIMEZONE}

systemctl restart systemd-timesyncd

apt-get update && sudo apt-get -y upgrade
