#!/bin/bash

    echo HOSTNAME = $HOSTNAME
    echo TIMEZONE = $(timedatectl | grep "Time zone" | awk '{print $3}') $(date +%z)
    echo USER = $USER
    echo OS = $OSTYPE
    echo DATE = $(date +%d) $(date +%b) $(date +%Y) $(date +%T)
    echo UPTAME = $(uptime -p)
    echo UPTAME_SEC = $(cat /proc/uptime | awk '{print $1}')
    echo IP = $(ip address | grep "eth0" | grep "inet" | awk '{print $2}')
    echo MASK = $(ifconfig eth0 | grep "netmask" | awk '{print $4}')
    echo GATEWAY = $(ip r | grep "default" | awk '{print $3}')
echo RAM_TOTAL = $(free | grep Mem | awk '{kbyte =$2 /1024/1024; printf("%.3f GB", kbyte)}')
echo RAM_USED = $(free | grep Mem | awk '{kbyte =$3 /1024/1024; printf("%.3f GB", kbyte)}')
echo RAM_FREE = $(free | grep Mem | awk '{kbyte =$4 /1024/1024; printf("%.3f GB", kbyte)}')
echo SPACE_ROOT = $(df -h /root | grep "/dev/" | awk '{mb=$2*1024; printf("%.2f MB", mb)}')
echo SPACE_ROOT_USED  = $(df -h /root | grep "/dev/" | awk '{mb=$3*1024; printf("%.2f MB", mb)}')
echo SPACE_ROOT_FREE = $(df -h /root | grep "/dev/" | awk '{mb=$4*1024; printf("%.2f MB", mb)}')