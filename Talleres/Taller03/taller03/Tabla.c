#include <stdio.h>
int main (void){
    unsigned int mul, num=1, pow=1; //Declaro `num`= 1, `pow`= 1, `mul`.

   while (num <= 9){ //Para Para `num` <= 9.
        while (pow <= num){ //Para `pow` <= `num`.
            mul = num * pow; // `mul` = `num` * `pow`
            printf("%u ", mul); // Imprimo `mul` 
            pow++; //Incremento en 1 a `pow`.
        }
        num++; // Incremento en 1 a `num`. 
        pow = 1; // Asigno valor 1 a `pow`.
        printf ("\n"); // Inicio nueva línea de texto.
   }
   return 0;
}