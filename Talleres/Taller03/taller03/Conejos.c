#include <stdio.h>

int main(){
    int ayer, hoy, man, d=0; // Declaro variables `ayer`, `hoy`, `man`, `d=0`.
    
    printf("Por favor introduzca la población de conejos de ayer: "); // Solicito población de ayer.
    scanf("%d", &ayer); //Asigno valor a variable `ayer`.
    printf("Por favor introduzca la población de conejos de hoy: "); // Solicito población de hoy.
    scanf("%d", &hoy); // Asigno valor a variable `hoy`.
    
    man = ayer + hoy; // Calculo `man`.
    if (man > 70000){ // Si `man` > 70000.
        printf("ALERTA: Mañana se debe realizar la exportación de 40000 conejos a la isla vecina."); // Imprimir mensaje de alerta.
    }

    else if (man <= 70000){ // Si `man` <= 70000.
         do { 
            man = ayer + hoy; // Calculo `man`.
            ayer = hoy; // Reasigno valor `ayer`.
            hoy = man; // Reasigno valor `hoy`.
            d++; // Incremento `d` en 1. 
         }while (man <= 70000); // Para `man` <= 70000.
        printf("Faltan %d días para que sea necesaria la exportación de 40000 conejos. a la isla vecina.", d); // Imprimo resultados.
        }
    return 0; // Retorno 0.
}