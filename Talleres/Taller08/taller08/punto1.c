#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// funciones
void suma(int numeros[], unsigned n);

int main(void){
    unsigned n;
    int numeros[] = {0};

    do{
        printf("Cuantos numeros tiene el vector?: ");
        scanf("%u", &n);
    }while(n > 10);

    suma(numeros, n);
}
void suma(int numeros[], unsigned n){
    srand(time(NULL));
    for(int i = 0; i < n; i++){
        numeros[i] = rand() % 20;
    }
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++){
            if(numeros[i] == numeros[j]){
                numeros[i] = rand() % 20;
            }
        }
    }
    int nMax, sumT = 0;

    for(int i = 1; i < n; i++){
        if(numeros[i] > numeros[nMax]){
            nMax = i;
        }
        else{
            nMax = nMax;
        }
    }
    for(int i = 0; i < n; i++){
        sumT += numeros[i];
    }
    if(numeros[nMax] == (sumT-numeros[nMax])){
        printf("Si, el numero es: %d", numeros[nMax]);
    }
    else{
        printf("NO");
    }
}