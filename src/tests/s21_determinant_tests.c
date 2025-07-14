#include "test.h"

START_TEST(s21_determinant_0) {
  matrix_t matrix1;
  double result;
  s21_create_matrix(2, 2, &matrix1);
  s21_fill_matrix(&matrix1, 3, 3);
  check_correct_determinant(s21_determinant(&matrix1, &result));
  ck_assert_double_eq(result, -18);
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_determinant_1) {
  matrix_t matrix1;
  double result;
  s21_create_matrix(2, 7, &matrix1);
  s21_fill_matrix(&matrix1, 3, 3);
  check_incorrect_calc_determinant(s21_determinant(&matrix1, &result));
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_determinant_2) {
  matrix_t matrix1;
  double result;
  s21_create_matrix(2, 7, &matrix1);
  s21_fill_matrix(&matrix1, 3, 3);
  check_incorrect_determinant(s21_determinant(NULL, &result));
  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_determinant_4) {
  matrix_t matrix1;
  double result;
  s21_create_matrix(2, 2, &matrix1);
  s21_fill_matrix(&matrix1, 2.4, 1.451);
  check_correct_determinant(s21_determinant(&matrix1, &result));
  ck_assert_double_eq_tol(result, -4.2108, 1e06);

  s21_remove_matrix(&matrix1);
}
END_TEST

START_TEST(s21_determinant_5) {
  matrix_t mat_1 = {0};
  s21_create_matrix(5, 5, &mat_1);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      mat_1.matrix[i][j] = i + j;
    }
  }

  double mat_res = 5;

  int check = s21_determinant(&mat_1, &mat_res);
  ck_assert_int_eq(0, check);

  double mat_check = 0;
  ck_assert_double_eq(mat_check, mat_res);

  s21_remove_matrix(&mat_1);
}
END_TEST

START_TEST(s21_determinant_6) {
  matrix_t mat_1 = {0};
  s21_create_matrix(3, 3, &mat_1);
  mat_1.matrix[0][0] = 2;
  mat_1.matrix[0][1] = 5;
  mat_1.matrix[0][2] = 7;

  mat_1.matrix[1][0] = 6;
  mat_1.matrix[1][1] = 3;
  mat_1.matrix[1][2] = 4;

  mat_1.matrix[2][0] = 5;
  mat_1.matrix[2][1] = -2;
  mat_1.matrix[2][2] = -3;

  double mat_res = 5;

  int check = s21_determinant(&mat_1, &mat_res);
  ck_assert_int_eq(0, check);
  double mat_check = -1;

  // ck_assert_double_eq(mat_check, mat_res);
  ck_assert_double_eq_tol(mat_check, mat_res, 1e-12);

  s21_remove_matrix(&mat_1);
}
END_TEST

START_TEST(s21_determinant_7) {
  matrix_t mat_1 = {0};
  s21_create_matrix(3, 4, &mat_1);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      mat_1.matrix[i][j] = i + j;
    }
  }

  double mat_res = 5;

  int check = s21_determinant(&mat_1, &mat_res);
  ck_assert_int_eq(2, check);

  s21_remove_matrix(&mat_1);
}
END_TEST

START_TEST(s21_determinant_8) {
  double mat_res = 5;

  int check = s21_determinant(NULL, &mat_res);
  ck_assert_int_eq(1, check);
}
END_TEST

void check_correct_determinant(int code) {
  int expected = 0;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_determinant(int code) {
  int expected = 1;
  ck_assert_int_eq(code, expected);
}

void check_incorrect_calc_determinant(int code) {
  int expected = 2;
  ck_assert_int_eq(code, expected);
}

Suite *tests_for_s21_determinant(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_determinant_tests");
  tc = tcase_create("s21_determinant_tc");
  tcase_add_test(tc, s21_determinant_0);
  tcase_add_test(tc, s21_determinant_1);
  tcase_add_test(tc, s21_determinant_2);
  tcase_add_test(tc, s21_determinant_4);
  tcase_add_test(tc, s21_determinant_5);
  tcase_add_test(tc, s21_determinant_6);
  tcase_add_test(tc, s21_determinant_7);
  tcase_add_test(tc, s21_determinant_8);

  suite_add_tcase(s, tc);

  return s;
}