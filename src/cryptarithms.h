#ifndef CRYPTARITHMS_H
#define CRYPTARITHMS_H

#include <stdbool.h>
#include <stdlib.h>

enum error_t{
  ERROR_SUCCESS = EXIT_SUCCESS,,
};

/**
 * @brief Finds the solution of a given cryptarithm
 * @details For each of the permutations without repetition, 
	try each of the possible solutions to the given cryptarithm, 
	then print the solutions and their respective solution counters.
 * @param words
 * @return 
 */
enum error_t solve_cryptarithm(const char** words);

/**
 * @brief Counts unique letters and adds them to an array
 * @details Counts the amount of unique letters there is in the given
 * cryptarithm and adds each letter in a array
 * @param words
 * @param letters
 * @return amount of unique letters in the cryptarithm
 */
int count_unique_characters(const char** words, char* letters);

/**
 * @brief Checks if a letter is unique
 * @details Checks if a letter in not repeated in the letters array
 * @param amount_unique_chars
 * @param letter
 * @param letters
 * @return false if the letter is repeated, true if the letter is not found in letters array
 */
bool letter_is_unique(const unsigned int amount_unique_chars, char letter, char* letters);

/**
 * @brief Checks if the cryptarithm is valid
 * @details Checks if there is no more than 10 different letters in the cryptarithm
 * @param amount_unique_chars
 * @returns true if @a amount_unique_chars is no more than 10, else returns false
 */
bool words_is_valid(const unsigned int amount_unique_chars);

/**
 * @brief Calculates a permutation using the mathematic formula
 * @param total_amount
 * @param used_amount
 * @return The result of the permutation
 */
int permutation(const unsigned int total_amount, const unsigned int used_amount);

/**
 * @brief Calculates the factorial of a given number
 * @param n 
 * @return The result of the factorial
 */
int factorial(int n);

/**
 * @brief Finds a possible permutation with no repetition of the values
 * @param amount_unique_chars
 * @param digit_values
 * @return
 */
enum error_t find_digits_values(const unsigned int amount_unique_chars, int* digit_values);

/**
 * @brief
 * @param digit_values
 * @param index
 * @return
 */
enum error_t carry(int* digit_values, unsigned int index);

/**
 * @brief
 * @param amount_words
 * @param values
 * @param digit_values
 * @param letters
 * @param words
 * @return
 */
enum error_t convert_digits_to_value(const unsigned int amount_words, int* values, const int* digit_values, 
const char* letters, char** words);

/**
 * @brief Finds the position of a given char in a array
 * @details Traverses an array to check that the given character is not found in it
 * @param letters
 * @return The index of the array in which the character was found.
 * @return -1 if it didn't find that character in the array
 */
int get_char_position(char* letters);

/**
 * @brief Verifies that the sum results in the expected output
 * @details Perform the respective sum of all values to verify that the result 
 * is the output of the cryptarithm.
 * @param values
 * @param amount_words
 * @return true if the sum of the values is equal to the output, false if not. 
 */
bool values_are_valid(int* values, const unsigned int amount_words);

/**
 * @brief Finds the length of the biggest word in the matrix
 * @param words
 * @param amount_words
 * @return the length of the biggest word in the matrix
 */
int get_max_word_length(const char** words, const unsigned int amount_words);

/**
 * @brief Prints the solution of the Cryptarithm
 * @details Print one of the solutionsn, all of addends and the result (output)
 * @param values
 * @param amount_words
 * @param max_word_length
 */
enum error_t print_solution(const int* values, const unsigned int amount_words, const int max_word_length);


#endif
