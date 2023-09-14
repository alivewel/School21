.PHONY: all test gcov_report check rebuild clean

CC = g++ -Wall -Wextra -Werror -g -std=c++17
GCOVFLAGS = -fprofile-arcs -ftest-coverage
LIBS=-lgtest -lm -lstdc++ -lgmock -pthread

all: test


test: clean
	$(CC) tests/main_test.cc s21_containers.h -o test.out $(LIBS)
	./test.out

gcov_report: clean
	$(CC) $(GCOVFLAGS) tests/main_test.cc -o report.out $(LIBS)
	./report.out
	lcov -t "gcov_report" --ignore-errors mismatch -o report.info --no-external -c -d .
	genhtml -o report/ report.info
	rm -f *.gcno *.gcda *.info report.out *.gcov
	open ./report/index-sort-f.html


check:
	cp ../materials/linters/.clang-format ./
	clang-format -n */*.cc
	clang-format -n */*.h
	clang-format -n */*.tpp

	
	rm -rf .clang-format


rebuild: clean all

clean:
	rm -f *.o *.a *.gcno *.gcda *.info *.out *.gcov
	rm -rf ./report
	rm -rf *.dSYM
	rm -rf output
