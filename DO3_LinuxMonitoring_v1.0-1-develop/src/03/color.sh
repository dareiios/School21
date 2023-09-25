#!/bin/bash

#text
while="\e[97m" 
red="\e[91m" 
green="\e[92m" 
blue="\e[96m"
purple="\e[95m"
black="\e[30m"
ENDCOLOR="\e[0m" 
colortext=${red}
colortextAfter=${red}

#back
whileT="\e[107m" 
redT="\e[101m" 
greenT="\e[42m" 
blueT="\e[106m"
purpleT="\e[105m"
blackT="\e[40m"
colorback=${blueT}
colorbackAfter=${blueT}


case "$back" in
        "1" )      colorback=${whileT};;
        "2" )     colorback=${redT};;
        "3" )      colorback=${greenT};;
        "4" )     colorback=${blueT};;
        "5" )      colorback=${purpleT};;
        "6" )     colorback=${blackT};;
esac
case "$text" in
        "1" )      colortext=${while};;
        "2" )     colortext=${red};;
        "3" )      colortext=${green};;
        "4" )     colortext=${blue};;
        "5" )      colortext=${purple};;
        "6" )     colortext=${black};;
esac
case "$backAfter" in
        "1" )      colorbackAfter=${whileT};;
        "2" )     colorbackAfter=${redT};;
        "3" )      colorbackAfter=${greenT};;
        "4" )     colorbackAfter=${blueT};;
        "5" )      colorbackAfter=${purpleT};;
        "6" )     colorbackAfter=${blackT};;
esac
case "$textAfter" in
        "1" )      colortextAfter=${while};;
        "2" )     colortextAfter=${red};;
        "3" )      colortextAfter=${green};;
        "4" )     colortextAfter=${blue};;
        "5" )      colortextAfter=${purple};;
        "6" )     colortextAfter=${black};;
esac