#!/bin/bash
source color.sh
source config.conf



echo -e ${colorback}${colortext}HOSTNAME${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$HOSTNAME${ENDCOLOR}
echo -e ${colorback}${colortext}TIMEZONE${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(timedatectl | grep "Time zone" | awk '{print $3}') $(date +%z)${ENDCOLOR}
echo -e ${colorback}${colortext}USER${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$USER${ENDCOLOR}
echo -e ${colorback}${colortext}OS${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$OSTYPE${ENDCOLOR}

echo -e ${colorback}${colortext}DATE${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(date +%d) $(date +%b) $(date +%Y) $(date +%T)${ENDCOLOR}
echo -e ${colorback}${colortext}UPTAME${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(uptime -p)${ENDCOLOR}
echo -e ${colorback}${colortext}UPTAME_SEC${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(cat /proc/uptime | awk '{print $1}')${ENDCOLOR}
echo -e ${colorback}${colortext}IP${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(ip address | grep "eth0" | grep "inet" | awk '{print $2}')${ENDCOLOR}
echo -e ${colorback}${colortext}MASK${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(ifconfig eth0 | grep "netmask" | awk '{print $4}')${ENDCOLOR}
echo -e ${colorback}${colortext}GATEWAY${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(ip r | grep "default" | awk '{print $3}')${ENDCOLOR}

echo -e ${colorback}${colortext}RAM_TOTAL${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(free | grep Mem | awk '{kbyte =$2 /1024/1024; printf("%.3f GB", kbyte)}')${ENDCOLOR}
echo -e ${colorback}${colortext}RAM_USED${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(free | grep Mem | awk '{kbyte =$3 /1024/1024; printf("%.3f GB", kbyte)}')${ENDCOLOR}
echo -e ${colorback}${colortext}RAM_FREE${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(free | grep Mem | awk '{kbyte =$4 /1024/1024; printf("%.3f GB", kbyte)}')${ENDCOLOR}
echo -e ${colorback}${colortext}SPACE_ROOT${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(df -h /root | grep "/dev/" | awk '{mb=$2*1024; printf("%.2f MB", mb)}')${ENDCOLOR}
echo -e ${colorback}${colortext}SPACE_ROOT_USED${ENDCOLOR}  = ${colorbackAfter}${colortextAfter}$(df -h /root | grep "/dev/" | awk '{mb=$3*1024; printf("%.2f MB", mb)}')${ENDCOLOR}
echo -e ${colorback}${colortext}SPACE_ROOT_FREE${ENDCOLOR} = ${colorbackAfter}${colortextAfter}$(df -h /root | grep "/dev/" | awk '{mb=$4*1024; printf("%.2f MB", mb)}')${ENDCOLOR}

echo ""
BackColor $column1_background
TextColor $column1_font_color
BackColorAfter $column2_background
TextColorAfter $column2_font_color
