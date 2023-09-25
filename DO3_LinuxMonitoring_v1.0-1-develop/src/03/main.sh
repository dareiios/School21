#!/bin/bash

if [ "$#" != 4 ] ; then 
echo "Нужно 4 пармметра" 
exit
fi

if [ $1 = $2 ] || [ $3 = $4 ] ; then
echo "параметры не должны совпадать, вызовите скрипт повторно"
exit
fi

if [[ "$1" = [1-6] ]] &&
[[ "$2" = [1-6] ]] && 
[[ "$3" = [1-6] ]] && 
[[ "$4" = [1-6] ]]; then
chmod +x info.sh
chmod +x color.sh
export text=$2
export textAfter=$4
export back=$1
export backAfter=$3
bash info.sh
else
echo "параметры от 1 до 6"
exit
fi



