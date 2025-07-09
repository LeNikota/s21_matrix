#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) return INCORRECT_MATRIX;

  result->rows = rows;
  result->columns = columns;
  result->matrix = NULL;

  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) return CALCULATION_ERROR;

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));

    if (result->matrix[i] == NULL) {
      for (int j = 0; j < i; j++) free(result->matrix[j]);
      free(result->matrix);

      result->matrix = NULL;

      return CALCULATION_ERROR;
    }
  }

  return OK;
}
void s21_remove_matrix(matrix_t *A) {
  if (A == NULL || A->matrix == NULL) return;

  for (int i = 0; i < A->rows; i++) {
    if (A->matrix[i] != NULL) free(A->matrix[i]);
  }

  free(A->matrix);

  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A == NULL || B == NULL || A->matrix == NULL || B->matrix == NULL) {
    return FAILURE;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return FAILURE;
  }

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
        return FAILURE;
      }
    }
  }

  return SUCCESS;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return CALCULATION_ERROR;
  }

  int status = s21_create_matrix(A->rows, A->columns, result);
  if (status != OK) return status;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    return CALCULATION_ERROR;
  }

  int status = s21_create_matrix(A->rows, A->columns, result);
  if (status != OK) return status;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return OK;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (A == NULL || A->matrix == NULL || result == NULL) return INCORRECT_MATRIX;
  if (isnan(number)) return CALCULATION_ERROR;

  int status = s21_create_matrix(A->rows, A->columns, result);
  if (status != OK) return status;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A == NULL || B == NULL || result == NULL || A->matrix == NULL ||
      B->matrix == NULL) {
    return INCORRECT_MATRIX;
  }
  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }

  int status = s21_create_matrix(A->rows, B->columns, result);
  if (status != OK) return status;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      for (int k = 0; k < A->columns; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = 0;
  (void)A;
  (void)result;

  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = 0;
  (void)A;
  (void)result;

  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = 0;
  (void)A;
  (void)result;

  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;
  (void)A;
  (void)result;

  return error;
}