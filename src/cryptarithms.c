// Copyright 2022 Harold Carrillo & Rodrigo Hernandez & Andres Quesada

// Cryptarithms Library

#include <stdint.h>
#include <string.h>

#include "cryptarithms.h"


/*
Cryptarithms Library

  Procedure Solve Cryptarithm
    Create error as ERROR_SUCCESS
    Create max unique elements as 10
    Create letters as an array of chars with size max unique elements
    If letters != NULL then
      Create amount unique letters as Count unique letters (words, letters, word count)
      If Words is valid then
        Create digit values as an array of size amount unique letters
        If digit values != NULL then
          Initialiaze as zero (digit values, amount unique letters)
          Find Solutions(amount unique letters, letters,
          words, digit values, word count)
        Else
          Change error as ERROR_INVALID_ARRAY
      Else
        Print "invalid input"
        Change error as ERROR_EXCEEDED_UNIQUE_CHARS
    Else
      Change error as ERROR_INVALID_ARRAY;
    return error

  Procedure Count unique letters
    If words != NULL then
      letters[0] = ' '
      Create amount of unique letters as 0
      For word = 0; word < word count; word++
        Create word length as strlen(words[word])
        For letter index = 0; letter index < word length; letter index++
          If Letter Is Unique (10, words[word][letter index],letters) == true then
            If amount unique letters < 10 then
              letters[amount_unique_letters] = words[word][letter_index]
      return amount unique letters
    return 0
    
  Function Letter is Unique
    Create letters length as strlen(letters)
    For index = 0; index < letters length; index++
      If letters[index] == letter then
        return false
    return true

  Function Words is valid
    If amount of unique chars <= 10 then
      return true
    return false

  Procedure Find Solutions
    Create values as an array of size word count
      Initialiaze as zero (values, word count)
      Create amount of permutations as
      permutation(amount unique letters, max unique elements)
      Create solutions as 0
      For permutation = 1; permutation <= amount of permutations; permutation++
        Find digits values(amount unique letters, digit values)
      Print solutions + " solution(s) found"

  Function Permutation
    If total amount >= used amount
      return factorial(n) / factorial (n - r)
    return 0

  Function Factorial
    Create result as 1;
    For actual num = 2; actual num <= n; ++actual num
      Change result as result * actual num
    return result

  Procedure Find Digits values
    If digit values and amount unique letters > 0 then
      Create index as amount of unique chars - 1
      Change digit values[index] as digit values[index] + 1
      If digit values[index] == 10 then
        Change digit values[index] as 0
        If amount unique letters > 1
          Carry(digit values, index - 1)
      While Digit validator == false
        Change digit values[index] as digit values[index] + 1
          If digit values[index] == 10 then
            Change digit values[index] as 0
            Carry(digit values, index - 1)

  Function Carry
    If digit values != NULL
      Change digit values[index] as digit values[index] + 1
        If digit values[index] == 10
          Change digit values[index] as 0
          Carry(digit values, index - 1)
        return ERROR_SUCCESS
    return ERROR_INVALID_DIGITS

  Function Digit Validator
    If digit array != NULL then
      If digit count > 1 then
        For index = 0; index < digit count; index++
          For index2 = index + 1; index2 < digit count; index2++
            If digit array[index] == digit array[index2] then
              return false
      return true
    return false

  Procedure Try Solution
    If Values are valid(letters, words digit values, word count) then
      Convert digits to values(word count, values, digit values, letters, words)
      If Sum Is Valid(values, word count) then
        Create max word length as Get Max Word Length(words, word count)
        Print Solution(values, word count, max word length)
        Change solutions as solutions + 1

  Function Convert Digits To Value    
    If values and digit values and letter and words and amount words > 0 then
      Initialize as zero(values, amount words)
      For value = 0; value < amount of words; value++
        Create word length as strlen(words[value])
        For digit = 0; digit < word length; digit++
          Change values[value] as (values[value] * 10) + digit values[Get char position(letters, word[value][digit])]

  Function Get Char Position
    If array then
      For index = 0; index < array length; index++ 
        If array[index] == letter then
          return index
    return -1

  Function Values are Valid
    For word = 0; word < word count; word++
      Create digit index as Get Char Position(letters, words[word][0])
      If digit values[digit index] == 0 then
        return false
    return true

  Function Sum is Valid
    Create sum as 0
    For index = 0; index < amount of words - 1; index++
      Change sum as sum + values[index]
    If sum == values[amount of words - 1] then
      return true
    return false

  Function Get Max Word Length
    Create max size as strlen(words[0])
    For index = 1; index < amount of words; index++
      If max size < strlen(words[index]) then
        Change max size as strlen(words[index])
    return max size
  
  Procedure Print Solution
    If values and amount words > 0
      Print values[0]
      For index = 1; index < amount of words - 1; index++
        Print " + "
        Print values[index]
      For counter = 0; counter < max num size; counter++
        Print " - "
      Print values[amount of words - 1]
*/

