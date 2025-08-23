#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define JINETES 7
#define CARRERAS 10

void generarCarreras(unsigned int reCarr[], unsigned int n, unsigned int jin);
void imprimirCarreras(unsigned int reCarr[], unsigned int n, const char *nom[]);
const char* nombreJinete(unsigned int resulCarre[], unsigned int n, unsigned int m, const char * nom[]);
int* puntuacionJinetes (unsigned int reCarr[], unsigned int n, unsigned int m, const char *nom[]);
void reporte(int a[], unsigned int n, const char *nom[]);

int main(void){
	unsigned int resulCarre[CARRERAS * 4];
	const char * nombres[JINETES] = { "JuanR", "MiguelP", "AnaM", "LuisG", 
		"PedroJ", "LinaQ", "CarlosS"};

	// Inicializa generador de números aleatorios
	srand(time(NULL)); 

	generarCarreras(resulCarre, CARRERAS * 4, JINETES);
	imprimirCarreras(resulCarre, CARRERAS * 4, nombres);
	nombreJinete(resulCarre, CARRERAS, JINETES, nombres);
	int* punt = puntuacionJinetes(resulCarre, CARRERAS, JINETES, nombres);
	reporte(punt, JINETES, nombres);
}

void generarCarreras(unsigned int reCarr[], unsigned int n, unsigned int jin){
	for (unsigned int i = 0; i < n; i += 4){
		reCarr[i] = rand() % jin;
		reCarr[i + 1] = (rand() % 100) + 100;

		// Jinete no puede ocupar dos puestos a la vez
		do{
			reCarr[i+2] = rand() % jin;
		}while(reCarr[i] == reCarr[i + 2]); 

		// No es posible "empate" por tiempo
		do{
			reCarr[i + 3] = (rand() % 100) + 101;
		}while(reCarr[i+1] >= reCarr[i + 3]);
	}
}

void imprimirCarreras(unsigned int reCarr[], unsigned int n, const char *nom[]){
	puts("            |        1ro           |        2do           |");
	puts("Carrera No. | Nombre  | Tiempo [s] | Nombre  | Tiempo [s] |");
	for (unsigned int i = 0; i < n; i += 4){
		printf("%11d |", i/4 + 1);
		printf("%8s |", nom[reCarr[i]]);
		printf("%11u |", reCarr[i + 1]);
		printf("%8s |", nom[reCarr[i+2]]);
		printf("%11u |\n", reCarr[i + 3]);
	}
}

const char* nombreJinete(unsigned int reCarr[], unsigned int n, unsigned int m, const char *nom[]){
    unsigned int ganador[n]; // Declaro `ganador`
    unsigned int vecesGanadas[m]; // Declaro `vecesGanadas`
	unsigned int i, j; // Declaro `i` y `j`
	
	for(i=0; i < n; i++){ // Para `i`=0, `i`<`n`, `i`++
	    ganador[i] = reCarr[4*i]; // Calculo `ganador` de cada carrera
	}
	
	for(i=0; i<m; i++){ // Para `i`=0, `i`<`m`, `i`++
	    vecesGanadas[i] = 0; // Asigno 0 a `vecesGanadas[i]` 
	    for(j=0; j<n; j++){ // Para j=0, j<n, j++
	        if(ganador[j]==i){ // Si `ganador[i]` = `i`
	            vecesGanadas[i]++; // Incremento `vecesGanadas[i]`
	        }
	    }
	}
	unsigned int mayor, gana; // Declaro `mayor` y `gana`
	mayor = vecesGanadas[0]; // Asigno `vecesGanadas[0]` a `mayor`
	gana = 0; // Asigno 0 a `gana`
	
	for(i=0; i<m; i++){ //Para `i`=0, `i`<`m`, `i`++
	    if(vecesGanadas[i] > mayor){ //Si `vecesGanadas[i]`>`mayor`
	        mayor = vecesGanadas[i]; // Asigno vecesGanadas[i]` a `mayor`
	        gana = i; // Asigno `i` a `gana`
	    } 
	}
	return nom[gana]; // Retorno `nom[gana]`
}

int* puntuacionJinetes(unsigned int reCarr[], unsigned int n, unsigned int m, const char *nom[]){
	unsigned int i, j; // Declaro `i`, `j`
	static int puntuacion[JINETES]; // Declaro c
	for(i=0; i<m; i++){ // Para `i`=0, `i`<`m`, `i`++
	    puntuacion[i]=0; // Asigno `puntuacion`=0
		for(j=0; j<n; j++){ // Para `j`=0, `j`<`n`, `j`++
			if (reCarr[4*j] == i){ // Si `reCarr[4*j]` = `i`
				puntuacion[i] += 5; // Sumo 5 a `puntuacion[i]`
			}
			if(reCarr[4*j] == i && reCarr[4*j+3] - reCarr[4*j+1] > 5){ // Si `reCarr[4*j]` = i y si `reCarr[4*j+3]` 
				puntuacion[i] += 1; // Sumo 1 a `puntuacion[i]`
			}
			if (reCarr[4*j+2] == i){ // Si `reCarr[4*j+2]` = i
				puntuacion[i] += 3; // Sumo 3 a `puntuacion[i]`
			}
		}
	}
	return puntuacion; // Retornar `puntuacion`
}

void reporte(int a[], unsigned int n, const char *nom[]){
    int indiceMayor, i, j, v[n]; // Declaro `i`, `j`, `v[n]`
    printf("\n"); // Imprimo espacio
    for (i=0; i<n; i++){ // Para `i`=0, `i`<`n`, `i`++
        v[i] = i; // Asigno `i` a `v[i]`
    }
    printf("|     Nombre     |    Puntuación    |\n"); // Imprimo primera línea tabla
    for (i = 0; i < n; i++) { // Para `i`=0, `i`<`n`, `i`++
        indiceMayor = i; // Asigno `i` a `indiceMayor`
        for (j = i+1; j < n; j++) // Para `j`= `i`+1, `j`<`n`, `j`++
            if (a[j] > a[indiceMayor]) // Si `a[j]` = `a[indiceMayor]`
                indiceMayor = j; // Asigno `j` a `indiceMayor`
        
            if (i != indiceMayor){ // Si `i` != `indiceMayor`
                double aux = a[i], aux2=v[i]; // Declaro `aux` = `a[i]` y `aux2` = `v[i]`
                a[i] = a[indiceMayor]; // Asigno `a[indiceMayor]` a `a[i]`
                v[i] = v[indiceMayor]; // Asigno `v[indiceMayor]` a `v[i]`
                a[indiceMayor] = aux; // Asigno `aux` a `a[indiceMayor]`
                v[indiceMayor] = aux2; // Asigno `aux2` a `v[indiceMayor]` 
            }
    }
    for (i=0; i<n; i++){ // Para `i`=0, `i`<`n`, `i`++
        printf("|%11s     |%11d       |\n", nom[v[i]], a[i]); // Imprimo línea de tabla 
    }
}