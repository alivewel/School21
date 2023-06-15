CC=gcc
FLAGS=-Wall -Werror -Wextra -std=c11
OS := $(shell uname)

ifeq ($(OS),Linux)
TEST_LIBS = -lcheck -lm -lpthread -lrt -lsubunit -fprofile-arcs -ftest-coverage
else
TEST_LIBS = -lcheck -lm -lpthread -fprofile-arcs -ftest-coverage
endif

all: clean s21_math.a test gcov_report

test: clean s21_math.a
	gcc s21_math_test.c s21_math.c s21_math.a $(TEST_LIBS) -o unit_tests

s21_math.a: s21_math.o
	ar -crs s21_math.a s21_math.o

s21_math.o:
	gcc $(FLAGS) -c s21_math.c

gcov_report: clean s21_math.a test
	./unit_tests
	lcov -t "./unit_tests"  -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

format:
	cp ../materials/linters/.clang-format ./
	clang-format -i *.c *.h
	rm .clang-format

clean:
	rm -rf s21_math
	rm -rf *.o
	rm -rf *.a
	rm -rf *.gcno
	rm -rf *.gcda
	rm -rf *.gcov
	rm -rf *.info
	rm -rf *.html
	rm -rf *.css
	rm -rf test
	rm -rf gcov_test
	rm -rf unit_tests
	rm -rf report
	rm -rf gcov

rebuild: clean all
