#include <stdio.h>
#define tam 4
unsigned fijas(unsigned numS[], unsigned jug[]);
unsigned picas(unsigned numS[], unsigned jug[]);


int main(void){
    int numSecreto[tam], numJugada[tam]; // Declaro `numSecreto[]` y `numJugada[]`
    unsigned pica=0, fija=0, jugada=0, a; // Declaro `pica`, `fija`, `jugada` y `a`

    printf("Ingrese número secreto:\n"); // Solicito número secreto
    numerosNorepetidos(numSecreto, tam); // Llamo función `numerosNorepetidos`

    do{
    printf("Ingrese jugada:\n"); //Solicito jugadas
    numerosNorepetidos(numJugada, tam); //Llamo función `numerosNorepetidos`

    pica = picas(numSecreto, numJugada); // Llamo función `picas`
    fija = fijas(numSecreto, numJugada); // Llamo función `fijas`
    jugada++; // Incremento `jugada` en 1
    
    printf("Desea seguir jugando? Si la respuesta es afirmativa, marque 1, de lo contrario, marque 0. \n"); // Confirmar continuar juego 
    scanf("%u", &a); // Asigno valor a `a`
    if(a==0){ // Si `a` = 0
        printf("El juego ha finalizado. El número de jugadas fue: %u", jugada); // Finalizo juego e imprimo jugadas // Finalizo juego e imprimo jugadas
        return 0;
    }

    } while (fija<tam); // Mientras `fijas`<tam

    printf("El juego ha finalizado. El número de jugadas fue: %u", jugada); // Finalizo juego e imprimo jugadas
}


unsigned fijas(unsigned numS[], unsigned jug[]){
    unsigned i, fij=0; // Declaro `i`, `fijas`=0.
    for (i=0; i<4; i++){ // Para `i`=0; `i`<4; `i`++
        if (numS[i] == jug[i]){ // Si `numS[i]` = `jug[i]`
        fij++; // `fij`++
        }
    }
    return fij; // Retorno `fij`
}

unsigned picas(unsigned numS[], unsigned jug[]){
    unsigned i, j, pic=0; // Declaro `i`, `j`, `pic`=0.
    for (i=0; i<4; i++){ // Para `i`=0; `i`<4; `i`++
        for (j=0; j<4; j++){ // Para `j`=0; `j`<4, `j`++
            if (numS[i]==jug[j] && i !=j){ // Si `numS[i]` = `jug[j]` y `i` != `j`
            pic++; // `pic`++
            }
        }
    }
    return pic; //Retorno `pic`
}