#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

void s21_write(matrix_t *matrixStruct, double value) {
  for (int i = 0; i < matrixStruct->rows; i++) {
    for (int j = 0; j < matrixStruct->columns; j++) {
      matrixStruct->matrix[i][j] = value;
    }
  }
}

void s21_write_right(matrix_t *A) {
  double num = 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++, num++) {
      A->matrix[i][j] = num;
    }
  }
}

void s21_write_back(matrix_t *A) {
  double num = 32;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++, num--) {
      A->matrix[i][j] = num;
    }
  }
}

START_TEST(create_matrix) {
  int code = 0;
  matrix_t A = {0};
  code = s21_create_matrix(1, 1, &A);
  ck_assert_int_eq(code, 0);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mult_num) {
  const int rows = 2;
  const int cols = 2;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(rows, cols, &check);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 1;
  m.matrix[1][0] = 1;
  m.matrix[1][1] = 1;
  check.matrix[0][0] = 2;
  check.matrix[0][1] = 2;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 2;
  int num = 2;
  matrix_t res = {0};
  ck_assert_int_eq(s21_mult_number(&m, num, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix) {
  const int rows = 2;
  const int cols = 2;
  matrix_t m = {0};
  s21_create_matrix(rows, cols, &m);
  matrix_t check = {0};
  s21_create_matrix(cols, rows, &check);
  m.matrix[0][0] = 1;
  m.matrix[0][1] = 2;
  m.matrix[1][0] = 3;
  m.matrix[1][1] = 4;
  check.matrix[0][0] = 1;
  check.matrix[0][1] = 3;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 4;
  matrix_t res = {0};
  ck_assert_int_eq(s21_transpose(&m, &res), 0);
  ck_assert_int_eq(s21_eq_matrix(&check, &res), 1);
  s21_remove_matrix(&m);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(test_s21_eq_matrix) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t temp3;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &temp3);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 1);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp3), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&temp3);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  temp2.matrix[1][1] = 0;
  temp2.matrix[1][2] = 77;
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(test_s21_eq_matrix_3) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(2, 3, &temp2);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(test_s21_eq_matrix_4) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 21, &temp2);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(test_s21_eq_matrix_5) {
  matrix_t temp;
  matrix_t temp2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  temp.matrix[0][1] = 4.67773;
  temp2.matrix[0][1] = 4.67774;
  ck_assert_int_eq(s21_eq_matrix(&temp, &temp2), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

START_TEST(test_s21_sum_matrix) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_write_right(&temp);
  s21_write_back(&temp2);
  for (int i = 0; (i < temp.rows); i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] + temp2.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&temp, &temp2, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_sum_matrix_2) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  ck_assert_int_eq(s21_sum_matrix(&temp, &temp2, &result), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_write_right(&temp);
  s21_write_back(&temp2);
  for (int i = 0; (i < temp.rows); i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] - temp2.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&temp, &temp2, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  ck_assert_int_eq(s21_sub_matrix(&temp, &temp2, &result), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_mult_number) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  double num = 777.777;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  for (int i = 0; (i < temp.rows); i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] * 777.777;
    }
  }
  ck_assert_int_eq(s21_mult_number(&temp, num, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_mult_number_2) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  double num = 777.777;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  for (int i = 0; i < temp.rows; i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] * 777.777;
    }
  }
  ck_assert_int_eq(s21_mult_number(&temp, num, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_mult_matrix_2) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(3, 2, &temp);
  s21_create_matrix(2, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  result_defolt.matrix[0][0] = 9;
  result_defolt.matrix[0][1] = 12;
  result_defolt.matrix[0][2] = 15;
  result_defolt.matrix[1][0] = 19;
  result_defolt.matrix[1][1] = 26;
  result_defolt.matrix[1][2] = 33;
  result_defolt.matrix[2][0] = 29;
  result_defolt.matrix[2][1] = 40;
  result_defolt.matrix[2][2] = 51;
  ck_assert_int_eq(s21_mult_matrix(&temp, &temp2, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_mult_matrix_4) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(2, 3, &temp);
  s21_create_matrix(3, 2, &temp2);
  s21_create_matrix(2, 2, &result_defolt);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  result_defolt.matrix[0][0] = 22;
  result_defolt.matrix[0][1] = 28;
  result_defolt.matrix[1][0] = 49;
  result_defolt.matrix[1][1] = 64;
  ck_assert_int_eq(s21_mult_matrix(&temp, &temp2, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_mult_matrix_3) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_write_right(&temp);
  s21_write_right(&temp2);
  ck_assert_int_eq(s21_mult_matrix(&temp, &temp2, &result), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_transpose) {
  matrix_t temp;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(3, 2, &temp);
  s21_create_matrix(2, 3, &result_defolt);
  s21_write_right(&temp);
  result_defolt.matrix[0][0] = 1;
  result_defolt.matrix[0][1] = 3;
  result_defolt.matrix[0][2] = 5;
  result_defolt.matrix[1][0] = 2;
  result_defolt.matrix[1][1] = 4;
  result_defolt.matrix[1][2] = 6;
  ck_assert_int_eq(s21_transpose(&temp, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_determinant) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 2, &temp);
  s21_write_right(&temp);
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 2);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 3, &temp);
  s21_write_right(&temp);
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 0);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 0;
  temp.matrix[0][1] = 9;
  temp.matrix[0][2] = 5;

  temp.matrix[1][0] = 4;
  temp.matrix[1][1] = 3;
  temp.matrix[1][2] = -5;

  temp.matrix[2][0] = -1;
  temp.matrix[2][1] = 6;
  temp.matrix[2][2] = -4;
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 324);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 1;
  temp.matrix[1][1] = 1;
  temp.matrix[2][2] = 1;

  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 1);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_calc_complements) {
  matrix_t test, result;
  s21_create_matrix(3, 2, &test);
  int result_status;
  s21_write_right(&test);
  result_status = s21_calc_complements(&test, &result);
  ck_assert_int_eq(result_status, 2);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t test, result;
  s21_create_matrix(3, 3, &test);
  s21_write_right(&test);
  int result_status = s21_calc_complements(&test, &result);
  ck_assert_int_eq(result_status, 0);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
  matrix_t test, test_2, result;
  s21_create_matrix(3, 3, &test);
  test.matrix[0][0] = 1;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = 3;
  test.matrix[1][0] = 0;
  test.matrix[1][1] = 4;
  test.matrix[1][2] = 2;
  test.matrix[2][0] = 5;
  test.matrix[2][1] = 2;
  test.matrix[2][2] = 1;
  s21_calc_complements(&test, &result);
  s21_create_matrix(3, 3, &test_2);
  test_2.matrix[0][0] = 0;
  test_2.matrix[0][1] = 10;
  test_2.matrix[0][2] = -20;
  test_2.matrix[1][0] = 4;
  test_2.matrix[1][1] = -14;
  test_2.matrix[1][2] = 8;
  test_2.matrix[2][0] = -8;
  test_2.matrix[2][1] = -2;
  test_2.matrix[2][2] = 4;
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_uint_eq(result.matrix[i][j], test_2.matrix[i][j]);
    }
  }
  s21_remove_matrix(&test);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_inverse_matrix) {
  matrix_t temp, result_defolt, result_defolt_2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &result_defolt);
  temp.matrix[0][0] = 2;
  temp.matrix[0][1] = 5;
  temp.matrix[0][2] = 7;
  temp.matrix[1][0] = 6;
  temp.matrix[1][1] = 3;
  temp.matrix[1][2] = 4;
  temp.matrix[2][0] = 5;
  temp.matrix[2][1] = -2;
  temp.matrix[2][2] = -3;
  result_defolt.matrix[0][0] = 1;
  result_defolt.matrix[0][1] = -1;
  result_defolt.matrix[0][2] = 1;
  result_defolt.matrix[1][0] = -38;
  result_defolt.matrix[1][1] = 41;
  result_defolt.matrix[1][2] = -34;
  result_defolt.matrix[2][0] = 27;
  result_defolt.matrix[2][1] = -29;
  result_defolt.matrix[2][2] = 24;

  s21_inverse_matrix(&temp, &result_defolt_2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_uint_eq(result_defolt.matrix[i][j],
                        result_defolt_2.matrix[i][j]);
    }
  }
  s21_remove_matrix(&temp);
  s21_remove_matrix(&result_defolt);
  s21_remove_matrix(&result_defolt_2);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t temp, result;
  s21_create_matrix(3, 3, &temp);
  s21_write_right(&temp);
  int result_status = s21_inverse_matrix(&temp, &result);
  ck_assert_int_eq(result_status, 2);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t temp, result;
  s21_create_matrix(3, 3, &temp);
  s21_write_right(&temp);
  int result_status = s21_inverse_matrix(&temp, &result);
  ck_assert_int_eq(result_status, 2);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_inverse_matrix_4) {
  matrix_t temp, result;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 1;
  temp.matrix[1][1] = 1;
  temp.matrix[2][2] = 1;
  s21_inverse_matrix(&temp, &result);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_uint_eq(temp.matrix[i][j], result.matrix[i][j]);
    }
  }
  s21_remove_matrix(&temp);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_eq_matrix_test_1) {
  matrix_t result1;
  matrix_t result2;
  s21_create_matrix(41, 41, &result1);
  s21_create_matrix(41, 41, &result2);
  s21_write(&result1, 1);
  s21_write(&result2, 1);
  int expected_result = 1;
  int actual_result = s21_eq_matrix(&result1, &result2);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
}
END_TEST

