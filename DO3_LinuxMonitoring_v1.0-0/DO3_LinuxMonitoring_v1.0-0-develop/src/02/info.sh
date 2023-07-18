#!/bin/bash

HOSTNAME=$(hostname -s)
echo HOSTNAME = $HOSTNAME

TIMEZONE_COUNTRY=$(timedatectl|grep -E 'Time zone'|awk '{print $3}')
TIMEZONE_CITY=$(timedatectl|grep -E 'Time zone'|awk '{print $4}'|sed -e s/,//g|sed -e s/\(//g)
TIMEZONE_NUMBER=$(timedatectl|grep -E 'Time zone'|awk '{print $5}'|sed -e s/+//g|sed -e s/\)//g)
TIMEZONE_NUMBER=$(echo "$TIMEZONE_NUMBER/100" | bc)
TIMEZONE_SCALE=$(timedatectl|grep -E 'Time zone'|awk '{print $5}'|cut -c-1)
echo "TIMEZONE = $TIMEZONE_COUNTRY $TIMEZONE_CITY $TIMEZONE_SCALE$TIMEZONE_NUMBER"

USER=$(echo $USER)
echo USER = $USER

OS=$(hostnamectl|grep -E Ubuntu|awk '{print $3,$4}')
echo OS = $OS

DATE=$(date|awk '{print $3,$2,$6,$4}')
echo DATE = $DATE

UPTIME=$(uptime -p|awk '{print $2,$3,$4,$5}'|sed -e s/,//g)
echo UPTIME = $UPTIME

UPTIME_SEC=$(cat /proc/uptime|awk '{print $1}')
echo UPTIME_SEC = $UPTIME_SEC

IP=$(ifconfig enp0s3|grep -w 'inet'|awk '{print $2}')
echo IP = $IP

MASK=$(ifconfig enp0s3|grep -w 'inet'|awk '{print $4}')
echo MASK = $MASK

GATEWAY=$(ip route|grep -w 'default'|awk '{print $3}')
echo GATEWAY = $GATEWAY

RAM_TOTAL=$(free -m|grep -E 'Mem'|awk '{print $2}')
if [ $RAM_TOTAL -lt 1024 ]
then
echo RAM_TOTAL = 0$(echo "scale=3; $RAM_TOTAL/1024" | bc) GB
else
echo RAM_TOTAL = $(echo "scale=3; $RAM_TOTAL/1024" | bc) GB
fi

RAM_USED=$(free -m|grep -E 'Mem'|awk '{print $3}')
if [ $RAM_USED -lt 1024 ]
then
echo RAM_USED = 0$(echo "scale=3; $RAM_USED/1024" | bc) GB
else
echo RAM_USED = $(echo "scale=3; $RAM_USED/1024" | bc) GB
fi

RAM_FREE=$(free -m|grep -E 'Mem'|awk '{print $4}')
if [ $RAM_FREE -lt 1024 ]
then
echo RAM_FREE = 0$(echo "scale=3; $RAM_FREE/1024" | bc) GB
else
echo RAM_FREE = $(echo "scale=3; $RAM_FREE/1024" | bc) GB
fi

SPACE_ROOT=$(df -k /|grep -E dev|awk '{print $2}')
echo SPACE_ROOT = $(echo "scale=2; $SPACE_ROOT/1024" | bc) MB

SPACE_ROOT_USED=$(df -k /|grep -E dev|awk '{print $3}')
echo SPACE_ROOT_USED = $(echo "scale=2; $SPACE_ROOT_USED/1024" | bc) MB

SPACE_ROOT_FREE=$(df -k /|grep -E dev|awk '{print $4}')
echo SPACE_ROOT_FREE = $(echo "scale=2; $SPACE_ROOT_FREE/1024" | bc) MB
