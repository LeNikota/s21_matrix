#include "test.h"

START_TEST(s21_eq_matrix_0) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  s21_fill_matrix(&matrix1, 2, 0.12345678);
  s21_fill_matrix(&matrix2, 2, 0.12345678);
  check_correct_eq(s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix_1) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  s21_fill_matrix(&matrix1, 2, 0.12345678);
  s21_fill_matrix(&matrix2, 2, 0.12345678);
  check_incorrect_eq(s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &matrix2);
  s21_fill_matrix(&matrix1, 2, 0.2);
  s21_fill_matrix(&matrix2, 2, 0.3);
  check_incorrect_eq(s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(3, 7, &matrix1);
  s21_create_matrix(3, 7, &matrix2);
  s21_fill_matrix(&matrix1, 0, 0.17);
  s21_fill_matrix(&matrix2, 0, 0.17);
  check_correct_eq(s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t matrix1;
  matrix_t matrix2;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &matrix2);
  s21_fill_matrix(&matrix1, 1, 64);
  s21_fill_matrix(&matrix2, 2, 3);
  check_incorrect_eq(s21_eq_matrix(&matrix1, &matrix2));
  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&matrix2);
}
END_TEST

void check_incorrect_eq(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

void check_correct_eq(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

Suite *tests_for_s21_eq_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_eq_matrix_tests");
  tc = tcase_create("s21_eq_matrix_tc");
  tcase_add_test(tc, s21_eq_matrix_0);
  tcase_add_test(tc, s21_eq_matrix_1);
  tcase_add_test(tc, s21_eq_matrix_2);
  tcase_add_test(tc, s21_eq_matrix_3);
  tcase_add_test(tc, s21_eq_matrix_4);

  suite_add_tcase(s, tc);

  return s;
}