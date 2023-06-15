#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_INF 1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define s21_PI 3.14159265358979323846264338327950288
#define s21_PI_2 1.57079632679489661923132169163975144
#define s21_PI_4 0.785398163397448309615660845819875721
#define s21_E 2.71828182845904523536028747135266250
#define s21_LN2 0.693147180559945309417232121458176568
#define s21_DBL_MAX 1.79769313486231570814527423731704357e+308L
#define s21_EPS 1e-17
#define s21_TEPS 1e-06
#define s21_M_PI_6 s21_PI_2 / 3.0
#define s21_2_PI 2 * 3.14159265358979323846264338327950288
#define s21_3_PI_2 3 * s21_PI_2

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double x, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double factorial(int x);

#endif  // SRC_S21_MATH_H_
