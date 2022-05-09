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
## Reglas básicas en la resolución de problemas de aritmética verbal:
1.La suma de la misma letra un numero par de veces resulta en un número par. A+A=2A(par)
2.Cada letra es un número diferente.
3.Si A+B == A, cuando esta en unidades B es definitvamente 0,si no entonces es 0 ó 9.
4.El acarreo máximo es de n+1, siendo n el tamaño de los nums que están en la suma.
5.Si la suma de dos núms de n dígitos es un num de n+1 dígitos entonces el dígito más a la izquierda del resultado es un 1.

## Salidas 

```  
formato == int[]:
         + int[]
    -------------- ->(cant de “-”  == tam en dígitos del resultado)
           Int[]
“_ solution(s) found”
```

- Errores: “invalid input”
- No puede tener más de diez chars distintos
- Solo sumas.
