// Copyright 2022 Rodrigo Hernandez & Harold Carrillo
#include <stdio.h>
#include <stdlib.h>

#include "cryptarithms.h"
#include "matrix.h"

#define TEST_TRUE(cond) \
  if (!(cond)) { \
    fprintf(stderr, "FAILED %s\n", #cond); \
    error = EXIT_FAILURE; \
  }

int test_count_unique_letters(void);
int test_is_letter_unique(void);
int test_get_char_position(void);
int test_words_is_valid(void);
int test_permutation(void);
int test_permutation_middle(void);
int test_permutation_max(void);
int test_factorial_normal(void);
int test_factorial_zero(void);
int test_factorial_one(void);
int test_sum_is_valid(void);

int main(void) {
  int error = EXIT_SUCCESS;

  error = test_count_unique_letters();
  error = test_is_letter_unique();

  error = test_get_char_position();
  error = test_words_is_valid();

  error = test_permutation();
  error = test_permutation_middle();
  error = test_permutation_max();

  error = test_factorial_normal();
  error = test_factorial_one();
  error = test_factorial_zero();

  error = test_sum_is_valid();
  return error;
}

int test_count_unique_letters(void) {
  int error = EXIT_SUCCESS;
  struct matrix matrix;
  matrix_init(&matrix);
  char* element = (char*) calloc(6, sizeof(char));
  element = "ABCDE";
  if (element) {
    matrix_append(&matrix, element);
    if (matrix.elements) {
      char* letters = (char*) calloc(11, sizeof(char));
      if (letters) {
        TEST_TRUE(count_unique_letters(matrix.elements, letters, 5)  == 5)
        free(letters);
      }
    }
  }
  matrix_uninit(&matrix);
  return error;
}

int test_is_letter_unique(void) {
  int error = EXIT_SUCCESS;
  char word[4] = {'C', 'O', 'C', 'A'};
  TEST_TRUE(is_letter_unique(10, 'C', word)  == false)
  return error;
}

int test_get_char_position(void) {
  int error = EXIT_SUCCESS;
  char word[4] = {'S', 'E', 'N', 'D'};
  TEST_TRUE(get_char_position(word, 'R') == 0)
  return error;
}

int test_words_is_valid(void) {
  int error = EXIT_SUCCESS;
  TEST_TRUE(words_is_valid(8) == true)
  return error;
}

int test_permutation(void) {
  int error = EXIT_SUCCESS;
  TEST_TRUE(permutation(5, 2) == 20)
  return error;
}

int test_permutation_middle(void) {
  int error = EXIT_SUCCESS;
  TEST_TRUE(permutation(10, 5) == 30240)
  return error;
}

int test_permutation_max(void) {
  int error = EXIT_SUCCESS;
  TEST_TRUE(permutation(10, 10) == 3628800)
  return error;
}

int test_factorial_normal(void) {
  int error = EXIT_SUCCESS;
  TEST_TRUE(factorial(4) == 24)
  return error;
}

int test_factorial_zero(void) {
  int error = EXIT_SUCCESS;
  TEST_TRUE(factorial(0) == 1)
  return error;
}

int test_factorial_one(void) {
  int error = EXIT_SUCCESS;
  TEST_TRUE(factorial(1) == 1)
  return error;
}

int test_sum_is_valid(void) {
  int error = EXIT_SUCCESS;
  uint64_t* values = (uint64_t*) calloc(5, sizeof(uint64_t));
  for (int index = 1; index < 5; index++) {
    values[index-1] = index;
  }
  values[4] = 10;
  TEST_TRUE(sum_is_valid(values, 5) == true)
  free(values);
  return error;
}