START_TEST(s21_eq_matrix_test_2) {
  matrix_t result1;
  matrix_t result2;
  s21_create_matrix(83, 83, &result1);
  s21_create_matrix(83, 83, &result2);
  s21_write(&result1, 7);
  s21_write(&result2, 9);
  int expected_result = 0;
  int actual_result = s21_eq_matrix(&result1, &result2);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
}
END_TEST

START_TEST(s21_eq_matrix_test_3) {
  matrix_t result1;
  matrix_t result2;
  s21_create_matrix(32, 32, &result1);
  s21_create_matrix(27, 27, &result2);
  s21_write(&result1, 42);
  s21_write(&result2, 42);
  int expected_result = 0;
  int actual_result = s21_eq_matrix(&result1, &result2);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
}
END_TEST

START_TEST(s21_eq_matrix_test_4) {
  matrix_t result1;
  matrix_t result2;
  s21_create_matrix(22, 22, &result1);
  s21_create_matrix(22, 22, &result2);
  s21_write(&result1, 13);
  s21_write(&result2, 12);
  int expected_result = 0;
  int actual_result = s21_eq_matrix(&result1, &result2);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
}
END_TEST

START_TEST(s21_sum_matrix_test_1) {
  matrix_t result;
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(4, 4, &result1);
  s21_create_matrix(4, 4, &result2);
  s21_write(&result1, 3);
  s21_write(&result2, 4);
  s21_create_matrix(4, 4, &result);
  s21_write(&result, 7);
  s21_sum_matrix(&result1, &result2, &result3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result.matrix[i][j], result3.matrix[i][j]);
    }
  }
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sum_matrix_test_2) {
  matrix_t result;
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(2, 2, &result1);
  s21_create_matrix(4, 4, &result2);
  int expected_result = s21_create_matrix(2, 2, &result3);
  int actual_result = s21_sum_matrix(&result1, &result2, &result);
  ck_assert_int_ne(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result3);
}
END_TEST

