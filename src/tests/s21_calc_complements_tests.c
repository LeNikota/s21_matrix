#include "test.h"

START_TEST(s21_calc_complements_0) {
  matrix_t matrix1;
  matrix_t result;
  matrix_t expected_matrix;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &expected_matrix);

  expected_matrix.matrix[0][0] = 8.0;
  expected_matrix.matrix[0][1] = -6.0;
  expected_matrix.matrix[1][0] = -4.0;
  expected_matrix.matrix[1][1] = 2.0;

  s21_fill_matrix(&matrix1, 2, 2);

  check_correct_calc_complements(s21_calc_complements(&matrix1, &result));
  check_calc_complements_got_expected(&result, &expected_matrix);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}
END_TEST

START_TEST(s21_calc_complements_1) {
  matrix_t matrix1;
  matrix_t result;
  matrix_t expected_matrix;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &expected_matrix);

  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 3.2;
  matrix1.matrix[0][2] = 4.4;
  matrix1.matrix[1][0] = 5.6;
  matrix1.matrix[1][1] = 7;
  matrix1.matrix[1][2] = 8;
  matrix1.matrix[2][0] = 9.2;
  matrix1.matrix[2][1] = 10.4;
  matrix1.matrix[2][2] = 11.6;

  expected_matrix.matrix[0][0] = -2.0;
  expected_matrix.matrix[0][1] = 8.64;
  expected_matrix.matrix[0][2] = -6.16;
  expected_matrix.matrix[1][0] = 8.64;
  expected_matrix.matrix[1][1] = -17.28;
  expected_matrix.matrix[1][2] = 8.64;
  expected_matrix.matrix[2][0] = -5.2;
  expected_matrix.matrix[2][1] = 8.64;
  expected_matrix.matrix[2][2] = -3.92;

  check_correct_calc_complements(s21_calc_complements(&matrix1, &result));
  check_calc_complements_got_expected(&result, &expected_matrix);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&expected_matrix);
}
END_TEST

START_TEST(s21_calc_complements_2) {
  matrix_t result;

  check_incorrect_calc_complements(s21_calc_complements(NULL, &result));
}
END_TEST

START_TEST(s21_calc_complements_3) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(3, 7, &matrix1);

  check_incorrect_calculation_calc_complements(
      s21_calc_complements(&matrix1, &result));

  s21_remove_matrix(&matrix1);
}
END_TEST

void check_calc_complements_got_expected(matrix_t *got_matrix,
                                         matrix_t *expected_matrix) {
  for (int i = 0; i < expected_matrix->rows; i++) {
    for (int j = 0; j < expected_matrix->columns; j++) {
      ck_assert_double_eq_tol(got_matrix->matrix[i][j],
                              expected_matrix->matrix[i][j], 1e-06);
    }
  }
}

void check_correct_calc_complements(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_calc_complements(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_calculation_calc_complements(int code) {
  int expected = 2;
  ck_assert_int_eq(code, expected);
}

Suite *tests_for_s21_calc_complements(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_calc_complements_tests");
  tc = tcase_create("s21_calc_complements_tc");
  tcase_add_test(tc, s21_calc_complements_0);
  tcase_add_test(tc, s21_calc_complements_1);
  tcase_add_test(tc, s21_calc_complements_2);
  tcase_add_test(tc, s21_calc_complements_3);

  suite_add_tcase(s, tc);

  return s;
}