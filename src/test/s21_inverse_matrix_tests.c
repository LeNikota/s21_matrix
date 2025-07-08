#include "test.h"

START_TEST(s21_inverse_matrix_0) {
  matrix_t matrix1;
  matrix_t result;
  matrix_t expected_matrix;
  s21_create_matrix(2, 2, &matrix1);
  s21_create_matrix(2, 2, &expected_matrix);
  s21_fill_matrix(&matrix1, 3, 3);

  expected_matrix.matrix[0][0] = -0.6666666;
  expected_matrix.matrix[0][1] = 0.3333333;
  expected_matrix.matrix[1][0] = 0.5;
  expected_matrix.matrix[1][1] = -0.16666666;

  check_correct_inverse_matrix(s21_inverse_matrix(&matrix1, &result));

  check_inversed_matrix_got_expected(&result, &expected_matrix);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&expected_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_1) {
  matrix_t matrix1;
  matrix_t result;
  matrix_t expected_matrix;
  s21_create_matrix(3, 3, &matrix1);
  s21_create_matrix(3, 3, &expected_matrix);

  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 7;
  matrix1.matrix[0][2] = 2;
  matrix1.matrix[1][0] = 7;
  matrix1.matrix[1][1] = 2;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 1;
  matrix1.matrix[2][1] = 1;
  matrix1.matrix[2][2] = 1;

  expected_matrix.matrix[0][0] = 0.8;
  expected_matrix.matrix[0][1] = 1;
  expected_matrix.matrix[0][2] = -7.6;
  expected_matrix.matrix[1][0] = 0.2;
  expected_matrix.matrix[1][1] = 0;
  expected_matrix.matrix[1][2] = -0.4;
  expected_matrix.matrix[2][0] = -1;
  expected_matrix.matrix[2][1] = -1;
  expected_matrix.matrix[2][2] = 9;

  check_correct_inverse_matrix(s21_inverse_matrix(&matrix1, &result));
  check_inversed_matrix_got_expected(&result, &expected_matrix);

  s21_remove_matrix(&matrix1);
  s21_remove_matrix(&expected_matrix);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_2) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(3, 3, &matrix1);

  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 7;
  matrix1.matrix[0][2] = 2;
  matrix1.matrix[1][0] = 7;
  matrix1.matrix[1][1] = 2;
  matrix1.matrix[1][2] = 6;
  matrix1.matrix[2][0] = 1;
  matrix1.matrix[2][1] = 1;
  matrix1.matrix[2][2] = 1;

  check_incorrect_inverse_matrix(s21_inverse_matrix(NULL, &result));

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_inverse_matrix_3) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(3, 5, &matrix1);

  check_incorrect_calc_inverse_matrix(s21_inverse_matrix(&matrix1, &result));

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_inverse_matrix_4) {
  matrix_t matrix1;
  matrix_t result;
  s21_create_matrix(2, 2, &matrix1);

  matrix1.matrix[0][0] = 2;
  matrix1.matrix[0][1] = 3;
  matrix1.matrix[1][0] = 4;
  matrix1.matrix[1][1] = 6;

  check_incorrect_calc_inverse_matrix(s21_inverse_matrix(&matrix1, &result));

  s21_remove_matrix(&matrix1);
}
END_TEST

void check_correct_inverse_matrix(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_inverse_matrix(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_calc_inverse_matrix(int code) {
  int expected = 2;
  ck_assert_int_eq(code, expected);
}

void check_inversed_matrix_got_expected(matrix_t *got_matrix,
                                        matrix_t *expected_matrix) {
  for (int i = 0; i < expected_matrix->rows; i++) {
    for (int j = 0; j < expected_matrix->columns; j++) {
      ck_assert_double_eq_tol(got_matrix->matrix[i][j],
                              expected_matrix->matrix[i][j], 1e-06);
    }
  }
}

Suite *tests_for_s21_inverse_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_inverse_matrix_tests");
  tc = tcase_create("s21_inverse_matrix_tc");
  tcase_add_test(tc, s21_inverse_matrix_0);
  tcase_add_test(tc, s21_inverse_matrix_1);
  tcase_add_test(tc, s21_inverse_matrix_2);
  tcase_add_test(tc, s21_inverse_matrix_3);
  tcase_add_test(tc, s21_inverse_matrix_4);

  suite_add_tcase(s, tc);

  return s;
}