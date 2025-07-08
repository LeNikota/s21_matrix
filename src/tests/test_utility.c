#include "test.h"

void s21_fill_matrix(matrix_t *A, int rows, int columns) {
  // srand(time(NULL));

  // if (A == NULL || A->matrix == NULL || rows < 1 || columns < 1) {
  //   return ERROR;
  // }
  // if (rows != A->rows || columns != A->columns) {
  //   return CALCULATION_ERROR;
  // }

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      // Random values 0.0-99.9
      A->matrix[i][j] = (double)(rand() % 1000) / 10.0;
    }
  }
}