FLAGS=-Wall -Werror -Wextra -std=c++17 -pedantic -lstdc++
OS = $(shell uname)
ifeq ($(OS), Linux)
 CHECK_FLAGS = -lpthread -lcheck -pthread -lrt -lm -lsubunit -lgtest
else
 CHECK_FLAGS = -lcheck -lm -lpthread -lgtest
endif

all: clean s21_matrix_oop.a test gcov_report

test: clean s21_matrix_oop.a
	gcc $(FLAGS) $(CHECK_FLAGS) s21_test_oop.cc s21_matrix_oop.a -o test.out 
	./test.out

gcov_report:
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage s21_test_oop.cc s21_matrix_oop.cc $(CHECK_FLAGS) -o test
	./test
	lcov -t "test" --ignore-errors mismatch -o test.info --no-external -c -d  ./
	genhtml test.info -o report
	open report/index.html

s21_matrix_oop.a: s21_matrix_oop.o
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

s21_matrix_oop.o:
	gcc -c $(FLAGS) s21_matrix_oop.cc

style:
	cp ../materials/linters/.clang-format .
	clang-format -n *.cc
	clang-format -n *.h
	rm .clang-format

leak: test
	CK_FORK=no leaks --atExit -- ./test.out

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

clean:
	rm -rf test s21_matrix *.out *.a *.o report/ *.info *.gcda *.gcno
