#!/bin/bash

#text
while="\e[97m" 
red="\e[91m" 
green="\e[92m" 
blue="\e[96m"
purple="\e[95m"
black="\e[30m"
ENDCOLOR="\e[0m" 
# colortext=${red}
# colortextAfter=${red}

#back
whileT="\e[107m" 
redT="\e[101m" 
greenT="\e[42m" 
blueT="\e[106m"
purpleT="\e[105m"
blackT="\e[40m"
# colorback=${blueT}
# colorbackAfter=${blueT}


case "$back" in
        "default")	colorback=${whileT};;
        "1" )      colorback=${whileT};;
        "2" )     colorback=${redT};;
        "3" )      colorback=${greenT};;
        "4" )     colorback=${blueT};;
        "5" )      colorback=${purpleT};;
        "6" )     colorback=${blackT};;
        
esac
case "$text" in
        "default")	colortext=${purple};;
        "1" )      colortext=${while};;
        "2" )     colortext=${red};;
        "3" )      colortext=${green};;
        "4" )     colortext=${blue};;
        "5" )      colortext=${purple};;
        "6" )     colortext=${black};;
esac
case "$backAfter" in
        "default")	colorbackAfter=${whileT};;
        "1" )      colorbackAfter=${whileT};;
        "2" )     colorbackAfter=${redT};;
        "3" )      colorbackAfter=${greenT};;
        "4" )     colorbackAfter=${blueT};;
        "5" )      colorbackAfter=${purpleT};;
        "6" )     colorbackAfter=${blackT};;
esac
case "$textAfter" in
        "default")	colortextAfter=${purple};;
        "1" )      colortextAfter=${while};;
        "2" )     colortextAfter=${red};;
        "3" )      colortextAfter=${green};;
        "4" )     colortextAfter=${blue};;
        "5" )      colortextAfter=${purple};;
        "6" )     colortextAfter=${black};;
esac

function BackColor() {
        if [ $# = 1 ] ; then
                if [ $1 = 1 ] ; then 
                echo -e "Column 1 background = $back (${colorback}white$ENDCOLOR)"
                elif [ $1 = 2 ] ; then 
                echo -e "Column 1 background = $back (${colorback}red$ENDCOLOR)"
                elif [ $1 = 3 ] ; then 
                echo -e "Column 1 background = $back (${colorback}green$ENDCOLOR)"
                elif [ $1 = 4 ] ; then 
                echo -e "Column 1 background = $back (${colorback}blue$ENDCOLOR)"
                elif [ $1 = 5 ] ; then 
                echo -e "Column 1 background = $back (${colorback}purple$ENDCOLOR)"
                elif [ $1 = 6 ] ; then 
                echo -e "Column 1 background = $back (${colorback}black$ENDCOLOR)"
                fi
        else
        echo -e "Column 1 background = $back (${colorback}white$ENDCOLOR)"
        fi
}

function TextColor() {
        if [ $# = 1 ] ; then
                if [ $1 = 1 ] ; then
                echo -e "Column 1 font color = $text (${colortext}white$ENDCOLOR)"
                elif [ $1 = 2 ] ; then 
                echo -e "Column 1 font color = $text (${colortext}red$ENDCOLOR)"
                elif [ $1 = 3 ] ; then 
                echo -e "Column 1 font color = $text (${colortext}green$ENDCOLOR)"
                elif [ $1 = 4 ] ; then 
                echo -e "Column 1 font color = $text (${colortext}blue$ENDCOLOR)"
                elif [ $1 = 5 ] ; then 
                echo -e "Column 1 font color = $text (${colortext}purple$ENDCOLOR)"
                elif [ $1 = 6 ] ; then 
                echo -e "Column 1 font color = $text (${colortext}black$ENDCOLOR)"
                fi
        else
        echo -e "Column 1 font color = $text (${colortext}purple$ENDCOLOR)"
        fi
}

function BackColorAfter() {
        if [ $# = 1 ] ; then
                if [ $1 = 1 ] ; then 
                echo -e "Column 2 background = $backAfter (${colorbackAfter}white$ENDCOLOR)"
                elif [ $1 = 2 ] ; then 
                echo -e "Column 2 background = $backAfter (${colorbackAfter}red$ENDCOLOR)"
                elif [ $1 = 3 ] ; then 
                echo -e "Column 2 background = $backAfter (${colorbackAfter}green$ENDCOLOR)"
                elif [ $1 = 4 ] ; then 
                echo -e "Column 2 background = $backAfter (${colorbackAfter}blue$ENDCOLOR)"
                elif [ $1 = 5 ] ; then 
                echo -e "Column 2 background = $backAfter (${colorbackAfter}purple$ENDCOLOR)"
                elif [ $1 = 6 ] ; then 
                echo -e "Column 2 background = $backAfter (${colorbackAfter}black$ENDCOLOR)"
                fi
        else
        echo -e "Column 2 background = $backAfter (${colorbackAfter}white$ENDCOLOR)"
        fi
}

function TextColorAfter() {
        if [ $# = 1 ] ; then
                if [ $1 = 1 ] ; then
                echo -e "Column 2 font color = $textAfter (${colortextAfter}white$ENDCOLOR)"
                elif [ $1 = 2 ] ; then 
                echo -e "Column 2 font color = $textAfter (${colortextAfter}red$ENDCOLOR)"
                elif [ $1 = 3 ] ; then 
                echo -e "Column 2 font color = $textAfter (${colortextAfter}green$ENDCOLOR)"
                elif [ $1 = 4 ] ; then 
                echo -e "Column 2 font color = $textAfter (${colortextAfter}blue$ENDCOLOR)"
                elif [ $1 = 5 ] ; then 
                echo -e "Column 2 font color = $textAfter (${colortextAfter}purple$ENDCOLOR)"
                elif [ $1 = 6 ] ; then 
                echo -e "Column 2 font color = $textAfter (${colortextAfter}black$ENDCOLOR)"
                fi
        else
        echo -e "Column 2 font color = $textAfter (${colortextAfter}purple$ENDCOLOR)"
        fi
}