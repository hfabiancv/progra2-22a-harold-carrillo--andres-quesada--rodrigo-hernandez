// Copyright 2022 Harold Carrillo & Rodrigo Hernandez & Andres Quesada

// Cryptarithms Library

#include <stdint.h>
#include <string.h>

#include "cryptarithms.h"

/**
 * @brief Finds all of the possible solutions of the cryptarithm
 * @param amount_unique_letters The amount of unique letters in the cryptarithm
 * @param letters Array that contains each of the unique letters in the cryptarithm
 * @param words Array that contains every string or word in the cryptarithm
 * @param amount_words The amount of strings or words.
 * @return @c ERROR_INVALID_DIGITS if @a letter_values array is not valid
 * @return @c ERROR_PRINT_UNSUCCESSFUL if word_values is not valid or is empty, so it can't print anything.
 * @return @c ERROR_SUCCESS if doesnt fail while looking for a possible solution
 */
enum error_t find_solutions(uint64_t amount_unique_letters, char* letters,
char** words, uint64_t* letter_values, uint64_t amount_words);

/**
 * @brief Checks if all of the letters word_values are unique
 * @param letter_values Array that contains all of the digits, or letter values
 * @param amount_unique_letters Amount of digits, (letter values) @a letter_values size
 * @return true if all digits (letters word_values) are different from each other
 * @return false if there is a repeated digit value
 */
bool digit_validator(uint64_t* letter_values, uint64_t amount_unique_letters);

/**
 * @brief Checks if the word_values of each word do not leading zeros
 * @param letter_values Array that contains the values of each unique letter.
 * @param amount_words The amount of strings or words.
 * @return true if the number doesnt have leading zeros
 * @return false if the number have leading zeros
 */ 
bool values_are_valid(char* letters, char** words, uint64_t* letter_values,
uint64_t amount_words);

/**
 * @brief Try one of the possible solutions of the cryptarithm
 * @param solutions The amount of solutions. Must be initialized as zero
 * @see find_solutions
 * @see try_solution
 */
enum error_t try_solution(char* letters, char** words,
uint64_t* letter_values, uint64_t* word_values, uint64_t amount_words,
uint64_t* solutions);

/**
 * @brief Writes every solution found in a binary file
 * @details Appends word_values array elements at the end of a binary file, named output.bin
 * @see convert_digits_to_value
 * @return ERROR_CANNOT_OPEN_FILE if it cannot open the file
 * @return ERROR_INVALID_ARRAY If word_values array is not NULL
 * @return ERROR_SUCCESS if it successfully appends data in the binary file
 */
enum error_t append_output_binary(const uint64_t* word_values,
const uint64_t amount_words);

/**
 * @brief try every number from 0 to 9 in every index position (one by one).
 * @param index-The value's location within the array.
 * @see convert_digits_to_value, find_digits_values
 */
void carry(uint64_t* letter_values, uint64_t index);


// Procedure Solve Cryptarithm
enum error_t solve_cryptarithm(char** words, uint64_t amount_words) {
  enum error_t error = ERROR_SUCCESS;
  // Create max unique elements = 10
  const unsigned int max_unique_elements = 10;
  // Create letters as an array of chars with size max unique elements
  char* letters = (char*) calloc(max_unique_elements + 1, sizeof(char));
  if (letters) {
    // Create unique chars as Count unique characters (**words, *letters)
    uint64_t amount_unique_letters = count_unique_letters(words,
    letters, amount_words);

    // If Words is valid then
    if (words_is_valid(amount_unique_letters)) {
      uint64_t* letter_values = (uint64_t*) calloc(amount_unique_letters,
      sizeof(uint64_t));
      if (letter_values) {
        // Initialiaze array word_values and digit word_values as zero
        fill_array_zero(letter_values, amount_unique_letters);
        find_solutions(amount_unique_letters, letters, words,
        letter_values, amount_words);
        free(letter_values);
      } else {
        error = ERROR_INVALID_ARRAY;
      }
    } else {
      printf("invalid input\n");
      error = ERROR_EXCEEDED_UNIQUE_CHARS;
    }
    free(letters);
  } else {
    error = ERROR_INVALID_ARRAY;
  }
  return error;
}

// Procedure Count unique characters
int count_unique_letters(char** words, char* letters, uint64_t amount_words) {
  if (words && letters) {
    letters[0] = ' ';
    int amount_unique_letters = 0;

    for (uint64_t word = 0; word < amount_words; word++) {
      // Create word length as strlen(words[word])
      uint64_t word_length = strlen(words[word]);
      for (uint64_t letter_index = 0; letter_index < word_length;
      letter_index++) {
        // if Letter Is Unique (words[word][letter index], letters) then
        if (is_letter_unique(10, words[word][letter_index], letters) == true) {
          /// Finds each unique letter and stored them in letters array
          if (amount_unique_letters < 10) {
            letters[amount_unique_letters] = words[word][letter_index];
          }
          amount_unique_letters++;
        }
      }
    }
    return amount_unique_letters;
  }
  return 0;  // 0 for error
}

