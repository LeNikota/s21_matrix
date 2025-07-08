#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows <= 0 || columns <= 0 || result == NULL) return ERROR;

  result->rows = rows;
  result->columns = columns;
  result->matrix = NULL;

  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (result->matrix == NULL) return ERROR;

  for (int i = 0; i < rows; i++) {
    result->matrix[i] = (double *)malloc(columns * sizeof(double));

    if (result->matrix[i] == NULL) {
      for (int j = 0; j < i; j++) free(result->matrix[j]);
      free(result->matrix);

      result->matrix = NULL;

      return ERROR;
    }

    for (int j = 0; j < rows; j++) result->matrix[i][j] = 0.0;
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
  int error = 0;
  (void)A;
  (void)B;

  return error;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  (void)A;
  (void)B;
  (void)result;

  return error;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  (void)A;
  (void)B;
  (void)result;

  return error;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = 0;
  (void)A;
  (void)number;
  (void)result;

  return error;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = 0;
  (void)A;
  (void)B;
  (void)result;

  return error;
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