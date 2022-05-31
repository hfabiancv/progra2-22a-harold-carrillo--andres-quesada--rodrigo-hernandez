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

## Design pseudocode

See pseudocode [here](design/design.pseudo)

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

To compile:

```shell
make
```
  
After its compiled the program can be called with:

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
