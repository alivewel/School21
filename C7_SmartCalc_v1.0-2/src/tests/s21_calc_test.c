#include "../s21_calc.h"

#include <check.h>

#define OK 0
#define FAIL 1

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ACCURACY 1e-4

START_TEST(validation_1) {
  char str[256] = "1.2+23";
  int expected = 0;
  int res = 0;

  expected = OK;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(validation_2) {
  char str[256] = "12++23";
  int expected = 0;
  int res = 0;

  expected = FAIL;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(validation_3) {
  char str[256] = "(1223))";
  int expected = 0;
  int res = 0;

  expected = FAIL;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(validation_4) {
  char str[256] = "((12+23";
  int expected = 0;
  int res = 0;

  expected = FAIL;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(validation_5) {
  char str[256] = ".12+23.";
  int expected = 0;
  int res = 0;

  expected = FAIL;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(validation_6) {
  char str[256] = "mod12+23";
  int expected = 0;
  int res = 0;

  expected = FAIL;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(validation_7) {
  char str[256] = "5mod12+23";
  int expected = 0;
  int res = 0;

  expected = OK;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(validation_8) {
  char str[256] = "cos(12+23)";
  int expected = 0;
  int res = 0;

  expected = OK;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(validation_9) {
  char str[256] = "*(-4)";
  int expected = 0;
  int res = 0;

  expected = FAIL;
  res = validation(str);
  ck_assert_int_eq(expected, res);
}
END_TEST

START_TEST(calc_test_1) {
  double result = 0.0;
  char input_string[256] = "(5+5)*(-2)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -20, ACCURACY);
}

START_TEST(calc_test_2) {
  double result = 0.0;
  char input_string[256] = "(10+10*2)/(-3)";
  calculator(input_string, &result);
  ck_assert_double_eq(result, -10);
}

START_TEST(calc_test_3) {
  double result = 0.0;
  char input_string[256] = "2.0/(3.0+2.0)*5.0";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
}

START_TEST(calc_test_4) {
  double result = 0.0;
  char input_string[256] = "10.0+10.0*10.0";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 110, ACCURACY);
}

START_TEST(calc_test_5) {
  double result = 0.0;
  char input_string[256] = "-5+(-4)*(-2)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 3, ACCURACY);
}

START_TEST(calc_test_6) {
  double result = 0.0;
  char input_string[256] = "-5.0mod(-3.0)";
  calculator(input_string, &result);
  ck_assert_double_eq(result, -2);
}

START_TEST(calc_test_7) {
  double result = 0.0;
  char input_string[256] = "1.0/2.0*(2.0-1.0)";
  calculator(input_string, &result);
  ck_assert_double_eq(result, 0.5);
}

START_TEST(calc_test_9) {
  double result = 0.0;
  char input_string[256] = "1.10+2.0+(3.0-5.5)*(1.5 - 6.5)";
  calculator(input_string, &result);
  ck_assert_double_eq(result, 15.6);
}

START_TEST(calc_test_10) {
  double result = 0.0;
  char input_string[256] = "6.6-1.1-2.2-3.3-4.4-5.5";
  calculator(input_string, &result);
  ck_assert_double_eq(result, -9.9);
}

START_TEST(calc_test_11) {
  double result = 0.0;
  char input_string[256] = "1.1-2.2-3.3-4.4-5.5+6.6";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -7.70, ACCURACY);
}

START_TEST(calc_test_12) {
  double result = 0.0;
  char input_string[256] = "-1.1*5";
  calculator(input_string, &result);
  ck_assert_double_eq(result, -5.5);
}

START_TEST(calc_test_13) {
  double result = 0.0;
  char input_string[256] = "2^2";
  calculator(input_string, &result);
  ck_assert_double_eq(result, 4);
}

START_TEST(calc_test_14) {
  double result = 0.0;
  char input_string[256] = "5^3";
  calculator(input_string, &result);
  ck_assert_double_eq(result, 125);
}

START_TEST(calc_test_16) {
  double result = 0.0;
  char input_string[256] = "(2^2)^3";
  calculator(input_string, &result);
  ck_assert_double_eq(result, 64);
}

START_TEST(calc_test_17) {
  double result = 0.0;
  char input_string[256] = "-5+3*2^2";
  calculator(input_string, &result);
  ck_assert_double_eq(result, 7);
}

START_TEST(calc_test_19) {
  double result = 0.0;
  char input_string[256] = "5mod(-1.5)";
  calculator(input_string, &result);
  ck_assert_double_eq(result, 0.5);
}

START_TEST(calc_test_20) {
  double result = 0.0;
  char input_string[256] = "(5mod(-1.5)*4)^2";
  calculator(input_string, &result);
  ck_assert_double_eq(result, 4);
}

START_TEST(calc_test_21) {
  double result = 0.0;
  char input_string[256] = "sin(30)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.988032, ACCURACY);
}

START_TEST(calc_test_22) {
  double result = 0.0;
  char input_string[256] = "sin(45)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.850904, ACCURACY);
}

START_TEST(calc_test_23) {
  double result = 0.0;
  char input_string[256] = "sin(60)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.304811, ACCURACY);
}

START_TEST(calc_test_24) {
  double result = 0.0;
  char input_string[256] = "sin(90)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.893997, ACCURACY);
}

START_TEST(calc_test_25) {
  double result = 0.0;
  char input_string[256] = "sin(120)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.580611, ACCURACY);
}

START_TEST(calc_test_26) {
  double result = 0.0;
  char input_string[256] = "sin(180)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.801153, ACCURACY);
}

START_TEST(calc_test_27) {
  double result = 0.0;
  char input_string[256] = "sin(270)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.176046, ACCURACY);
}

START_TEST(calc_test_28) {
  double result = 0.0;
  char input_string[256] = "sin(360)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.958916, ACCURACY);
}

START_TEST(calc_test_29) {
  double result = 0.0;
  char input_string[256] = "sin(0)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0, ACCURACY);
}

START_TEST(calc_test_30) {
  double result = 0.0;
  char input_string[256] = "cos(30)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.154251, ACCURACY);
}

START_TEST(calc_test_31) {
  double result = 0.0;
  char input_string[256] = "cos(45)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.525322, ACCURACY);
}

START_TEST(calc_test_32) {
  double result = 0.0;
  char input_string[256] = "cos(90)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.448074, ACCURACY);
}

START_TEST(calc_test_33) {
  double result = 0.0;
  char input_string[256] = "cos(120)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.814181, ACCURACY);
}

START_TEST(calc_test_34) {
  double result = 0.0;
  char input_string[256] = "cos(180)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.598460, ACCURACY);
}

START_TEST(calc_test_35) {
  double result = 0.0;
  char input_string[256] = "cos(270)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.984382, ACCURACY);
}

START_TEST(calc_test_36) {
  double result = 0.0;
  char input_string[256] = "cos(360)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.283691, ACCURACY);
}

START_TEST(calc_test_37) {
  double result = 0.0;
  char input_string[256] = "cos(0)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1, ACCURACY);
}

START_TEST(calc_test_38) {
  double result = 0.0;
  char input_string[256] = "tan(90)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -1.995200, ACCURACY);
}

START_TEST(calc_test_40) {
  double result = 0.0;
  char input_string[256] = "(sin(45)+cos(30)+tan(45)+tan(90))*2";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.25946, ACCURACY);
}

START_TEST(calc_test_43) {
  double result = 0.0;
  char input_string[256] = "asin(0.5)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.523598, ACCURACY);
}

START_TEST(calc_test_44) {
  double result = 0.0;
  char input_string[256] = "acos(0.5)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.047198, ACCURACY);
}

START_TEST(calc_test_45) {
  double result = 0.0;
  char input_string[256] = "acos(1)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0, ACCURACY);
}

START_TEST(calc_test_46) {
  double result = 0.0;
  char input_string[256] = "atan(0)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0, ACCURACY);
}

START_TEST(calc_test_47) {
  double result = 0.0;
  char input_string[256] = "atan(1)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.785398, ACCURACY);
}

START_TEST(calc_test_48) {
  double result = 0.0;
  char input_string[256] = "sqrt(100)/sqrt(25)*sqrt(121)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 22, ACCURACY);
}

START_TEST(calc_test_49) {
  double result = 0.0;
  char input_string[256] = "ln(5)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.609438, ACCURACY);
}

START_TEST(calc_test_50) {
  double result = 0.0;
  char input_string[256] = "-5.0mod(-3.0)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -2, ACCURACY);
}

START_TEST(calc_test_52) {
  double result = 0.0;
  char input_string[256] = "1.0/2.0*(2.0-1.0)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.5, ACCURACY);
}

START_TEST(calc_test_53) {
  double result = 0.0;
  char input_string[256] = "1.1+2.0+(3.0*4.0)+(5.0+6.8)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 26.9, ACCURACY);
}

START_TEST(calc_test_54) {
  double result = 0.0;
  char input_string[256] = "10^10";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, pow(10, 10), ACCURACY);
}

START_TEST(calc_test_55) {
  double result = 0.0;
  char input_string[256] = "1 - 1";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0, ACCURACY);
}

START_TEST(calc_test_56) {
  double result = 0.0;
  char input_string[256] =
      "1+2+3+4+5+6+7+8+9+10+100-3-2-10-3*2+12+15+16+17+18/2";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 203, ACCURACY);
}

START_TEST(calc_test_57) {
  double result = 0.0;
  char input_string[256] =
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+"
      "1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 128, ACCURACY);
}

START_TEST(calc_test_58) {
  double result = 0.0;
  char input_string[256] =
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*1*"
      "1*1*1*1*1*1*1*1*1*1*1*1*1*1";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1, ACCURACY);
}

START_TEST(calc_test_60) {
  double result = 0.0;
  char input_string[256] = "1+1";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
}

START_TEST(calc_test_61) {
  double result = 0.0;
  char input_string[256] = "(1+1)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
}

START_TEST(calc_test_62) {
  double result = 0.0;
  char input_string[256] = "(1+1)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
}

START_TEST(calc_test_63) {
  double result = 0.0;
  char input_string[256] = "(1+1)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
}

START_TEST(calc_test_64) {
  double result = 0.0;
  char input_string[256] = "(1+1)";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
}

START_TEST(calc_test_65) {
  double result = 0.0;
  char input_string[256] = "((((1)+(1))))";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
}

START_TEST(calc_test_66) {
  double result = 0.0;
  char input_string[256] = "(5*9)-(2+(3-(2/1)+35))";
  calculator(input_string, &result);
  ck_assert_double_eq_tol(result, (5 * 9) - (2 + (3 - (2 / 1) + 35)), ACCURACY);
}

START_TEST(calc_test_67) {
  double result = 0.0;
  char input_string[256] = "(";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_68) {
  double result = 0.0;
  char input_string[256] = "()";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_69) {
  double result = 0.0;
  char input_string[256] = "1+)3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_70) {
  double result = 0.0;
  char input_string[256] = "(18/9.3)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.935483, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_71) {
  double result = 0.0;
  char input_string[256] = "(1/+2)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_72) {
  double result = 0.0;
  char input_string[256] = "1.2+5";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.2 + 5, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_73) {
  double result = 0.0;
  char input_string[256] = "1.2+5+9+6";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.2 + 5 + 9 + 6, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_78) {
  double result = 0.0;
  char input_string[256] = "1.54837495+1.345213431+(-(5)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_80) {
  double result = 0.0;
  char input_string[256] = "1-1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_81) {
  double result = 0.0;
  char input_string[256] = "1-0";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1 - 0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_82) {
  double result = 0.0;
  char input_string[256] = "1-0.1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1 - 0.1, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_85) {
  double result = 0.0;
  char input_string[256] = "156156*3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 156156 * 3, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_86) {
  double result = 0.0;
  char input_string[256] = "156156*3*3*0.1*0.1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 156156 * 3 * 3 * 0.1 * 0.1, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_88) {
  double result = 0.0;
  char input_string[256] = "*156156*3*3*0.1*0.1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_89) {
  double result = 0.0;
  char input_string[256] = "156156*3*3*0.1*0.1*()";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_90) {
  double result = 0.0;
  char input_string[256] = "156/2";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 156 / 2, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_91) {
  double result = 0.0;
  char input_string[256] = "512/2/2/2";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 512 / 2 / 2 / 2, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_92) {
  double result = 0.0;
  char input_string[256] = "512/2/2/2/0.5";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 512 / 2 / 2 / 2 / 0.5, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_98) {
  double result = 0.0;
  char input_string[256] = "-2+12";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 10, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_99) {
  double result = 0.0;
  char input_string[256] = "(-2)^2";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 4, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_100) {
  double result = 0.0;
  char input_string[256] = "ln((9.980000)^123)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 282.9717201, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_102) {
  double result = 0.0;
  char input_string[256] = "^2^2";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_103) {
  double result = 0.0;
  char input_string[256] = "2^^2";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_104) {
  double result = 0.0;
  char input_string[256] = "(3.4)mod3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.4, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_105) {
  double result = 0.0;
  char input_string[256] = "(.3+ .3)mod.3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_106) {
  double result = 0.0;
  char input_string[256] = "mod 0";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_107) {
  double result = 0.0;
  char input_string[256] = "mod1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_111) {
  double result = 0.0;
  char input_string[256] = "21513+1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 21514, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_112) {
  double result = 0.0;
  char input_string[256] = "2/2+(1)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_113) {
  double result = 0.0;
  char input_string[256] = "1+(1)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_114) {
  double result = 0.0;
  char input_string[256] = "1+(54*2+1)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 110, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_115) {
  double result = 0.0;
  char input_string[256] = "1+1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_116) {
  double result = 0.0;
  char input_string[256] = "121/121*(369mod2)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_117) {
  double result = 0.0;
  char input_string[256] = "216/31+13*24";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 318.967742, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_118) {
  double result = 0.0;
  char input_string[256] = "1.54837495*5.34521343";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 8.2763946, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_119) {
  double result = 0.0;
  char input_string[256] = "1.54837495+1.34521343";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2.893588, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_120) {
  double result = 0.0;
  char input_string[256] = "2125/613+(74*1.34521343)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 103.012351, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_121) {
  double result = 0.0;
  char input_string[256] = "-1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -1, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_122) {
  double result = 0.0;
  char input_string[256] = "-1+21";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 20, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_123) {
  double result = 0.0;
  char input_string[256] = "1-(1)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_124) {
  double result = 0.0;
  char input_string[256] = "1-(-1)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1 - (-1), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_125) {
  double result = 0.0;
  char input_string[256] = "1-(-1)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_126) {
  double result = 0.0;
  char input_string[256] = "-1--1--1--1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_127) {
  double result = 0.0;
  char input_string[256] = "-1--1-1--1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_128) {
  double result = 0.0;
  char input_string[256] = "--1.54837495-1.34521343";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_129) {
  double result = 0.0;
  char input_string[256] = "-1.54837495---1.34521343";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_130) {
  double result = 0.0;
  char input_string[256] = "---1.54837495-1.34521343";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_131) {
  double result = 0.0;
  char input_string[256] = "1.54837495+1.34521343";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.54837495 + 1.34521343, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_132) {
  double result = 0.0;
  char input_string[256] = "1+1/3*2^12-44";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1322.3333333, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_133) {
  double result = 0.0;
  char input_string[256] = "sin(90)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, sin(90), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_134) {
  double result = 0.0;
  char input_string[256] = "cos(90)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, cos(90), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_135) {
  double result = 0.0;
  char input_string[256] = "tan(90)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, tan(90), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_136) {
  double result = 0.0;
  char input_string[256] = "sqrt(90)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, sqrt(90), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_137) {
  double result = 0.0;
  char input_string[256] = "ln(90)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, log(90), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_139) {
  double result = 0.0;
  char input_string[256] = "acos(0.5)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, acos(0.5), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_140) {
  double result = 0.0;
  char input_string[256] = "asin(0.5)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, asin(0.5), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_141) {
  double result = 0.0;
  char input_string[256] = "atan(90)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, atan(90), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_142) {
  double result = 0.0;
  char input_string[256] = "-1 + 2";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_143) {
  double result = 0.0;
  char input_string[256] = "-1+(-2)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -3.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_144) {
  double result = 0.0;
  char input_string[256] = "0.3 + 0.3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.6, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_145) {
  double result = 0.0;
  char input_string[256] = ".3 + .3*.3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_146) {
  double result = 0.0;
  char input_string[256] = "(1+2)*4*cos(3.141592*7-2)+sin(2*3.141592)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 4.9938107, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_147) {
  double result = 0.0;
  char input_string[256] = "(-3)*(-3.141592-(7*(-7))";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_148) {
  double result = 0.0;
  char input_string[256] = "sin(sin(sin(sin(sin(90)))))";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, sin(sin(sin(sin(sin(90))))), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_149) {
  double result = 0.0;
  char input_string[256] = "(123) * (123)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, (123) * (123), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_150) {
  double result = 0.0;
  char input_string[256] = "(123)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, (123), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_151) {
  double result = 0.0;
  char input_string[256] = "*1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_152) {
  double result = 0.0;
  char input_string[256] = "1(";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_153) {
  double result = 0.0;
  char input_string[256] = "1)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_156) {
  double result = 0.0;
  char input_string[256] = "tan()+3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_158) {
  double result = 0.0;
  char input_string[256] = "-*3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_159) {
  double result = 0.0;
  char input_string[256] = "5mod4";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_160) {
  double result = 0.0;
  char input_string[256] = "90-3*()*3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_163) {
  double result = 0.0;
  char input_string[256] = "mod";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_164) {
  double result = 0.0;
  char input_string[256] = "sin(2)+1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, sin(2) + 1, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_165) {
  double result = 0.0;
  char input_string[256] = "cos(2)+2";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, cos(2) + 2, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_166) {
  double result = 0.0;
  char input_string[256] = "3mod4";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 3, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_167) {
  double result = 0.0;
  char input_string[256] = "acos(0.3)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, acos(0.3), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_168) {
  double result = 0.0;
  char input_string[256] = "ln(ln(2))";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.366513, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_169) {
  double result = 0.0;
  char input_string[256] = "sqrt(8)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2.828427, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_171) {
  double result = 0.0;
  char input_string[256] = "1+tan(1.5707963267948)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1 + tan(1.5707963267948), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_172) {
  double result = 0.0;
  char input_string[256] =
      "1+tan(1.5707963267948 + 1.5707963267948 + 1.5707963267948)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(
      result, 1 + tan(1.5707963267948 + 1.5707963267948 + 1.5707963267948),
      ACCURACY);
  ck_assert_int_eq(stat, 0);
}

