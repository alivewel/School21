CC = gcc
FLAGS = -Wall -Werror -Wextra
C11=-std=c11

all: cat

cat:
	$(CC) $(FLAGS) $(C11) s21_cat.c -o s21_cat

test:
	sh test.sh

test_leak:
	sh test_leak_cat.sh

style:
	cp ../../materials/linters/.clang-format .
	clang-format -n -Werror *.c
	clang-format -n -Werror *.h
	rm .clang-format

clean: 
	rm -rf *.o
	rm -rf s21_cat

rebuild: clean s21_cat