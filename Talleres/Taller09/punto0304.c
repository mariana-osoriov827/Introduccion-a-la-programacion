#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define TAMAÑO 4
// Funcio adiccional para que el numero secreto no tenga digitos repetidos.
int NoNumRepetido(int numbSecret[], int aleatorio);
int numPicas(int numbSecret[], int numbPlayer[]); // Funcion Punto 3.
int numFijas(int numbSecret[], int numbPlayer[]); // Funcion punto 4

int main(void)
{
    int numAleat;
    int stop;
    int numbSecret[TAMAÑO] = {0};
    int a[TAMAÑO] = {0};

    srand(time(NULL));
    // Creacion de numero de 4 digitos no repetidos
    for (int i = 0; i < TAMAÑO; i++)
    {
        do
        {
            stop = 0;
            numAleat = rand() % 10;
            stop = NoNumRepetido(numbSecret, numAleat);
        } while (stop);
        numbSecret[i] = numAleat;
        printf("%d", numbSecret[i]);

        int numUsuario;
        do
        {
            
            printf("\nPara jugar, tienes que escribir un numero de cuatro digitos: ");
            scanf("%1d", &numUsuario);
        } while (NoNumRepetido(a, numUsuario));
        a[i] = numUsuario;

    }

    printf("\nNumero de picas: %d", numPicas(numbSecret, a));
    printf("\nNumero de Fijas: %d", numFijas(numbSecret, a));
}
// Funcion adiccional
int NoNumRepetido(int numbSecret[], int aleatorio)
{
    int stop = 0;
    for (int j = 0; j < TAMAÑO; j++)
    {
        if (numbSecret[j] == aleatorio)
        {
            stop = 1;
        }
    }
    return stop;
}
// Funcion Punto 3.
int numPicas(int numbSecret[], int numbPlayer[])
{
    int Picas = 0;
    for (int i = 0; i < TAMAÑO; i++)
    {
        for (int j = 0; j < TAMAÑO; j++)
        {
            int stop = j;
            if (numbSecret[i] == numbPlayer[j] && i != j)
            {
                Picas++;
            }
        }
    }
    return Picas;
}
// Función punto 4.
int numFijas(int numbSecret[], int numbPlayer[])
{
    int Fijas = 0;
    for (int i = 0; i < TAMAÑO; i++)
    {
        if (numbSecret[i] == numbPlayer[i])
        {
            Fijas++;
        }
    }
    return Fijas;
}