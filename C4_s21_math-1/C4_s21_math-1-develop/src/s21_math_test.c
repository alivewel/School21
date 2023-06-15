#include "s21_math.h"

#include <check.h>
#include <math.h>

START_TEST(s21_abs_1) {
  int x = 0;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_2) {
  int x = -0;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_3) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_4) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_5) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_6) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_7) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_8) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_9) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_10) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_11) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_12) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_13) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_14) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_15) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_16) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_17) {
  int x = 324342;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_18) {
  int x = -1215752192;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_19) {
  int x = 1215752192;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_20) {
  int x = 143424;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_21) {
  int x = 235235;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_22) {
  int x = 754665;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_23) {
  int x = 1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_24) {
  int x = -1;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_25) {
  int x = 10000000;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_26) {
  int x = -1111111111;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_27) {
  int x = -999999999;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_28) {
  int x = 999999;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_29) {
  int x = 1111111111;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_30) {
  int x = -753535;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_31) {
  int x = -5;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_32) {
  int x = 253535;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_33) {
  int x = 5;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_34) {
  int x = -253535;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(s21_abs_35) {
  int x = 753535;
  int expected = 0;
  int res = 0;

  expected = abs(x);
  res = s21_abs(x);
  ck_assert_int_eq(expected, res);
}
END_TEST

Suite *abs_suite(void) {
  Suite *suite = suite_create("Abs");
  TCase *tc_core = tcase_create("s21_abs");
  tcase_add_test(tc_core, s21_abs_1);
  tcase_add_test(tc_core, s21_abs_2);
  tcase_add_test(tc_core, s21_abs_3);
  tcase_add_test(tc_core, s21_abs_4);
  tcase_add_test(tc_core, s21_abs_5);
  tcase_add_test(tc_core, s21_abs_6);
  tcase_add_test(tc_core, s21_abs_7);
  tcase_add_test(tc_core, s21_abs_8);
  tcase_add_test(tc_core, s21_abs_9);
  tcase_add_test(tc_core, s21_abs_10);
  tcase_add_test(tc_core, s21_abs_11);
  tcase_add_test(tc_core, s21_abs_12);
  tcase_add_test(tc_core, s21_abs_13);
  tcase_add_test(tc_core, s21_abs_14);
  tcase_add_test(tc_core, s21_abs_15);
  tcase_add_test(tc_core, s21_abs_16);
  tcase_add_test(tc_core, s21_abs_17);
  tcase_add_test(tc_core, s21_abs_18);
  tcase_add_test(tc_core, s21_abs_19);
  tcase_add_test(tc_core, s21_abs_20);
  tcase_add_test(tc_core, s21_abs_21);
  tcase_add_test(tc_core, s21_abs_22);
  tcase_add_test(tc_core, s21_abs_23);
  tcase_add_test(tc_core, s21_abs_24);
  tcase_add_test(tc_core, s21_abs_25);
  tcase_add_test(tc_core, s21_abs_26);
  tcase_add_test(tc_core, s21_abs_27);
  tcase_add_test(tc_core, s21_abs_28);
  tcase_add_test(tc_core, s21_abs_29);
  tcase_add_test(tc_core, s21_abs_30);
  tcase_add_test(tc_core, s21_abs_31);
  tcase_add_test(tc_core, s21_abs_32);
  tcase_add_test(tc_core, s21_abs_33);
  tcase_add_test(tc_core, s21_abs_34);
  tcase_add_test(tc_core, s21_abs_35);
  suite_add_tcase(suite, tc_core);
  return suite;
}

// ########################################################################################################################

START_TEST(s21_sin_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_4) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_sin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_sin_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_8) {
  double x = -123456789;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_10) {
  double x = s21_INF;
  long double res = 0;

  res = s21_sin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_sin_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_12) {
  double x = -s21_INF;
  long double res = 0;

  res = s21_sin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_sin_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_27) {
  double x = -s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_36) {
  double x = -45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_38) {
  double x = -10.489156;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_40) {
  double x = -5.454;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_42) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_44) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sin_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = sin(x);
  res = s21_sin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

