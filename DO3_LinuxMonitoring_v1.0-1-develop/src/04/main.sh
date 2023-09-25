#!/bin/bash

source config.conf

function Start () {
        chmod +x info.sh
    chmod +x color.sh
    chmod +x config.conf
    export text=$column1_font_color
    export textAfter=$column2_font_color
    export back=$column1_background
    export backAfter=$column2_background
    bash info.sh
}

flag=1

if [[ -z $column1_background ]] ; then
    column1_background=default
    flag=0
fi


if [[ -z $column1_font_color ]] ; then
    column1_font_color=default
    flag=0
fi

if [[ -z $column2_background ]] ; then
    column2_background=default
    flag=0
fi

if [[ -z $column2_font_color ]] ; then
    column2_font_color=default
    flag=0
fi


if [ $flag = 1 ] ; then
    if [[ "$column1_background" = [1-6] ]] &&
    [[ "$column1_font_color" = [1-6] ]] && 
    [[ "$column2_background" = [1-6] ]] && 
    [[ "$column2_font_color" = [1-6] ]]; then
        if [ $column1_background = $column1_font_color ] || [ $column2_background = $column2_font_color ] ; then
            echo "параметры не должны совпадать, вызовите скрипт повторно"
            exit
        fi
        Start
    else
        echo "параметры от 1 до 6"
        exit
    fi
else
Start
fi


