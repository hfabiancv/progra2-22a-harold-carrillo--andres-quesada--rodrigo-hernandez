// Copyright 2022 Harold Carrillo Valverde <HAROLD.CARRILLO@ucr.ac.cr>
// Modified example of Dynamic Growing Array
// from Jeisson Hidalgo Cespedes.
#ifndef MATRIX_H
#define MATRIX_H

#include <stdint.h>

/**
 * @brief This structure is for using a dynamically growing 2D array
 */
struct matrix {
  /// Amount of elements
  uint64_t count;
  /// Capacity or size of elements array
  uint64_t capacity;
  /// 2D Matrix that constains all of the elements
  char** elements;
};

typedef struct matrix matrix_t;

/**
 * @brief Initialize the struct matrix
 * @details Dynamically allocates elements array in memory and assigns count as 0 and capacity as
 * INITIAL_CAPACITY
 * @param matrix Structure of struct matrix. Contains a count, capacity, and a 2D array of chars
 * @return @c EXIT_SUCCESS if it initializes the struct correctly
 * @return @c EXIT_FAILURE if it fails while doing the initialization process
 */
int matrix_init(struct matrix* matrix);

/**
 * @brief Un-initialize the struct matrix
 * @details Destroys elements matrix, and set count and capacity as 0
 * @param matrix Structure of struct matrix.
 * @return @c EXIT_SUCCESS if it un-initializes the struct correctly
 * @return @c EXIT_FAILURE if it fails while doing the un-initialization process
 */
int matrix_uninit(struct matrix* matrix);
/**
 * @brief Appends a new element in struct matrix elements
 * @details Adds a new row to the matrix. If it doesnt have enough capacity it will call @a increase_capacity
 * to create a new matrix with an increased size
 * @param matrix Structure of struct matrix
 * @param element The new element to be added
 * @return @c EXIT_SUCCESS if it adds the new element 
 * @return @c EXIT_FAILURE if it fails while adding the new element
 */
int matrix_append(struct matrix* matrix, char* element);

#endif  // MATRIX_H
