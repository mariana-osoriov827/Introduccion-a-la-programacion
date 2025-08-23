# Taller08

## 1. Suma (30%)
Escriba la función suma que reciba como parámetro un entero positivo n<=10 que indica la cantidad de números  en el vector, y un vector numero con números enteros. La función debe determinar si alguno de estos números es igual a la suma de los restantes n-1. En caso de una respuesta afirmativa debe decir cuál es.

```Text 
Ejemplo 1
    n=4
    numero | 5 | 15 | 6 | 4 | 
    salida : SI 15
```

```Text 
Ejemplo 2 
    n=6
    numero | 1 | 2 | 3 | 4 | 5 | 16 | 
    salida : NO
```

## 2. Maquina (30%)
Una máquina tiene dos botones llamados A y B. En un tablero digital se muestra un número. Al presionar A el número se  duplica y al presionar B se le suma uno. El número inicial de la máquina siempre es cero. Elabore una función maquina que reciba como entrada el número final que aparece en el tablero y encuentre e imprima una secuencia de As y Bs con longitud mínima con la cual se pueda obtener ese número. La función debe devolver la longitud mínima.

```Text 
Ejemplo 1
    Entrada : (Número final en el tablero ) 11 
    Salida: (secuencia de As y Bs) BAABAB
    Longitud mínima a devolver: 6
```

```Text
Ejemplo 2
    Entrada : (Número final en el tablero ) 351 
    Salida: (secuencia de As y Bs) BAABAABABABABAB
    Longitud mínima a devolver: 15
```

## 3. Subcadena más larga (40%)
Escriba la función subcadena que reciba como entrada un vector de caracteres llamado letras y un valor n que indica el número de caracteres en el vector, la función debe determinar el tamaño de la subcadena más grande que tenga todos sus caracteres en orden ascendente e imprimir en la función la subcadena.

```Text
Ejemplo 1
    n=9
    letras | t | i | r | a | b | u | z | o | n |
    Salida: 4
    (La subcadena ascendente más larga es abuz que tiene longitud 4 
```

```Text
Ejemplo 2
    n=5
    letras | a | r | e | p | a |
    Salida: 2
    (la subcadena ascendente más larga puede ser ar o ep que tienen longitud 2)
```

# Funcion 1: `Suma` 

Determina si uno de los numeros es igual a la suma de los restantes n-1. En caso de una respuesta afirmativa debe decir cuál es.

## Refinamineto 1

### Entradas

- Tamaño del arreglo como numero positivo menor o igual a 10.
- Vector para numeros aleatorios.

### Salida

- Sí, y numero, o No.

### Pseudo-código

1. Creo semilla para numeros aleatorios.
1. Recorro arreglo de numeros y asigno un numero aleatorio del 1 - 20.
1. Comparo numeros del arreglo para que no hallan repetidos.
1. Defino variable para auxiliar numero mayor y variable para sumatoria de numeros e inicializo en cero.
1. Recorro arreglo de numeros desde posicion 1.
   1. Si valor del número es mayor al maximo numero.
      1. Asigno valor del numero a maximo numero.
1. Recorro arreglo numeros.
   1. Defino variable sumaTotal y sumo el numero de cada posicion.
1. Si numero maximo es igual a la suma menos numero maximo.
   1. Imprimo enunciado: Si, y el numero.
   1. Si no se cumple, Imprimo No.

## Refinamineto 2

### Entradas

- `n`: Tamaño del arreglo positivo menor o igual a 10.
- `numeros`: arreglo para numeros aleatorios.

### Salida

- Sí, y numero, o No.

### Pseudo-código

1. Declaro semilla `srand()` para numeros aleatorios.
1. Para `i` desde `0`; hasta `i` menor a `n`; incremento `i` en `1`.
   1. Asigno valor aleatorio a cada posicion.
1. Comparo numeros del arreglo para que no hallan repetidos.
1. Defino variable `nMax` para numero mayor y `sumT` e inicializo en cero.
1. Para `i` desde `1`; hasta `i` menor a `n`; incremento `i` en `1`.
   1. Si valor de `numeros[i]` es mayor a `numeros[nMax]`.
      1. Asigno valor de `numeros[i]` a `numeros[nMax]`.
1. Para `i` desde `0`; hasta `i` menor a `n`; incremento `i` en `1`.
   1. Adiciono a `sumT` el numero de cada posicion.
1. Si `numeros[nMax]` es igual a `sumT` menos `numeros[nMax]`.
   1. Imprimo enunciado: Si, y `numeros[nMax]`.
   1. Si no se cumple, Imprimo No.


## Refinamiento `maquina`

### Entradas
`num`: entero que representa número final que se muestra en el tablero digital. 

### Salidas
`i`: entero que representa longitud mínima.

1. Declarar arreglo tipo char `sec`.
1. Declarar e inicializar entero `i`=0.
1. Mientras `num`>=0.
    1. Si `num` es par.
        1. Asignar A a la posición i de `sec`.
        1. Dividir `num` entre 2.
    1. Si `num` es impar.
        1. Asignar B a la posición i de `sec`.
        1. Disminuir `num` en 1.
    1. Incrementar `i` en 1. 
1. Imprimir `sec`
1. Imprimir `i`
1. Retornar `i`

## Refinamiento `subcadena`

### Entradas
`letras`: vector de caracteres. 
`n`: número de caracteres en el vector. 

### Salidas
void. 

1.Declaro `i`, `aux`, `cad=0`, `cad2=0`.
1. Para `i`=0; `i`<`n`, `i`++
    1. Si `letras[i]` < `letras[i]`
       1. Incremento `cad` en 1
    1. Sino, Si `cad` > `cad2`
        1. Asigno `cad` a `cad2`
        1. Asigno `i` a `aux`
        1. Asigno `1` a `cad`
    1. Sino, Si `cad` > `cad2`
        1. Asigno `cad` a `cad2`
        1. Asigno `i` a `aux`
1. Imprimo longitud de cadena
1. Imprimo subcadena 