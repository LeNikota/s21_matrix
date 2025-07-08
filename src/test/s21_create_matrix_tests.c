#include "test.h"

START_TEST(s21_create_matrix_0) {
  matrix_t matrix;
  check_incorrect_create(s21_create_matrix(0, 2, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_1) {
  matrix_t matrix;
  check_incorrect_create(s21_create_matrix(0, 0, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_2) {
  matrix_t matrix;
  check_incorrect_create(s21_create_matrix(56, 0, &matrix));
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t matrix;
  check_correct_create(s21_create_matrix(2, 2, &matrix));
  s21_remove_matrix(&matrix);
}
END_TEST

void check_incorrect_create(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

void check_correct_create(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

Suite *tests_for_s21_create_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_create_matrix_tests");
  tc = tcase_create("s21_create_matrix_tc");
  tcase_add_test(tc, s21_create_matrix_0);
  tcase_add_test(tc, s21_create_matrix_1);
  tcase_add_test(tc, s21_create_matrix_2);
  tcase_add_test(tc, s21_create_matrix_3);

  suite_add_tcase(s, tc);

  return s;
}