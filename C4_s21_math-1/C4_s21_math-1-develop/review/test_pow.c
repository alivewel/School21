#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define s21_INF 1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_DBL_MAX 1.79769313486231570814527423731704357e+308L
#define s21_EPS     1e-17
#define s21_E       2.71828182845904523536028747135266250

long double s21_exp(double x) {
  long double res = 0;
  if (x != x) res = s21_NAN;
  else if (x == 0.0) res = 1;
  else if (x == -s21_INF) res = 0;
  else if (x == s21_INF) res = x;
  else if (x < 0) res = 1 / s21_exp(-x);
  else {
    long double add = 1;
    long double i = 1;
    res = 1;
    while (fabs((double)add) > s21_EPS) { // замени на свою
      add *= x / i;
      i++;
      res += add;
      if (res > s21_DBL_MAX) {
        res = s21_INF;
        break;
      }
    }
  }

  return res;
}

long double s21_log(double x) {
  double res = 0;
  if (x != x || x < 0) res = s21_NAN;
  else if (x == 0) res = -s21_INF;
  else if (x == 1) res = 0;
  else if (x == s21_INF) res = x;
  else {
    int powCount = 0;
    double prev = 0;
    while (x >= s21_E) {
      x /= s21_E;
      powCount++;
    }
    for (int i = 0; i < 15; i++) {
      prev = res;
      res = prev + 2 * (x - s21_exp(prev)) / (x + s21_exp(prev));
    }
    res += powCount;
  }

  return res;
}

long double s21_pow(double base, double exp) {
  long double res, pow;
  if (base == 0 && exp == 0) {
    res = 1.0;
  } else if (exp == 1) {
    res = base;
  } else if (base == -s21_INF) {
    res = s21_INF;
  }else {
    pow = exp * s21_log(base);
    res = s21_exp(pow);
  }
  return res;
}

int main () {
  printf("pow = %Lf\n", s21_pow(40, 12));
  printf("pow = %f\n", pow(40, 12));
  printf("pow = %.15Lf\n", s21_pow(0.5, 10));
  printf("pow = %.15f\n", pow(0.5, 10));
  printf("pow = %Lf\n", s21_pow(40, 1.2));
  printf("pow = %f\n", pow(40, 1.2));
  printf("pow = %Lf\n", s21_pow(40, 10));
  printf("pow = %Lf\n", (long double)pow(40, 10));
  printf("pow = %f\n", pow(40, 10));
  printf("pow = %Lf\n", s21_pow(35, 10.2));
  printf("pow = %Lf\n", (long double)pow(35, 10.2));
  printf("pow = %f\n", pow(35, 10.2));
  printf("pow = %Lf\n", s21_pow(79.2341, 18.131232));
  printf("pow = %Lf\n", (long double)pow(79.2341, 18.131232));
  printf("pow = %f\n", pow(79.2341, 18.131232));
  printf("pow = %f\n", pow(0, 2));
  printf("pow = %Lf\n", s21_pow(0, 2));
  printf("pow = %f\n", pow(2, 0));
  printf("pow = %Lf\n", s21_pow(2, 0));
  printf("pow = %f\n", pow(0, 0));
  printf("pow = %Lf\n", s21_pow(0, 0));
  printf("pow = %f\n", pow(1, 0));
  printf("pow = %Lf\n", s21_pow(1, 0));
  printf("pow = %f\n", pow(0, 1));
  printf("pow = %Lf\n", s21_pow(0, 1));
  printf("pow = %f\n", pow(1, 1232312));
  printf("pow = %Lf\n", s21_pow(1, 1232312));
  printf("pow = %Lf\n", s21_pow(s21_NAN, 2));
  printf("pow = %f\n", pow(s21_NAN, 2));
  printf("pow = %Lf\n", s21_pow(31, s21_NAN));
  printf("pow = %f\n", pow(31, s21_NAN));
  printf("pow = %Lf\n", s21_pow(31, -s21_NAN));
  printf("pow = %f\n", pow(31, -s21_NAN));
  printf("pow = %Lf\n", s21_pow(-s21_NAN, 2));
  printf("pow = %f\n", pow(-s21_NAN, 2));
  printf("pow = %Lf\n", s21_pow(s21_INF, 2));
  printf("pow = %f\n", pow(s21_INF, 2));

  printf("pow = %Lf\n", s21_pow(-1, 1));
  printf("pow = %f\n", pow(-1, 1));
  printf("pow = %Lf\n", s21_pow(0.8, 10));
  printf("pow = %f\n", pow(0.8, 10));
  printf("pow = %Lf\n", s21_pow(1, 100));
  printf("pow = %f\n", pow(1, 100));
  printf("pow = %Lf\n", s21_pow(100, 1));
  printf("pow = %f\n", pow(100, 1));
  printf("pow = %Lf\n", s21_pow(-0, s21_INF));
  printf("pow = %f\n", pow(-0, s21_INF));
  printf("pow = %Lf\n", s21_pow(0, 95));
  printf("pow = %f\n", pow(0, 95));
  printf("pow = %Lf\n", s21_pow(-s21_INF, s21_INF));
  printf("pow = %f\n", pow(-s21_INF, s21_INF));
  printf("pow = %Lf\n", s21_pow(95, 0));
  printf("pow = %f\n", pow(95, 0));
 
  return(0);
}