#include "cryptarithms.h"

/*
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
*/