// START_TEST(calc_test_183) {
//   double result = 0.0;
//   char input_string[256] = "sin(60)cos(60)";
//   int stat = calculator(input_string, &result);
//   ck_assert_double_eq_tol(result, 0.0, ACCURACY);
//   ck_assert_int_eq(stat, 1);
// }

START_TEST(calc_test_184) {
  double result = 0.0;
  char input_string[256] = ".5";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_185) {
  double result = 0.0;
  char input_string[256] = "sin(5+3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_186) {
  double result = 0.0;
  char input_string[256] = "(1+5)-2";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 4.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_187) {
  double result = 0.0;
  char input_string[256] = "cos(1*2)-1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -1.4161468, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_188) {
  double result = 0.0;
  char input_string[256] = "(1+2)*4+3";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 15.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_189) {
  double result = 0.0;
  char input_string[256] = "2/(3+2)*5";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_190) {
  double result = 0.0;
  char input_string[256] = "2/4-1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, -0.5, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_191) {
  double result = 0.0;
  char input_string[256] = "2-4/1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2 - 4 / 1, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_192) {
  double result = 0.0;
  char input_string[256] = "2*4/1";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 2 * 4 / 1, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_193) {
  double result = 0.0;
  char input_string[256] = "atan(5)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, atan(5), ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_195) {
  double result = 0.0;
  char input_string[256] = "log(55dududu";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_196) {
  double result = 0.0;
  char input_string[256] = "1mod32";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.0, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_197) {
  double result = 0.0;
  char input_string[256] = "4+5/3-sqrt(14)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 1.92500927, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_198) {
  double result = 0.0;
  char input_string[256] = "98^6";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 885842380864, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_199) {
  double result = 0.0;
  char input_string[256] = "17/4+(14/2*(3-1^4))";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 18.25, ACCURACY);
  ck_assert_int_eq(stat, 0);
}

