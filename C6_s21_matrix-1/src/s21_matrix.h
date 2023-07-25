#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Сравнение матриц
#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/* Все операции (кроме сравнения матриц) должны
   возвращать результирующий код */
enum status {
  OK,
  /* неправильная матрица */
  INCORRECT_MATRIX,
  /* Ошибка расчета (несоответствие размеров матриц;
   матрица, для которой невозможно произвести расчеты и т.д.) */
  CALCULATION_ERROR
};

void s21_remove_matrix(matrix_t *A);
int s21_create_matrix(int rows, int columns, matrix_t *result);
int s21_check_matrix(matrix_t *A);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
void s21_create_small_matrix(matrix_t *A, matrix_t *new_small_matrix,
                             int remove_columns);
double s21_determinant_help(matrix_t *A, int num_rows);
int s21_determinant(matrix_t *A, double *result);
int s21_create_small_matrix_minor(matrix_t *A, matrix_t *new_small_matrix,
                                  int remove_rows, int remove_columns);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // SRC_S21_MATRIX_H_
