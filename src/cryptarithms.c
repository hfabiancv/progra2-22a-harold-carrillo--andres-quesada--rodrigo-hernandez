/*
                Algorithm

Cryptarithms Library

  Procedure Solve Cryptarithm
    Create max unique elements = 10
    Create letters as an array of chars with size max unique elements
    Create unique chars as Count unique characters (**words, *letters)
    If Words is valid then
      Create digit values as an array of max unique elements
      Initialiaze array values as zero
      Create amount of permutations as permutation(unique chars, max unique elements)
      Create solutions as 0
      For int permutation = 1; i <= amount of permutations; permutation++
        Fill digit values(*digit values)
        Create values as an array of amount words 
        Fill values(*values, *digit values, amount of words) 
        If Check values then
          Create max num size as Get Max Num Size
          Print Solution(amount of words, values, max num size)
          solutions++
      return ERROR_SUCCESS
    Else
      return ERROR_EXCEEDED_UNIQUE_CHARS

  Procedure Count unique characters
    Create amount of unique chars as 0
    For word = 0; word < amount of words; word++
      Create word length as strlen(words[word])
      For letter index= 0; letter index < word length; letter index++
        For unique char index = amount of unique chars - 1; unique char index >= 0; unique char index++
          If unique char index == -1 then
            letters[amount of unique chars] = words[letter index];
            Change amount of unique chars as amount of unique chars + 1
          Else if letters[unique char index] == words[letter index] then
            break
    return amount of unique chars    

  Function Words is valid
    If amount of unique chars <= 10 then
      return true
    return false

  Function Permutation
    return factorial(n) / factorial (n - r)

  Function Factorial
    Create result as 1;
    for actual num = 2; actual num <= n; ++i
        Chnage result as result * actual num
    return result

  Procedure Fill digits values
    

  Function Fill values     
    For value = 0; value < amount of words; value++
      Create word length as strlen(words[word])
      For digit = 0; digit < word lenght; digit++
        values[value] = (values[value] * 10) + digit values[Get char position(*letters, word[digit])]

  Function Get Char Position
    If words then
      For index = 0; index < words lenght; index++ 
        If words[index] == letter
          return index
    return -1;

  Function Check Values
    Create sum as 0
    For index = 0; index < amount of words - 1; index++
      sum += values[index]
    If sum == values[amount of words - 1]
      return true
    return false

  Function Get Max Num Size
    Create max size as strlen(words[0])
    For index = 1; index < amount of words; index++
      if max size < strlen(words[index])
        max size = strlen(words[index])
    return max size

  
  Function Print Solution
    Print values[0]
    For index = 1; index < amount of words - 1; index++
      Print " + "
      Print values[index]
    Print " -----"
    Print values[amount of words - 1]
   
*/


 

//Cryptarithms Library
#include "cryptarithms.h"


