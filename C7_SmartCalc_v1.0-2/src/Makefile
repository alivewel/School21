CARGS = gcc -g -Wall -Werror -Wextra -std=c11 -pedantic
GCOVFLAGS = -fprofile-arcs -ftest-coverage

OS = $(shell uname)
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lpthread -lcheck -pthread -lrt -lm -lsubunit
else
	CHECK_FLAGS = -lcheck
endif

all: install

s21_calc.a:
	$(CARGS) -c s21_calc.c
	ar rcs s21_calc.a *.o
	rm -rf *.o

test: s21_calc.a
	$(CARGS) ./tests/s21_calc_test.c s21_calc.a $(CHECK_FLAGS) -o unit_test
	./unit_test

gcov_report: s21_calc.a
	$(CARGS) $(GCOVFLAGS) ./tests/s21_calc_test.c s21_calc.c $(CHECK_FLAGS) -o test
	./test
	lcov -t "test" -o test.info --no-external -c -d  ./
	genhtml test.info -o report
	open report/index.html

install: uninstall
	mkdir -p ~/Applications
	cd Qt_project/untitled && \
	qmake && \
	make && \
	make clean && \
	rm -f Makefile && \
	cd .. && \
	mv untitled/untitled.app ~/Applications/untitled.app

uninstall:
	rm -rf ~/Applications/untitled.app

open:
	open ~/Applications/untitled.app

run: install open

clang:
	clang-format -style=Google -n tests/*.c s21_calc.c s21_calc.h Qt_project/untitled/graphwindow.cpp Qt_project/untitled/graphwindow.h Qt_project/untitled/mainwindow.cpp Qt_project/untitled/mainwindow.cpp

clang-fix:
	clang-format -style=Google -i tests/*.c s21_calc.c s21_calc.h Qt_project/untitled/graphwindow.cpp Qt_project/untitled/graphwindow.h Qt_project/untitled/mainwindow.cpp Qt_project/untitled/mainwindow.cpp

leaks: test
	CK_FORK=no leaks --atExit -- ./unit_test

brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh

lcov:
ifeq ($(OS),Linux)
	sudo apt install lcov
endif
ifeq ($(OS),Darwin)
	brew install lcov
endif

valgrind: test
	valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./unit_test

clean:
	rm -rf build*
	rm -rf *.o *.gcno *.gcda *.a *.info report .clang-format *.out *.dSYM
	rm -f unit_test
	rm -f gcov_test
	rm -f out