/**
 * @brief Finds all of the possible solutions of the cryptarithm
 * @param amount_unique_letters The amount of unique letters in the cryptarithm
 * @param letters Array that contains each of the unique letters in the cryptarithm
 * @param words Array that contains every string or word in the cryptarithm
 * @param word_count The amount of strings or words.
 * @return @c ERROR_INVALID_DIGITS if @a digit_values array is not valid
 * @return @c ERROR_PRINT_UNSUCCESSFUL if values is not valid or is empty, so it can't print anything.
 * @return @c ERROR_SUCCESS if doesnt fail while looking for a possible solution
 */
enum error_t find_solutions(uint64_t amount_unique_letters, char* letters,
char** words, uint64_t* digit_values, uint64_t word_count);

/**
 * @brief Checks if all of the letters values are unique
 * @param digit_arr Array that contains all of the digits, or letter values
 * @param digit_count Amount of digits, @a digit_arr size
 * @return true if all digits (letters values) are different from each other
 * @return false if there is a repeated digit value
 */
bool digit_validator(uint64_t* digit_arr, uint64_t digit_count);

/**
 * @brief Checks if the values of each word do not leading zeros
 * @param digit_values Array that contains the values of each unique letter
 * @param word_count The amount of strings or words.
 * @return true if the number doesnt have leading zeros
 * @return false if the number have leading zeros
 */ 
bool values_are_valid(char* letters, char** words, uint64_t* digit_values,
uint64_t word_count);

/**
 * @brief Try one of the possible solutions of the cryptarithm
 * @param solutions The amount of solutions. Must be initialized as zero
 * @see find_solutions
 * @see try_solution
 */
enum error_t try_solution(char* letters, char** words,
uint64_t* digit_values, uint64_t* values, uint64_t word_count,
uint64_t* solutions);

/**
 * @brief Writes every solution found in a binary file
 * @details Appends values array elements at the end of a binary file, named output.bin
 * @see convert_digits_to_value
 * @return ERROR_CANNOT_OPEN_FILE if it cannot open the file
 * @return ERROR_INVALID_ARRAY If values array is not NULL
 * @return ERROR_SUCCESS if it successfully appends data in the binary file
 */
enum error_t append_output_binary(const uint64_t* values,
const uint64_t word_count);


