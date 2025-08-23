# Taller09

Un juego muy conocido es picas y fijas, el cual consiste en tratar de adivinar un número en la menor cantidad de intentos. En cada intento, el jugador dice 4 dígitos (no repetidos) y el oponente le da pistas de cuántos aciertos tuvo, sin indicarle cuales fueron, de la siguiente forma: Si algún dígito que dice el jugador se encuentra dentro del número a adivinar, pero no está en la posición correcta, se llama PICA. 
Si el digito se encuentra en la posición adecuada, se llama FIJA. Así, las pistas serán la cantidad de PICAS y la cantidad de FIJAS que se tienen. El juego termina cuando algún jugador tiene 4 FIJAS (4 dígitos en el orden adecuado).

## Refinamiento función: `picas`
Recibe dos arreglos (el primero corresponde al número secreto y el segundo a la jugada de un jugador) y retorna la cantidad de PICAS.

### Entradas
`numS`: Arreglo que corresponde al número secreto.
`jug`: Arreglo que corresponde a la jugada de un jugador. 

### Salidas
`pic`: Entero que almacena cantidad de picas.

### Pseudocódigo
1. Declaro `i`, `j`, `pic`=0.
1. Para `i`=0; `i`<4; `i`++
    1. Para `j`=0; `j`<4, `j`++
        1. Si `numS[i]` = `jug[j]` y `i` != `j`
        1. `pic`++
1. Retorno `pic`

## Refinamiento función: `fijas`
Recibe dos arreglos (el primero corresponde al número secreto y el segundo a la jugada de un jugador) y retorna la cantidad de FIJAS.

### Entradas
`numS`: Arreglo que corresponde al número secreto.
`jug`: Arreglo que corresponde a la jugada de un jugador. 

### Salidas
`fij`: Entero que almacena cantidad de fijas.

### Pseudocódigo
1. Declaro `i`, `fij`=0.
1. Para `i`=0; `i`<4; `i`++
    1. Si `numS[i]` = `jug[i]`
    1. `fij`++
1. Retorno `fij`
