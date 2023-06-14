CC = gcc
FLAGS = -Wall -Werror -Wextra
C11=-std=c11

s21_grep:
	$(CC) $(FLAGS) $(C11) s21_grep.c -o s21_grep

test:
	sh test_func_grep.sh

test_leak:
	sh test_leak_grep.sh

clean: 
	rm -rf *.o
	rm -rf s21_grep

rebuild: clean s21_grep