START_TEST(s21_sum_matrix_test_3) {
  matrix_t result;
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(4, 4, &result1);
  s21_create_matrix(4, 4, &result2);
  s21_write(&result1, 0);
  result2.matrix[0][0] = 1;
  result2.matrix[1][1] = 1;
  result2.matrix[2][2] = 1;
  result2.matrix[3][3] = 1;
  int expected_result = s21_create_matrix(4, 4, &result3);
  result3.matrix[0][0] = 1;
  result3.matrix[1][1] = 1;
  result3.matrix[2][2] = 1;
  result3.matrix[3][3] = 1;
  int actual_result = s21_sum_matrix(&result1, &result2, &result);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result3.matrix[i][j], result.matrix[i][j]);
    }
  }
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_1) {
  matrix_t result;
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(4, 4, &result1);
  s21_create_matrix(4, 4, &result2);
  s21_write(&result1, 4);
  s21_write(&result2, 3);
  s21_create_matrix(4, 4, &result);
  s21_write(&result, 1);
  int sum_m = s21_sub_matrix(&result1, &result2, &result3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result.matrix[i][j], result3.matrix[i][j]);
    }
  }
  ck_assert_uint_eq(sum_m, 0);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_sub_matrix_test_2) {
  matrix_t result;
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(2, 2, &result1);
  s21_create_matrix(4, 4, &result2);
  int expected_result = s21_create_matrix(2, 2, &result3);
  int actual_result = s21_sum_matrix(&result1, &result2, &result);
  ck_assert_int_ne(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result3);
}
END_TEST

START_TEST(s21_sub_matrix_test_3) {
  matrix_t result;
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(4, 4, &result1);
  s21_create_matrix(4, 4, &result2);
  s21_write(&result2, 0);
  result1.matrix[0][0] = 1;
  result1.matrix[1][1] = 1;
  result1.matrix[2][2] = 1;
  result1.matrix[3][3] = 1;
  int expected_result = s21_create_matrix(4, 4, &result3);
  result3.matrix[0][0] = 1;
  result3.matrix[1][1] = 1;
  result3.matrix[2][2] = 1;
  result3.matrix[3][3] = 1;
  int actual_result = s21_sub_matrix(&result1, &result2, &result);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result3.matrix[i][j], result.matrix[i][j]);
    }
  }
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_mult_number_test_1) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(4, 4, &result1);
  s21_write(&result1, 3);
  int expected_result = s21_create_matrix(4, 4, &result2);
  s21_write(&result2, 30);
  int actual_result = s21_mult_number(&result1, 10, &result3);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result3.matrix[i][j], result2.matrix[i][j]);
    }
  }
  ck_assert_int_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result3);
}
END_TEST

