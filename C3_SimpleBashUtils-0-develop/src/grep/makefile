all: s21_grep.o
	gcc -Wall -Werror -Wextra s21_grep.o -o s21_grep

s21_grep.o:
	gcc -Wall -Werror -Wextra -c s21_grep.c

clean:
	rm -rf *.o

rebuild: clean all