START_TEST(calc_test_200) {
  double result = 0.0;
  char input_string[256] = "17/4+(14/2*(3-1^4)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_201) {
  double result = 0.0;
  char input_string[256] = "17/4(14/2*(3-1^4)";
  int stat = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(stat, 1);
}

START_TEST(calc_test_202) {
  double result = 0.0;
  int status = 0;
  char input_string[8] = "24+1/2";
  status = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 24.5, ACCURACY);
  ck_assert_int_eq(status, 0);
}

START_TEST(calc_test_203) {
  double result = 0.0;
  int status = 0;
  char input_string[8] = "2)+2";
  status = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 0.0, ACCURACY);
  ck_assert_int_eq(status, 1);
}

START_TEST(calc_test_204) {
  double result = 0.0;
  int status = 0;
  char input_string[8] = "2+2";
  status = calculator(input_string, &result);
  ck_assert_double_eq_tol(result, 4.0, ACCURACY);
  ck_assert_int_eq(status, 0);
}

Suite *validater_suite(void) {
  Suite *suite = suite_create("validater");
  TCase *tc_core = tcase_create("validation");
  tcase_add_test(tc_core, validation_1);
  tcase_add_test(tc_core, validation_2);
  tcase_add_test(tc_core, validation_3);
  tcase_add_test(tc_core, validation_4);
  tcase_add_test(tc_core, validation_5);
  tcase_add_test(tc_core, validation_6);
  tcase_add_test(tc_core, validation_7);
  tcase_add_test(tc_core, validation_8);
  tcase_add_test(tc_core, validation_9);
  suite_add_tcase(suite, tc_core);
  return suite;
}

