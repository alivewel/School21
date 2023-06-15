#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) x *= -1;
  return x;
}

long double s21_fabs(double x) {
  long double res = 0;
  if (x == -s21_INF)
    res = s21_INF;
  else if (x == 0.0)
    res = 0.0;
  else if (x != x)
    res = s21_NAN;
  else if (x < 0)
    res = -x;
  else
    res = x;
  return res;
}

long double s21_ceil(double x) {
  long double res = (long double)x;
  if (x == s21_INF)
    res = s21_INF;
  else if (x != x)
    res = s21_NAN;
  else if (x > 0 && x != s21_INF && x != -s21_INF &&
           (long double)x - (long long)x != 0)
    res = (long long)x + 1;
  else if (x <= -1 && x != s21_INF && x != -s21_INF &&
           (long double)x - (long long)x != 0)
    res = (long long)x;
  else if (x > -1 && x < 0)
    res = -0.0;
  else
    res = x;
  return res;
}

long double s21_cos(double x) {
  long double res = 0;
  if (x != x || x == s21_INF || x == -s21_INF)
    res = s21_NAN;
  else {
    if (s21_fabs(x) > 2 * s21_PI) x = s21_fmod(x, 2 * s21_PI);
    for (int i = 0; i < 15; i++) {
      res +=
          (s21_pow(-1.0, i) * s21_pow(x, 2.0 * i)) / (factorial(2 * i) * 1.0);
    }
  }

  return res;
}

long double s21_log(double x) {
  double res = 0;
  if (x != x || x < 0)
    res = s21_NAN;
  else if (x == 0)
    res = -s21_INF;
  else if (x == 1)
    res = 0;
  else if (x == s21_INF)
    res = x;
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

long double s21_sin(double x) {
  long double res = 0;
  if (x != x || x == s21_INF || x == -s21_INF)
    res = s21_NAN;
  else if (x == 0)
    res = x;
  else {
    if (s21_fabs(x) > 2 * s21_PI) x = s21_fmod(x, 2 * s21_PI);
    for (int i = 0; i < 15; i++) {
      res += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / factorial(1 + 2 * i);
    }
  }

  return res;
}

long double s21_tan(double x) {
  long double res = 0;
  if (x != x || x == s21_INF || x == -s21_INF)
    res = s21_NAN;
  else if (x == 0)
    res = x;
  else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}

long double s21_asin(double x) {
  long double res = 0;
  if (x == s21_NAN || x == s21_INF || x == -s21_INF || s21_fabs(x) > 1)
    res = s21_NAN;
  else if (x == 0)
    res = x;
  else {
    res = s21_atan(x / s21_sqrt(1 - x * x));
  }

  return res;
}

long double s21_acos(double x) {
  long double res = 0;
  if (x != x || x == s21_INF || x == -s21_INF || s21_fabs(x) > 1)
    res = s21_NAN;
  else if (x == 1)
    res = 0;
  else if (x == -1)
    res = s21_PI;
  else if (x == 0)
    res = s21_PI_2;
  else if (0 < x && x < 1) {
    res = s21_atan(s21_sqrt(1 - x * x) / x);
  } else {
    res = s21_PI + s21_atan(s21_sqrt(1 - x * x) / x);
  }

  return res;
}

long double s21_atan(double x) {
  long double res = 0;
  if (x != x)
    res = s21_NAN;
  else if (x == 0)
    res = x;
  else if (x == s21_INF)
    res = s21_PI_2;
  else if (x == -s21_INF)
    res = -s21_PI_2;
  else if (x == -1)
    res = -s21_PI_4;
  else if (x == 1)
    res = s21_PI_4;
  else if (s21_fabs(x) < 1) {
    for (int i = 0; i < 5000; i++) {
      res += (s21_pow(-1, i) * s21_pow(x, 1 + 2 * i)) / (1 + 2 * i);
    }
  } else {
    long double sum = 0;
    for (int i = 0; i < 5000; i++) {
      sum += (s21_pow(-1, i) * s21_pow(x, -1 - (2 * i))) / (1 + 2 * i);
    }
    res = (s21_PI * s21_sqrt(s21_pow(x, 2))) / (2 * x) - sum;
  }

  return res;
}

long double factorial(int x) {
  long double res = 0;
  if (x < 0) {
    res = x;
  } else if (x == 0) {
    res = 1;
  } else {
    res = x * factorial(x - 1);
  }

  return res;
}

long double s21_exp(double x) {
  long double res = 0;
  if (x != x)
    res = s21_NAN;
  else if (x == 0.0)
    res = 1;
  else if (x == -s21_INF)
    res = 0;
  else if (x == s21_INF)
    res = x;
  else if (x < 0)
    res = 1 / s21_exp(-x);
  else {
    long double add = 1;
    long double i = 1;
    res = 1;
    while (s21_fabs((double)add) > s21_EPS) {
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

long double s21_pow(double base, double exp) {
  long double res, pow;
  if (base == 0 && exp == 0) {
    res = 1.0;
  } else if (exp == 1) {
    res = base;
  } else if (base == -s21_INF) {
    res = s21_INF;
  } else if (base < 0 && exp - (long int)exp != 0) {
    res = s21_NAN;
  } else {
    pow = exp * s21_log(s21_fabs(base));
    res = s21_exp(pow);
    if ((int)exp % 2 != 0 && base < 0) res *= -1;
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res;
  if (x < 0) {
    res = s21_NAN;
  } else if (x == 0.0) {
    res = x;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}

long double s21_floor(double x) {
  long double res = (long double)x;
  if (x == s21_INF)
    res = s21_INF;
  else if (x != x)
    res = s21_NAN;
  else if (x > 0 && x != s21_INF && x != -s21_INF &&
           (long double)x - (long long)x != 0)
    res = (long long)x;
  else if (x < 0 && x != s21_INF && x != -s21_INF &&
           (long double)x - (long long)x != 0)
    res = (long long)x - 1;
  else
    res = x;
  return res;
}