int Solve_Cryptarithm(void){

  return 0;
}
/*
Cryptarithms Library

  Procedure Solve Cryptarithm
    Create max unique elements = 10
    Create letters as an array of chars with size max unique elements
    Create unique chars as Count unique characters (**words, *letters)
    If Words is valid then
      Create digit values as an array of max unique elements
      Initialiaze array values as zero
      Create amount of permutations as permutation(unique chars, max unique elements)
      Create solutions as 0
      For int permutation = 1; i <= amount of permutations; permutation++
        Find digit values(*digit values)
        Create values as an array of amount words 
        Convert Digits To Value(*values, *digit values, amount of words) 
        If Values Are Valid then
          Create max num size as Get Max Num Size
          Print Solution(amount of words, values, max num size)
          solutions++
      return ERROR_SUCCESS
    Else
      return ERROR_EXCEEDED_UNIQUE_CHARS

  Procedure Count unique characters
    If words then
      letters[0] = word[0][0];
      Create amount of unique chars as 1
      For word = 0; word < amount of words; word++
        Create word length as strlen(words[word])
        For letter index= 0; letter index < word length; letter index++
          For unique char index = 1; unique char index < amount of unique chars; unique char index++
            if Letter Is Unique (words[word][letter index], letters) then
              letters[letter index] = words[word][letter index]
            Else
              break
      return amount of unique chars 
    return -1
    
  Function Letter is Unique
    For index = 0; index < amount of unique chars; index++
      If letter == letters[index] then
        return false
    return true

  Function Words is valid
    If amount of unique chars <= 10 then
      return true
    return false

  Function Permutation
    return factorial(n) / factorial (n - r)

  Function Factorial
    Create result as 1;
    for actual num = 2; actual num <= n; ++i
        Chnage result as result * actual num
    return result

  Procedure Find Digits values
    Create index as amount of unique chars - 1
    While Digits are unique == false
      Change values[index] as values[index] + 1
        If values[index] == 10 then
          Carry(index - 1)
		  
  Function Carry
    values[index]++
      If values[index] == 10	
        values[index] = 0
	   Carry(index - 1)

  Function Convert Digits To Value    
    For value = 0; value < amount of words; value++
      Create word length as strlen(words[word])
      For digit = 0; digit < word lenght; digit++
        values[value] = (values[value] * 10) + digit values[Get char position(*letters, word[value][digit])]

  Function Get Char Position
    If array then
      For index = 0; index < array length; index++ 
        If array[index] == letter then
          return index
    return -1; 

  Function Values Are Valid
    Create sum as 0
    For index = 0; index < amount of words - 1; index++
      sum += values[index]
    If sum == values[amount of words - 1] then
      return true
    return false

  Function Get Max Num Size
    Create max size as strlen(words[0])
    For index = 1; index < amount of words; index++
      If max size < strlen(words[index]) then
        max size = strlen(words[index])
    return max size
  
  Procedure Print Solution
    Print values[0]
    For index = 1; index < amount of words - 1; index++
      Print " + "
      Print values[index]
    For counter = 0; counter < max num size; counter++
      Print " - "
    Print values[amount of words - 1]
*/

bool words_is_valid(int amount_unique_chars){
  if(amount_unique_chars <= 10){
    return true;
  }
  return false;
}

  //Function Permutation
    //return factorial(n) / factorial (n - r)
int permutation(int total_amount, unsigned int used_amount){
  if(total_amount>used_amount){
    return (factorial(total_amount) / factorial(total_amount - used_amount));
  }
  //else return ERROR
}

  //Function Factorial
    //Create result as 1;
    //for actual num = 2; actual num <= n; ++i
        //Chnage result as result * actual num
    //return result
int factorial(int n){
  if(n>=0){
    int result = 1;
    for(int actual_num = 2; actual_num <= n; ++actual_num){
      result *= actual_num;
    }
    return result;
  }
  //else return ERROR
}
int amount_of_unique_characters(void){}//debería recibir

bool letter_is_unique(int, char, char[]){
}

  //Procedure Fill digits values
    

  //Function Fill values     
    //For value = 0; value < amount of words; value++
      //Create word length as strlen(words[word])
      //For digit = 0; digit < word lenght; digit++
        //values[value] = (values[value] * 10) + digit values[Get char position(*letters, word[digit])]

  //Function Get Char Position
    //If words then
      //For index = 0; index < words lenght; index++ 
        //If words[index] == letter
          //return index
    //return -1;

  //Function Check Values
    //Create sum as 0
    //For index = 0; index < amount of words - 1; index++
      //sum += values[index]
    //If sum == values[amount of words - 1]
      //return true
    //return false

  //Function Get Max Num Size
    //Create max size as strlen(words[0])
    //For index = 1; index < amount of words; index++
      //if max size < strlen(words[index])
        //max size = strlen(words[index])
    //return max size

  
  //Function Print Solution
    //Print values[0]
    //For index = 1; index < amount of words - 1; index++
      //Print " + "
      //Print values[index]
    //Print " -----"
    //Print values[amount of words - 1]
   
