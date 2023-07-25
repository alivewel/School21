FLAGS=-Wall -Werror -Wextra -std=c11
OS = $(shell uname)
ifeq ($(OS), Linux)
 CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit
else
 CHECK_FLAGS = -lcheck -lm
endif

all: clean s21_matrix.a test gcov_report

test: clean s21_matrix.a
	gcc $(CHECK_FLAGS) s21_test.c s21_matrix.a -o test.out && ./test.out

gcov_report:
	gcc -fprofile-arcs -ftest-coverage s21_test.c s21_matrix.c $(CHECK_FLAGS) -o test
	./test
	lcov -t "test" -o test.info --no-external -c -d  ./
	genhtml test.info -o report
	open report/index.html

s21_matrix.a: s21_matrix.o
	ar rcs s21_matrix.a s21_matrix.o
	ranlib s21_matrix.a

s21_matrix.o:
	gcc -c $(FLAGS) s21_matrix.c

style:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c
	clang-format -n *.h

leak: test
	CK_FORK=no leaks --atExit -- ./test.out

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

clean:
	rm -rf test s21_matrix *.out *.a *.o report/ *.info *.gcda *.gcno
