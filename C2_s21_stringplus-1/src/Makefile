FLAGS=-Wall -Werror -Wextra -std=c11

all: clean s21_string.a test gcov_report

test: clean s21_string.a
	gcc -fsanitize=address -lcheck test.c s21_string.a -o test.out && ./test.out

gcov_report:
	gcc -fprofile-arcs -ftest-coverage test.c s21_string.c s21_sprintf.c -o test -lcheck
	./test
	lcov -t "Core" -o test.info -c -d ./
	genhtml test.info -o report
	open report/index.html

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o s21_sprintf.o
	ranlib s21_string.a

s21_string.o:
	gcc -c $(FLAGS) s21_string.c s21_sprintf.c

clean:
	rm -rf test s21_string *.out *.a *.o report/ *.info *.gcda *.gcno