START_TEST(s21_mult_number_test_2) {
  matrix_t result1;
  matrix_t result3;
  s21_create_matrix(2, 2, &result1);
  int expected_result = 0;
  int actual_result = s21_mult_number(&result1, 3, &result3);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_mult_matrix_test_1) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  matrix_t result4;
  s21_create_matrix(4, 4, &result1);
  s21_create_matrix(4, 4, &result2);
  s21_write(&result1, 3);
  s21_write(&result2, 3);
  int expected_result = s21_create_matrix(4, 4, &result3);
  s21_write(&result3, 36);
  int actual_result = s21_mult_matrix(&result1, &result2, &result4);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      ck_assert_double_eq(result3.matrix[i][j], result4.matrix[i][j]);
    }
  }
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result4);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_mult_matrix_test_2) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  matrix_t result4;
  s21_create_matrix(4, 4, &result1);
  s21_create_matrix(3, 3, &result2);
  s21_write(&result1, 3);
  s21_write(&result2, 3);
  int expected_result = s21_create_matrix(4, 4, &result3);
  expected_result = 1;
  int actual_result = s21_mult_matrix(&result1, &result2, &result4);
  ck_assert_uint_ne(expected_result, actual_result);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_calc_complements_test_1) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;

  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 1;
  result1.matrix[0][1] = 2;
  result1.matrix[0][2] = 3;

  result1.matrix[1][0] = 0;
  result1.matrix[1][1] = 4;
  result1.matrix[1][2] = 2;

  result1.matrix[2][0] = 5;
  result1.matrix[2][1] = 2;
  result1.matrix[2][2] = 1;
  int expected_result = s21_create_matrix(3, 3, &result2);
  result2.matrix[0][0] = 0;
  result2.matrix[0][1] = 10;
  result2.matrix[0][2] = -20;

  result2.matrix[1][0] = 4;
  result2.matrix[1][1] = -14;
  result2.matrix[1][2] = 8;

  result2.matrix[2][0] = -8;
  result2.matrix[2][1] = -2;
  result2.matrix[2][2] = 4;
  int actual_result = s21_calc_complements(&result1, &result3);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result2.matrix[i][j], result3.matrix[i][j], 1e-6);
    }
  }
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result1);
}

START_TEST(s21_calc_complements_test_2) {
  matrix_t result1;
  matrix_t result3;
  s21_create_matrix(3, -1, &result1);
  int expected_result = 2;
  int actual_result = s21_calc_complements(&result1, &result3);
  ck_assert_int_eq(expected_result, actual_result);
}
END_TEST

