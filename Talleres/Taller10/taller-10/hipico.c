#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define JINETES 7
#define CARRERAS 10

typedef struct {
	int id;
	char nombre[JINETES];
	int carr[CARRERAS];
	int puntaje;
} Jinete;

void generarCarreras(Jinete *participantes, unsigned n, unsigned jin);
void imprimirCarreras(Jinete participantes[JINETES], int pod[3][CARRERAS], unsigned n, unsigned jin);
char * ganador(int podios[3][CARRERAS], Jinete participantes[JINETES]);
void calcularPuntos(int pod[3][CARRERAS], Jinete participantes[JINETES]);
void reportarTorneo(Jinete participantes[JINETES], unsigned jin);

int main(void){
	Jinete participantes[JINETES];
	const char * nombres[JINETES] = { "JuanR", "MiguelP", "AnaM", "LuisG", "PedroJ", "LinaQ", "CarlosS"};
	int podios[3][CARRERAS];

	srand(time(NULL));


	for(int i=0; i<JINETES; i++){
		participantes[i].id = i;
		strcpy(participantes[i].nombre, nombres[i]);
	}

	for (int i=0; i<JINETES; i++){
	    generarCarreras(&participantes[i], CARRERAS, JINETES);
	}

	imprimirCarreras(participantes, podios, CARRERAS, JINETES);
	ganador(podios, participantes);
	calcularPuntos(podios, participantes);
	reportarTorneo(participantes, JINETES);
}

void generarCarreras(Jinete *par, unsigned n, unsigned jin){
	for (unsigned i = 0; i < jin; i ++){
		for(unsigned j = 0; j < n; j ++){
		par[i].carr[j] = (rand() % 100) + 100;
		}
	}
}

void imprimirCarreras(Jinete participantes[JINETES], int pod[3][CARRERAS], unsigned n, unsigned jin){
	int aux=0, aux2=0;
	int car[jin], ji[jin];
	for (unsigned i = 0; i < n; i ++){
		for (unsigned j=0; j < jin; j++){
			ji[j] = participantes[j].id;
			car[j] = participantes[j].carr[i];
		}
		for (unsigned j = 0; j < jin; j++) {
        	int indiceMayor = j;
        	for (int k = j+1; k < jin; k++)
            if (car[k] < car[indiceMayor])

                indiceMayor = k;
            if (j != indiceMayor){
                double aux = car[j], aux2=ji[j];
				   car[j] = car[indiceMayor];
				   ji[j] = ji[indiceMayor];
				   car[indiceMayor] = aux;
				   ji[indiceMayor] = aux2;
                }
            for(unsigned x=0; x < 3; x++){
			pod[x][i] = ji[x];
            }
	}
	}
	
	puts("            |        1ro           |        2do           |         3ro          |");
	puts("Carrera No. | Nombre  | Tiempo [s] | Nombre  | Tiempo [s] | Nombre  | Tiempo [s] |");
	for (unsigned i = 0, j=0; i < n; i++){
		printf("%11d |", i+1);
		printf("%8s |", participantes[pod[j][i]].nombre);
		printf("%11u |", participantes[pod[j][i]].carr[i]);
		printf("%8s |", participantes[pod[j+1][i]].nombre);
		printf("%11u |", participantes[pod[j+1][i]].carr[i]);
		printf("%8s |", participantes[pod[j+2][i]].nombre);
		printf("%11u |\n", participantes[pod[j+2][i]].carr[i]);
	}
}
char * ganador(int podios[3][CARRERAS], Jinete participantes[JINETES]){
    unsigned victorias[JINETES] = {0};

    for (unsigned j = 0; j < CARRERAS; j++){
        int i = 0;
        victorias[podios[i][j]]++;
    }

    unsigned maxVic = 0;
    unsigned idGan;

    for (unsigned i = 0; i < JINETES; i++){
        if (victorias[i] > maxVic){
            maxVic = victorias[i];
            idGan = i;
        }
    }
    return participantes[idGan].nombre;
}

void calcularPuntos(int pod[3][CARRERAS], Jinete participantes[JINETES]){
    for (int j = 0; j < JINETES; j++){
        participantes[j].puntaje=0;
    }
    for (int j = 0, i=0; j < CARRERAS; j++){
            participantes[pod[i][j]].puntaje += 5;
            if (participantes[pod[i+1][j]].carr[j]-participantes[pod[i][j]].carr[j]>5){
                participantes[pod[i][j]].puntaje++;
            }
            participantes[pod[i+1][j]].puntaje += 3;
            participantes[pod[i+2][j]].puntaje += 1;
        }
}

void reportarTorneo(Jinete participantes[JINETES], unsigned jin){
	unsigned idJin[JINETES];

	for (unsigned i = 0; i < jin; i++){
		idJin[i] = i;
	}

	for (unsigned i = 0; i < jin - 1; i++){
		unsigned posMax = i;
		for (unsigned j = i + 1; j < jin; j++){
			if (participantes[j].puntaje > participantes[posMax].puntaje){
				posMax = j;
			}
		}

		if (posMax != i){
			Jinete aux = participantes[i];
			participantes[i] = participantes[posMax];
			participantes[posMax] = aux;
		}
	}

	puts("Pos. |  Nombre | Puntos |");
	for (unsigned i = 0; i < jin; i++){
		printf("%4u | %7s | %6u |\n", i+1, participantes[i].nombre, participantes[i].puntaje);
	}
}