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
  ERROR_READ_VALUES,
};

enum error_t solve_cryptarithm(char** words, uint64_t word_count);

int count_unique_letters(char** words, char* letters, uint64_t word_count);

bool is_letter_unique(const int amount_unique_letters, const char letter,
const char* letters);

bool words_is_valid(const int amount_unique_letters);

uint64_t permutation(const uint64_t total_amount, const uint64_t used_amount);

uint64_t factorial(uint64_t number);

enum error_t find_digits_values(const uint64_t amount_unique_letters,
uint64_t* digit_values);

void carry(uint64_t* digit_values, uint64_t index);

enum error_t convert_digits_to_value(const uint64_t amount_words,
uint64_t* values, const uint64_t* digit_values, char* letters, char** words);

uint64_t get_char_position(char* letters, const char letter);

bool sum_is_valid(uint64_t* values, const uint64_t amount_words);

size_t get_max_word_length(char** words, const uint64_t amount_words);

enum error_t print_solution(const uint64_t* values, const uint64_t amount_words,
const size_t max_word_length);

void initialize_as_zero(uint64_t* array, const uint64_t array_size);


#endif
