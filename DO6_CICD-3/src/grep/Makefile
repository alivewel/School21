CC = gcc
FLAGS = -Wall -Werror -Wextra
C11=-std=c11

all: grep

grep:
	$(CC) $(FLAGS) $(C11) s21_grep.c -o s21_grep

test:
	sh test.sh

test_leak:
	sh test_leak_grep.sh

style:
	cp ../../materials/linters/.clang-format .
	clang-format -n -Werror *.c
	clang-format -n -Werror *.h
	rm .clang-format

clean: 
	rm -rf *.o
	rm -rf s21_grep

rebuild: clean s21_grep