#!/bin/bash

a=$(date "+%d_%m_%y_%H_%M_%S").status  
echo HOSTNAME = $HOSTNAME >> $a
echo TIMEZONE = $(timedatectl | grep "Time zone" | awk '{print $3}') $(date +%z) >> $a
echo USER = $USER >> $a
echo OS = $OSTYPE >> $a
echo DATE = $(date +%d) $(date +%b) $(date +%Y) $(date +%T) >> $a
echo UPTAME = $(uptime -p) >> $a
echo UPTAME_SEC = $(cat /proc/uptime | awk '{print $1}') >> $a
echo IP = $(ip address | grep "eth0" | grep "inet" | awk '{print $2}') >> $a
echo MASK = $(ifconfig eth0 | grep "netmask" | awk '{print $4}') >> $a
echo GATEWAY = $(ip r | grep "default" | awk '{print $3}') >> $a
echo RAM_TOTAL = $(free | grep Mem | awk '{kbyte =$2 /1024/1024; printf("%.3f GB", kbyte)}') >> $a
echo RAM_USED = $(free | grep Mem | awk '{kbyte =$3 /1024/1024; printf("%.3f GB", kbyte)}') >> $a
echo RAM_FREE = $(free | grep Mem | awk '{kbyte =$4 /1024/1024; printf("%.3f GB", kbyte)}') >> $a
echo SPACE_ROOT = $(df -h /root | grep "/dev/" | awk '{mb=$2*1024; printf("%.2f MB", mb)}') >> $a
echo SPACE_ROOT_USED  = $(df -h /root | grep "/dev/" | awk '{mb=$3*1024; printf("%.2f MB", mb)}') >> $a
echo SPACE_ROOT_FREE = $(df -h /root | grep "/dev/" | awk '{mb=$4*1024; printf("%.2f MB", mb)}') >> $a