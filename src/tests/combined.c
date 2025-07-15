#include "test.h"

/*

Matrix A:
    -3.45 , -2.22 , -1.31 , -4.42 , -5.53
    7.12  ,  3.33 ,  4.41 ,  5.52 ,  6.63
    -1.67 , -4.44 , -5.51 , -6.62 , -7.73
    4.23  ,  5.55 ,  6.61 ,  7.72 ,  8.83
    -8.89 , -6.66 , -7.71 , -8.82 , -9.93


Matrix B:
    -6.9   , 2.24   , -3.34  , 8.46   , -1.78
    -4.44  , 6.66   , 3.88   , 2.1    , -13.32
    2.62   , 8.82   , -11.02 , 13.22  , -15.42
    -8.84  , 7.04   , -13.24 , 15.44  , -17.64
    5.06   , 13.26  , -15.46 , 17.66  , -19.86

Matrix expected:
    14.2026   , -352.288  , -453.3801  , -641.6242  , -486.4965
    -403.6176 , 424.977   , -981.0156  , 398.7174   , -1329.5648
    452.1854  , -353.0575 , 1189.2194  , -370.4142  , 1633.6014
    -648.4898 , 633.348   , -1351.4522 , 613.5508   , -1931.5682
    571.2474  , -888.5208 , 1493.7621  , -1076.5946 , 1999.9754

*/
START_TEST(combined_0) {
  matrix_t A;
  matrix_t B;
  matrix_t sum;
  matrix_t sub;
  matrix_t scalar_mul;
  matrix_t matrix_mul;
  matrix_t transpose;
  matrix_t transpose_scaled_down;
  matrix_t expected;
  double determinant;

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);
  s21_create_matrix(5, 5, &expected);

  A.matrix[0][0] = -3.45;
  A.matrix[0][1] = -2.22;
  A.matrix[0][2] = -1.31;
  A.matrix[0][3] = -4.42;
  A.matrix[0][4] = -5.53;
  A.matrix[1][0] = 7.12;
  A.matrix[1][1] = 3.33;
  A.matrix[1][2] = 4.41;
  A.matrix[1][3] = 5.52;
  A.matrix[1][4] = 6.63;
  A.matrix[2][0] = -1.67;
  A.matrix[2][1] = -4.44;
  A.matrix[2][2] = -5.51;
  A.matrix[2][3] = -6.62;
  A.matrix[2][4] = -7.73;
  A.matrix[3][0] = 4.23;
  A.matrix[3][1] = 5.55;
  A.matrix[3][2] = 6.61;
  A.matrix[3][3] = 7.72;
  A.matrix[3][4] = 8.83;
  A.matrix[4][0] = -8.89;
  A.matrix[4][1] = -6.66;
  A.matrix[4][2] = -7.71;
  A.matrix[4][3] = -8.82;
  A.matrix[4][4] = -9.93;

  B.matrix[0][0] = -6.9;
  B.matrix[0][1] = 2.24;
  B.matrix[0][2] = -3.34;
  B.matrix[0][3] = 8.46;
  B.matrix[0][4] = -1.78;
  B.matrix[1][0] = -4.44;
  B.matrix[1][1] = 6.66;
  B.matrix[1][2] = 3.88;
  B.matrix[1][3] = 2.1;
  B.matrix[1][4] = -13.32;
  B.matrix[2][0] = 2.62;
  B.matrix[2][1] = 8.82;
  B.matrix[2][2] = -11.02;
  B.matrix[2][3] = 13.22;
  B.matrix[2][4] = -15.42;
  B.matrix[3][0] = -8.84;
  B.matrix[3][1] = 7.04;
  B.matrix[3][2] = -13.24;
  B.matrix[3][3] = 15.44;
  B.matrix[3][4] = -17.64;
  B.matrix[4][0] = 5.06;
  B.matrix[4][1] = 13.26;
  B.matrix[4][2] = -15.46;
  B.matrix[4][3] = 17.66;
  B.matrix[4][4] = -19.86;

  expected.matrix[0][0] = 14.2026;
  expected.matrix[0][1] = -352.288;
  expected.matrix[0][2] = -453.3801;
  expected.matrix[0][3] = -641.6242;
  expected.matrix[0][4] = -486.4965;
  expected.matrix[1][0] = -403.6176;
  expected.matrix[1][1] = 424.977;
  expected.matrix[1][2] = -981.0156;
  expected.matrix[1][3] = 398.7174;
  expected.matrix[1][4] = -1329.5648;
  expected.matrix[2][0] = 452.1854;
  expected.matrix[2][1] = -353.0575;
  expected.matrix[2][2] = 1189.2194;
  expected.matrix[2][3] = -370.4142;
  expected.matrix[2][4] = 1633.6014;
  expected.matrix[3][0] = -648.4898;
  expected.matrix[3][1] = 633.348;
  expected.matrix[3][2] = -1351.4522;
  expected.matrix[3][3] = 613.5508;
  expected.matrix[3][4] = -1931.5682;
  expected.matrix[4][0] = 571.2474;
  expected.matrix[4][1] = -888.5208;
  expected.matrix[4][2] = 1493.7621;
  expected.matrix[4][3] = -1076.5946;
  expected.matrix[4][4] = 1999.9754;

  s21_sum_matrix(&A, &B, &sum);
  s21_mult_number(&sum, 3, &scalar_mul);
  s21_sub_matrix(&scalar_mul, &B, &sub);
  s21_mult_matrix(&sub, &B, &matrix_mul);
  check_got_expected(s21_transpose(&matrix_mul, &transpose), &transpose,
                     &expected);

  s21_mult_number(&transpose, 0.01, &transpose_scaled_down);
  s21_determinant(&transpose_scaled_down, &determinant);

  ck_assert_double_eq_tol(determinant, -28.018105, 1e-06);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&sum);
  s21_remove_matrix(&sub);
  s21_remove_matrix(&scalar_mul);
  s21_remove_matrix(&matrix_mul);
  s21_remove_matrix(&transpose);
  s21_remove_matrix(&transpose_scaled_down);
  s21_remove_matrix(&expected);
}

Suite *tests_combined(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("combined_tests");
  tc = tcase_create("combined_tc");
  tcase_add_test(tc, combined_0);

  suite_add_tcase(s, tc);

  return s;
}