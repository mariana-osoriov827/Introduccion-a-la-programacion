#include <stdio.h>
#define tam 4

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
    if(a==0){ //Si `a` = 0
        printf("El juego ha finalizado. El número de jugadas fue: %u", jugada); // Finalizo juego e imprimo jugadas // Finalizo juego e imprimo jugadas
        return 0;
    }

    } while (fija<tam); // Mientras `fijas`<tam

    printf("El juego ha finalizado. El número de jugadas fue: %u", jugada); // Finalizo juego e imprimo jugadas
}