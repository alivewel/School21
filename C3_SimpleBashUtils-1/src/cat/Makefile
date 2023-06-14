CC = gcc
FLAGS = -Wall -Werror -Wextra
C11=-std=c11

s21_cat:
	$(CC) $(FLAGS) $(C11) s21_cat.c -o s21_cat

test:
	sh test_func_cat.sh

test_leak:
	sh test_leak_cat.sh

clean: 
	rm -rf *.o
	rm -rf s21_cat

rebuild: clean s21_cat