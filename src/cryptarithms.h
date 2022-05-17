#ifndef CRYPTARITHMS_H
#define CRYPTARITHMS_H

/**
 * @brief
 * @param
 * @return 
 */
int Solve_Cryptarithm(void);

/**
 * @brief
 * @param
 * @return
 */
int Amount_of_unique_characters(void);

/**
 * @brief
 * @param
 * @return
 */
bool Letter_is_unique(int, char, char[]);

/**
 * @brief
 * @param
 * @return
 */
bool Words_is_valid(void);

/**
 * @brief
 * @param n 
 * @return The result of the permutation
 */
int Permutation(int n);

/**
 * @brief
 * @param
 * @return The result of the factorial
 */
int Factorial(int n);

/**
 * @brief
 * @param Amount of unique chars
 * @return
 */
void Find_Digits_Values(int);

/**
 * @brief
 * @param int array Values
 * @return
 */
void Carry(int []);

/**
 * @brief
 * @param
 * @return
 */
void Convert_Digits_To_Value(void);

/**
 * @brief
 * @param
 * @return The position of the char
 */
int Get_char_position(char []);

/**
 * @brief
 * @param int array Values
 * @param Amount of words
 * @return
 */
bool Values_are_valid(int [], int);

/**
 * @brief
 * @param char array words
 * @param amount of words
 * @return
 */
int Get_Max_Num_Size(char [], int);

/**
 * @brief Prints the solution found
 * @param int array Values
 * @param Amount of words
 */
void Print_Solution(int [], int)

#endif