#pragma once

#include <check.h>
#include <stdlib.h>

#include "../s21_matrix.h"

#define S21_EPSILON 0.0000001

Suite *tests_for_s21_create_matrix();
Suite *tests_for_s21_remove_matrix();
Suite *tests_for_s21_eq_matrix();
Suite *tests_for_s21_sum_matrix();
Suite *tests_for_s21_sub_matrix();
Suite *tests_for_s21_mult_number();
Suite *tests_for_s21_mult_matrix();
Suite *tests_for_s21_transpose();
Suite *tests_for_s21_calc_complements();
Suite *tests_for_s21_determinant();
Suite *tests_for_s21_inverse_matrix();

void check_incorrect_create(int code);
void check_correct_create(int code);

void check_incorrect_eq(int code);
void check_correct_eq(int code);

void check_result_sum(matrix_t *A, matrix_t *B, matrix_t *result);
void check_incorrect_matrix_sum(int code);
void check_incorrect_calc_sum(int code);
void check_correct_sum(int code);

void check_result_sub(matrix_t *A, matrix_t *B, matrix_t *result);
void check_incorrect_matrix_sub(int code);
void check_incorrect_calc_sub(int code);
void check_correct_sub(int code);

void check_result_mult_num(matrix_t *A, double num, matrix_t *result);
void check_incorrect_matrix_mult_num(int code);
void check_incorrect_calc_mult_num(int code);
void check_correct_mult_num(int code);

void check_result_mult(matrix_t *A, matrix_t *B, matrix_t *result,
                       matrix_t *check);
void check_incorrect_matrix_mult(int code);
void check_incorrect_calc_mult(int code);
void check_correct_mult(int code);

void check_incorrect_transpose(int code);
void check_correct_transpose(int code);

void check_correct_determinant(int code);
void check_incorrect_determinant(int code);
void check_incorrect_calc_determinant(int code);

void check_correct_calc_complements(int code);
void check_incorrect_calc_complements(int code);
void check_incorrect_calculation_calc_complements(int code);
void check_calc_complements_got_expected(matrix_t *got_matrix,
                                         matrix_t *expected_matrix);

void check_correct_inverse_matrix(int code);
void check_incorrect_inverse_matrix(int code);
void check_incorrect_calc_inverse_matrix(int code);
void check_inversed_matrix_got_expected(matrix_t *got_matrix,
                                        matrix_t *expected_matrix);

// Suite *s21_add_test(void) {
//   Suite *s = suite_create("s21_addition");
//   TCase *tc = tcase_create("Core");

//   tcase_add_test(tc, s21_addition_1);
//   tcase_add_test(tc, s21_addition_2);
//   tcase_add_test(tc, s21_addition_3);
//   tcase_add_test(tc, s21_addition_4);

//   suite_add_tcase(s, tc);

//   return s;
// }