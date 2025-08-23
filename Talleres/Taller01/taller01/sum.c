#include <stdio.h>

int main(void){
    int dig, sum, u, d, c, um, dm, dig2; //Declaro variables `dig`, `sum`, `u`, `d`, `c`, `um`, `dm`, `dig2`

    printf ("Ingrese un número entero de no más de 5 dígitos: "); //Solicito número al usuario.
    scanf("%d", &dig); //Asigno valor a variable `dig`.

    u = dig % 10; //Calculo primer dígito
    dig2 = dig / 10; //Calculo `dig2`
    d = dig2 % 10; //Calculo segundo dígito
    dig2= dig2 / 10; //Calculo `dig2`
    c = dig2 % 10; //Calculo tercer dígito
    dig2 = dig2 / 10; //Calculo `dig2`
    um = dig2 % 10; //Calculo cuarto dígito
    dig2 = dig2 / 10; //Calculo `dig2`
    dm = dig2 % 10; //Calculo quinto dígito

    sum = u + d + c + um + dm; //Calculo `sum`
    
    printf ("El número ingresado fue %d, la sumatoria de sus cifras es %d.", dig, sum); //Imprimo resultado
    return 0;
}