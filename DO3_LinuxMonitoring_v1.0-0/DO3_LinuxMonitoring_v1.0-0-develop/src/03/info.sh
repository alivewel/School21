#!/bin/bash

HOSTNAME=$(hostname -s)
echo ${COLUMN1_BACK}${COLUMN1_FONT}HOSTNAME${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$HOSTNAME${ENDCOLOR}

TIMEZONE_COUNTRY=$(timedatectl|grep -E 'Time zone'|awk '{print $3}')
TIMEZONE_CITY=$(timedatectl|grep -E 'Time zone'|awk '{print $4}'|sed -e s/,//g|sed -e s/\(//g)
TIMEZONE_NUMBER=$(timedatectl|grep -E 'Time zone'|awk '{print $5}'|sed -e s/+//g|sed -e s/\)//g)
TIMEZONE_NUMBER=$(echo "$TIMEZONE_NUMBER/100" | bc)
TIMEZONE_SCALE=$(timedatectl|grep -E 'Time zone'|awk '{print $5}'|cut -c-1)
echo ${COLUMN1_BACK}${COLUMN1_FONT}TIMEZONE${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$TIMEZONE_COUNTRY $TIMEZONE_CITY $TIMEZONE_SCALE$TIMEZONE_NUMBER${ENDCOLOR}

USER=$(echo $USER)
echo ${COLUMN1_BACK}${COLUMN1_FONT}USER${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$USER${ENDCOLOR}

OS=$(hostnamectl|grep -E Ubuntu|awk '{print $3,$4}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}OS${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$OS${ENDCOLOR}

DATE=$(date|awk '{print $3,$2,$6,$4}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}DATE${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$DATE${ENDCOLOR}

UPTIME=$(uptime -p|awk '{print $2,$3,$4,$5}'|sed -e s/,//g)
echo ${COLUMN1_BACK}${COLUMN1_FONT}UPTIME${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$UPTIME${ENDCOLOR}

UPTIME_SEC=$(cat /proc/uptime|awk '{print $1}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}UPTIME_SEC${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$UPTIME_SEC${ENDCOLOR}

IP=$(ifconfig enp0s3|grep -w 'inet'|awk '{print $2}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}IP${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$IP${ENDCOLOR}

MASK=$(ifconfig enp0s3|grep -w 'inet'|awk '{print $4}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}MASK${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$MASK${ENDCOLOR}

GATEWAY=$(ip route|grep -w 'default'|awk '{print $3}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}GATEWAY${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$GATEWAY${ENDCOLOR}

RAM_TOTAL=$(free -m|grep -E 'Mem'|awk '{print $2}')
if [ $RAM_TOTAL -lt 1000 ]
then
echo ${COLUMN1_BACK}${COLUMN1_FONT}RAM_TOTAL${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}0$(echo "scale=3; $RAM_TOTAL/1024" | bc) GB${ENDCOLOR}
else
echo ${COLUMN1_BACK}${COLUMN1_FONT}RAM_TOTAL${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$(echo "scale=3; $RAM_TOTAL/1024" | bc) GB${ENDCOLOR}
fi

RAM_USED=$(free -m|grep -E 'Mem'|awk '{print $3}')
if [ $RAM_USED -lt 1000 ]
then
echo ${COLUMN1_BACK}${COLUMN1_FONT}RAM_USED${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}0$(echo "scale=3; $RAM_USED/1024" | bc) GB${ENDCOLOR}
else
echo ${COLUMN1_BACK}${COLUMN1_FONT}RAM_USED${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$(echo "scale=3; $RAM_USED/1024" | bc) GB${ENDCOLOR}
fi

RAM_FREE=$(free -m|grep -E 'Mem'|awk '{print $4}')
if [ $RAM_FREE -lt 1000 ]
then
echo ${COLUMN1_BACK}${COLUMN1_FONT}RAM_FREE${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}0$(echo "scale=3; $RAM_FREE/1024" | bc) GB${ENDCOLOR}
else
echo ${COLUMN1_BACK}${COLUMN1_FONT}RAM_FREE${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$(echo "scale=3; $RAM_FREE/1024" | bc) GB${ENDCOLOR}
fi

SPACE_ROOT=$(df -k /|grep -E dev|awk '{print $2}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}SPACE_ROOT${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$(echo "scale=2; $SPACE_ROOT/1024" | bc) MB${ENDCOLOR}

SPACE_ROOT_USED=$(df -k /|grep -E dev|awk '{print $3}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}SPACE_ROOT_USED${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$(echo "scale=2; $SPACE_ROOT_USED/1024" | bc) MB${ENDCOLOR}

SPACE_ROOT_FREE=$(df -k /|grep -E dev|awk '{print $4}')
echo ${COLUMN1_BACK}${COLUMN1_FONT}SPACE_ROOT_FREE${ENDCOLOR} = ${COLUMN2_BACK}${COLUMN2_FONT}$(echo "scale=2; $SPACE_ROOT_FREE/1024" | bc) MB${ENDCOLOR}
