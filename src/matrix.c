// Copyright 2022 Harold Carrillo Valverde <HAROLD.CARRILLO@ucr.ac.cr>
// Modified example of Dynamic Growing Array
// from Jeisson Hidalgo Cespedes.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"

/*
Matrix File

  Procedure matrix Init
    Change matrix->count as 0
    Change matrix->capacity as INITIAL_CAPACITY
    Change matrix->elements as Create Matrix
    If matrix->elements == NULL
      Change matrix capacity as 0

  Procedure matrix Uninit
    Destroy Matrix(matrix->elements, matrix->capacity)
    Change matrix->count as 0
    Change matrix->capacity as 0

  Procedure Create Matrix
    Create matrix as an matrix of rows
    If matrix then
      For row = 0; row < rows; row++
        Create matrix[row] as an matrix of cols
        If matrix[row] == NULL
          Destroy matrix(matrix, rows)
          return NULL
    return matrix

  Procedure Destroy Matrix
    If matrix != NULL then
      For row = 0; row < rows; row++
        free(matrix[row])
      free(matrix) 
      
  Procedure matrix Append
    If matrix->count == matrix->capacity then
      Increase Capacity(matrix)
    Create element length as strlen(element)
    For index= 0; index < element_length; index++
      Change matrix->elements[matrix->count][index] as element[index]
    Change matrix->count as matrix->count + 1

  Procedure increase capacity
    Create new capacity as INCREASE_FACTOR * matrix->capacity
    Create new elements as Create Matrix
    If new elements != NULL then
      For row = 0; row < matrix->count; row++
        Create element length as strlen(matrix->elements[row])
        For column = 0; column < element length; column++
          Change new elements[row][column] as matrix->elements[row][column]
      Destroy Matrix
      matrix->elements = new elements
      matrix->capacity = new capacity
*/

/// The initial capacity of the elements matrix
#define INITIAL_CAPACITY 10;
/// The increase factor used while increasing the capacity of the matrix
#define INCREASE_FACTOR 10;

/**
 * @brief Increase the capacity of the matrix
 * @details Creates a new matrix with an increased capacity that will 
 * contain all of the data in the actual elements matrix. 
 * @return @c EXIT_SUCCESS if it correctly creates a new matrix 
 * with an increased capacity
 * @return @c EXIT_FAILURE if it fails creating the new matrix
 */
int increase_capacity(struct matrix* matrix);

/**
 * @brief Creates a matrix allocated in dynamic memory
 * @param rows Amount of rows of the matrix
 * @param cols Amount of cols of the matrix
 * @param element_size Size of the element, i.e, datatype contained 
 * in the 2D matrix
 * @returns A dynamic allocated matrix
 */
void** create_matrix(const uint64_t rows, const uint64_t cols,
const uint64_t element_size);
/**
 * @brief Destroy a matrix allocated in dynamic memory
 * @see create_matrix
 * @param matrix An array of vectors.
 * @param rows amount of rows of the matrix
 */
void destroy_matrix(void** matrix, const uint64_t rows);


int matrix_init(struct matrix* matrix) {
  assert(matrix);
  int error = EXIT_SUCCESS;
  const int cols_capacity = 20;
  matrix->count = 0;
  matrix->capacity = INITIAL_CAPACITY;
  matrix->elements = (char**) create_matrix(matrix->capacity, cols_capacity,
  sizeof(char*));
  if (matrix->elements == NULL) {
    matrix->capacity = 0;
    error = EXIT_FAILURE;
  }
  return error;
}

// Taken from create_matrix example of
// Jeisson Hidalgo Cespedes - 2022
void** create_matrix(const uint64_t rows, const uint64_t cols, const
uint64_t element_size) {
  void** matrix = calloc(rows, sizeof(void*));
  if (matrix) {
    for (uint64_t row = 0; row < rows; row++) {
      if ((matrix[row] = calloc(cols, element_size)) == NULL) {
        destroy_matrix(matrix, rows);
        return NULL;
      }
    }
  }
  return matrix;
}

void destroy_matrix(void** matrix, const uint64_t rows) {
  if (matrix) {
    for (uint64_t row = 0; row < rows; row++) {
      free(matrix[row]);
    }
    free(matrix);
  }
}

int matrix_uninit(struct matrix* matrix) {
  assert(matrix);
  if (matrix->elements) {
    destroy_matrix((void**)matrix->elements, matrix->capacity);
    matrix->count = matrix->capacity = 0;
    return EXIT_SUCCESS;
  }
  return EXIT_FAILURE;
}

int matrix_append(struct matrix* matrix, char* element) {
  assert(matrix);
  int error = EXIT_SUCCESS;
  if (matrix->count == matrix->capacity) {
    error = increase_capacity(matrix);
  }
  if (error == EXIT_SUCCESS) {
    uint64_t element_length = strlen(element);
    for (uint64_t index = 0; index < element_length; index++) {
      matrix->elements[matrix->count][index] = element[index];
    }
    matrix->count++;
  }
  return error;
}

int increase_capacity(struct matrix* matrix) {
  assert(matrix);
  int error = EXIT_SUCCESS;
  uint64_t new_capacity = INCREASE_FACTOR;
  const int cols_capacity = 20;
  new_capacity*= matrix->capacity;
  char** new_elements = (char**)create_matrix(new_capacity, cols_capacity,
  sizeof(char*));

  if (new_elements) {
    for (uint64_t row = 0; row < matrix->count; row++) {
      uint64_t element_length = strlen(matrix->elements[row]);
      for (uint64_t column = 0; column < element_length; column++) {
        new_elements[row][column] = matrix->elements[row][column];
      }
    }
    destroy_matrix((void**)matrix->elements, matrix->capacity);
    matrix->elements = new_elements;
    matrix->capacity = new_capacity;
  } else {
    error = EXIT_FAILURE;
  }
  return error;
}