Suite *culc_suite(void) {
  Suite *suite = suite_create("s21_calc");
  TCase *tc_core = tcase_create("s21_calc");
  tcase_add_test(tc_core, calc_test_1);
  tcase_add_test(tc_core, calc_test_2);
  tcase_add_test(tc_core, calc_test_3);
  tcase_add_test(tc_core, calc_test_4);
  tcase_add_test(tc_core, calc_test_5);
  tcase_add_test(tc_core, calc_test_6);
  tcase_add_test(tc_core, calc_test_7);
  tcase_add_test(tc_core, calc_test_9);
  tcase_add_test(tc_core, calc_test_10);
  tcase_add_test(tc_core, calc_test_11);
  tcase_add_test(tc_core, calc_test_12);
  tcase_add_test(tc_core, calc_test_13);
  tcase_add_test(tc_core, calc_test_14);
  tcase_add_test(tc_core, calc_test_16);
  tcase_add_test(tc_core, calc_test_17);
  tcase_add_test(tc_core, calc_test_19);
  tcase_add_test(tc_core, calc_test_20);
  tcase_add_test(tc_core, calc_test_21);
  tcase_add_test(tc_core, calc_test_22);
  tcase_add_test(tc_core, calc_test_23);
  tcase_add_test(tc_core, calc_test_24);
  tcase_add_test(tc_core, calc_test_25);
  tcase_add_test(tc_core, calc_test_26);
  tcase_add_test(tc_core, calc_test_27);
  tcase_add_test(tc_core, calc_test_28);
  tcase_add_test(tc_core, calc_test_29);
  tcase_add_test(tc_core, calc_test_30);
  tcase_add_test(tc_core, calc_test_31);
  tcase_add_test(tc_core, calc_test_32);
  tcase_add_test(tc_core, calc_test_33);
  tcase_add_test(tc_core, calc_test_34);
  tcase_add_test(tc_core, calc_test_35);
  tcase_add_test(tc_core, calc_test_36);
  tcase_add_test(tc_core, calc_test_37);
  tcase_add_test(tc_core, calc_test_38);
  tcase_add_test(tc_core, calc_test_40);
  tcase_add_test(tc_core, calc_test_43);
  tcase_add_test(tc_core, calc_test_44);
  tcase_add_test(tc_core, calc_test_45);
  tcase_add_test(tc_core, calc_test_46);
  tcase_add_test(tc_core, calc_test_47);
  tcase_add_test(tc_core, calc_test_48);
  tcase_add_test(tc_core, calc_test_49);
  tcase_add_test(tc_core, calc_test_50);
  tcase_add_test(tc_core, calc_test_52);
  tcase_add_test(tc_core, calc_test_53);
  tcase_add_test(tc_core, calc_test_54);
  tcase_add_test(tc_core, calc_test_55);
  tcase_add_test(tc_core, calc_test_56);
  tcase_add_test(tc_core, calc_test_57);
  tcase_add_test(tc_core, calc_test_58);
  tcase_add_test(tc_core, calc_test_60);
  tcase_add_test(tc_core, calc_test_61);
  tcase_add_test(tc_core, calc_test_62);
  tcase_add_test(tc_core, calc_test_63);
  tcase_add_test(tc_core, calc_test_64);
  tcase_add_test(tc_core, calc_test_65);
  tcase_add_test(tc_core, calc_test_66);
  tcase_add_test(tc_core, calc_test_67);
  tcase_add_test(tc_core, calc_test_68);
  tcase_add_test(tc_core, calc_test_69);
  tcase_add_test(tc_core, calc_test_70);
  tcase_add_test(tc_core, calc_test_71);
  tcase_add_test(tc_core, calc_test_72);
  tcase_add_test(tc_core, calc_test_73);
  tcase_add_test(tc_core, calc_test_78);
  tcase_add_test(tc_core, calc_test_80);
  tcase_add_test(tc_core, calc_test_81);
  tcase_add_test(tc_core, calc_test_82);
  tcase_add_test(tc_core, calc_test_85);
  tcase_add_test(tc_core, calc_test_86);
  tcase_add_test(tc_core, calc_test_88);
  tcase_add_test(tc_core, calc_test_89);
  tcase_add_test(tc_core, calc_test_90);
  tcase_add_test(tc_core, calc_test_91);
  tcase_add_test(tc_core, calc_test_92);
  tcase_add_test(tc_core, calc_test_98);
  tcase_add_test(tc_core, calc_test_99);
  tcase_add_test(tc_core, calc_test_100);
  tcase_add_test(tc_core, calc_test_102);
  tcase_add_test(tc_core, calc_test_103);
  tcase_add_test(tc_core, calc_test_104);
  tcase_add_test(tc_core, calc_test_105);
  tcase_add_test(tc_core, calc_test_106);
  tcase_add_test(tc_core, calc_test_107);
  tcase_add_test(tc_core, calc_test_111);
  tcase_add_test(tc_core, calc_test_112);
  tcase_add_test(tc_core, calc_test_113);
  tcase_add_test(tc_core, calc_test_114);
  tcase_add_test(tc_core, calc_test_115);
  tcase_add_test(tc_core, calc_test_116);
  tcase_add_test(tc_core, calc_test_117);
  tcase_add_test(tc_core, calc_test_118);
  tcase_add_test(tc_core, calc_test_119);
  tcase_add_test(tc_core, calc_test_120);
  tcase_add_test(tc_core, calc_test_121);
  tcase_add_test(tc_core, calc_test_122);
  tcase_add_test(tc_core, calc_test_123);
  tcase_add_test(tc_core, calc_test_124);
  tcase_add_test(tc_core, calc_test_125);
  tcase_add_test(tc_core, calc_test_126);
  tcase_add_test(tc_core, calc_test_127);
  tcase_add_test(tc_core, calc_test_128);
  tcase_add_test(tc_core, calc_test_129);
  tcase_add_test(tc_core, calc_test_130);
  tcase_add_test(tc_core, calc_test_131);
  tcase_add_test(tc_core, calc_test_132);
  tcase_add_test(tc_core, calc_test_133);
  tcase_add_test(tc_core, calc_test_134);
  tcase_add_test(tc_core, calc_test_135);
  tcase_add_test(tc_core, calc_test_136);
  tcase_add_test(tc_core, calc_test_137);
  tcase_add_test(tc_core, calc_test_139);
  tcase_add_test(tc_core, calc_test_140);
  tcase_add_test(tc_core, calc_test_141);
  tcase_add_test(tc_core, calc_test_142);
  tcase_add_test(tc_core, calc_test_143);
  tcase_add_test(tc_core, calc_test_144);
  tcase_add_test(tc_core, calc_test_145);
  tcase_add_test(tc_core, calc_test_146);
  tcase_add_test(tc_core, calc_test_147);
  tcase_add_test(tc_core, calc_test_148);
  tcase_add_test(tc_core, calc_test_149);
  tcase_add_test(tc_core, calc_test_150);
  tcase_add_test(tc_core, calc_test_151);
  tcase_add_test(tc_core, calc_test_152);
  tcase_add_test(tc_core, calc_test_153);
  tcase_add_test(tc_core, calc_test_156);
  tcase_add_test(tc_core, calc_test_158);
  tcase_add_test(tc_core, calc_test_159);
  tcase_add_test(tc_core, calc_test_160);
  tcase_add_test(tc_core, calc_test_163);
  tcase_add_test(tc_core, calc_test_164);
  tcase_add_test(tc_core, calc_test_165);
  tcase_add_test(tc_core, calc_test_166);
  tcase_add_test(tc_core, calc_test_167);
  tcase_add_test(tc_core, calc_test_168);
  tcase_add_test(tc_core, calc_test_169);
  tcase_add_test(tc_core, calc_test_171);
  tcase_add_test(tc_core, calc_test_172);
  tcase_add_test(tc_core, calc_test_184);
  tcase_add_test(tc_core, calc_test_185);
  tcase_add_test(tc_core, calc_test_186);
  tcase_add_test(tc_core, calc_test_187);
  tcase_add_test(tc_core, calc_test_188);
  tcase_add_test(tc_core, calc_test_189);
  tcase_add_test(tc_core, calc_test_190);
  tcase_add_test(tc_core, calc_test_191);
  tcase_add_test(tc_core, calc_test_192);
  tcase_add_test(tc_core, calc_test_193);
  tcase_add_test(tc_core, calc_test_195);
  tcase_add_test(tc_core, calc_test_196);
  tcase_add_test(tc_core, calc_test_197);
  tcase_add_test(tc_core, calc_test_198);
  tcase_add_test(tc_core, calc_test_199);
  tcase_add_test(tc_core, calc_test_200);
  tcase_add_test(tc_core, calc_test_201);
  tcase_add_test(tc_core, calc_test_202);
  tcase_add_test(tc_core, calc_test_203);
  tcase_add_test(tc_core, calc_test_204);
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
  srunner_test(validater_suite(), &no_failed);
  srunner_test(culc_suite(), &no_failed);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}