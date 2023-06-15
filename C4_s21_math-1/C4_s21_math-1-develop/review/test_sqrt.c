#include <stdio.h>
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

long double s21_sqrt(double x) {
  long double res;
  if (x < 0) {
    res = s21_NAN;
  } else if (x == -0.0) {
    res = -0.0;
  } else if (x == 0.0) {
    res = 0.0;
  }  else {
    res = s21_pow(x, 0.5);
  }
  return res;
}

int main(void) {
  double x = 423123122200.1;
  printf("%.16Lf\n", s21_sqrt(x));
  printf("%.16lf\n", sqrt(x));
  printf("%.16Lf\n", s21_sqrt(-1));
  printf("%.16lf\n", sqrt(-1));
  printf("%.16Lf\n", s21_sqrt(-0.0));
  printf("%.16lf\n", sqrt(-0.0));
  printf("%.16Lf\n", s21_sqrt(0.0));
  printf("%.16lf\n\n", sqrt(0.0));
  printf("%.16Lf\n", s21_sqrt(1));
  printf("%.16lf\n", sqrt(1));
  printf("%.16Lf\n", s21_sqrt(s21_INF));
  printf("%.16lf\n", sqrt(s21_INF));
  printf("%.16Lf\n", s21_sqrt(s21_NAN));
  printf("%.16lf\n", sqrt(s21_NAN));
  printf("%.16Lf\n", s21_sqrt(-1001));
  printf("%.16lf\n", sqrt(-1001));
  printf("%.16Lf\n", s21_sqrt(1001));
  printf("%.16lf\n", sqrt(1001));
  printf("%.16Lf\n", s21_sqrt(123456789));
  printf("%.16lf\n", sqrt(123456789));
  return 0;
}