#ifndef CRYPTARITHMS_H
#define CRYPTARITHMS_H
#include <stdbool.h>

/**
 * @brief
 * @param
 * @return 
 */
int solve_Cryptarithm(void);

/**
 * @brief
 * @param
 * @return
 */
int amount_of_unique_characters(void);

/**
 * @brief
 * @param
 * @return
 */
bool letter_is_unique(int, char, char[]);

/**
 * @brief
 * @param
 * @return
 */
bool words_is_valid(void);

/**
 * @brief
 * @param n 
 * @return The result of the permutation
 */
int int permutation(int total_amount, unsigned int used_amount);

/**
 * @brief
 * @param
 * @return The result of the factorial
 */
int factorial(int n);

/**
 * @brief
 * @param Amount of unique chars
 * @return
 */
void find_Digits_Values(int);

/**
 * @brief
 * @param int array Values
 * @return
 */
void carry(int []);

/**
 * @brief
 * @param
 * @return
 */
void convert_Digits_To_Value(void);

/**
 * @brief
 * @param
 * @return The position of the char
 */
int get_char_position(char []);

/**
 * @brief
 * @param int array Values
 * @param Amount of words
 * @return
 */
bool values_are_valid(int [], int);

/**
 * @brief
 * @param char array words
 * @param amount of words
 * @return
 */
int get_Max_Num_Size(char [], int);

/**
 * @brief Prints the solution found
 * @param int array Values
 * @param Amount of words
 */
void print_Solution(int [], int)

#endif