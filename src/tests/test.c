#include "test.h"

int main(void) {
  Suite *suites[] = {
      tests_for_s21_create_matrix(),    tests_for_s21_remove_matrix(),
      tests_for_s21_eq_matrix(),        tests_for_s21_sum_matrix(),
      tests_for_s21_sub_matrix(),       tests_for_s21_mult_number(),
      tests_for_s21_mult_matrix(),      tests_for_s21_transpose(),
      tests_for_s21_calc_complements(), tests_for_s21_determinant(),
      tests_for_s21_inverse_matrix(),   NULL};

  int total_failed = 0;

  for (int i = 0; suites[i] != NULL; i++) {
    SRunner *runner = srunner_create(suites[i]);

    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);

    int number_failed = srunner_ntests_failed(runner);
    total_failed += number_failed;

    srunner_free(runner);
  }

  return (total_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}