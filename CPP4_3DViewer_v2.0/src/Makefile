FLAGS = -Wall -Werror -Wextra -std=c++17 -pedantic -lstdc++
OS = $(shell uname)
ifeq ($(OS), Linux)
 CHECK_FLAGS = -lpthread -lcheck -pthread -lrt -lm -lsubunit -lgtest
else
 CHECK_FLAGS = -lcheck -lm -lpthread -lgtest
endif
TEST = tests/*.cc
MODEL = 3DViewer/model/*.cc

all: install

test: clean s21_viewer.a
	gcc $(FLAGS) $(CHECK_FLAGS) $(TEST) s21_viewer.a -o test.out 
	./test.out

gcov_report:
	gcc $(FLAGS) -fprofile-arcs -ftest-coverage $(TEST) $(MODEL) $(CHECK_FLAGS) -o test
	./test
	lcov -t "test" --ignore-errors mismatch -o test.info --no-external -c -d  ./
	genhtml test.info -o report
	open report/index.html

s21_viewer.a: s21_viewer.o
	ar rcs s21_viewer.a *.o
	ranlib *.a

s21_viewer.o:
	gcc -c $(FLAGS) $(MODEL)

install: uninstall
	cd 3DViewer && qmake && make -j6 && make clean && rm Makefile && cd ../

uninstall:
	rm -rf 3DViewer/3DViewer

open:
	open 3DViewer/3DViewer.app

run: install open

dvi:
	open dvi.md

dist:
	rm -rf Archive_3DViewer_v2_0/
	mkdir Archive_3DViewer_v2_0
	mkdir Archive_3DViewer_v2_0/src
	cp -r ./3DViewer/3DViewer.app Archive_3DViewer_v2_0/src
	tar cvzf Archive_3DViewer_v2_0.tgz Archive_3DViewer_v2_0/
	rm -rf Archive_3DViewer_v2_0/

style:
	cp ../materials/linters/.clang-format .
	clang-format -n --style=Google tests/*.cc 3DViewer/controller/*.cc 3DViewer/controller/*.h 3DViewer/model/*.cc 3DViewer/model/*.h 3DViewer/view/*.cc 3DViewer/view/*.h 3DViewer/*.cc
	rm .clang-format

leak: test
	CK_FORK=no leaks --atExit -- ./test.out

install_brew:
	cd ~
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov

clean:
	rm -rf test *.out *.a *.o report/ *.info *.gcda *.gcno
	rm -rf *.gcno *gcda *.gcov *.info
	rm -rf report gcov test
	rm -rf 3DViewer.a
	rm -rf 3DViewer/*.o 3DViewer/.qmake.stash 3DViewer/3DViewer.app
	rm -rf Archive_3DViewer_v2_0.tgz
	rm -rf 3DViewer/moc_glwidget.cpp 3DViewer/moc_predefs.h 3DViewer/moc_viewer.cpp 3DViewer/Makefile
	@echo Cleanup complete!
