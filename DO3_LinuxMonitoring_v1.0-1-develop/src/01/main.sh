#!/bin/bash

if [[ $1  =~ ^[+-]?[0-9]+[.,][0-9]+$ ]] || [[ $1 =~ ^[+-]?[0-9]+$ ]] || [ "$#" != 1 ] ; then
    echo "некорректный ввод"
    exit 1
fi

echo "$1"