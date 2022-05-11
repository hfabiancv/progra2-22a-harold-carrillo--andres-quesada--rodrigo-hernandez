# progra2-22a-harold-carrillo--andres-quesada--rodrigo-hernandez
Proyecto 1: Criptoaritmo, del curso Programacion 2 2022-I

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
3. The maximum carry is n-1, where n is the maximum size of all the numbers that are in the sum.
4. The maximum carry is n-1, where n is the amount of numbers in the sum.

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
- Show "invalid input" if there are more than 10 different letters

* * *

# Design

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
  ```

* * * 

# User manual

## Call instructions

Program can be called with:

```
bin/cryptarithm textfile.txt  
bin/cryptarithm < tests/testname.txt
bin/cryptarithm
```

## Parameters

Minimum of 3 strings, i.e. two adding words and the solution (output).  
Words must always be separated by at least one space.  
Standard input
 
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
