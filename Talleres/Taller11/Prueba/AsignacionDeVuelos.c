#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CANTV 4
#define CANTA 5
#define CANTP 5

typedef struct {
    unsigned id;
    unsigned hora;
    char *cd[15];
    unsigned tv;
    unsigned ct;
    unsigned ev;
}Vuelos;

typedef struct {
    unsigned ta;
    unsigned cs;
    unsigned tv;
    unsigned disp;
}Aeronaves;

typedef struct{
    char *nom[15];
    unsigned ta[5];
    unsigned disp;
    unsigned tv;
}Pilotos;

char *buscarPiloto(Pilotos p[CANTP], Aeronaves a);
unsigned asignarAeronave(Vuelos v[CANTV], Aeronaves a[CANTA], Pilotos p[CANTP]);

int main(){
    Vuelos v[4];
    Aeronaves a[6];
    Pilotos p[5];

    FILE *cfPtr;
    if ((cfPtr = fopen("datos.txt", "r")) == NULL) {
      puts("File could not be opened");
    } 
    else {  
    printf("Vuelos: \n");
    for(int i=0; i<4; i++){
        fscanf(cfPtr, "%4u %2u %15s %1u %3u %1u", &v[i].id, &v[i].hora, v[i].cd, &v[i].tv, &v[i].ct, &v[i].ev); 
        printf("#%d:\n ID: %u\n Hora: %u:00\n Ciudad de destino: %s\n Tipo de vuelo(0 nacional, 1 internacional): %u\n Tiquetes vendidos: %u\n Estado del vuelo(Sin asignar - 0, Programado - 1, Cancelado - 2): %u\n", i+1, v[i].id, v[i].hora, v[i].cd, v[i].tv, v[i].ct, v[i].ev);
        printf("\n");
        }
    }

    printf("Aeronaves: \n");
    for(int i=0; i<5; i++){
        fscanf(cfPtr, "%u %u %u %u", &a[i].ta, &a[i].cs, &a[i].tv, &a[i].disp); 
        printf("#%d:\n Tipo avion: %u\n Cantidad de sillas: %u \n Tipo de vuelo(0 nacional, 1 internacional): %u\n Aviones disponibles: %u \n", i+1, a[i].ta, a[i].cs, a[i].tv, a[i].disp);
        printf("\n");
    }

    printf("Pilotos: \n");
    for(int i=0; i<5; i++){
        fscanf(cfPtr, "%15s", p[i].nom); 
        printf("#%d:\n Nombre:%15s \n", i+1, p[i].nom);
        printf("Tipos de avion: ");
        for(int j=0; j<5; j++){
            fscanf(cfPtr, "%u", &p[i].ta[j]); 
            printf("%u ", p[i].ta[j]);
        }
        printf("\n");
        fscanf(cfPtr, "%u %u", &p[i].disp, &p[i].tv); 
        printf("Disponibilidad actual(0 disponible, 1 ocupado): %u \nTipo de vuelo(0 nacional, 1 internacional, 2 ambos): %u\n", p[i].disp, p[i].tv);
        printf("\n");
      }
    fclose(cfPtr);
    for(int i=0; i<CANTA; i++){
        printf("\n Piloto aeronave %d: %s\n", i+1, buscarPiloto(p, a[i]));
    }
    printf("Vuelos cancelados: %u", asignarAeronave(v, a, p));
}

char *buscarPiloto(Pilotos p[CANTP], Aeronaves a){
    int piloto=0;
    char *noDisp="NoDisp";
    for(int i=0; i<CANTP ; i++){
        if (p[i].disp==0){
            for(int j=0; j<5; j++){
                if(p[i].ta[j]==a.ta){
                p[i].disp=1;
                piloto=1;
                return p[i].nom;
                }
            }
        }
    }
    if(piloto==0){
    return noDisp;
    }
}

unsigned asignarAeronave(Vuelos v[4], Aeronaves a[6], Pilotos p[5]){
    unsigned vuCan=0;
    char *noDisp="NoDisp";
    for(int i=0; i<CANTV; i++){
        int smin=0, amin=-1;
        char *piloto;
        for(int j=0; j<CANTA; j++){
            if(a[j].disp > 0 && v[i].tv == a[j].tv && v[i].ct <= a[j].cs){
                if(smin == 0 || smin > a[j].cs){
                    smin = a[j].cs;
                    amin = j;
                }
            }
        }

        if(amin!=-1){
            piloto = buscarPiloto(p, a[amin]);
            printf("Piloto vuelo #%d: %s \n", i+1, piloto);
            if(piloto != noDisp){
                printf("Aeronave vuelo #%d: %u \n", i+1, a[amin].ta);
                a[amin].disp--;
            }
            else if(piloto == noDisp){
            vuCan++;
            }
        }
        printf("\n");
    }
    return vuCan;
}
