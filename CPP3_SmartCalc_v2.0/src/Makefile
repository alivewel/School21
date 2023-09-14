FLAGS = -Wall -Werror -Wextra -std=c++17 -pedantic -lstdc++
OS = $(shell uname)
ifeq ($(OS), Linux)
 CHECK_FLAGS = -lpthread -lcheck -pthread -lrt -lm -lsubunit -lgtest
else
 CHECK_FLAGS = -lcheck -lm -lpthread -lgtest
endif
MODEL = s21_SmartCalc_v2/model
VIEW = s21_SmartCalc_v2/view
CONTROLLER = s21_SmartCalc_v2/controller
MAIN = s21_SmartCalc_v2/main.cc
CC = $(MODEL)/*.cc $(CONTROLLER)/*.cc
H = $(MODEL)/*.h $(CONTROLLER)/*.h
VIEWCC = $(VIEW)/*.cc
VIEWH = $(VIEW)/*.h
TEST = tests/*.cc

all: install

test: clean s21_calc.a
	gcc $(FLAGS) $(CHECK_FLAGS) $(TEST) s21_calc.a -o test.out 
	./test.out

gcov_report:
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage $(TEST) $(CC) $(CHECK_FLAGS) -o test
	./test
	lcov -t "test" --ignore-errors mismatch -o test.info --no-external -c -d  ./
	genhtml test.info -o report
	open report/index.html

s21_calc.a: s21_calc.o
	ar rcs s21_calc.a *.o
	ranlib *.a

s21_calc.o:
	gcc -c $(FLAGS) $(CC)

install: uninstall
	mkdir -p ~/Applications
	cd s21_SmartCalc_v2 && \
	qmake && \
	make && \
	make clean && \
	rm -f Makefile && \
	cd .. && \
	mv s21_SmartCalc_v2/s21_SmartCalc_v2.app ~/Applications/s21_SmartCalc_v2.app

uninstall:
	rm -rf ~/Applications/s21_SmartCalc_v2.app

open:
	open ~/Applications/s21_SmartCalc_v2.app

run: install open

dvi:
	open dvi.md

dist:
	rm -rf Archive_s21_SmartCalc_v2/
	mkdir Archive_s21_SmartCalc_v2
	mkdir Archive_s21_SmartCalc_v2/src
	cp -r ~/Applications/s21_SmartCalc_v2.app Archive_s21_SmartCalc_v2/src
	tar cvzf Archive_s21_SmartCalc_v2.tgz Archive_s21_SmartCalc_v2/
	rm -rf Archive_s21_SmartCalc_v2/

style:
	cp ../materials/linters/.clang-format .
	clang-format -n $(CC) $(VIEWCC) $(MAIN) $(TEST)
	clang-format -n $(H) $(VIEWH)
	rm .clang-format

leak: test
	CK_FORK=no leaks --atExit -- ./test.out

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

clean:
	rm -rf test *.out *.a *.o report/ *.info *.gcda *.gcno