#include <stdio.h>

int main() {
    unsigned int num, sum=0, cif; // Declaro variables `num`, `cif`, `sum`
    printf("Escriba número entero: "); //Solicito valor a usuario.
    scanf("%u", &num); //Asigno valor a `num`.
    
    cif = num; // Asigno valor `num` a `cif`.
    do{
        do{
            sum += cif % 10; // Sumo el módulo 10 de `cif` a `sum`
            cif /= 10; // Asigno `cif` dividido en 10
            printf("Actualización suma: %u \n", sum); // Imprimo resultado. 
        } while (cif > 0); // Para `cif` > 0 
            cif = sum; // Asigno valor `num` a `cif`.
            sum = 0; // Asigno valor 0 a `sum`
            sum += cif % 10; // Sumo el módulo 10 de `cif` a `sum`
            cif /= 10; // Asigno `cif` dividido en 10
            printf("Actualización suma: %u \n", sum); // Imprimo resultado. 
    } while (cif > 0); // Para `cif` >= 10 
    
    if (sum == 9){ // Si `sum` == 9
        printf ("El número %u es múltiplo de 9.", num); // Sí, imprimo resultado de múltiplo de 9.
    }
    else if (sum != 9){ // Sino, si `sum` != 9 
    printf("El número %u no es múltiplo de 9.", num); // Imprimo resultado de no es múltiplo de 9.
    }
    return 0;
}