#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define s21_INF 1.0 / 0.0
#define s21_NAN 0.0 / 0.0

long double s21_fabs(double x) {
  long double res = (long double)x;
  if (res < 0)
    res *= -1;
  else if (res == -0.0)
    res = 0.0;
  else if (res == -s21_INF)
    res = s21_INF;
  else if (res == -s21_NAN)
    res = s21_NAN;
  return res;
}

long double s21_fmod(double x, double y) {
  if (x != x || y != y || y == 0 || x == s21_INF || x == -s21_INF) {
    x = s21_NAN;
  } else if (y != s21_INF && y != -s21_INF) {
    y = s21_fabs(y);
    double mult = y;
    for (int i = 1; mult <= s21_fabs(x); i++) {
      mult = s21_fabs(y);
      mult *= i;
    }
    if (x > 0.0)
      x = x - (mult - y);
    else
      x = x + mult - y;
  }
  return x;
}

int main () {
  printf ("fmod : %.20f\n", fmod(-11, 2));
  printf ("fmod : %.20Lf\n", s21_fmod(-11, 2));
  printf ("fmod : %.20f\n", fmod(-12, -12));
  printf ("fmod : %.20Lf\n\n", s21_fmod(-12, -12));
  printf ("fmod : %.20f\n", fmod(1, 0));
  printf ("fmod : %.20Lf\n", s21_fmod(1, 0)); 
  printf ("fmod : %.20f\n", fmod(0, 1));
  printf ("fmod : %.20Lf\n", s21_fmod(0, 1)); 
  printf ("fmod : %.20f\n", fmod(-3.4, 0));
  printf ("fmod : %.20Lf\n", s21_fmod(-3.4, 0)); 
  printf ("fmod : %.20f\n", fmod(0, -3.4));
  printf ("fmod : %.20Lf\n", s21_fmod(0, -3.4));  
  printf ("fmod : %.20f\n", fmod(s21_NAN, 2));
  printf ("fmod : %.20Lf\n", s21_fmod(s21_NAN, 2));
  printf ("fmod : %.20f\n", fmod(-11, s21_NAN));
  printf ("fmod : %.20Lf\n", s21_fmod(-11, s21_NAN));
  printf ("fmod : %.20f\n", fmod(s21_INF, 2));
  printf ("fmod : %.20Lf\n", s21_fmod(s21_INF, 2));
  printf ("fmod : %.20f\n", fmod(2, s21_INF));
  printf ("fmod : %.20Lf\n", s21_fmod(2, s21_INF));
  printf ("fmod : %.20f\n", fmod(-s21_INF, 2));
  printf ("fmod : %.20Lf\n", s21_fmod(-s21_INF, 2));
  printf ("fmod : %.20f\n", fmod(2, -s21_INF));
  printf ("fmod : %.20Lf\n", s21_fmod(2, -s21_INF));
  printf ("fmod : %.20f\n", fmod(s21_INF, s21_INF));
  printf ("fmod : %.20Lf\n", s21_fmod(s21_INF, s21_INF));
  printf ("fmod : %.20f\n", fmod(-s21_INF, -s21_INF));
  printf ("fmod : %.20Lf\n", s21_fmod(-s21_INF, -s21_INF));
  printf ("\n");
  printf ("fmod : %.20f\n", fmod(0.000001, 1));
  printf ("fmod : %.20Lf\n", s21_fmod(0.000001, 0));
  printf ("fmod : %.20f\n", fmod(1, 0.000001));
  printf ("fmod : %.20Lf\n", s21_fmod(1, 0.000001));
  printf ("fmod : %.20f\n", fmod(1, 0));
  printf ("fmod : %.20Lf\n", s21_fmod(1, 0)); 


  return(0);
}