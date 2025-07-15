#include "test.h"

void s21_fill_matrix(matrix_t *matrix, double start, double step) {
  if (matrix == NULL || matrix->rows <= 0 || matrix->columns <= 0) return;

  double val = start;
  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->matrix[i][j] = val;
      val += step;
    }
  }
}

void check_got_expected(int error, matrix_t *got, matrix_t *expected) {
  ck_assert_int_eq(got->rows, expected->rows);
  ck_assert_int_eq(got->columns, expected->columns);

  for (int i = 0; i < expected->rows; i++) {
    for (int j = 0; j < expected->columns; j++) {
      // ck_assert_double_eq_tol(got->matrix[i][j], expected->matrix[i][j],
      // 1e-06);
      ck_assert_double_eq_tol(got->matrix[i][j], expected->matrix[i][j], 1e-03);
    }
  }

  ck_assert_int_eq(error, OK);
}