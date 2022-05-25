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
 * @param
 * @return 
 */
int solve_Cryptarithm(void);

/**
 * @brief Counts unique letters and adds them to an array
 * @details Counts the amount of unique letters there is in the given
	cryptarithm and adds each letter in a array
 * @return amount of unique letters in the cryptarithm
 */
int amount_of_unique_characters(void);

/**
 * @brief Checks if a letter is unique
 * @details Checks if a letter in not repeated in the letters array
 * @param
 * @return false if the letter is repeated, true if the letter is not found in letters array
 */
bool letter_is_unique(int, char, char[]);

/**
 * @brief Checks if the cryptarithm is valid
 * @details Checks if there is no more than 10 different letters in the cryptarithm
 * @param The amount of unique characters in the current input
 * @returns true if @a amount_unique_chars is no more than 10, else returns false
 */
bool words_is_valid(int);

/**
 * @brief Calculates a permutation using the mathematic formula
 * @param The total amount of objetcs
 * @param The amount of objects selected
 * @return The result of the permutation
 */
int permutation(int total_amount, unsigned int used_amount);

/**
 * @brief Calculates the factorial of a given number
 * @param The number to be used
 * @return The result of the factorial
 */
int factorial(int n);

/**
 * @brief Finds a possible permutation with no repetition of the values
 * @param Amount of unique chars
 * @return
 */
void find_Digits_Values(int);

/**
 * @brief
 * @param digit_values
 * @param index
 * @return
 */
void carry(int []);

/**
 * @brief
 * @param amount_words
 * @param values
 * @param digit_values
 * @param letters
 * @param words
 * @return
 */
void convert_Digits_To_Value(void);

/**
 * @brief Finds the position of a given char in a array
 * @details Traverses an array to check that the given character is not found in it
 * @param
 * @return The index of the array in which the character was found.
 * @return -1 if it didn't find that character in the array
 */
int get_char_position(char []);

/**
 * @brief Verifies that the sum results in the expected output
 * @details Perform the respective sum of all values to verify that the result 
	is the output of the cryptarithm.
 * @param int array Values
 * @param Amount of words
 * @return true if the sum of the values is equal to the output, false if not. 
 */
bool values_are_valid(int [], int);

/**
 * @brief Finds the size of the biggest number in the array
 * @param char array words
 * @param amount of words
 * @return the size of the biggest number in the array
 */
int get_Max_Num_Size(char [], int);

/**
 * @brief Prints the solution of the Cryptarithm
 * @details Print one of the solutions
 * @param int array Values
 * @param Amount of words
 */
void print_Solution(int [], int);
void print_Solution(int [], int);

#endif
