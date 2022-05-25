// Copyright 2022 Harold Carrillo & Rodrigo Hernandez & Andres Quesada

#ifndef CRYPTARITHMS_H
#define CRYPTARITHMS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include <inttypes.h>

enum error_t{
  ERROR_SUCCESS = EXIT_SUCCESS,
  ERROR_EXCEEDED_UNIQUE_CHARS,
  ERROR_NOT_FOUND,
  ERROR_PRINT_UNSUCCESSFUL,
  ERROR_INVALID_DIGITS,
  ERROR_INVALID_ARRAY,
};

/**
 * @brief Finds the solution of a given cryptarithm
 * @details For each of the permutations without repetition, 
	try each of the possible solutions to the given cryptarithm, 
	then print the solutions and their respective solution counters.
 * @param words
 * @return 
 */
enum error_t solve_cryptarithm(char** words, uint64_t word_coount);

/**
 * @brief Counts unique letters and adds them to an array
 * @details Counts the amount of unique letters there is in the given
 * cryptarithm and adds each letter in a array
 * @param words
 * @param letters
 * @return amount of unique letters in the cryptarithm
 */
int count_unique_letters(char** words, char* letters, uint64_t word_count);

/**
 * @brief Checks if a letter is unique
 * @details Checks if a letter in not repeated in the letters array
 * @param amount_unique_letters
 * @param letter
 * @param letters
 * @return false if the letter is repeated, true if the letter is not found in letters array
 */
bool is_letter_unique(const int amount_unique_letters, const char letter,
const char* letters);

/**
 * @brief Checks if the cryptarithm is valid
 * @details Checks if there is no more than 10 different letters in the cryptarithm
 * @param amount_unique_letters
 * @returns true if @a amount_unique_letters is no more than 10, else returns false
 */
bool words_is_valid(const int amount_unique_letters);

/**
 * @brief Calculates a permutation using the mathematic formula
 * @param total_amount
 * @param used_amount
 * @return The result of the permutation
 */
uint64_t permutation(const uint64_t total_amount, const uint64_t used_amount);

/**
 * @brief Calculates the factorial of a given number
 * @param n 
 * @return The result of the factorial
 */
uint64_t factorial(uint64_t number);

/**
 * @brief Finds a possible permutation with no repetition of the values
 * @param amount_unique_letters
 * @param digit_values
 * @return
 */
enum error_t find_digits_values(const uint64_t amount_unique_letters,
int* digit_values);

/**
 * @brief
 * @param digit_values
 * @param index
 * @return
 */
enum error_t carry(int* digit_values, uint64_t index);

/**
 * @brief
 * @param amount_words
 * @param values
 * @param digit_values
 * @param letters
 * @param words
 * @return
 */
enum error_t convert_digits_to_value(const uint64_t amount_words,
int* values, const int* digit_values, char* letters, char** words);

/**
 * @brief Finds the position of a given char in a array
 * @details Traverses an array to check that the given character is not found in it
 * @param letters
 * @return The index of the array in which the character was found.
 * @return -1 if it didn't find that character in the array
 */
uint64_t get_char_position(char* letters, char letter);

/**
 * @brief Verifies that the sum results in the expected output
 * @details Perform the respective sum of all values to verify that the result 
 * is the output of the cryptarithm.
 * @param values
 * @param amount_words
 * @return true if the sum of the values is equal to the output, false if not. 
 */
bool sum_is_valid(int* values, const uint64_t amount_words);

/**
 * @brief Finds the length of the biggest word in the matrix
 * @param words
 * @param amount_words
 * @return the length of the biggest word in the matrix
 */
uint64_t get_max_word_length(char** words, const uint64_t amount_words);

/**
 * @brief Prints the solution of the Cryptarithm
 * @details Print one of the solutionsn, all of addends and the result (output)
 * @param values
 * @param amount_words
 * @param max_word_length
 */
enum error_t print_solution(const int* values, const uint64_t amount_words,
const uint64_t max_word_length);


void initialize_as_zero(int* array, uint64_t array_size);


#endif