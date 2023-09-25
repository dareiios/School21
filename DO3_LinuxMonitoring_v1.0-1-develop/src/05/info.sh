#!/bin/bash


echo  "Total number of folders (including all nested ones) =" $(find $1 -type d | wc -l)

echo "TOP 5 folders of maximum size arranged in descending order (path and size):" 

echo -e "$(du -h $1 | sort -rh | head -5 | awk 'BEGIN{i=1}{printf "%d - %s, %s\n", i, $2, $1; i++}')"

echo "Total number of files =" $(find $1 -type f | wc -l)

echo "Number of:" 
echo "Configuration files (with the .conf extension) =" $(find $1 -type f -name "*.conf" | wc -l)
echo "Text files =" $(find $1 -type f -name "*.txt" | wc -l)
echo "Executable files =" $(find $1 -type f  -executable | wc -l)
echo "Log files (with the extension .log) =" $(find $1 -type f -name "*.log" | wc -l) 
echo "Archive files =" $(find $1 -type f -name "*.zip" -o -name "*.7z" -o -name "*.rar" -o -name "*.tar" | wc -l)
echo "Symbolic links =" $(find $1 -type l | wc -l)

echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"  

for ((var=1; var<=10; var++))
do
    name=$(find $1 -type f -exec du -h {} + | sort -hr | sed -n "$var"p | awk '{print $2}')
    size=$(find $1 -type f -exec du -h {} + | sort -hr | sed -n "$var"p | awk '{print $1}')
    filename=($(find "$1" -type f -exec du -h {} + | sort -rh | head -11 | awk '{print $2}'))
    filetype=$(file ${filename[var]} | awk '{print $3}')
    if  [ "$name" != NULL ] &&  [ "$size" != NULL ]; then
        echo -e "$var - $name, $size , $filetype"
    fi
done

echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file): "

filename=($(find $1 -type f -executable  -exec du -sh {} + | sort -rh | head -11 | awk '{print $2}'))
filesize=($(find $1 -type f -executable  -exec du -sh {} + | sort -rh | head -11 | awk '{print $1}'))
count=1
for ((i=0; i<10; i++))
    do
        if ! [ -z "$filename" ] ; then
            exemd5hash=$(md5sum ${filename[i]} | awk '{print $1}' )
            echo -e "$count-${filename[i]}, ${filesize[i]}, $exemd5hash"
            count=$((count+1))
        fi
        
    done

