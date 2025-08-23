#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void esOrdenCorrecto(int f[3][3], unsigned mar, unsigned m, unsigned n);

int main() {
    FILE *cfPtr;
    if ((cfPtr = fopen("formaciones.txt", "r")) == NULL) {
      puts("File could not be opened");
    } 

    else { 
    unsigned columnas, filas, margen;
    fscanf(cfPtr, "%u %u %u", &margen, &filas, &columnas); 
    printf("Margen: %u Filas: %u Cantidad de soldados: %u\n", margen, filas, columnas);
    int fi[filas][columnas];
    while (!feof(cfPtr)){
    for(int i=0; i<filas; i++){
      for(int j=0; j<columnas; j++){
        fscanf(cfPtr, "%d", &fi[i][j]); 
        printf("%d ", fi[i][j]);
      }
      printf("\n");
    }
   }
   esOrdenCorrecto(fi, margen, columnas, filas);
  }
  fclose(cfPtr);
  return 0;
}

void esOrdenCorrecto(int f[3][3], unsigned mar, unsigned m, unsigned n){
    for(int i=0; i<n-1; i++){
        for(int j=1; j<m; j++){
        if(fabs(f[i][j] - f [i][j-1]) > mar){
            printf("El orden es incorrecto. ");
            exit(EXIT_SUCCESS);
        }
        if(i!=0 && fabs(f[i][j] - f [i-1][j]) > mar){
            printf("El orden es incorrecto. ");
            exit(EXIT_SUCCESS);
        }
        if(i!=0 && fabs(f[i][j] - f [i+1][j]) > mar){
            printf("El orden es incorrecto. ");
            exit(EXIT_SUCCESS);
        }
        if(fabs(f[i][j] - f [i][j+1]) > mar){
            printf("El orden es incorrecto. ");
            exit(EXIT_SUCCESS);
        }
        }
    }
    printf("El orden es correcto. ");
    exit(EXIT_SUCCESS);
}