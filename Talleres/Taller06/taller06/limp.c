#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 10	// Cantidad de elementos en secuencia de números reales.
#define MAX 5	// Valor máximo que puede tomar cada elemento.

// Prototipos
void iniNums(float numList[], unsigned int n, unsigned int maxNum);
void impNums(const float mumList[], unsigned int n);
float promedio(float numeros[]);
float desviacionEstandar (float numeros[], float promedi);
void limpieza (float numeros[], float num, float promedi, float desv);

int main(void){
	float numeros[SIZE];
	float desv;
	float promedi;
	float num;
	
	printf("Introduzca número para calcular rango de limpieza: \n");
	scanf("%f", &num);
	
	srand(time(NULL));

	iniNums(numeros, SIZE, MAX);
	impNums(numeros, SIZE);
	promedi = promedio(numeros);
	printf("Promedio: %f\n", promedi);
	desv = desviacionEstandar(numeros, promedi);
	printf("Desviación estándar: %f\n", desv);
	limpieza(numeros, num, promedi, desv);

	return 0;
}

// Inicializa arreglo numList[] de tamaño n con números flotantes entre 0 y maxNum.
void iniNums(float numList[], unsigned int n, unsigned int maxNum){ 
	for (size_t i = 0; i < n; i++){
		numList[i] = ((float)rand() / (float)(RAND_MAX)) * maxNum; 
	} 
}

// Imprime arreglo numList[] de tamaño n.
void impNums(const float numList[], unsigned int n){
	printf("%s\n|", "Secuencia de números reales:");
	for (size_t i = 0; i < n; i++){
		printf("%6.2f|", numList[i]);
	}
	puts("");
}

float promedio (float numeros[]){
	float sum = 0; // Declaro `sum` y asigno valor 0.
	float prom; //Declaro prom.

	for (int i=0; i<SIZE; i++){ // Para i=0; i<size; i++ 
	sum += numeros[i];// Sumo número en posición i del arreglo. 
	}
	prom = sum / SIZE; // Calculo `prom` dividiendo sumatoria entre size. 
	return prom; // Retorno `prom`
}


float desviacionEstandar (float numeros[], float promedi){
	float dis; // Declaro `dis`
	float desvest;
	float sum = 0; // Declaro `sum` y asigno valor 0.
	for (int i=0; i<SIZE; i++){ // Para i=0; i<SIZE; i++
	dis = numeros[i] - promedi; // Calculo `dis` para cada número del arreglo. 
	dis *= dis; // Elevo `dis` al cuadrado. 
	sum += dis; // Sumo valor `dis` al acumulado `sum`
	}
	desvest = sum / SIZE; // Calculo `desvest`. 
	desvest = sqrt(desvest);
	return desvest; // Retorno `desvest`.
}

void limpieza (float numeros[], float num, float promedi, float desv){
	float x, y; // Declaro `x` y `y`
	x = promedi - num * desv; // Calculo `x`
	y = promedi + num * desv; // Calculo `y`
	printf("Números en el rango de limpieza (%f, %f): \n", x, y);
	for(int i=0; i<SIZE; i++){ // Para i=0; i<SIZE; i++
    	if (numeros[i] >= x && numeros[i] <= y){ // numeros[i] >= `x` y numeros[i] <= `y`
     	printf("%f \n", numeros[i]); // Sí, imprimo valor. 
		}
	}
	return 0; // Retorno 0.
}