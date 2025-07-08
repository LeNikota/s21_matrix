#include "test.h"

START_TEST(s21_mult_num_matrix_0) {
  matrix_t matrix1;
  double num = 2;
  matrix_t res;
  s21_create_matrix(2, 2, &matrix1);
  s21_fill_matrix(&matrix1, 1, 2);
  check_correct_mult_num(s21_mult_number(&matrix1, num, &res));
  check_result_mult_num(&matrix1, num, &res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_num_matrix_1) {
  matrix_t matrix1;
  double num = 11;
  matrix_t res;
  s21_create_matrix(2, 2, &matrix1);
  s21_fill_matrix(&matrix1, 4, 0.2);
  check_correct_mult_num(s21_mult_number(&matrix1, num, &res));
  check_result_mult_num(&matrix1, num, &res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_num_matrix_2) {
  matrix_t matrix1;
  double num = 0.14256;
  matrix_t res;
  s21_create_matrix(2, 2, &matrix1);
  s21_fill_matrix(&matrix1, 0.4, 2);
  check_correct_mult_num(s21_mult_number(&matrix1, num, &res));
  check_result_mult_num(&matrix1, num, &res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_mult_num_matrix_3) {
  matrix_t matrix1;
  double num = 0.14256;
  matrix_t res;
  s21_create_matrix(2, 2, &matrix1);
  s21_fill_matrix(&matrix1, 0.4, 2);
  check_incorrect_matrix_mult_num(s21_mult_number(NULL, num, &res));
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_mult_num_matrix_4) {
  matrix_t matrix1;
  matrix_t res;
  s21_create_matrix(2, 2, &matrix1);
  s21_fill_matrix(&matrix1, 0.4, 2);
  check_incorrect_calc_mult_num(s21_mult_number(&matrix1, NAN, &res));
  s21_remove_matrix(&matrix1);
}
END_TEST

void check_result_mult_num(matrix_t *A, double num, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      ck_assert_double_eq_tol((A->matrix[i][j] * num), result->matrix[i][j],
                              S21_EPSILON);
    }
  }
}

void check_incorrect_matrix_mult_num(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_calc_mult_num(int code) {
  int expected = 2;
  ck_assert_int_eq(code, expected);
}

void check_correct_mult_num(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

Suite *tests_for_s21_mult_number(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_mult_num_matrix_tests");
  tc = tcase_create("s21_mult_num_matrix_tc");
  tcase_add_test(tc, s21_mult_num_matrix_0);
  tcase_add_test(tc, s21_mult_num_matrix_1);
  tcase_add_test(tc, s21_mult_num_matrix_2);
  tcase_add_test(tc, s21_mult_num_matrix_3);
  tcase_add_test(tc, s21_mult_num_matrix_4);

  suite_add_tcase(s, tc);

  return s;
}