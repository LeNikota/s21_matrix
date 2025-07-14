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