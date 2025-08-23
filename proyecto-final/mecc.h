#ifndef MECC_H
#define MECC_H

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <math.h>
#ifdef _WIN32
  #include "lib/curses.h"
#else
  #include <curses.h>
#endif
#include <sys/time.h>

#define COLUMNAS 50
#define FILAS 5
#define LARGO 5

typedef enum {
        PAR_OK = 1,
        PAR_WAR,
        PAR_ERR,
} ParColor;

typedef struct {
  char nombre[20];
  unsigned AdjWPM;
  unsigned a;
  unsigned cantWord;
  char palabras[10][5];
} Leccion;

typedef struct {
  char letra;
  float tiempo;
  int acierto;
} Caracter;

void confTerm(void);
void demoDeltaT(WINDOW *campPtr, WINDOW *notfPtr, Caracter usuario[][COLUMNAS], double p[]);
void finTerm(WINDOW *campPtr, WINDOW *notfPtr);
int nombreLeccion(char nombre[], WINDOW *campPtr);
Leccion cargarLeccion(char nombre[], WINDOW *campPtr);
void imprimirLeccion(Leccion lec, Caracter usuario[][COLUMNAS], WINDOW *campPtr, double p[]);
void calcularResultados(double p[], Leccion lec);
int reporte(double p[], Leccion lec, WINDOW *campPtr);
void asignarPuntos(int puntos, int r);

#endif