// Function char is unique
bool is_letter_unique(const int amount_unique_letters, const char letter,
const char* letters) {
  if (letters) {
    for (int index = 0; index < amount_unique_letters; index++) {
      if (letter == letters[index])
        return false;
    }
    return true;
  }
  return false;
}

bool words_is_valid(const int amount_unique_letters) {
  if (amount_unique_letters <= 10)
    return true;
  return false;
}

void fill_array_zero(uint64_t* array, const uint64_t array_size) {
  if (array) {
    for (uint64_t index = 0; index < array_size; index++) {
      array[index] = 0;
    }
  }
}

enum error_t find_solutions(uint64_t amount_unique_letters, char* letters,
char** words, uint64_t* letter_values, uint64_t amount_words) {
  enum error_t error = ERROR_SUCCESS;
  uint64_t* word_values = (uint64_t*) calloc(amount_words, sizeof(uint64_t));
  if (word_values) {
    fill_array_zero(word_values, amount_words);
    const unsigned int max_unique_elements = 10;
    const uint64_t amount_permutations = permutation(max_unique_elements,
    amount_unique_letters);
    // Create solutions as 0
    uint64_t solutions = 0;
    /// Removes output.bin if it exist
    remove("output.bin");
    for (uint64_t permutation = 1; permutation <= amount_permutations;
    permutation++) {
      error = find_digits_values(amount_unique_letters, letter_values);
      if (error == ERROR_SUCCESS) {
        /// With the current permutations of letters values
        /// check if it is a solution
        error = try_solution(letters, words, letter_values, word_values,
        amount_words, &solutions);
      } else {
        break;
      }
    }
    free(word_values);
    // Print " solution(s) found"
    printf("%" PRIu64 " solution(s) found\n", solutions);
  }
  return error;
}

uint64_t permutation(const uint64_t total_amount, const uint64_t used_amount) {
  if (total_amount >= used_amount)  // return factorial(n) / factorial (n - r)
    return (factorial(total_amount) / factorial(total_amount - used_amount));
  return 0;
}

// Function Factorial
uint64_t factorial(uint64_t number) {
  // Create result as 1;
  int result = 1;
  for (uint64_t actual_num = 2; actual_num <= number; ++actual_num) {
      // Change result as result * actual num
    result *= actual_num;
  }
  return result;
}

// Procedure Find Digits word_values
enum error_t find_digits_values(const uint64_t amount_unique_letters,
uint64_t* letter_values) {
  if (letter_values && amount_unique_letters > 0) {
    // Create index as amount of unique chars - 1
    uint64_t index = amount_unique_letters - 1;
    letter_values[index]++;

    if (letter_values[index] == 10) {
      letter_values[index] = 0;
      if (amount_unique_letters > 1)
        carry(letter_values, index - 1);
    }
    // While Digits are unique == false
    while (!digit_validator(letter_values, amount_unique_letters)) {
      // Change letter_values[index] as letter_values[index] + 1
      letter_values[index]++;
      // If letter_values[index] == 10 then
      if (letter_values[index] == 10) {
        // Carry(letter_values*, index - 1)
        letter_values[index] = 0;
        carry(letter_values, index - 1);
      }
    }
    return ERROR_SUCCESS;
  }
  return ERROR_INVALID_DIGITS;
}

