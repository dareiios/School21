#!/bin/bash
chmod +x info.sh
bash info.sh
echo ""
echo "желаете сохранить? y/n"
read answer
if [ $answer == "y" ] || [ $answer == "Y" ]; then
    bash writeToFile.sh
else
    exit 
fi