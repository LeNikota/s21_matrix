#include "test.h"

START_TEST(s21_mult_matrix_0) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  matrix_t check;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_fill_matrix(&matrix1, 1, 2);
  s21_fill_matrix(&matrix2, 2, 2);
  s21_create_matrix(matrix1.rows, matrix2.columns, &check);

  check_correct_mult(s21_mult_matrix(&matrix1, &matrix2, &res));
  check_result_mult(&matrix1, &matrix2, &res, &check);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  matrix_t check;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  s21_fill_matrix(&matrix1, 1.2, 0.6);
  s21_fill_matrix(&matrix2, 2, 0.98);
  s21_create_matrix(matrix1.rows, matrix2.columns, &check);
  check_correct_mult(s21_mult_matrix(&matrix1, &matrix2, &res));
  check_result_mult(&matrix1, &matrix2, &res, &check);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(s21_mult_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  s21_fill_matrix(&matrix1, 1.2, 0.6);
  s21_fill_matrix(&matrix2, 2, 0.98);

  check_incorrect_matrix_mult(s21_mult_matrix(&matrix1, NULL, &res));

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_mult_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  s21_create_matrix(8, 1, &matrix1);
  s21_create_matrix(15, 7, &matrix2);
  s21_fill_matrix(&matrix1, 1.2, 0.6);
  s21_fill_matrix(&matrix2, 2, 0.98);

  check_incorrect_calc_mult(s21_mult_matrix(&matrix1, &matrix2, &res));

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_mult_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  s21_create_matrix(4, 3, &matrix1);
  s21_create_matrix(4, 3, &matrix2);
  s21_fill_matrix(&matrix1, 1.2, 0.6);
  s21_fill_matrix(&matrix2, 2, 0.98);

  check_incorrect_calc_mult(s21_mult_matrix(&matrix1, &matrix2, &res));

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

void check_result_mult(matrix_t *A, matrix_t *B, matrix_t *result,
                       matrix_t *check) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int k = 0; k < B->rows; k++) {
        check->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
      ck_assert_double_eq_tol(check->matrix[i][j], result->matrix[i][j],
                              S21_EPSILON);
    }
  }
}

void check_incorrect_matrix_mult(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_calc_mult(int code) {
  int expected = 2;
  ck_assert_int_eq(code, expected);
}

void check_correct_mult(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

Suite *tests_for_s21_mult_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_mult_matrix_tests");
  tc = tcase_create("s21_mult_matrix_tc");
  tcase_add_test(tc, s21_mult_matrix_0);
  tcase_add_test(tc, s21_mult_matrix_1);
  tcase_add_test(tc, s21_mult_matrix_2);
  tcase_add_test(tc, s21_mult_matrix_3);
  tcase_add_test(tc, s21_mult_matrix_4);

  suite_add_tcase(s, tc);

  return s;
}