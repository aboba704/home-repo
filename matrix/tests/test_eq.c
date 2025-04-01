#include "test_matrix.h"

START_TEST(eq_1) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  int num = rand() % 100 + 1;
  matrix_t m1 = {0}, m2 = {0};
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m1.matrix[i][j] = num;
      m2.matrix[i][j] = num;
    }
  }
  int res = s21_eq_matrix(&m1, &m2);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_2) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  int num = rand() % 100 + 1;
  matrix_t m1 = {0}, m2 = {0};
  s21_create_matrix(rows, cols, &m1);
  s21_create_matrix(rows, cols, &m2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m1.matrix[i][j] = num;
      m2.matrix[i][j] = num + 1;
    }
  }
  int res = s21_eq_matrix(&m1, &m2);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

START_TEST(eq_3) {
  const int rows = rand() % 100 + 1;
  const int cols = rand() % 100 + 1;
  int num = rand() % 100 + 1;
  matrix_t m1 = {0}, m2 = {0};
  s21_create_matrix(rows, cols + 1, &m1);
  s21_create_matrix(rows, cols, &m2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      m1.matrix[i][j] = num;
      m2.matrix[i][j] = num;
    }
  }
  int res = s21_eq_matrix(&m1, &m2);
  ck_assert_int_eq(res, 0);
  s21_remove_matrix(&m1);
  s21_remove_matrix(&m2);
}
END_TEST

Suite *test_eq_matrix() {
  Suite *s = suite_create("\033[45m S21_EQ_MATRIX \033[0m");
  TCase *tc = tcase_create("case_eq_matrix");

  tcase_add_test(tc, eq_1);
  tcase_add_test(tc, eq_2);
  tcase_add_test(tc, eq_3);

  suite_add_tcase(s, tc);
  return s;
}
