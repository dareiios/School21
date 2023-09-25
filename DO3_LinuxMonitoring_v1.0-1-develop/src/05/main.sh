#!/bin/bash

WORD=$1;
lenth=${#WORD}
r=$((lenth-1))
lastSymbol=${WORD: r}

if [ "$#" == 1 ]  ; then
    if [ -d $1 ] ; then
        if  [ "$lastSymbol" == "/" ] ; then
            START_TIME=$(date +%s)
            chmod +x info.sh
            . ./info.sh
            END_TIME=$(date +%s)
            difference=$(( $END_TIME - $START_TIME ))
            echo "Script execution time (in seconds) = $difference "
        else
            echo "введите правильно директорию"
        fi
    else
        echo "не существует директория"
    fi
else
    echo "нужен 1 параметр"
fi


