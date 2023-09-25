#!/bin/bash
source color.sh

# #text
# while="\e[97m" 
# red="\e[91m" 
# green="\e[92m" 
# blue="\e[96m"
# purple="\e[95m"
# black="\e[30m"
# ENDCOLOR="\e[0m" 
# colortext=${red}
# colortextAfter=${red}

# #back
# whileT="\e[107m" 
# redT="\e[101m" 
# greenT="\e[42m" 
# blueT="\e[106m"
# purpleT="\e[105m"
# blackT="\e[40m"
# colorback=${blueT}
# colorbackAfter=${blueT}


# case "$1" in
#         "1" )      colorback=${whileT};;
#         "2" )     colorback=${redT};;
#         "3" )      colorback=${greenT};;
#         "4" )     colorback=${blueT};;
#         "5" )      colorback=${purpleT};;
#         "6" )     colorback=${blackT};;
# esac
# case "$2" in
#         "1" )      colortext=${while};;
#         "2" )     colortext=${red};;
#         "3" )      colortext=${green};;
#         "4" )     colortext=${blue};;
#         "5" )      colortext=${purple};;
#         "6" )     colortext=${black};;
# esac
# case "$3" in
#         "1" )      colorbackAfter=${whileT};;
#         "2" )     colorbackAfter=${redT};;
#         "3" )      colorbackAfter=${greenT};;
#         "4" )     colorbackAfter=${blueT};;
#         "5" )      colorbackAfter=${purpleT};;
#         "6" )     colorbackAfter=${blackT};;
# esac
# case "$4" in
#         "1" )      colortextAfter=${while};;
#         "2" )     colortextAfter=${red};;
#         "3" )      colortextAfter=${green};;
#         "4" )     colortextAfter=${blue};;
#         "5" )      colortextAfter=${purple};;
#         "6" )     colortextAfter=${black};;
# esac

# if [ "$#" != 4 ] ; then 
# echo "Нужно 4 пармметра" 
# exit
# fi

# if [ $1 = $2 ] || [ $3 = $4 ] ; then
# echo "параметры не должны совпадать, вызовите скрипт повторно"
# exit
# fi


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