START_TEST(s21_determinant_test_1) {
  matrix_t result1;
  double result2;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 1;
  result1.matrix[0][1] = 2;
  result1.matrix[0][2] = 3;

  result1.matrix[1][0] = 4;
  result1.matrix[1][1] = 5;
  result1.matrix[1][2] = 6;

  result1.matrix[2][0] = 7;
  result1.matrix[2][1] = 8;
  result1.matrix[2][2] = 9;
  double expected_result = 0;
  s21_determinant(&result1, &result2);
  ck_assert_ldouble_eq(expected_result, result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_determinant_test_2) {
  matrix_t result1;
  double result3;
  s21_create_matrix(3, 4, &result1);
  int actual_result = CALCULATION_ERROR;
  int expected_result = s21_determinant(&result1, &result3);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_1) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 2;
  result1.matrix[0][1] = 5;
  result1.matrix[0][2] = 7;

  result1.matrix[1][0] = 6;
  result1.matrix[1][1] = 3;
  result1.matrix[1][2] = 4;

  result1.matrix[2][0] = 5;
  result1.matrix[2][1] = -2;
  result1.matrix[2][2] = -3;

  int expected_result = s21_create_matrix(3, 3, &result2);
  result2.matrix[0][0] = 1;
  result2.matrix[0][1] = -1;
  result2.matrix[0][2] = 1;
  result2.matrix[1][0] = -38;
  result2.matrix[1][1] = 41;
  result2.matrix[1][2] = -34;
  result2.matrix[2][0] = 27;
  result2.matrix[2][1] = -29;
  result2.matrix[2][2] = 24;
  int actual_result = s21_inverse_matrix(&result1, &result3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result2.matrix[i][j], result3.matrix[i][j], 1e-6);
    }
  }
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(s21_inverse_matrix_test_2) {
  matrix_t result1;
  matrix_t result3;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 1;
  result1.matrix[0][1] = 2;
  result1.matrix[0][2] = 3;

  result1.matrix[1][0] = 4;
  result1.matrix[1][1] = 5;
  result1.matrix[1][2] = 6;

  result1.matrix[2][0] = 7;
  result1.matrix[2][1] = 8;
  result1.matrix[2][2] = 9;
  int expected_result = CALCULATION_ERROR;
  int actual_result = s21_inverse_matrix(&result1, &result3);
  ck_assert_uint_eq(expected_result, actual_result);

  s21_remove_matrix(&result1);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int a;

  suite_add_tcase(s1, tc_1);
  tcase_add_test(tc_1, create_matrix);
  tcase_add_test(tc_1, transpose_matrix);
  tcase_add_test(tc_1, mult_num);
  tcase_add_test(tc_1, test_s21_eq_matrix);
  tcase_add_test(tc_1, test_s21_eq_matrix_2);
  tcase_add_test(tc_1, test_s21_eq_matrix_3);
  tcase_add_test(tc_1, test_s21_eq_matrix_3);
  tcase_add_test(tc_1, test_s21_eq_matrix_4);
  tcase_add_test(tc_1, test_s21_eq_matrix_5);
  tcase_add_test(tc_1, test_s21_sum_matrix);
  tcase_add_test(tc_1, test_s21_sum_matrix_2);
  tcase_add_test(tc_1, test_s21_sub_matrix);
  tcase_add_test(tc_1, test_s21_sub_matrix_2);
  tcase_add_test(tc_1, test_s21_mult_number);
  tcase_add_test(tc_1, test_s21_mult_number_2);
  tcase_add_test(tc_1, test_s21_mult_matrix_2);
  tcase_add_test(tc_1, test_s21_mult_matrix_4);
  tcase_add_test(tc_1, test_s21_mult_matrix_3);
  tcase_add_test(tc_1, test_s21_transpose);
  tcase_add_test(tc_1, test_s21_determinant);
  tcase_add_test(tc_1, test_s21_determinant_2);
  tcase_add_test(tc_1, test_s21_determinant_3);
  tcase_add_test(tc_1, test_s21_determinant_5);
  tcase_add_test(tc_1, test_s21_calc_complements);
  tcase_add_test(tc_1, test_s21_calc_complements_2);
  tcase_add_test(tc_1, test_s21_calc_complements_3);
  tcase_add_test(tc_1, test_s21_inverse_matrix);
  tcase_add_test(tc_1, test_s21_inverse_matrix_2);
  tcase_add_test(tc_1, test_s21_inverse_matrix_3);
  tcase_add_test(tc_1, test_s21_inverse_matrix_4);
  tcase_add_test(tc_1, s21_eq_matrix_test_1);
  tcase_add_test(tc_1, s21_eq_matrix_test_2);
  tcase_add_test(tc_1, s21_eq_matrix_test_3);
  tcase_add_test(tc_1, s21_eq_matrix_test_4);
  tcase_add_test(tc_1, s21_sum_matrix_test_1);
  tcase_add_test(tc_1, s21_sum_matrix_test_2);
  tcase_add_test(tc_1, s21_sum_matrix_test_3);
  tcase_add_test(tc_1, s21_sub_matrix_test_1);
  tcase_add_test(tc_1, s21_sub_matrix_test_2);
  tcase_add_test(tc_1, s21_sub_matrix_test_3);
  tcase_add_test(tc_1, s21_mult_number_test_1);
  tcase_add_test(tc_1, s21_mult_number_test_2);
  tcase_add_test(tc_1, s21_mult_matrix_test_1);
  tcase_add_test(tc_1, s21_mult_matrix_test_2);
  tcase_add_test(tc_1, s21_calc_complements_test_1);
  tcase_add_test(tc_1, s21_calc_complements_test_2);
  tcase_add_test(tc_1, s21_determinant_test_1);
  tcase_add_test(tc_1, s21_determinant_test_2);
  tcase_add_test(tc_1, s21_inverse_matrix_test_1);
  tcase_add_test(tc_1, s21_inverse_matrix_test_2);
  srunner_run_all(sr, CK_ENV);
  a = srunner_ntests_failed(sr);
  srunner_free(sr);

  return a == 0 ? 0 : 1;
}
