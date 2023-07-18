# !/bin/bash

./s21_grep -ne main s21_grep.c > s21_grep.txt
grep -ne main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 1"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -vi main s21_grep.c > s21_grep.txt
grep -vi main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 2"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -ni main s21_grep.c > s21_grep.txt
grep -ni main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 3"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -e main s21_grep.c > s21_grep.txt
grep -e main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 4"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -i main s21_grep.c > s21_grep.txt
grep -i main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 5"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -ie main s21_grep.c > s21_grep.txt
grep -ie main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 6"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -sc main s21_grep.c > s21_grep.txt
grep -c main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 7"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -l main s21_grep.c > s21_grep.txt
grep -l main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 8"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -n main s21_grep.c > s21_grep.txt
grep -n main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 9"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -h main s21_grep.c > s21_grep.txt
grep -h main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 10"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -v main s21_grep.c > s21_grep.txt
grep -v main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 11"
  exit 1;
fi
rm s21_grep.txt grep.txt

# ./s21_grep -e main -i s21_grep.c > s21_grep.txt
# grep -e main -i s21_grep.c > grep.txt
# if !(cmp -s s21_grep.txt grep.txt) ; then
# exit 1;
# rm s21_grep.txt grep.txt

# ./s21_grep -h main -i s21_grep.c > s21_grep.txt
# grep -h main -i s21_grep.c > grep.txt
# if !(cmp -s s21_grep.txt grep.txt) ; then
# exit 1;
# rm s21_grep.txt grep.txt

./s21_grep -s main s21_grep.c > s21_grep.txt
grep -s main s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 12"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -o flags s21_grep.c > s21_grep.txt
grep -o flags s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 13"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -c int s21_grep.c > s21_grep.txt
grep -c int s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 14"
  exit 1;
fi
rm s21_grep.txt grep.txt

./s21_grep -vc int s21_grep.c > s21_grep.txt
grep -vc int s21_grep.c > grep.txt
if !(cmp -s s21_grep.txt grep.txt) ; then
  echo "no 15"
  exit 1;
fi
rm s21_grep.txt grep.txt