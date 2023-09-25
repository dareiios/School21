CC = gcc
CFLAGS = -Wall -Werror -Wextra
TEST_LIBS = -lcheck -lm -lpthread
OBJECTS=s21_math.o
SOURSES=s21_math.c
GCOVFLAGS = -fprofile-arcs -ftest-coverage

all: clean s21_math.a 

s21_math.a: s21_math.o
	$(CC) -c $(SOURSES)
	ar rcs s21_math.a $(OBJECTS)

test: test.c s21_math.a
	$(CC) $(CFLAGS) -c test.c -o test.o
	$(CC) test.o s21_math.a $(TEST_LIBS) -o test && ./test 

gcov_report: s21_math.a 
	$(CC) $(CFLAGS) --coverage test.c s21_math.c s21_math.a $(TEST_LIBS) -o gcov_test
	./gcov_test
	lcov -t "gcov_test" -o gcov_test.info -c -d .
	genhtml -o report/ gcov_test.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.a.out gcov_test ./GcovReport *.gcno *gcda report/ *.info *.dSYM ./CPPLINT* test

rebuild: clean all
