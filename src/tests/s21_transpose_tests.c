#include "test.h"

START_TEST(s21_transpose_0) {
  matrix_t matrix1;
  matrix_t res;
  s21_create_matrix(3, 2, &matrix1);
  s21_fill_matrix(&matrix1, 2, 4);
  check_correct_transpose(s21_transpose(&matrix1, &res));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_1) {
  matrix_t matrix1;
  matrix_t res;
  s21_create_matrix(2, 5, &matrix1);
  s21_fill_matrix(&matrix1, 1, 5.3);
  // s21_print_matrix(&matrix1);
  check_correct_transpose(s21_transpose(&matrix1, &res));
  // s21_print_matrix(&res);
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t matrix1;
  matrix_t res;
  s21_create_matrix(3, 2, &matrix1);
  s21_fill_matrix(&matrix1, 2, 4);
  check_incorrect_transpose(s21_transpose(NULL, &res));
  s21_remove_matrix(&matrix1);
}
END_TEST

void check_incorrect_transpose(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

void check_correct_transpose(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

Suite *tests_for_s21_transpose(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_transpose_tests");
  tc = tcase_create("s21_transpose_tc");
  tcase_add_test(tc, s21_transpose_0);
  tcase_add_test(tc, s21_transpose_1);
  tcase_add_test(tc, s21_transpose_2);

  suite_add_tcase(s, tc);

  return s;
}