all: s21_cat.o
	gcc -Wall -Werror -Wextra s21_cat.o -o s21_cat

s21_cat.o:
	gcc -Wall -Werror -Wextra -c s21_cat.c

clean:
	rm -rf *.o

rebuild: clean all