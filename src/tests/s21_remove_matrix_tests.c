#include "test.h"

START_TEST(s21_remove_matrix_0) {
  matrix_t matrix;
  s21_create_matrix(2, 2, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

START_TEST(s21_remove_matrix_1) {
  matrix_t matrix;
  s21_create_matrix(6, 12, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
}
END_TEST

Suite *tests_for_s21_remove_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_remove_matrix_tests");
  tc = tcase_create("s21_remove_matrix_tc");
  tcase_add_test(tc, s21_remove_matrix_0);
  tcase_add_test(tc, s21_remove_matrix_1);

  suite_add_tcase(s, tc);

  return s;
}