// Verifies if every digit is different
bool digit_validator(uint64_t* letter_values, uint64_t amount_unique_letters) {
  if (letter_values) {  // != NULL
    if (amount_unique_letters == 1) {
      return true;
    }
    for (uint64_t actual_index = 0; actual_index < amount_unique_letters; actual_index++) {
      for (uint64_t next_index = actual_index + 1; next_index < amount_unique_letters; next_index++) {
        if (letter_values[actual_index] == letter_values[next_index]) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}

// Function Carry
void carry(uint64_t* letter_values, uint64_t index) {
  if (letter_values) {
    // letter_values[index]++
    letter_values[index]++;
    // If letter_values[index] == 10
    if (letter_values[index] == 10) {
      // letter_values[index] = 0
      letter_values[index] = 0;
      // Carry(letter_values*, index - 1)
      carry(letter_values, index - 1);
    }
  }
}

enum error_t try_solution(char* letters, char** words,
uint64_t* letter_values, uint64_t* word_values, uint64_t amount_words,
uint64_t* solutions) {
  enum error_t error = ERROR_SUCCESS;
  if (values_are_valid(letters, words, letter_values, amount_words)) {
    error = convert_digits_to_value(amount_words, word_values, letter_values,
    letters, words);
    if (error == ERROR_SUCCESS) {
      if (sum_is_valid(word_values, amount_words)) {
        // Create max word length as Get Max Word Length
        size_t max_word_length = get_max_word_length(words, amount_words);
        /// Prints the solution found
        error = print_solution(word_values, amount_words, max_word_length);
        if (error == ERROR_SUCCESS) {
          /// Writes the actual solution found (output) in a binary file
          error = append_output_binary(word_values, amount_words);
        }
        *(solutions) += 1;
      }
    }
  }
  return error;
}

bool values_are_valid(char* letters, char** words, uint64_t* letter_values,
uint64_t amount_words) {
  if (letters && words && letter_values && amount_words > 0) {
    int max_word_length = get_max_word_length(words, amount_words);
    if (max_word_length > 1) {
      for (uint64_t word = 0; word < amount_words; word++) {
        uint64_t digit_index = get_char_position(letters, words[word][0]);
        /// Checks if word value won't start with leading zeros
        if (letter_values[digit_index] == 0) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}

// Function Convert Digits To Value
enum error_t convert_digits_to_value(const uint64_t amount_words,
uint64_t* word_values, const uint64_t* letter_values, char* letters, char** words) {
  if (word_values && letter_values && letters && words && amount_words > 0) {
    fill_array_zero(word_values, amount_words);
    // For value = 0; value < amount of words; value++
    for (uint64_t value = 0; value < amount_words; value++) {
      // Create word length as strlen(words[word])
      uint64_t word_length = strlen(words[value]);
      // For digit = 0; digit < word lenght; digit++
      for (uint64_t digit = 0; digit < word_length; digit++) {
        uint64_t digit_index = get_char_position(letters, words[value][digit]);
        word_values[value] = (word_values[value] * 10) + letter_values[digit_index];
      }
    }
    return ERROR_SUCCESS;

  } else {
    return ERROR_INVALID_ARRAY;
  }
}

// Function Get Char Position
uint64_t get_char_position(char* letters, const char letter) {
  if (letters) {
    uint64_t letters_length = strlen(letters);
    for (uint64_t index = 0; index < letters_length; index++) {
      if (letters[index] == letter) {
        return index;
      }
    }
  }
  return 0;  // error, array is null or index is not found
}

// Function Values Are Valid
bool sum_is_valid(uint64_t* word_values, const uint64_t amount_words) {
  // Create sum as 0
  uint64_t sum = 0;
  for (uint64_t index = 0; index < amount_words - 1; index++) {
    sum += word_values[index];
  }
  if (sum == word_values[amount_words - 1]) {
    return true;
  }
  return false;
}

// Function Get Max Word Length
size_t get_max_word_length(char** words, const uint64_t amount_words) {
  // Create max size as strlen(words[0])
  size_t max_size = strlen(words[0]);
  for (uint64_t index = 1; index < amount_words; index++) {
    // If max size < strlen(words[index]) then
    if (max_size < strlen(words[index])) {
      max_size = strlen(words[index]);
    }
  }
  return max_size;
}

// Procedure Print Solution
enum error_t print_solution(const uint64_t* word_values, const uint64_t amount_words,
const size_t max_word_length) {
  // Print word_values[0]
  if (word_values && amount_words > 0) {
    printf("%3s%*"PRIu64" \n", "", (int)max_word_length, word_values[0]);
    for (uint64_t index = 1; index < amount_words - 1; index++) {
      printf("  +");
      // Print word_values[index]
      printf("%*"PRIu64" \n", (int)max_word_length , word_values[index]);
    }
    printf("   ");
    for (uint64_t counter = 0; counter < max_word_length; counter++) {
      printf("-");
    }
    // Print word_values[amount of words - 1]
    printf(" \n = %"PRIu64" \n\n", word_values[amount_words - 1]);
    return ERROR_SUCCESS;
  }
  return ERROR_PRINT_UNSUCCESSFUL;
}

enum error_t append_output_binary(const uint64_t* word_values,
const uint64_t amount_words) {
  enum error_t error = ERROR_SUCCESS;
  if (word_values) {
    FILE *append_ptr;
    append_ptr = fopen("output.bin", "ab");
    if (!append_ptr) {
      error = ERROR_CANNOT_OPEN_FILE;
    }
    if (error == ERROR_SUCCESS) {
      /// Writes the actual solution (word_values content) in a binary file
      for (uint64_t index = 0; index < amount_words; index++) {
        fwrite(&word_values[index], sizeof(index), 1, append_ptr);
      }
      fclose(append_ptr);
    }
  } else {
    error = ERROR_INVALID_ARRAY;
  }
  return error;
}