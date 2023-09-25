#!/bin/bash

# make s21_string.a
# gcc -g test_s21_string.c s21_string.a -o test -lcheck -lcheck -lpthread -lm -D_GNU_SOURCE -lrt -lsubunit
# valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
cd ./cat/
# cd ./cat/
# make s21_grep
gcc -std=c11 -D_GNU_SOURCE -Wall -Werror -Wextra s21_cat.c -o test
# gcc -Wall -Werror -Wextra s21_cat.c -o test
# gcc -g  s21_grep.c  -o test -lcheck -lcheck -lpthread -lm -D_GNU_SOURCE -lrt -lsubunit
# valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test -e
# valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test -c -e /\\ test_1_grep.txt
# valgrind --log-file="valgrind_s21_grep.log" --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all
# bash test_valgrind_cat.sh
bash test_valgrind_cat.sh
