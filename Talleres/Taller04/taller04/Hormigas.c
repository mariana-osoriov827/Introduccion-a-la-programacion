#include <stdio.h>
int main (void){
    int rojas, enanas, m=0; // Declaro variables. 
    float t1, t2;
    printf("Por favor introduzca la cantidad de hormigas rojas: "); // Solicito valor hormigas rojas al usuario.
    scanf("%d", &rojas); // Asigno valor a `rojas`.
    printf("Por favor introduzca la cantidad de hormigas enanas: "); // Solicito valor hormigas enanas al usuario. 
    scanf("%d", &enanas); // Asigno valor a `enanas`.
    
    if (rojas >= enanas){ // Si `rojas` >= `enanas`
    printf("Los datos no corresponden con lo solicitado"); // Sí, imprimir mensaje de error.
    } 
    else {
    printf("Por favor introduzca la tasa de crecimiento de hormigas rojas: "); // Solicito valor tasa de crecimiento hormigas rojas al usuario.
    scanf("%f", &t1); // Asigno valor a `t1`.
    printf("Por favor introduzca la tasa de crecimiento de hormigas enanas: "); // Solicito valor tasa de crecimiento hormigas enanas al usuario.
    scanf("%f", &t2); // Asigno valor a `t2`.    
    
    if (t1 <= t2){ // Si `t1` < `t2` 
    printf("Los datos no corresponden con lo solicitado"); // Sí, imprimir mensaje de error.
    }
    else {

    do {
        rojas = rojas * (1 + t1/100); //  `rojas` = `rojas` * (1+`t1`)
        enanas = enanas * (1 + t2/100); // `enanas` = `enanas` * (1+`t2`)
        m++; // m++
        
        if (rojas > 20000){ // Si rojas > 20000
        t1 = t1 * 0.5; // Sí, `t1` = `t1` * 0.5
        }
        if (enanas > 20000){ // Si enanas > 20000
        t2 = t2 * 0.5; // Sí, `t2` = `t2` * 0.5
        }
        if (enanas > 20000){ // Si `enanas` > 20000
        enanas = enanas * 0.5; // Sí, `enanas` = `enanas` * 0.5
        }

    } while (rojas <= enanas); // Para `rojas`<=  `enanas` 
    printf("El número de meses necesario para que la población A supere o sea igual a la población B es %d meses y las cantidades de hormigas serán de %d y %d respectivamente", m, rojas, enanas); // Imprimo resultados. 
    return 0;
}
}
}