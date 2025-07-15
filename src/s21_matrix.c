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
  if (A == NULL || result == NULL || A->matrix == NULL) {
    return INCORRECT_MATRIX;
  }

  int status = s21_create_matrix(A->columns, A->rows, result);
  if (status != OK) return status;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!A || !A->matrix || !result) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  if (A->rows == 1) {
    s21_create_matrix(1, 1, result);

    result->matrix[0][0] = 1;

    return OK;
  }

  s21_create_matrix(A->columns, A->rows, result);

  matrix_t minor;
  s21_create_matrix(A->rows - 1, A->columns - 1, &minor);

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      double det = 0;

      get_minor(A, &minor, i, j);
      s21_determinant(&minor, &det);

      result->matrix[i][j] = det * ((i + j) % 2 ? -1 : 1);
    }
  }

  s21_remove_matrix(&minor);

  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (A == NULL || result == NULL || A->matrix == NULL) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALCULATION_ERROR;

  int n = A->rows;
  double det = 1.0;

  matrix_t temp;
  if (s21_create_matrix(n, n, &temp)) return CALCULATION_ERROR;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp.matrix[i][j] = A->matrix[i][j];
    }
  }

  for (int col = 0; col < n; col++) {
    // Partial pivoting:
    // find the row with the largest element in current column
    int max_row = col;
    for (int row = col + 1; row < n; row++) {
      if (fabs(temp.matrix[row][col]) > fabs(temp.matrix[max_row][col])) {
        max_row = row;
      }
    }

    // If the maximum element is zero, the matrix is singular
    if (fabs(temp.matrix[max_row][col]) < 1e-12) {
      *result = 0.0;
      s21_remove_matrix(&temp);
      return OK;
    }

    // Swap rows if needed
    if (max_row != col) {
      for (int j = 0; j < n; j++) {
        double tmp = temp.matrix[col][j];
        temp.matrix[col][j] = temp.matrix[max_row][j];
        temp.matrix[max_row][j] = tmp;
      }
      det *= -1;  // Row swap changes the sign of determinant
    }

    // Perform elimination for all rows below
    for (int row = col + 1; row < n; row++) {
      double factor = temp.matrix[row][col] / temp.matrix[col][col];
      for (int j = col; j < n; j++) {
        temp.matrix[row][j] -= factor * temp.matrix[col][j];
      }
    }
  }

  // Calculate determinant as product of diagonal elements
  for (int i = 0; i < n; i++) {
    det *= temp.matrix[i][i];
  }

  *result = det;
  s21_remove_matrix(&temp);

  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (A == NULL || result == NULL || A->matrix == NULL || A->rows <= 0 ||
      A->columns <= 0) {
    return INCORRECT_MATRIX;
  }

  if (A->rows != A->columns) {
    return CALCULATION_ERROR;
  }

  double det = 0;
  int det_status = s21_determinant(A, &det);
  if (det_status != 0) return det_status;
  if (fabs(det) < 1e-7) return CALCULATION_ERROR;

  matrix_t complements;
  matrix_t adjugate;
  s21_calc_complements(A, &complements);
  s21_transpose(&complements, &adjugate);
  s21_mult_number(&adjugate, 1.0 / det, result);

  s21_remove_matrix(&complements);
  s21_remove_matrix(&adjugate);

  return OK;
}

// Utility
void get_minor(matrix_t *A, matrix_t *minor, int row, int col) {
  for (int i = 0, mi = 0; i < A->rows; i++) {
    if (i == row) continue;
    for (int j = 0, mj = 0; j < A->columns; j++) {
      if (j == col) continue;
      minor->matrix[mi][mj] = A->matrix[i][j];
      mj++;
    }
    mi++;
  }
}