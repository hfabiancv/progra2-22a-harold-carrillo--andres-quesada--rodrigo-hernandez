# progra2-22a-harold-carrillo--andres-quesada--rodrigo-hernandez
Proyecto 1: Criptoaritmo, del curso Programacion 2 2022-I

# Análisis

## Entradas
### Formato: 
``` 
char[] + char[] = char[] 
```

- Son del alfabeto inglés.
- Solo caracteres ASCII
- Mayus y minus.
- No hace falta que sean palabras válidas..

## Desarrollo
- Varias posibles soluciones.
- Cada char tiene un valor distinto entre [0,9].
- Basado en los 8 tipos de instrucción procedimental.
- Si tengo x valores fijos y z valores variables, entonces… countCharsVariables, cantNumNoAsignados->permutación sin repetición. Más de una solución

### Reglas básicas en la resolución de problemas de aritmética verbal:
1. La suma de la misma letra un numero par de veces resulta en un número par. A+A=2A(par)
2. Cada letra es un número diferente.
3. Si A + B == A, cuando esta en unidades B es definitivamente 0, si no entonces es 0 ó 9.
4. El acarreo máximo es de n+1, siendo n el tamaño de los nums que están en la suma.
5. Si la suma de dos núms de n dígitos es un num de n+1 dígitos entonces el dígito más a la izquierda del resultado es un 1.

## Salidas 
### Formato:

```  
           int[]
         + int[]
    -------------- -> (cant de “-”  == tam en dígitos del resultado)
           Int[]
 _ solution(s) found
```

- Errores: “invalid input”
- No puede tener más de diez chars distintos
- Solo sumas.

# Diseño

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