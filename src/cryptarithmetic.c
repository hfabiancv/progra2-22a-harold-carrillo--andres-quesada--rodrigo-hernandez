// Copyright 2022 Harold Carrillo Valverde <HAROLD.CARRILLO@ucr.ac.cr>

#include "cryptarithms.h"
#include "matrix.h"

/**
 * @brief Reads values for the struct matrix
 * @details Reads all of the words to be append in the struct matrix
 * @returns @c ERROR_SUCCESS if it correctly reads all of the values
 * @returns @c ERROR_READ_VALUES if it fails while reading the values
 */
enum error_t read_values(struct matrix* const values);

/**
 * @brief Starts the execution of the cryptarithmetic program
 * @return an error code, ERROR_SUCCESS on sucess
 */
int main() {
  int error = ERROR_SUCCESS;
  struct matrix matrix;
  error = matrix_init(&matrix);
  if (error == EXIT_SUCCESS) {
    /// Read a cryptarithm given by the user
    error = read_values(&matrix);
    if (error == ERROR_SUCCESS) {
      /// Solve the cryptarithm previously read
      error = solve_cryptarithm(matrix.elements, matrix.count);

    } else if (error == ERROR_READ_VALUES) {
      fprintf(stderr, "cryptarithmetic: invalid read data\n");
    } else {
      fprintf(stderr, "cryptarithmetic: invalid array\n");
    }
  }
  error = matrix_uninit(&matrix);
  return error;
}

enum error_t read_values(struct matrix* values) {
  const int array_size = 20;
  char* value = (char*) calloc(array_size, sizeof(char));
  enum error_t error = ERROR_SUCCESS;

  if (value) {
    if (scanf(" %19s ", value) == 1) {
      matrix_append(values, value);
    } else {
      error = ERROR_READ_VALUES;
    }
    if (error == ERROR_SUCCESS) {
      /// Read all of the addends in the cryptarithm
      while (scanf("+ %19s ", value) == 1) {
        matrix_append(values, value);
      }
      /// Read the output (result) of the cryptarithm
      if (scanf("= %19s", value) == 1) {
        matrix_append(values, value);
      } else {
        error = ERROR_READ_VALUES;
      }
    }
    free(value);
  } else {
    error = ERROR_INVALID_ARRAY;
  }
  return error;
}
