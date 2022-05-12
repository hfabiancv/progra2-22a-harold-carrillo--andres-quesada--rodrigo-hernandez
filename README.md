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
  
### Format: 

``` 
SEND + MORE = MONEY 
```
  
```
  SEND 
+ MORE
= MONEY
```
  
### Requirements

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

### Format

```  
If there is more than 10 different letters then

  invalid input

Else
           
    9567 
  + 1085 
   ----- 
 = 10652 

1 solution(s) found
```

### Requirements:

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
  
![Program design](/assets/imgs/ProgramDesign.png "Program design")  

## Algorithm in pseudocode

```
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

  Procedure Find Digit Values
    

  Function Convert Digits To Value    
    For value = 0; value < amount of words; value++
      Create word length as strlen(words[word])
      For digit = 0; digit < word lenght; digit++
        values[value] = (values[value] * 10) + digit values[Get char position(*letters, word[value][digit])]

  Function Get Char Position
    If array then
      For index = 0; index < array length; index++ 
        If array[index] == letter
          return index
    return -1; 

  Function Values Are Valid
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
  
  Procedure Print Solution
    Print values[0]
    For index = 1; index < amount of words - 1; index++
      Print " + "
      Print values[index]
    For counter = 0; counter < max num size; counter++
      Print " - "
    Print values[amount of words - 1]
```  
  
```
Cryptarithmetic File
 
  Procedure main
    Create words as Create Matrix
    Read Words(words)
    If words then
     Solve Cryptarithm(words)
    Destroy Matrix(words)

  Procedure Create Matrix
    Create matrix and allocate the corresponding memory using calloc
      If matrix is True
        For row = 0; row < rows; row++
          If (matrix[row] = calloc(cols, element_size)) == NULL
            Destroy Matrix
            return NULL;
    return matrix

  Procedure Destroy Matrix
    If matrix is True
      For row = 0; row < rows; row++
        Free matrix[row]
      Free matrix w

  Function Read Words
    While there is data
      Read Word

```
  

* * * 

# User manual

## Call instructions
  
Program can be called with:

```
bin/cryptarithmetic textfile.txt  
bin/cryptarithmetic < tests/testname.txt
bin/cryptarithmetic
```
  
## Parameters

Minimum of 3 strings, i.e. two adding words and the solution (output).  
After the first word the rest of the words must be accompanied by a + and a blank space, except for the last word.  
The last word must be accompanied by an "=" followed by a blank space.  
  
## Examples of program execution

Example 1 - Upon executing the program with no parameters:  
“Please input the words followed by their sum:”  
User Input = SEND + MORE = MONEY  
  
Example 2 – If the program is executed passing parameters:  
For example from “textfile.txt”:  
ANDRES + FABIAN = RODRIGO  
  
### Results

Example 1:

```
    9567  
  + 1085  
   -----  
 = 10652  
  
 1 solution(s) found 
```

Example 2: 

```
 invalid input   
```

* * *

# References

[1]: <https://www.cs.cornell.edu/andru/mathclub/handouts/2015/03-04-soln.pdf> "Cryptarithms"