// Procedure Solve Cryptarithm
enum error_t solve_cryptarithm(char** words, uint64_t word_count) {
  enum error_t error = ERROR_SUCCESS;
  // Create max unique elements = 10
  const unsigned int max_unique_elements = 10;
  // Create letters as an array of chars with size max unique elements
  char* letters = (char*) calloc(max_unique_elements + 1, sizeof(char));
  if (letters) {
    // Create unique chars as Count unique characters (**words, *letters)
    uint64_t amount_unique_letters = count_unique_letters(words,
    letters, word_count);

    // If Words is valid then
    if (words_is_valid(amount_unique_letters)) {
      uint64_t* digit_values = (uint64_t*) calloc(amount_unique_letters,
      sizeof(uint64_t));
      if (digit_values) {
        // Initialiaze array values and digit values as zero
        initialize_as_zero(digit_values, amount_unique_letters);
        find_solutions(amount_unique_letters, letters, words,
        digit_values, word_count);
        free(digit_values);
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
int count_unique_letters(char** words, char* letters, uint64_t word_count) {
  if (words && letters) {
    letters[0] = ' ';
    int amount_unique_letters = 0;

    for (uint64_t word = 0; word < word_count; word++) {
      // Create word length as strlen(words[word])
      uint64_t word_length = strlen(words[word]);
      for (uint64_t letter_index = 0; letter_index < word_length;
      letter_index++) {
        // if Letter Is Unique (words[word][letter index], letters) then
        if (is_letter_unique(10, words[word][letter_index], letters) == true) {
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

void initialize_as_zero(uint64_t* array, const uint64_t array_size) {
  if (array) {
    for (uint64_t index = 0; index < array_size; index++) {
      array[index] = 0;
    }
  }
}

enum error_t find_solutions(uint64_t amount_unique_letters, char* letters,
char** words, uint64_t* digit_values, uint64_t word_count) {
  enum error_t error = ERROR_SUCCESS;
  uint64_t* values = (uint64_t*) calloc(word_count, sizeof(uint64_t));
  if (values) {
    initialize_as_zero(values, word_count);
    const unsigned int max_unique_elements = 10;
    const uint64_t amount_permutations = permutation(max_unique_elements,
    amount_unique_letters);
    // Create solutions as 0
    uint64_t solutions = 0;
    remove("output.bin");
    for (uint64_t permutation = 1; permutation <= amount_permutations;
    permutation++) {
      error = find_digits_values(amount_unique_letters, digit_values);
      if (error == ERROR_SUCCESS) {
        error = try_solution(letters, words, digit_values, values,
        word_count, &solutions);
      } else {
        break;
      }
    }
    free(values);
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

// Procedure Find Digits values
enum error_t find_digits_values(const uint64_t amount_unique_letters,
uint64_t* digit_values) {
  if (digit_values && amount_unique_letters > 0) {
    // Create index as amount of unique chars - 1
    uint64_t index = amount_unique_letters - 1;
    digit_values[index]++;

    if (digit_values[index] == 10) {
      digit_values[index] = 0;
      if (amount_unique_letters > 1)
        carry(digit_values, index - 1);
    }
    // While Digits are unique == false
    while (!digit_validator(digit_values, amount_unique_letters)) {
      // Change digit_values[index] as digit_values[index] + 1
      digit_values[index]++;
      // If digit_values[index] == 10 then
      if (digit_values[index] == 10) {
        // Carry(digit_values*, index - 1)
        digit_values[index] = 0;
        carry(digit_values, index - 1);
      }
    }
    return ERROR_SUCCESS;
  }
  return ERROR_INVALID_DIGITS;
}

// Verifies if every digit is different
bool digit_validator(uint64_t* digit_arr, uint64_t digit_count) {
  if (digit_arr) {  // != NULL
    if (digit_count == 1) {
      return true;
    }
    for (uint64_t index = 0; index < digit_count; index++) {
      for (uint64_t index2 = index + 1; index2 < digit_count; index2++) {
        if (digit_arr[index] == digit_arr[index2]) {
          return false;
        }
      }
    }
    return true;
  }
  return false;
}

// Function Carry
void carry(uint64_t* digit_values, uint64_t index) {
  if (digit_values) {
    // digit_values[index]++
    digit_values[index]++;
    // If digit_values[index] == 10
    if (digit_values[index] == 10) {
      // digit_values[index] = 0
      digit_values[index] = 0;
      // Carry(digit_values*, index - 1)
      carry(digit_values, index - 1);
    }
  }
}

enum error_t try_solution(char* letters, char** words,
uint64_t* digit_values, uint64_t* values, uint64_t word_count,
uint64_t* solutions) {
  enum error_t error = ERROR_SUCCESS;
  if (values_are_valid(letters, words, digit_values, word_count)) {
    error = convert_digits_to_value(word_count, values, digit_values,
    letters, words);
    if (error == ERROR_SUCCESS) {
      if (sum_is_valid(values, word_count)) {
        // Create max word length as Get Max Word Length
        size_t max_word_length = get_max_word_length(words, word_count);
        // Print Solution(amount of words, values, max word length)
        error = print_solution(values, word_count, max_word_length);
        if (error == ERROR_SUCCESS) {
          error = append_output_binary(values, word_count);
        }
        *(solutions) += 1;
      }
    }
  }
  return error;
}

bool values_are_valid(char* letters, char** words, uint64_t* digit_values,
uint64_t word_count) {
  if (letters && words && digit_values && word_count > 0) {
    int max_word_length = get_max_word_length(words, word_count);
    if (max_word_length > 1) {
      for (uint64_t word = 0; word < word_count; word++) {
        uint64_t digit_index = get_char_position(letters, words[word][0]);
        if (digit_values[digit_index] == 0) {
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
uint64_t* values, const uint64_t* digit_values, char* letters, char** words) {
  if (values && digit_values && letters && words && amount_words > 0) {
    initialize_as_zero(values, amount_words);
    // For value = 0; value < amount of words; value++
    for (uint64_t value = 0; value < amount_words; value++) {
      // Create word length as strlen(words[word])
      uint64_t word_length = strlen(words[value]);
      // For digit = 0; digit < word lenght; digit++
      for (uint64_t digit = 0; digit < word_length; digit++) {
        uint64_t digit_index = get_char_position(letters, words[value][digit]);
        values[value] = (values[value] * 10) + digit_values[digit_index];
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
  return 0;  // error
}

// Function Values Are Valid
bool sum_is_valid(uint64_t* values, const uint64_t amount_words) {
  // Create sum as 0
  uint64_t sum = 0;
  for (uint64_t index = 0; index < amount_words - 1; index++) {
    sum += values[index];
  }
  if (sum == values[amount_words - 1]) {
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
enum error_t print_solution(const uint64_t* values, const uint64_t amount_words,
const size_t max_word_length) {
  // Print values[0]
  if (values && amount_words > 0) {
    printf("%3s%*"PRIu64" \n", "", (int)max_word_length, values[0]);
    for (uint64_t index = 1; index < amount_words - 1; index++) {
      printf("  +");
      // Print values[index]
      printf("%*"PRIu64" \n", (int)max_word_length , values[index]);
    }
    printf("   ");
    for (uint64_t counter = 0; counter < max_word_length; counter++) {
      printf("-");
    }
    // Print values[amount of words - 1]
    printf(" \n = %"PRIu64" \n\n", values[amount_words - 1]);
    return ERROR_SUCCESS;
  }
  return ERROR_PRINT_UNSUCCESSFUL;
}

enum error_t append_output_binary(const uint64_t* values,
const uint64_t word_count) {
  enum error_t error = ERROR_SUCCESS;
  if (values) {
    FILE *append_ptr;
    append_ptr = fopen("output.bin", "ab");
    if (!append_ptr) {
      error = ERROR_CANNOT_OPEN_FILE;
    }
    if (error == ERROR_SUCCESS) {
      for (uint64_t index = 0; index < word_count; index++) {
        fwrite(&values[index], sizeof(index), 1, append_ptr);
      }
      fclose(append_ptr);
    }
  } else {
    error = ERROR_INVALID_ARRAY;
  }
  return error;
}