#!/bin/bash

# TEST FLAGS SOLO
./s21_cat -n s21_cat.c >> s21_cat.txt
cat -n s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 2"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -b s21_cat.c >> s21_cat.txt
cat -b s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 3"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -n s21_cat.c >> s21_cat.txt
cat -n s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 4"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -s s21_cat.c >> s21_cat.txt
cat -s s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 5"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -e s21_cat.c >> s21_cat.txt
cat -e s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
     echo "no 6"
  exit 1;
fi
rm s21_cat.txt cat.txt

# ### TEST FLAGS DOUBLE
./s21_cat -be s21_cat.c >> s21_cat.txt
cat -be s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 7"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bn s21_cat.c >> s21_cat.txt
cat -bn s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 8"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bs s21_cat.c >> s21_cat.txt
cat -bs s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 9"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bt s21_cat.c >> s21_cat.txt
cat -bt s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 10"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -ne s21_cat.c >> s21_cat.txt
cat -ne s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 11"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -ns s21_cat.c >> s21_cat.txt
cat -ns s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 12"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -nt s21_cat.c >> s21_cat.txt
cat -nt s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 13"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -es s21_cat.c >> s21_cat.txt
cat -es s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 14"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -et s21_cat.c >> s21_cat.txt
cat -et s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 15"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -st s21_cat.c >> s21_cat.txt
cat -st s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 16"
  exit 1;
fi
rm s21_cat.txt cat.txt

# TEST FLAGS TRIPLE
./s21_cat -bet s21_cat.c >> s21_cat.txt
cat -bet s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 17"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bes s21_cat.c >> s21_cat.txt
cat -bes s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 18"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -ben s21_cat.c >> s21_cat.txt
cat -ben s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 19"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bns s21_cat.c >> s21_cat.txt
cat -bns s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 20"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bnt s21_cat.c >> s21_cat.txt
cat -bnt s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 21"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bst s21_cat.c >> s21_cat.txt
cat -bst s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 22"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -nes s21_cat.c >> s21_cat.txt
cat -nes s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 23"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -nst s21_cat.c >> s21_cat.txt
cat -nst s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 24"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -net s21_cat.c >> s21_cat.txt
cat -net s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 25"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -est s21_cat.c >> s21_cat.txt
cat -est s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 26"
  exit 1;
fi
rm s21_cat.txt cat.txt

# # TEST FLAGS MIXED
./s21_cat -nest s21_cat.c >> s21_cat.txt
cat -nest s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 27"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -best s21_cat.c >> s21_cat.txt
cat -best s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 28"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bent s21_cat.c >> s21_cat.txt
cat -bent s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 29"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bens s21_cat.c >> s21_cat.txt
cat -bens s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 30"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bnst s21_cat.c >> s21_cat.txt
cat -bnst s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 31"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat -bnst s21_cat.c >> s21_cat.txt
cat -bnst s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 32"
  exit 1;
fi
rm s21_cat.txt cat.txt

./s21_cat --number-nonblank s21_cat.c >> s21_cat.txt
cat -b s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 33"
  exit 1;
fi


./s21_cat --number s21_cat.c >> s21_cat.txt
cat -n s21_cat.c >> cat.txt
if !(cmp -s s21_cat.txt cat.txt) ; then
  echo "no 34"
  exit 1;
fi
rm s21_cat.txt cat.txt
