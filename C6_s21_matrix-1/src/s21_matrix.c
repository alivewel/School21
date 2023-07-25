#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (s21_check_matrix(A) == OK) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
  }
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (rows > 0 && columns > 0 && result != NULL) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      status = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows && status != INCORRECT_MATRIX; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix == NULL) {
          s21_remove_matrix(result);
          status = INCORRECT_MATRIX;
        }
      }
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_check_matrix(matrix_t *A) {
  int result = INCORRECT_MATRIX;
  if (A->rows > 0 && A->columns > 0 && A != NULL && A->matrix != NULL) {
    result = OK;
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  result->matrix = NULL;
  if (s21_check_matrix(A) == OK && s21_check_matrix(B) == OK) {
    if (A->rows == B->rows && A->columns == B->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  result->matrix = NULL;
  if (s21_check_matrix(A) == OK && s21_check_matrix(B) == OK) {
    if (A->rows == B->rows && A->columns == B->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;
  result->matrix = NULL;
  if (s21_check_matrix(A) == OK) {
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  result->matrix = NULL;
  if (s21_check_matrix(A) == OK && s21_check_matrix(B) == OK) {
    if (A->columns == B->rows) {
      s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          result->matrix[i][j] = 0;
          for (int k = 0; k < A->columns; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;
  result->matrix = NULL;
  if (s21_check_matrix(A) == OK) {
    s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = FAILURE;
  if (s21_check_matrix(A) == OK && s21_check_matrix(B) == OK &&
      A->rows == B->rows && A->columns == B->columns) {
    status = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= 1e-7) status = FAILURE;
      }
    }
  } else {
    status = FAILURE;
  }
  return status;
}

void s21_create_small_matrix(matrix_t *A, matrix_t *new_small_matrix,
                             int remove_columns) {
  s21_create_matrix(A->rows - 1, A->columns - 1, new_small_matrix);
  for (int i = 1, i_new = 0; i < A->rows; i++) {
    for (int j = 0, j_new = 0; j < A->columns; j++) {
      if (j != remove_columns) {
        new_small_matrix->matrix[i_new][j_new] = A->matrix[i][j];
        j_new++;
      }
    }
    i_new++;
  }
}

/* rows - строки, columns - столбцы */
double s21_determinant_help(matrix_t *A, int num_rows) {
  double determinant = 0;
  if (A->rows == 1) {
    determinant = A->matrix[0][0];
  } else if (A->rows == 2) {
    determinant =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int i = 0; i < num_rows; i++) {
      matrix_t new_small_matrix;
      s21_create_small_matrix(A, &new_small_matrix, i);
      double sign = 1.0;
      if (i % 2 != 0) sign = -1.0;
      determinant += sign * A->matrix[0][i] *
                     s21_determinant_help(&new_small_matrix, num_rows - 1);
      s21_remove_matrix(&new_small_matrix);
    }
  }
  return determinant;
}

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (A == NULL || A->rows < 1 || A->columns < 1) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else if (A->rows == 1 && A->columns == 1) {
    *result = A->matrix[0][0];
  } else {
    *result = s21_determinant_help(A, A->rows);
  }
  return status;
}

int s21_create_small_matrix_minor(matrix_t *A, matrix_t *new_small_matrix_compl,
                                  int remove_rows, int remove_columns) {
  int status = OK;
  if (s21_create_matrix(A->rows - 1, A->columns - 1, new_small_matrix_compl) ==
      0) {
    for (int i = 0, i_new = 0; i < A->rows; i++) {
      for (int j = 0, j_new = 0; j < A->columns; j++) {
        if (j != remove_columns && i != remove_rows) {
          new_small_matrix_compl->matrix[i_new][j_new] = A->matrix[i][j];
          j_new++;
        }
      }
      if (i != remove_rows) i_new++;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  result->matrix = NULL;
  int status = OK;
  if (s21_check_matrix(A) == OK) {
    if (A->rows == A->columns) {
      s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double sign = 1.0;
          if ((i + j) % 2 != 0) sign = -1.0;
          matrix_t new_small_matrix_compl;
          if (s21_create_small_matrix_minor(A, &new_small_matrix_compl, i, j) ==
              OK) {
            double determinant = 0;
            s21_determinant(&new_small_matrix_compl, &determinant);
            result->matrix[i][j] = sign * determinant;
            s21_remove_matrix(&new_small_matrix_compl);
          }
        }
      }
    } else {
      status = CALCULATION_ERROR;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  result->matrix = NULL;
  int status = OK;
  double determinant = 0;
  s21_determinant(A, &determinant);
  if (s21_check_matrix(A) != OK) {
    status = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    status = CALCULATION_ERROR;
  } else if (determinant == 0) {
    status = CALCULATION_ERROR;
  } else {
    matrix_t inverse_matrix;
    matrix_t transpose_matrix;
    s21_calc_complements(A, &inverse_matrix);
    s21_transpose(&inverse_matrix, &transpose_matrix);
    s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = 1 / determinant * transpose_matrix.matrix[i][j];
      }
    }
    s21_remove_matrix(&inverse_matrix);
    s21_remove_matrix(&transpose_matrix);
  }
  return status;
}
