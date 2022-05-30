# progra2-22a-harold-carrillo--andres-quesada--rodrigo-hernandez

Project 1: Cryptarithms, from the course of Programación 2-22a

* * *

# Analysis

[Cryptarithms][1] are puzzles where letters stand for different digits in an arithmetic problem. The problem  
is usually to figure out which letters stand for which digits.  
Often it helps to write equations using the letters. Algebra can then be used to solve for the letters.  
Sometimes you can narrow the possibilities for a given letter down to a small number of choices, and  
you just have to try them and see if there is a way to get a solution.  
  
In a cryptarithm each letter represents a unique value from 0 to 9, so it cannot have more than 10 different letters.  
A program is required that is capable of solving cryptoarithms in which only additions are performed.  
It is necessary that the program can find all possible solutions, if any, of the cryptoarithm problems given to it.  
The program must be able to solve cryptarithms with as many digits as possible, and when solutions are found,  
they must be shown in the standard output with their respective indicator of the number of solutions.
  
## Input
  
### Input Format

``` 
SEND + MORE = MONEY 
```
  
```
  SEND 
+ MORE
= MONEY
```
  
### Input Requirements

- English alphabet characters.
- ASCII characters only.
- Uppercase and lowercase are different.
- Doesn't need to be valid words.
- Can't have more than ten distinct letters
  
## Development

- Several possible solutions.
- Each letter (char) has a different value between [0,9].
- Based on the 8 procedural instruction types.
- To get the amount of all possible solutions permutation without repetition is needed
  
### Basic rules for solving verbal arithmetic problems

1. Adding the same letter an even number of times results in an even number. A+A=2A(even)
2. If A + B == A, when it is in units B it is definitely 0, if not then it is 0 or 9.
3. The maximum carry is n-1, where n is the amount of numbers in the sum.

## Output

### Output Format

If there is more than 10 different letters then  

``` invalid input ```

Else  

```
    9567 
  + 1085 
   ----- 
 = 10652 

1 solution(s) found
```

### Output Requirements

- Only sums.
- Can show more than one solution if there are any.
- Show "invalid input" if there are more than 10 different letters.
- The numbers should be aligned to the right according to the number of digits of the largest number.
- After the first number, the rest of the numbers that add up must be accompanied by a "+".
- The last number, i.e., the result of the sum, must be separated from the numbers adding by a set of "-".
- The last number must be accompanied by an "=".

* * *

# Design

## Diagram
  
![Program design](/assets/images/ProgramDesign.jpg "Program design")

## Algorithm in pseudocode

```
cryptarithms.c

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
          Change values[value] as (values[value] * 10) + 
          digit values[Get char position(letters, word[value][digit])]

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
```  
  
```
cryptarithmetic.c
 
  Procedure main
    Create struct matrix matrix
    Array init(&matrix)
    Read Values(&matrix)
    If error == EXIT SUCCESS then
     Solve Cryptarithm(matrix.elements, matrix.count)
    matrix Uninit(&matrix)
    return error

  Procedure Read Values
    Create value as an char matrix of size 21
    Create error as EXIT SUCCESS
    If value != NULL then
      If there is data
        Read value
        matrix Append(values, value)
      While there is data
        Read value
        matrix append(values, value)
      If there is data
        Read values
        matrix append(values ,value)
    Else
      Change error as EXIT FAILURE
    return error
```
  
```
matrix.c

  Procedure matrix Init
    Change matrix->count as 0
    Change matrix->capacity as INITIAL_CAPACITY
    Change matrix->elements as Create Matrix
    If matrix->elements == NULL
      Change matrix capacity as 0

  Procedure matrix Uninit
    Destroy Matrix(matrix->elements, matrix->capacity)
    Change matrix->count as 0
    Change matrix->capacity as 0

  Procedure Create Matrix
    Create matrix as an matrix of rows
    If matrix then
      For row = 0; row < rows; row++
        Create matrix[row] as an matrix of cols
        If matrix[row] == NULL
          Destroy matrix(matrix, rows)
          return NULL
    return matrix

  Procedure Destroy Matrix
    If matrix != NULL then
      For row = 0; row < rows; row++
        free(matrix[row])
      free(matrix) 
      
  Procedure matrix Append
    If matrix->count == matrix->capacity then
      Increase Capacity(matrix)
    Create element length as strlen(element)
    For index= 0; index < element_length; index++
      Change matrix->elements[matrix->count][index] as element[index]
    Change matrix->count as matrix->count + 1

  Procedure increase capacity
    Create new capacity as INCREASE_FACTOR * matrix->capacity
    Create new elements as Create Matrix
    If new elements != NULL then
      For row = 0; row < matrix->count; row++
        Create element length as strlen(matrix->elements[row])
        For column = 0; column < element length; column++
          Change new elements[row][column] as matrix->elements[row][column]
      Destroy Matrix
      matrix->elements = new elements
      matrix->capacity = new capacity
```

* * *

# User manual

## Scope

This manual is intended for users that are using the Cryptarithmetic app.

The following sub-sections contain all of the documentation to call the app, as well as some examples and results.

## Overview

### What is the Cryptarithmetic program

The Cryptarithmetic app is a solution for solving an special kind of mathematic problems called cryptarithms.

Allows to solve cryptoarithms in a much easier and faster way than the traditional way.

### Features

- It allows to solve cryptoarithms in which there are n number of words.
- It finds each of the solutions to the cryptoarithm given to it, and prints them to the standard output.
- Allows to work with as many digits as possible

## Call instructions
  
Program can be called with:

```shell
bin/cryptarithmetic < textfile.txt  
bin/cryptarithmetic < tests/testname.txt
bin/cryptarithmetic
```
  
## Parameters

Minimum of 2 strings, i.e. one adding word and the solution (output).  
After the first word the rest of the words must be accompanied by a "+" and a blank space, except for the last word.  
The last word must be accompanied by an "=" followed by a blank space.  

## Examples of program execution

### Examples upon executing the program with no parameters

Example 1:
User Input = ```SEND + MORE = MONEY```

Example 2:
User Input = ```ABCD + EFGH + IJKL + LMNO = PQRST```
  
### Examples if the program is executed passing parameters  

Example 2, from “textfile1.txt”:
```ANDRES + FABIAN = RODRIGO```

Example 1, from “textfile2.txt”:

```
  ONE 
+ TWO 
+ TWO 
+ THREE 
+ THREE 
= ELEVEN
```

## Results  

<details>
    <summary>Examples upon executing the program with no parameters</summary>
Example 1:

```
    9567  
  + 1085  
   -----  
 = 10652  
  
 1 solution(s) found
```
  
Example 2:

```invalid input```
</details>

<details>
    <summary>Examples if the program is executed passing parameters</summary>
Example 1:  

```
 invalid input   
```

Example 2:

```
      391
  +   803
  +   803
  + 84611
  + 84611
   ------
 = 171219
 
 1 solution(s) found
```
</details>
  
* * *

[1]: <https://www.cs.cornell.edu/andru/mathclub/handouts/2015/03-04-soln.pdf> "Cryptarithms"
