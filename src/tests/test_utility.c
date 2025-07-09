#include "test.h"

void s21_fill_matrix(matrix_t *matrix, int mode, double value) {
  if (matrix == NULL || matrix->rows <= 0 || matrix->columns <= 0) return;

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      switch (mode) {
        case 0:  // Fill with constant value
          matrix->matrix[i][j] = value;
          break;
        case 1:  // Fill with row-based pattern
          matrix->matrix[i][j] = value * (i + 1);
          break;
        case 2:  // Fill with column-based pattern
          matrix->matrix[i][j] = value * (j + 1);
          break;
        case 3:  // Fill with identity-like pattern
          matrix->matrix[i][j] = (i == j) ? value : 0;
          break;
        default:  // Linear increment pattern
          matrix->matrix[i][j] = value + i * matrix->columns + j;
      }
    }
  }
}