Suite *ersin_suite(void) {
  Suite *suite = suite_create("Sin");
  TCase *tc_core = tcase_create("s21_sin");
  tcase_add_test(tc_core, s21_sin_1);
  tcase_add_test(tc_core, s21_sin_2);
  tcase_add_test(tc_core, s21_sin_3);
  tcase_add_test(tc_core, s21_sin_4);
  tcase_add_test(tc_core, s21_sin_5);
  tcase_add_test(tc_core, s21_sin_6);
  tcase_add_test(tc_core, s21_sin_7);
  tcase_add_test(tc_core, s21_sin_8);
  tcase_add_test(tc_core, s21_sin_9);
  tcase_add_test(tc_core, s21_sin_10);
  tcase_add_test(tc_core, s21_sin_11);
  tcase_add_test(tc_core, s21_sin_12);
  tcase_add_test(tc_core, s21_sin_13);
  tcase_add_test(tc_core, s21_sin_14);
  tcase_add_test(tc_core, s21_sin_15);
  tcase_add_test(tc_core, s21_sin_16);
  tcase_add_test(tc_core, s21_sin_17);
  tcase_add_test(tc_core, s21_sin_18);
  tcase_add_test(tc_core, s21_sin_19);
  tcase_add_test(tc_core, s21_sin_20);
  tcase_add_test(tc_core, s21_sin_21);
  tcase_add_test(tc_core, s21_sin_22);
  tcase_add_test(tc_core, s21_sin_23);
  tcase_add_test(tc_core, s21_sin_24);
  tcase_add_test(tc_core, s21_sin_25);
  tcase_add_test(tc_core, s21_sin_26);
  tcase_add_test(tc_core, s21_sin_27);
  tcase_add_test(tc_core, s21_sin_28);
  tcase_add_test(tc_core, s21_sin_29);
  tcase_add_test(tc_core, s21_sin_30);
  tcase_add_test(tc_core, s21_sin_31);
  tcase_add_test(tc_core, s21_sin_32);
  tcase_add_test(tc_core, s21_sin_33);
  tcase_add_test(tc_core, s21_sin_34);
  tcase_add_test(tc_core, s21_sin_35);
  tcase_add_test(tc_core, s21_sin_36);
  tcase_add_test(tc_core, s21_sin_37);
  tcase_add_test(tc_core, s21_sin_38);
  tcase_add_test(tc_core, s21_sin_39);
  tcase_add_test(tc_core, s21_sin_40);
  tcase_add_test(tc_core, s21_sin_41);
  tcase_add_test(tc_core, s21_sin_42);
  tcase_add_test(tc_core, s21_sin_43);
  tcase_add_test(tc_core, s21_sin_44);
  tcase_add_test(tc_core, s21_sin_45);
  tcase_add_test(tc_core, s21_sin_46);
  tcase_add_test(tc_core, s21_sin_47);
  tcase_add_test(tc_core, s21_sin_48);
  tcase_add_test(tc_core, s21_sin_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}
// ########################################################################################################################

START_TEST(s21_acos_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_4) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_acos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_acos_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_10) {
  double x = s21_INF;
  long double res = 0;

  res = s21_acos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_acos_12) {
  double x = -s21_INF;
  long double res = 0;

  res = s21_acos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_acos_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_36) {
  double x = -45645689.456834;
  long double res = 0;

  res = s21_acos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_acos_37) {
  double x = 45645689.456834;
  long double res = 0;

  res = s21_acos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_acos_43) {
  double x = 21.0;
  long double res = 0;

  res = s21_acos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_acos_44) {
  double x = -21.0;
  long double res = 0;

  res = s21_acos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_acos_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_acos_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = acos(x);
  res = s21_acos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_asin_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_4) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_10) {
  double x = s21_INF;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_12) {
  double x = -s21_INF;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_36) {
  double x = -45645689.456834;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_37) {
  double x = 45645689.456834;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_38) {
  double x = -10.489156;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_39) {
  double x = 10.489156;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_42) {
  double x = -21.0;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_43) {
  double x = 21.0;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_44) {
  double x = -21.0;
  long double res = 0;

  res = s21_asin(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_asin_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_asin_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = asin(x);
  res = s21_asin(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_atan_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_4) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_atan(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_atan_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_8) {
  double x = -123456789;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_10) {
  double x = s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_12) {
  double x = -s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_27) {
  double x = -s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_36) {
  double x = -45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_38) {
  double x = -10.489156;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_40) {
  double x = -5.454;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_42) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_44) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_atan_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = atan(x);
  res = s21_atan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_ceil_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_4) {
  double x = s21_NAN;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_ceil_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_8) {
  double x = -123456789;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_10) {
  double x = s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_ceil_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_12) {
  double x = -s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_ceil_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_27) {
  double x = -s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_36) {
  double x = -45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_38) {
  double x = -10.489156;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_40) {
  double x = -5.454;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_42) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_44) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_ceil_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = ceil(x);
  res = s21_ceil(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_cos_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_4) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_cos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_cos_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_8) {
  double x = -123456789;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_10) {
  double x = s21_INF;
  long double res = 0;

  res = s21_cos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_cos_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_12) {
  double x = -s21_INF;
  long double res = 0;

  res = s21_cos(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_cos_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_27) {
  double x = -s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_36) {
  double x = -45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_38) {
  double x = -10.489156;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_40) {
  double x = -5.454;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_42) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_44) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_cos_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = cos(x);
  res = s21_cos(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_exp_1) {
  double x = 0.32431;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_2) {
  double x = 324524452453.021331;
  long double res = 0;

  res = s21_exp(x);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_exp_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_4) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_exp(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_exp_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_6) {
  double x = 999999;
  long double res = 0;

  res = s21_exp(x);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_exp_7) {
  double x = 123456789;
  long double res = 0;

  res = s21_exp(x);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_exp_8) {
  double x = 0.725648;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_9) {
  double x = -0.543231;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_10) {
  double x = s21_INF;
  long double res = 0;

  res = s21_exp(x);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_exp_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_12) {
  double x = -s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_23) {
  double x = 0.00524;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_exp_25) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = exp(x);
  res = s21_exp(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_fabs_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_4) {
  double x = s21_NAN;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_fabs_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_8) {
  double x = -123456789;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_10) {
  double x = s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_fabs_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_12) {
  double x = -s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_fabs_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST
START_TEST(s21_fabs_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_27) {
  double x = -s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_36) {
  double x = -45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_38) {
  double x = -10.489156;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_40) {
  double x = -5.454;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_42) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_44) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fabs_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = fabs(x);
  res = s21_fabs(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_floor_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_4) {
  double x = s21_NAN;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_floor_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_8) {
  double x = -123456789;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_10) {
  double x = s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_floor_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_12) {
  double x = -s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_floor_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_27) {
  double x = -s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_36) {
  double x = -45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_38) {
  double x = -10.489156;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_40) {
  double x = -5.454;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_42) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_44) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_floor_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = floor(x);
  res = s21_floor(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_fmod_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_4) {
  double x = s21_NAN;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_fmod_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 13252523);
  res = s21_fmod(x, 13252523);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_8) {
  double x = -123456789;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, -12.239721);
  res = s21_fmod(x, -12.239721);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_10) {
  double x = s21_INF;
  long double res = 0;

  res = s21_fmod(x, s21_INF);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, s21_PI);
  res = s21_fmod(x, s21_PI);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_12) {
  double x = -s21_INF;
  long double res = 0;

  res = s21_fmod(x, 2);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 20);
  res = s21_fmod(x, 20);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, -2);
  res = s21_fmod(x, -2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, -2);
  res = s21_fmod(x, -2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_24) {
  double x = s21_INF;
  long double res = 0;

  res = s21_fmod(x, s21_INF);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_27) {
  double x = -s21_INF;
  long double res = 0;

  res = s21_fmod(x, s21_INF);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_28) {
  double x = s21_INF;
  long double res = 0;

  res = s21_fmod(x, -s21_INF);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_30) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_fmod(x, s21_NAN);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_31) {
  double x = -0.5;
  long double res = 0;

  res = s21_fmod(x, s21_NAN);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_32) {
  double x = 53535;
  long double res = 0;

  res = s21_fmod(x, s21_NAN);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_33) {
  double x = 532;
  long double res = 0;

  res = s21_fmod(x, -s21_NAN);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_fmod_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_38) {
  double x = -10.489156;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_40) {
  double x = -5.454;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_42) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_44) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_fmod_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = fmod(x, 2);
  res = s21_fmod(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_log_1) {
  double x = 1.0;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_2) {
  double x = 1233;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_3) {
  double x = 0;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_log_4) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_5) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_8) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_9) {
  double x = 12.239721;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_10) {
  double x = s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_log_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_12) {
  double x = s21_INF;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_log_13) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_15) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_17) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_19) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_21) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_infinite(expected);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_log_23) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_infinite(expected);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_log_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_25) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_26) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_27) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_30) {
  double x = -0.753535;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_31) {
  double x = -0.5;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_32) {
  double x = -0.253535;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_36) {
  double x = -45645689.456834;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_38) {
  double x = -10.489156;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_40) {
  double x = -5.454;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_42) {
  double x = -21.0;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_44) {
  double x = -21.0;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_46) {
  double x = -0.253535;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_log_48) {
  double x = -0.001;
  long double res = 0;

  res = s21_log(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_log_49) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = log(x);
  res = s21_log(x);
  ck_assert_ldouble_infinite(expected);
  ck_assert_ldouble_infinite(res);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_pow_1) {
  long double expected = 0;
  long double res = 0;

  expected = pow(5.1, 8);
  res = s21_pow(5.1, 8);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0);
  res = s21_pow(x, 0);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_4) {
  double x = s21_NAN;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, s21_NAN);
  res = s21_pow(x, s21_NAN);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_pow_5) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_pow(x, 2);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_pow_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.001);
  res = s21_pow(x, 0.001);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_7) {
  double x = 12345;
  long double res = 0;

  res = s21_pow(x, s21_NAN);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_pow_8) {
  double x = -12345.123;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, -123);
  res = s21_pow(x, -123);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_10) {
  double x = s21_INF;
  long double res = 0;

  res = s21_pow(x, s21_INF);
  ck_assert_ldouble_infinite(res);
}
END_TEST

