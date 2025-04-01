#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 1 || columns < 1) return 1;
  result->matrix = (double **)calloc(rows, sizeof(double *));
  if (result->matrix == NULL) return 1;
  result->rows = rows;
  result->columns = columns;
  for (int i = 0; i < rows; ++i) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    if (result->matrix[i] == NULL) {
      for (int j = 0; j < i; ++j) free(result->matrix[j]);
      free(result->matrix);
    }
  }

  return 0;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; ++i) free(A->matrix[i]);
    free(A->matrix);
  }
  A->rows = 0;
  A->columns = 0;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      if (round(A->matrix[i][j]) != round(B->matrix[i][j])) return FAILURE;
    }
  }
  return SUCCESS;
}