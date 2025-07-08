#include "test.h"

START_TEST(s21_sum_matrix_0) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_fill_matrix(&matrix1, 1, 0.2);
  s21_fill_matrix(&matrix2, 2, 0.2);
  check_correct_sum(s21_sum_matrix(&matrix1, &matrix2, &res));
  check_result_sum(&matrix1, &matrix2, &res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sum_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  s21_create_matrix(3, 2, &matrix1);
  s21_create_matrix(3, 2, &matrix2);
  s21_fill_matrix(&matrix1, 8, 1);
  s21_fill_matrix(&matrix2, 11, 1);
  check_correct_sum(s21_sum_matrix(&matrix1, &matrix2, &res));
  check_result_sum(&matrix1, &matrix2, &res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  s21_create_matrix(2, 4, &matrix1);
  s21_create_matrix(2, 4, &matrix2);
  s21_fill_matrix(&matrix1, 2, 0.11);
  s21_fill_matrix(&matrix2, 4, 0.17);
  check_correct_sum(s21_sum_matrix(&matrix1, &matrix2, &res));
  check_result_sum(&matrix1, &matrix2, &res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  s21_create_matrix(7, 4, &matrix1);
  s21_create_matrix(2, 4, &matrix2);
  s21_fill_matrix(&matrix1, 2, 0.11);
  s21_fill_matrix(&matrix2, 4, 0.17);
  check_incorrect_calc_sum(s21_sum_matrix(&matrix1, &matrix2, &res));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  matrix_t res;
  s21_create_matrix(7, 4, &matrix1);
  s21_create_matrix(2, 4, &matrix2);
  s21_fill_matrix(&matrix1, 2, 0.11);
  s21_fill_matrix(&matrix2, 4, 0.17);
  check_incorrect_matrix_sum(s21_sum_matrix(NULL, &matrix2, &res));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

void check_result_sum(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      ck_assert_double_eq_tol((A->matrix[i][j] + B->matrix[i][j]),
                              result->matrix[i][j], S21_EPSILON);
    }
  }
}

void check_incorrect_matrix_sum(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_calc_sum(int code) {
  int expected = 2;
  ck_assert_int_eq(code, expected);
}

void check_correct_sum(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

Suite *tests_for_s21_sum_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_sum_matrix_tests");
  tc = tcase_create("s21_sum_matrix_tc");
  tcase_add_test(tc, s21_sum_matrix_0);
  tcase_add_test(tc, s21_sum_matrix_1);
  tcase_add_test(tc, s21_sum_matrix_2);
  tcase_add_test(tc, s21_sum_matrix_3);
  tcase_add_test(tc, s21_sum_matrix_4);

  suite_add_tcase(s, tc);

  return s;
}