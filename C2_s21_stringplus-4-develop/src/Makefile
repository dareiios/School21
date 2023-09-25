CC = gcc
CFLAGS = -Wall  -Wextra -std=c11
OS := $(shell uname -s)

ifeq ($(OS), Darwin)
    CHECK=-lcheck -L.
	HTML_CREATE=lcov -t test.out -o report.info -c -d .; genhtml -o report report.info
else
    CHECK=-lcheck -lm -lsubunit -lrt -lpthread -L. #-L/usr/lib -L/usr/local/lib 
	HTML_CREATE=gcov -b -l -p -c s21_string.gcno; gcovr -g -k -r . --html --html-details -o report.html; mv report.s21_string.c.html report.html
	
endif

all: clean s21_string.a test gcov_report

test: clean s21_string.o testest.o
	$(CC) $(CFLAGS) s21_string.o testest.o $(CHECK)
	./a.out

s21_string.o:
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o

testest.o:
	$(CC) $(CFLAGS) -c s21_test.c -o testest.o

s21_string.a: clean 
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o
	ar rc s21_string.a s21_string.o
	ranlib s21_string.a


gcov_report: s21_string.a
	gcc -fprofile-arcs -ftest-coverage s21_test.c s21_string.c -lcheck -o GcovReport
	./GcovReport
	lcov -t "GcovReport" -o GcovReport.info -c -d .
	genhtml -o report GcovReport.info
	open ./report/index-sort-f.html
	rm -rf ./*.gcno ./*.gcda ./GcovReport.*

clang:
	cp ../materials/linters/.clang-format ../src/.clang-format
	clang-format -n *.c *.h 

clean:
	rm -rf *.g* report.* *.out *.o ./report s21_string.a *.txt *.cfg GcovReport a.out.dSYM

rebuild: clean all
