#include <stdio.h>

#define tam 4

int main(void){
    int numSecreto[tam], numJugada[tam];
    unsigned pic=0, fij=0;

    printf("Ingrese número secreto:\n");
    numerosNorepetidos(numSecreto, tam);
    
    do{
    printf("Ingrese jugada:\n");
    numerosNorepetidos(numJugada, tam);

    pic = picas(numSecreto, numJugada);
    fij = fijas(numSecreto, numJugada);

    } while (fij<tam);


}