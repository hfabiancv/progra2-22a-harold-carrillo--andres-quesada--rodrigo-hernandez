// Copyright 2022 Harold Carrillo & Rodrigo Hernandez & Andres Quesada

#ifndef CRYPTARITHMS_H
#define CRYPTARITHMS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

/**
 * @mainpage
 * Library for solving verbal artihmetic or "cryptarithms".
 * 1. @a cryptarithms.h
 * 2. @a matrix.h
 *
 * Sample:
 * @include {doc} cryptarithmetic.c
 * 
 * 
 */

enum error_t{
  ERROR_SUCCESS = EXIT_SUCCESS,
  ERROR_EXCEEDED_UNIQUE_CHARS,
  ERROR_NOT_FOUND,
  ERROR_PRINT_UNSUCCESSFUL,
  ERROR_INVALID_DIGITS,
  ERROR_INVALID_ARRAY,
  ERROR_READ_VALUES,
  ERROR_CANNOT_OPEN_FILE,
};

/**
 * @brief Finds the solution of a given cryptarithm
 * @details For each of the permutations without repetition, 
	try each of the possible solutions to the given cryptarithm, 
	then print the solutions and their respective solution counters.
 * @see convert_digits_to_value 
 * @param words Array that contains every string or word in the cryptarithm
 * @param amount_words The amount of strings or words.
 * @return @a ERROR SUCCESS if theres no error in the execution
 * @return @a ERROR_EXCEEDED_UNIQUE_CHARS if theres more
 * than 10 different characters in the cryptarithm
 * @return @a ERROR_INVALID_ARRAY if the array is not correctly
 * initialized, is empty, or is invalid.
 */
enum error_t solve_cryptarithm(char** words, uint64_t amount_words);

/**
 * @brief Counts unique letters and adds them to an array
 * @details Counts the amount of unique letters there is in the given
 * cryptarithm and adds each letter in a array.
 * @code{.c}
 * char** words = {{"AB"},{"BC"},{"ABC"}};
 * uint64_t amount_words = 3;
 * count_unique_letters(words, amount_words) == 3;
 * @endcode
 * @see @a solve_cryptarithm, convert_digits_to_value
 * @return amount of unique letters in the cryptarithm
 */
int count_unique_letters(char** words, char* letters, uint64_t amount_words);

/**
 * @brief Checks if a letter is unique
 * @details Checks if a letter in not repeated in the letters array
 * @example is_letter_unique(4, 'Q', "HELLO")== true, 
 * is_letter_unique(4, 'O', "HELLO")== false
 * @see convert_digits_to_value, get_char_position
 * @param amount_unique_letters Quantity of different
 * (unique) letters(characters).
 * @return false if the letter is repeated, true if
 * the letter is not found in letters array
 */
bool is_letter_unique(const int amount_unique_letters
  , const char letter, const char* letters);

/**
 * @brief Checks if the cryptarithm is valid
 * @details Checks if there is no more than 10 different letters in the cryptarithm
 * @code{.c}
 * char* word = "CODING";
 * word_length = strlen(word);//str_len == 6.
 * word_is_valid(word_length) == true;//6<10.
 * @endcode
 * @see is_letter_unique
 * @returns true if @a amount_unique_letters is no more
 * than 10, else returns false
 */
bool words_is_valid(const int amount_unique_letters);

/**
 * 
 * @brief Calculates a permutation using the mathematic formula.
 * @details This function uses the following formula:
 * \f$\frac{n!}{(n-r)!}\f$
 * @example permutation(7,4) == 840
 * @param total_amount-The amount total amount of objects
 * (things, numbers, letters, etc.) we can use.
 * @param used_amount-The amount of objects we are willing to use.
 * @return The result of the permutation
 */
uint64_t permutation(const uint64_t total_amount, const uint64_t used_amount);

/**
 * @brief Calculates the factorial of a given number
 * @example factorial(7) == 5040.
 * @param number number to which its factorial is to be calculated
 * @return The result of the factorial
 */
uint64_t factorial(uint64_t number);

/**
 * @brief Finds a possible combination with the digits.
 * @details Finds a possible combination with the digits following 
 * the same logic as decimal counting, with the exception that 
 * it must not have repeated values
 * @example 
 * amount_unique_letters == 4;
 * letters_values == {0,0,0,0}
 * find_digits_values(amount_unique_letters, letters_values)
 * letters_values == {0,1,2,3}
 * find_digits_values(amount_unique_letters, letters_values)
 * letters_values == {0,1,2,4}
 * find_digits_values(amount_unique_letters, letters_values)
 * letters_values == {0,1,2,5}
 * @see convert_digits_to_value
 * @returns @a ERROR_SUCCESS if there's digits, else @a ERROR_INVALID_DIGITS.
 */
enum error_t find_digits_values(const uint64_t amount_unique_letters
  , uint64_t* letter_values);

/**
 * @brief Takes an array with numbers separed in digits, unite 
 * the digits(of a vector) into a number and store it into another array.
 * @code{.c}
 * @endcode
 * @param amount_words Quantity of words stored in words.
 * @param word_values Array to store the word_values we get.
 * @param letter_values Array with given permutations of numbers between 0-9.
 * @param letters characters of a word.
 * @param words Array that contains every string or word in the cryptarithm.
 * @see solve_cryptarithm
 */
enum error_t convert_digits_to_value(const uint64_t amount_words
  , uint64_t* word_values, const uint64_t* letter_values, char* letters
  , char** words);

/**
 * @brief Finds the position of a given char in a array
 * @details Traverses an array to check that the given character 
 * is not found in it
 * @see convert_digits_to_value
 * @param letter-A certain character.
 * @return The index of the array in which the character was found.
 * @return -1 if it didn't find that character in the array
 */
uint64_t get_char_position(char* letters, const char letter);

/**
 * @brief Verifies that the sum results in the expected output
 * @details Perform the respective sum of all word_values to verify 
 * that the result a valid solution of the cryptarithm.
 * @see convert_digits_to_value
 * @return true if the sum of the word_values is equal to
 * the expected result, else false
 */
bool sum_is_valid(uint64_t* word_values, const uint64_t amount_words);

/**
 * @brief Finds the length of the biggest word in the matrix
 * @see convert_digits_to_value
 * @return the length of the biggest word in the matrix
 */
size_t get_max_word_length(char** words, const uint64_t amount_words);

/**
 * @brief Prints the solution of the Cryptarithm
 * @details Print one of the solutionsn, all of addends and the result (output)
 * @see convert_digits_to_value
 * @param max_word_length The length of the biggest word in the cryptarithm.
 * @return @c ERROR_PRINT_UNSUCCESSFUL if word_values is not valid or
 * is empty, so it can't print anything.
 * @return @c ERROR_SUCCESS if it prints correctly.
 */
enum error_t print_solution(const uint64_t* word_values
  , const uint64_t amount_words, const size_t max_word_length);

/**
 * @brief Fills an array with 0s.
 * @param array The array to be filled with zeros. Must be already initialize
 * @param array_size Size of @a array. Amount of elements
 */
void fill_array_zero(uint64_t* array, const uint64_t array_size);


#endif