START_TEST(s21_pow_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, s21_PI);
  res = s21_pow(x, s21_PI);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_12) {
  double x = -s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_pow_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_15) {
  double x = -s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 2);
  res = s21_pow(x, 2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_25) {
  double x = s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, -s21_INF);
  res = s21_pow(x, -s21_INF);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, -2);
  res = s21_pow(x, -2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_27) {
  double x = -s21_3_PI_2;
  long double res = 0;

  res = s21_pow(x, s21_3_PI_2);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_pow_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, -s21_3_PI_2);
  res = s21_pow(x, -s21_3_PI_2);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, s21_2_PI);
  res = s21_pow(x, s21_2_PI);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_44) {
  double x = -21.0;
  long double res = 0;

  res = s21_pow(x, 0.1);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_pow_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_46) {
  double x = -0.253535;
  long double res = 0;

  res = s21_pow(x, 0.1);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_pow_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_pow_48) {
  double x = -0.000001;
  long double res = 0;

  res = s21_pow(x, 0.1);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_pow_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = pow(x, 0.1);
  res = s21_pow(x, 0.1);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_sqrt_1) {
  double x = -1.0;
  long double res = 0;

  res = s21_sqrt(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_sqrt_2) {
  double x = -1233;
  long double res = 0;

  res = s21_sqrt(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_sqrt_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_4) {
  double x = s21_NAN;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_nan(res);
  ck_assert_ldouble_nan(expected);
}
END_TEST

START_TEST(s21_sqrt_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_10) {
  double x = s21_INF;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_infinite(res);
  ck_assert_ldouble_infinite(expected);
}
END_TEST

START_TEST(s21_sqrt_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_14) {
  double x = s21_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_28) {
  double x = s21_3_PI_2;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_sqrt_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = sqrt(x);
  res = s21_sqrt(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

// ########################################################################################################################

START_TEST(s21_tan_1) {
  double x = -1.0;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_2) {
  double x = -1233;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_3) {
  double x = 0;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_4) {
  double x = s21_NAN;
  long double res = 0;

  res = s21_tan(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_tan_5) {
  double x = -1;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_6) {
  double x = 1;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_7) {
  double x = 123456789;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_8) {
  double x = -123456789;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_9) {
  double x = -12.239721;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_10) {
  double x = s21_INF;
  long double res = 0;

  res = s21_tan(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_tan_11) {
  double x = s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_12) {
  double x = -s21_INF;
  long double res = 0;

  res = s21_tan(x);
  ck_assert_ldouble_nan(res);
}
END_TEST

START_TEST(s21_tan_13) {
  double x = -s21_PI;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_16) {
  double x = s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_17) {
  double x = -s21_PI_4;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_18) {
  double x = s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_19) {
  double x = -s21_M_PI_6;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_20) {
  double x = s21_E;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_21) {
  double x = -s21_E;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_22) {
  double x = 0.0;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_23) {
  double x = -0.0;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_24) {
  double x = 0.1;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_25) {
  double x = -0.1;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST
START_TEST(s21_tan_26) {
  double x = -s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_29) {
  double x = s21_2_PI;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_30) {
  double x = -0.753535;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_31) {
  double x = -0.5;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_32) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_33) {
  double x = 0.5;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_34) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_35) {
  double x = 0.753535;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_36) {
  double x = -45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_37) {
  double x = 45645689.456834;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_38) {
  double x = -10.489156;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_39) {
  double x = 10.489156;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_40) {
  double x = -5.454;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_41) {
  double x = 5.454;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_42) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_43) {
  double x = 21.0;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_44) {
  double x = -21.0;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_45) {
  double x = 0.253535;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_46) {
  double x = -0.253535;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_47) {
  double x = 0.000001;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_48) {
  double x = -0.000001;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

START_TEST(s21_tan_49) {
  double x = -0;
  long double expected = 0;
  long double res = 0;

  expected = tan(x);
  res = s21_tan(x);
  ck_assert_ldouble_eq_tol(expected, res, s21_TEPS);
}
END_TEST

Suite *acos_suite(void) {
  Suite *suite = suite_create("acos");
  TCase *tc_core = tcase_create("s21_acos");
  tcase_add_test(tc_core, s21_acos_1);
  tcase_add_test(tc_core, s21_acos_3);
  tcase_add_test(tc_core, s21_acos_4);
  tcase_add_test(tc_core, s21_acos_5);
  tcase_add_test(tc_core, s21_acos_6);
  tcase_add_test(tc_core, s21_acos_10);
  tcase_add_test(tc_core, s21_acos_12);
  tcase_add_test(tc_core, s21_acos_16);
  tcase_add_test(tc_core, s21_acos_17);
  tcase_add_test(tc_core, s21_acos_18);
  tcase_add_test(tc_core, s21_acos_19);
  tcase_add_test(tc_core, s21_acos_22);
  tcase_add_test(tc_core, s21_acos_23);
  tcase_add_test(tc_core, s21_acos_24);
  tcase_add_test(tc_core, s21_acos_25);
  tcase_add_test(tc_core, s21_acos_30);
  tcase_add_test(tc_core, s21_acos_31);
  tcase_add_test(tc_core, s21_acos_32);
  tcase_add_test(tc_core, s21_acos_33);
  tcase_add_test(tc_core, s21_acos_34);
  tcase_add_test(tc_core, s21_acos_35);
  tcase_add_test(tc_core, s21_acos_36);
  tcase_add_test(tc_core, s21_acos_37);
  tcase_add_test(tc_core, s21_acos_43);
  tcase_add_test(tc_core, s21_acos_44);
  tcase_add_test(tc_core, s21_acos_45);
  tcase_add_test(tc_core, s21_acos_46);
  tcase_add_test(tc_core, s21_acos_47);
  tcase_add_test(tc_core, s21_acos_48);
  tcase_add_test(tc_core, s21_acos_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *asin_suite(void) {
  Suite *suite = suite_create("asin");
  TCase *tc_core = tcase_create("s21_asin");
  tcase_add_test(tc_core, s21_asin_1);
  tcase_add_test(tc_core, s21_asin_3);
  tcase_add_test(tc_core, s21_asin_4);
  tcase_add_test(tc_core, s21_asin_5);
  tcase_add_test(tc_core, s21_asin_6);
  tcase_add_test(tc_core, s21_asin_10);
  tcase_add_test(tc_core, s21_asin_12);
  tcase_add_test(tc_core, s21_asin_16);
  tcase_add_test(tc_core, s21_asin_17);
  tcase_add_test(tc_core, s21_asin_18);
  tcase_add_test(tc_core, s21_asin_19);
  tcase_add_test(tc_core, s21_asin_22);
  tcase_add_test(tc_core, s21_asin_23);
  tcase_add_test(tc_core, s21_asin_24);
  tcase_add_test(tc_core, s21_asin_25);
  tcase_add_test(tc_core, s21_asin_30);
  tcase_add_test(tc_core, s21_asin_31);
  tcase_add_test(tc_core, s21_asin_32);
  tcase_add_test(tc_core, s21_asin_33);
  tcase_add_test(tc_core, s21_asin_34);
  tcase_add_test(tc_core, s21_asin_35);
  tcase_add_test(tc_core, s21_asin_36);
  tcase_add_test(tc_core, s21_asin_37);
  tcase_add_test(tc_core, s21_asin_38);
  tcase_add_test(tc_core, s21_asin_39);
  tcase_add_test(tc_core, s21_asin_42);
  tcase_add_test(tc_core, s21_asin_43);
  tcase_add_test(tc_core, s21_asin_44);
  tcase_add_test(tc_core, s21_asin_45);
  tcase_add_test(tc_core, s21_asin_46);
  tcase_add_test(tc_core, s21_asin_47);
  tcase_add_test(tc_core, s21_asin_48);
  tcase_add_test(tc_core, s21_asin_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}
Suite *atan_suite(void) {
  Suite *suite = suite_create("atan");
  TCase *tc_core = tcase_create("s21_atan");
  tcase_add_test(tc_core, s21_atan_1);
  tcase_add_test(tc_core, s21_atan_2);
  tcase_add_test(tc_core, s21_atan_3);
  tcase_add_test(tc_core, s21_atan_4);
  tcase_add_test(tc_core, s21_atan_5);
  tcase_add_test(tc_core, s21_atan_6);
  tcase_add_test(tc_core, s21_atan_7);
  tcase_add_test(tc_core, s21_atan_8);
  tcase_add_test(tc_core, s21_atan_9);
  tcase_add_test(tc_core, s21_atan_10);
  tcase_add_test(tc_core, s21_atan_11);
  tcase_add_test(tc_core, s21_atan_12);
  tcase_add_test(tc_core, s21_atan_13);
  tcase_add_test(tc_core, s21_atan_14);
  tcase_add_test(tc_core, s21_atan_15);
  tcase_add_test(tc_core, s21_atan_16);
  tcase_add_test(tc_core, s21_atan_17);
  tcase_add_test(tc_core, s21_atan_18);
  tcase_add_test(tc_core, s21_atan_19);
  tcase_add_test(tc_core, s21_atan_20);
  tcase_add_test(tc_core, s21_atan_21);
  tcase_add_test(tc_core, s21_atan_22);
  tcase_add_test(tc_core, s21_atan_23);
  tcase_add_test(tc_core, s21_atan_24);
  tcase_add_test(tc_core, s21_atan_25);
  tcase_add_test(tc_core, s21_atan_26);
  tcase_add_test(tc_core, s21_atan_27);
  tcase_add_test(tc_core, s21_atan_28);
  tcase_add_test(tc_core, s21_atan_29);
  tcase_add_test(tc_core, s21_atan_30);
  tcase_add_test(tc_core, s21_atan_31);
  tcase_add_test(tc_core, s21_atan_32);
  tcase_add_test(tc_core, s21_atan_33);
  tcase_add_test(tc_core, s21_atan_34);
  tcase_add_test(tc_core, s21_atan_35);
  tcase_add_test(tc_core, s21_atan_36);
  tcase_add_test(tc_core, s21_atan_37);
  tcase_add_test(tc_core, s21_atan_38);
  tcase_add_test(tc_core, s21_atan_39);
  tcase_add_test(tc_core, s21_atan_40);
  tcase_add_test(tc_core, s21_atan_41);
  tcase_add_test(tc_core, s21_atan_42);
  tcase_add_test(tc_core, s21_atan_43);
  tcase_add_test(tc_core, s21_atan_44);
  tcase_add_test(tc_core, s21_atan_45);
  tcase_add_test(tc_core, s21_atan_46);
  tcase_add_test(tc_core, s21_atan_47);
  tcase_add_test(tc_core, s21_atan_48);
  tcase_add_test(tc_core, s21_atan_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *ceil_suite(void) {
  Suite *suite = suite_create("ceil");
  TCase *tc_core = tcase_create("s21_ceil");
  tcase_add_test(tc_core, s21_ceil_1);
  tcase_add_test(tc_core, s21_ceil_2);
  tcase_add_test(tc_core, s21_ceil_3);
  tcase_add_test(tc_core, s21_ceil_4);
  tcase_add_test(tc_core, s21_ceil_5);
  tcase_add_test(tc_core, s21_ceil_6);
  tcase_add_test(tc_core, s21_ceil_7);
  tcase_add_test(tc_core, s21_ceil_8);
  tcase_add_test(tc_core, s21_ceil_9);
  tcase_add_test(tc_core, s21_ceil_10);
  tcase_add_test(tc_core, s21_ceil_11);
  tcase_add_test(tc_core, s21_ceil_12);
  tcase_add_test(tc_core, s21_ceil_13);
  tcase_add_test(tc_core, s21_ceil_14);
  tcase_add_test(tc_core, s21_ceil_15);
  tcase_add_test(tc_core, s21_ceil_16);
  tcase_add_test(tc_core, s21_ceil_17);
  tcase_add_test(tc_core, s21_ceil_18);
  tcase_add_test(tc_core, s21_ceil_19);
  tcase_add_test(tc_core, s21_ceil_20);
  tcase_add_test(tc_core, s21_ceil_21);
  tcase_add_test(tc_core, s21_ceil_22);
  tcase_add_test(tc_core, s21_ceil_23);
  tcase_add_test(tc_core, s21_ceil_24);
  tcase_add_test(tc_core, s21_ceil_25);
  tcase_add_test(tc_core, s21_ceil_26);
  tcase_add_test(tc_core, s21_ceil_27);
  tcase_add_test(tc_core, s21_ceil_28);
  tcase_add_test(tc_core, s21_ceil_29);
  tcase_add_test(tc_core, s21_ceil_30);
  tcase_add_test(tc_core, s21_ceil_31);
  tcase_add_test(tc_core, s21_ceil_32);
  tcase_add_test(tc_core, s21_ceil_33);
  tcase_add_test(tc_core, s21_ceil_34);
  tcase_add_test(tc_core, s21_ceil_35);
  tcase_add_test(tc_core, s21_ceil_36);
  tcase_add_test(tc_core, s21_ceil_37);
  tcase_add_test(tc_core, s21_ceil_38);
  tcase_add_test(tc_core, s21_ceil_39);
  tcase_add_test(tc_core, s21_ceil_40);
  tcase_add_test(tc_core, s21_ceil_41);
  tcase_add_test(tc_core, s21_ceil_42);
  tcase_add_test(tc_core, s21_ceil_43);
  tcase_add_test(tc_core, s21_ceil_44);
  tcase_add_test(tc_core, s21_ceil_45);
  tcase_add_test(tc_core, s21_ceil_46);
  tcase_add_test(tc_core, s21_ceil_47);
  tcase_add_test(tc_core, s21_ceil_48);
  tcase_add_test(tc_core, s21_ceil_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *cos_suite(void) {
  Suite *suite = suite_create("cos");
  TCase *tc_core = tcase_create("s21_cos");
  tcase_add_test(tc_core, s21_cos_1);
  tcase_add_test(tc_core, s21_cos_2);
  tcase_add_test(tc_core, s21_cos_3);
  tcase_add_test(tc_core, s21_cos_4);
  tcase_add_test(tc_core, s21_cos_5);
  tcase_add_test(tc_core, s21_cos_6);
  tcase_add_test(tc_core, s21_cos_7);
  tcase_add_test(tc_core, s21_cos_8);
  tcase_add_test(tc_core, s21_cos_9);
  tcase_add_test(tc_core, s21_cos_10);
  tcase_add_test(tc_core, s21_cos_11);
  tcase_add_test(tc_core, s21_cos_12);
  tcase_add_test(tc_core, s21_cos_13);
  tcase_add_test(tc_core, s21_cos_14);
  tcase_add_test(tc_core, s21_cos_15);
  tcase_add_test(tc_core, s21_cos_16);
  tcase_add_test(tc_core, s21_cos_17);
  tcase_add_test(tc_core, s21_cos_18);
  tcase_add_test(tc_core, s21_cos_19);
  tcase_add_test(tc_core, s21_cos_20);
  tcase_add_test(tc_core, s21_cos_21);
  tcase_add_test(tc_core, s21_cos_22);
  tcase_add_test(tc_core, s21_cos_23);
  tcase_add_test(tc_core, s21_cos_24);
  tcase_add_test(tc_core, s21_cos_25);
  tcase_add_test(tc_core, s21_cos_26);
  tcase_add_test(tc_core, s21_cos_27);
  tcase_add_test(tc_core, s21_cos_28);
  tcase_add_test(tc_core, s21_cos_29);
  tcase_add_test(tc_core, s21_cos_30);
  tcase_add_test(tc_core, s21_cos_31);
  tcase_add_test(tc_core, s21_cos_32);
  tcase_add_test(tc_core, s21_cos_33);
  tcase_add_test(tc_core, s21_cos_34);
  tcase_add_test(tc_core, s21_cos_35);
  tcase_add_test(tc_core, s21_cos_36);
  tcase_add_test(tc_core, s21_cos_37);
  tcase_add_test(tc_core, s21_cos_38);
  tcase_add_test(tc_core, s21_cos_39);
  tcase_add_test(tc_core, s21_cos_40);
  tcase_add_test(tc_core, s21_cos_41);
  tcase_add_test(tc_core, s21_cos_42);
  tcase_add_test(tc_core, s21_cos_43);
  tcase_add_test(tc_core, s21_cos_44);
  tcase_add_test(tc_core, s21_cos_45);
  tcase_add_test(tc_core, s21_cos_46);
  tcase_add_test(tc_core, s21_cos_47);
  tcase_add_test(tc_core, s21_cos_48);
  tcase_add_test(tc_core, s21_cos_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}
Suite *exp_suite(void) {
  Suite *suite = suite_create("exp");
  TCase *tc_core = tcase_create("s21_exp");
  tcase_add_test(tc_core, s21_exp_1);
  tcase_add_test(tc_core, s21_exp_2);
  tcase_add_test(tc_core, s21_exp_3);
  tcase_add_test(tc_core, s21_exp_4);
  tcase_add_test(tc_core, s21_exp_5);
  tcase_add_test(tc_core, s21_exp_6);
  tcase_add_test(tc_core, s21_exp_7);
  tcase_add_test(tc_core, s21_exp_8);
  tcase_add_test(tc_core, s21_exp_9);
  tcase_add_test(tc_core, s21_exp_10);
  tcase_add_test(tc_core, s21_exp_11);
  tcase_add_test(tc_core, s21_exp_12);
  tcase_add_test(tc_core, s21_exp_13);
  tcase_add_test(tc_core, s21_exp_14);
  tcase_add_test(tc_core, s21_exp_15);
  tcase_add_test(tc_core, s21_exp_16);
  tcase_add_test(tc_core, s21_exp_17);
  tcase_add_test(tc_core, s21_exp_18);
  tcase_add_test(tc_core, s21_exp_19);
  tcase_add_test(tc_core, s21_exp_20);
  tcase_add_test(tc_core, s21_exp_21);
  tcase_add_test(tc_core, s21_exp_22);
  tcase_add_test(tc_core, s21_exp_23);
  tcase_add_test(tc_core, s21_exp_24);
  tcase_add_test(tc_core, s21_exp_25);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *fabs_suite(void) {
  Suite *suite = suite_create("fabs");
  TCase *tc_core = tcase_create("s21_fabs");
  tcase_add_test(tc_core, s21_fabs_1);
  tcase_add_test(tc_core, s21_fabs_2);
  tcase_add_test(tc_core, s21_fabs_3);
  tcase_add_test(tc_core, s21_fabs_4);
  tcase_add_test(tc_core, s21_fabs_5);
  tcase_add_test(tc_core, s21_fabs_6);
  tcase_add_test(tc_core, s21_fabs_7);
  tcase_add_test(tc_core, s21_fabs_8);
  tcase_add_test(tc_core, s21_fabs_9);
  tcase_add_test(tc_core, s21_fabs_10);
  tcase_add_test(tc_core, s21_fabs_11);
  tcase_add_test(tc_core, s21_fabs_12);
  tcase_add_test(tc_core, s21_fabs_13);
  tcase_add_test(tc_core, s21_fabs_14);
  tcase_add_test(tc_core, s21_fabs_15);
  tcase_add_test(tc_core, s21_fabs_16);
  tcase_add_test(tc_core, s21_fabs_17);
  tcase_add_test(tc_core, s21_fabs_18);
  tcase_add_test(tc_core, s21_fabs_19);
  tcase_add_test(tc_core, s21_fabs_20);
  tcase_add_test(tc_core, s21_fabs_21);
  tcase_add_test(tc_core, s21_fabs_22);
  tcase_add_test(tc_core, s21_fabs_23);
  tcase_add_test(tc_core, s21_fabs_24);
  tcase_add_test(tc_core, s21_fabs_25);
  tcase_add_test(tc_core, s21_fabs_26);
  tcase_add_test(tc_core, s21_fabs_27);
  tcase_add_test(tc_core, s21_fabs_28);
  tcase_add_test(tc_core, s21_fabs_29);
  tcase_add_test(tc_core, s21_fabs_30);
  tcase_add_test(tc_core, s21_fabs_31);
  tcase_add_test(tc_core, s21_fabs_32);
  tcase_add_test(tc_core, s21_fabs_33);
  tcase_add_test(tc_core, s21_fabs_34);
  tcase_add_test(tc_core, s21_fabs_35);
  tcase_add_test(tc_core, s21_fabs_36);
  tcase_add_test(tc_core, s21_fabs_37);
  tcase_add_test(tc_core, s21_fabs_38);
  tcase_add_test(tc_core, s21_fabs_39);
  tcase_add_test(tc_core, s21_fabs_40);
  tcase_add_test(tc_core, s21_fabs_41);
  tcase_add_test(tc_core, s21_fabs_42);
  tcase_add_test(tc_core, s21_fabs_43);
  tcase_add_test(tc_core, s21_fabs_44);
  tcase_add_test(tc_core, s21_fabs_45);
  tcase_add_test(tc_core, s21_fabs_46);
  tcase_add_test(tc_core, s21_fabs_47);
  tcase_add_test(tc_core, s21_fabs_48);
  tcase_add_test(tc_core, s21_fabs_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *floor_suite(void) {
  Suite *suite = suite_create("floor");
  TCase *tc_core = tcase_create("s21_floor");
  tcase_add_test(tc_core, s21_floor_1);
  tcase_add_test(tc_core, s21_floor_2);
  tcase_add_test(tc_core, s21_floor_3);
  tcase_add_test(tc_core, s21_floor_4);
  tcase_add_test(tc_core, s21_floor_5);
  tcase_add_test(tc_core, s21_floor_6);
  tcase_add_test(tc_core, s21_floor_7);
  tcase_add_test(tc_core, s21_floor_8);
  tcase_add_test(tc_core, s21_floor_9);
  tcase_add_test(tc_core, s21_floor_10);
  tcase_add_test(tc_core, s21_floor_11);
  tcase_add_test(tc_core, s21_floor_12);
  tcase_add_test(tc_core, s21_floor_13);
  tcase_add_test(tc_core, s21_floor_14);
  tcase_add_test(tc_core, s21_floor_15);
  tcase_add_test(tc_core, s21_floor_16);
  tcase_add_test(tc_core, s21_floor_17);
  tcase_add_test(tc_core, s21_floor_18);
  tcase_add_test(tc_core, s21_floor_19);
  tcase_add_test(tc_core, s21_floor_20);
  tcase_add_test(tc_core, s21_floor_21);
  tcase_add_test(tc_core, s21_floor_22);
  tcase_add_test(tc_core, s21_floor_23);
  tcase_add_test(tc_core, s21_floor_24);
  tcase_add_test(tc_core, s21_floor_25);
  tcase_add_test(tc_core, s21_floor_26);
  tcase_add_test(tc_core, s21_floor_27);
  tcase_add_test(tc_core, s21_floor_28);
  tcase_add_test(tc_core, s21_floor_29);
  tcase_add_test(tc_core, s21_floor_30);
  tcase_add_test(tc_core, s21_floor_31);
  tcase_add_test(tc_core, s21_floor_32);
  tcase_add_test(tc_core, s21_floor_33);
  tcase_add_test(tc_core, s21_floor_34);
  tcase_add_test(tc_core, s21_floor_35);
  tcase_add_test(tc_core, s21_floor_36);
  tcase_add_test(tc_core, s21_floor_37);
  tcase_add_test(tc_core, s21_floor_38);
  tcase_add_test(tc_core, s21_floor_39);
  tcase_add_test(tc_core, s21_floor_40);
  tcase_add_test(tc_core, s21_floor_41);
  tcase_add_test(tc_core, s21_floor_42);
  tcase_add_test(tc_core, s21_floor_43);
  tcase_add_test(tc_core, s21_floor_44);
  tcase_add_test(tc_core, s21_floor_45);
  tcase_add_test(tc_core, s21_floor_46);
  tcase_add_test(tc_core, s21_floor_47);
  tcase_add_test(tc_core, s21_floor_48);
  tcase_add_test(tc_core, s21_floor_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *fmod_suite(void) {
  Suite *suite = suite_create("fmod");
  TCase *tc_core = tcase_create("s21_fmod");
  tcase_add_test(tc_core, s21_fmod_1);
  tcase_add_test(tc_core, s21_fmod_2);
  tcase_add_test(tc_core, s21_fmod_3);
  tcase_add_test(tc_core, s21_fmod_4);
  tcase_add_test(tc_core, s21_fmod_5);
  tcase_add_test(tc_core, s21_fmod_6);
  tcase_add_test(tc_core, s21_fmod_7);
  tcase_add_test(tc_core, s21_fmod_8);
  tcase_add_test(tc_core, s21_fmod_9);
  tcase_add_test(tc_core, s21_fmod_10);
  tcase_add_test(tc_core, s21_fmod_11);
  tcase_add_test(tc_core, s21_fmod_12);
  tcase_add_test(tc_core, s21_fmod_13);
  tcase_add_test(tc_core, s21_fmod_14);
  tcase_add_test(tc_core, s21_fmod_15);
  tcase_add_test(tc_core, s21_fmod_16);
  tcase_add_test(tc_core, s21_fmod_17);
  tcase_add_test(tc_core, s21_fmod_18);
  tcase_add_test(tc_core, s21_fmod_19);
  tcase_add_test(tc_core, s21_fmod_20);
  tcase_add_test(tc_core, s21_fmod_21);
  tcase_add_test(tc_core, s21_fmod_22);
  tcase_add_test(tc_core, s21_fmod_23);
  tcase_add_test(tc_core, s21_fmod_24);
  tcase_add_test(tc_core, s21_fmod_25);
  tcase_add_test(tc_core, s21_fmod_26);
  tcase_add_test(tc_core, s21_fmod_27);
  tcase_add_test(tc_core, s21_fmod_28);
  tcase_add_test(tc_core, s21_fmod_29);
  tcase_add_test(tc_core, s21_fmod_30);
  tcase_add_test(tc_core, s21_fmod_31);
  tcase_add_test(tc_core, s21_fmod_32);
  tcase_add_test(tc_core, s21_fmod_33);
  tcase_add_test(tc_core, s21_fmod_34);
  tcase_add_test(tc_core, s21_fmod_35);
  tcase_add_test(tc_core, s21_fmod_37);
  tcase_add_test(tc_core, s21_fmod_38);
  tcase_add_test(tc_core, s21_fmod_39);
  tcase_add_test(tc_core, s21_fmod_40);
  tcase_add_test(tc_core, s21_fmod_41);
  tcase_add_test(tc_core, s21_fmod_42);
  tcase_add_test(tc_core, s21_fmod_43);
  tcase_add_test(tc_core, s21_fmod_44);
  tcase_add_test(tc_core, s21_fmod_45);
  tcase_add_test(tc_core, s21_fmod_46);
  tcase_add_test(tc_core, s21_fmod_47);
  tcase_add_test(tc_core, s21_fmod_48);
  tcase_add_test(tc_core, s21_fmod_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *log_suite(void) {
  Suite *suite = suite_create("log");
  TCase *tc_core = tcase_create("s21_log");
  tcase_add_test(tc_core, s21_log_1);
  tcase_add_test(tc_core, s21_log_2);
  tcase_add_test(tc_core, s21_log_3);
  tcase_add_test(tc_core, s21_log_4);
  tcase_add_test(tc_core, s21_log_5);
  tcase_add_test(tc_core, s21_log_6);
  tcase_add_test(tc_core, s21_log_7);
  tcase_add_test(tc_core, s21_log_8);
  tcase_add_test(tc_core, s21_log_9);
  tcase_add_test(tc_core, s21_log_10);
  tcase_add_test(tc_core, s21_log_11);
  tcase_add_test(tc_core, s21_log_12);
  tcase_add_test(tc_core, s21_log_13);
  tcase_add_test(tc_core, s21_log_14);
  tcase_add_test(tc_core, s21_log_15);
  tcase_add_test(tc_core, s21_log_16);
  tcase_add_test(tc_core, s21_log_17);
  tcase_add_test(tc_core, s21_log_18);
  tcase_add_test(tc_core, s21_log_19);
  tcase_add_test(tc_core, s21_log_20);
  tcase_add_test(tc_core, s21_log_21);
  tcase_add_test(tc_core, s21_log_22);
  tcase_add_test(tc_core, s21_log_23);
  tcase_add_test(tc_core, s21_log_24);
  tcase_add_test(tc_core, s21_log_25);
  tcase_add_test(tc_core, s21_log_26);
  tcase_add_test(tc_core, s21_log_27);
  tcase_add_test(tc_core, s21_log_28);
  tcase_add_test(tc_core, s21_log_29);
  tcase_add_test(tc_core, s21_log_30);
  tcase_add_test(tc_core, s21_log_31);
  tcase_add_test(tc_core, s21_log_32);
  tcase_add_test(tc_core, s21_log_33);
  tcase_add_test(tc_core, s21_log_34);
  tcase_add_test(tc_core, s21_log_35);
  tcase_add_test(tc_core, s21_log_36);
  tcase_add_test(tc_core, s21_log_37);
  tcase_add_test(tc_core, s21_log_38);
  tcase_add_test(tc_core, s21_log_39);
  tcase_add_test(tc_core, s21_log_40);
  tcase_add_test(tc_core, s21_log_41);
  tcase_add_test(tc_core, s21_log_42);
  tcase_add_test(tc_core, s21_log_43);
  tcase_add_test(tc_core, s21_log_44);
  tcase_add_test(tc_core, s21_log_45);
  tcase_add_test(tc_core, s21_log_46);
  tcase_add_test(tc_core, s21_log_47);
  tcase_add_test(tc_core, s21_log_48);
  tcase_add_test(tc_core, s21_log_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *pow_suite(void) {
  Suite *suite = suite_create("pow");
  TCase *tc_core = tcase_create("s21_pow");
  tcase_add_test(tc_core, s21_pow_1);
  tcase_add_test(tc_core, s21_pow_2);
  tcase_add_test(tc_core, s21_pow_3);
  tcase_add_test(tc_core, s21_pow_4);
  tcase_add_test(tc_core, s21_pow_5);
  tcase_add_test(tc_core, s21_pow_6);
  tcase_add_test(tc_core, s21_pow_7);
  tcase_add_test(tc_core, s21_pow_8);
  tcase_add_test(tc_core, s21_pow_9);
  tcase_add_test(tc_core, s21_pow_10);
  tcase_add_test(tc_core, s21_pow_11);
  tcase_add_test(tc_core, s21_pow_12);
  tcase_add_test(tc_core, s21_pow_13);
  tcase_add_test(tc_core, s21_pow_14);
  tcase_add_test(tc_core, s21_pow_15);
  tcase_add_test(tc_core, s21_pow_16);
  tcase_add_test(tc_core, s21_pow_17);
  tcase_add_test(tc_core, s21_pow_18);
  tcase_add_test(tc_core, s21_pow_19);
  tcase_add_test(tc_core, s21_pow_20);
  tcase_add_test(tc_core, s21_pow_21);
  tcase_add_test(tc_core, s21_pow_22);
  tcase_add_test(tc_core, s21_pow_23);
  tcase_add_test(tc_core, s21_pow_24);
  tcase_add_test(tc_core, s21_pow_25);
  tcase_add_test(tc_core, s21_pow_26);
  tcase_add_test(tc_core, s21_pow_27);
  tcase_add_test(tc_core, s21_pow_28);
  tcase_add_test(tc_core, s21_pow_29);
  tcase_add_test(tc_core, s21_pow_33);
  tcase_add_test(tc_core, s21_pow_34);
  tcase_add_test(tc_core, s21_pow_35);
  tcase_add_test(tc_core, s21_pow_37);
  tcase_add_test(tc_core, s21_pow_39);
  tcase_add_test(tc_core, s21_pow_41);
  tcase_add_test(tc_core, s21_pow_43);
  tcase_add_test(tc_core, s21_pow_44);
  tcase_add_test(tc_core, s21_pow_45);
  tcase_add_test(tc_core, s21_pow_46);
  tcase_add_test(tc_core, s21_pow_47);
  tcase_add_test(tc_core, s21_pow_48);
  tcase_add_test(tc_core, s21_pow_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *sqrt_suite(void) {
  Suite *suite = suite_create("sqrt");
  TCase *tc_core = tcase_create("s21_sqrt");
  tcase_add_test(tc_core, s21_sqrt_1);
  tcase_add_test(tc_core, s21_sqrt_2);
  tcase_add_test(tc_core, s21_sqrt_3);
  tcase_add_test(tc_core, s21_sqrt_4);
  tcase_add_test(tc_core, s21_sqrt_6);
  tcase_add_test(tc_core, s21_sqrt_7);
  tcase_add_test(tc_core, s21_sqrt_10);
  tcase_add_test(tc_core, s21_sqrt_11);
  tcase_add_test(tc_core, s21_sqrt_14);
  tcase_add_test(tc_core, s21_sqrt_16);
  tcase_add_test(tc_core, s21_sqrt_18);
  tcase_add_test(tc_core, s21_sqrt_20);
  tcase_add_test(tc_core, s21_sqrt_22);
  tcase_add_test(tc_core, s21_sqrt_23);
  tcase_add_test(tc_core, s21_sqrt_24);
  tcase_add_test(tc_core, s21_sqrt_28);
  tcase_add_test(tc_core, s21_sqrt_29);
  tcase_add_test(tc_core, s21_sqrt_33);
  tcase_add_test(tc_core, s21_sqrt_34);
  tcase_add_test(tc_core, s21_sqrt_35);
  tcase_add_test(tc_core, s21_sqrt_37);
  tcase_add_test(tc_core, s21_sqrt_39);
  tcase_add_test(tc_core, s21_sqrt_41);
  tcase_add_test(tc_core, s21_sqrt_43);
  tcase_add_test(tc_core, s21_sqrt_45);
  tcase_add_test(tc_core, s21_sqrt_47);
  tcase_add_test(tc_core, s21_sqrt_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *tan_suite(void) {
  Suite *suite = suite_create("tan");
  TCase *tc_core = tcase_create("s21_tan");
  tcase_add_test(tc_core, s21_tan_1);
  tcase_add_test(tc_core, s21_tan_2);
  tcase_add_test(tc_core, s21_tan_3);
  tcase_add_test(tc_core, s21_tan_4);
  tcase_add_test(tc_core, s21_tan_5);
  tcase_add_test(tc_core, s21_tan_6);
  tcase_add_test(tc_core, s21_tan_7);
  tcase_add_test(tc_core, s21_tan_8);
  tcase_add_test(tc_core, s21_tan_9);
  tcase_add_test(tc_core, s21_tan_10);
  tcase_add_test(tc_core, s21_tan_11);
  tcase_add_test(tc_core, s21_tan_12);
  tcase_add_test(tc_core, s21_tan_13);
  tcase_add_test(tc_core, s21_tan_16);
  tcase_add_test(tc_core, s21_tan_17);
  tcase_add_test(tc_core, s21_tan_18);
  tcase_add_test(tc_core, s21_tan_19);
  tcase_add_test(tc_core, s21_tan_20);
  tcase_add_test(tc_core, s21_tan_21);
  tcase_add_test(tc_core, s21_tan_22);
  tcase_add_test(tc_core, s21_tan_23);
  tcase_add_test(tc_core, s21_tan_24);
  tcase_add_test(tc_core, s21_tan_25);
  tcase_add_test(tc_core, s21_tan_26);
  tcase_add_test(tc_core, s21_tan_29);
  tcase_add_test(tc_core, s21_tan_30);
  tcase_add_test(tc_core, s21_tan_31);
  tcase_add_test(tc_core, s21_tan_32);
  tcase_add_test(tc_core, s21_tan_33);
  tcase_add_test(tc_core, s21_tan_34);
  tcase_add_test(tc_core, s21_tan_35);
  tcase_add_test(tc_core, s21_tan_36);
  tcase_add_test(tc_core, s21_tan_37);
  tcase_add_test(tc_core, s21_tan_38);
  tcase_add_test(tc_core, s21_tan_39);
  tcase_add_test(tc_core, s21_tan_40);
  tcase_add_test(tc_core, s21_tan_41);
  tcase_add_test(tc_core, s21_tan_42);
  tcase_add_test(tc_core, s21_tan_43);
  tcase_add_test(tc_core, s21_tan_44);
  tcase_add_test(tc_core, s21_tan_45);
  tcase_add_test(tc_core, s21_tan_46);
  tcase_add_test(tc_core, s21_tan_47);
  tcase_add_test(tc_core, s21_tan_48);
  tcase_add_test(tc_core, s21_tan_49);
  suite_add_tcase(suite, tc_core);
  return suite;
}

void srunner_test(Suite *s, int *no_failed) {
  SRunner *srunner = srunner_create(s);
  srunner_run_all(srunner, CK_NORMAL);
  *no_failed = srunner_ntests_failed(srunner);
  srunner_free(srunner);
}

int main(void) {
  int no_failed = 0;
  srunner_test(ersin_suite(), &no_failed);
  srunner_test(abs_suite(), &no_failed);
  srunner_test(acos_suite(), &no_failed);
  srunner_test(asin_suite(), &no_failed);
  srunner_test(atan_suite(), &no_failed);
  srunner_test(ceil_suite(), &no_failed);
  srunner_test(cos_suite(), &no_failed);
  srunner_test(exp_suite(), &no_failed);
  srunner_test(fabs_suite(), &no_failed);
  srunner_test(floor_suite(), &no_failed);
  srunner_test(fmod_suite(), &no_failed);
  srunner_test(log_suite(), &no_failed);
  srunner_test(pow_suite(), &no_failed);
  srunner_test(sqrt_suite(), &no_failed);
  srunner_test(tan_suite(), &no_failed);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}