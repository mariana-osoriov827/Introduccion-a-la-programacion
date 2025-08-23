#include <stdio.h>

int main(void){

double SB, SN, AC, SH, AS, AP, ACC, SE; //Declaro variables `SB`, `SN`, `AC`, `SH`, `AS`, `ASj`, `AP`, `APj`, `ACC`, `SE`.
unsigned int HS; //Declaro variable `HS`.

printf("Se desea calcular el salario neto de Juan, para esto es necesario saber su salario por hora, introduzca valor:\n"); //Pregunto salario por hora de Juan.
scanf("%lf", &SH); //Asigno valor a variable `SH`.

printf("Además de esto, se requiere saber cuántas horas trabajó en la semana, introduzca valor:\n"); //Pregunto horas trabajadas. 
scanf("%u", &HS); //Asigno valor a variable `HS`.

printf("Por último, introduzca el número de veces que Juan asistió a las instalaciones de Cafam ubicadas en la autopista norte\n"); //Pregunto cantidad de veces que asistió a las instalaciones.
scanf("%lf", &AC); //Asigno valor a variable `AC`.

SB = HS * SH; //Calculo `SB`
AS = (SB * 0.135) / 3; //Calculo `AS`.
AP = (SB * 0.105) / 3; //Calculo `AP`.
ACC = AC * 5000; //Calculo `ACC`.
SE = SB * 0.05; //Calculo `SE`.

SN = SB - (AS + AP + ACC) + SE; //Calculo `SN`.
printf("Tomando en cuenta que el salario bruto de Juan es de %lf, que su aporte a los sistemas de salud es de %lf, su aporte a pensiones es de %lf, sus gastos de ingreso a Cafam fueron de %lf y el subsidio de educación fue de %lf, sus ingresos netos fueron de: %lf", SB, AS, AP, ACC, SE, SN); //Imprimo resultados. 

return 0;
}