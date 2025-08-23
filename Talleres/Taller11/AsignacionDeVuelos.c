#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    unsigned id;
    unsigned hora;
    char cd;
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
    char *nom;
    unsigned ta[5];
    unsigned disp;
    unsigned tv;
} Pilotos;

char *buscarPiloto(Pilotos p, Aeronaves a);
unsigned asignarAeronave(Vuelos v[4], Aeronaves a[6], Pilotos p[5]);

int main(){
    Vuelos v[4];
    Aeronaves a[6];
    Pilotos p[5];

    FILE *cfPtr;
    if ((cfPtr = fopen("vuelos.txt", "r")) == NULL) {
      puts("File could not be opened");
    } 
    else {  
    printf("Vuelos: \n");
    while (!feof(cfPtr)){
    for(int i=0; i<4; i++){
        fscanf(cfPtr, "%u %u %s %u %u %u", &v[i].id, &v[i].hora, v[i].cd, &v[i].tv, &v[i].ct, &v[i].ev); 
        printf("#%d:\n id-%u hora-%u:00 ciudad de destino-%s tipo de vuelo-%u tiquetes vendidos-%u estado del vuelo(Sin asignar - 0, Programado - 1, Cancelado - 2)-%u \n", i+1, v[i].id, v[i].hora, v[i].cd, v[i].tv, v[i].ct, v[i].ev);
            }
        }
    fclose(cfPtr);
    }

    FILE *cf2Ptr;
    if ((cf2Ptr = fopen("aeronaves.txt", "r")) == NULL) {
      puts("File could not be opened");
    } 
    else {  
    printf("Aeronaves: \n");
    while (!feof(cf2Ptr)){
    for(int i=0; i<4; i++){
        fscanf(cfPtr, "%u %u %u %u", &a[i].ta, &a[i].cs, &a[i].tv, &a[i].disp); 
        printf("#%d:\n tipo avión-%u cantidad de sillas-%u tipo de vuelo-%u aviones disponibles-%u", i+1, a[i].ta, a[i].cs, a[i].tv, a[i].disp);
        printf("\n");
      }
    }
    fclose(cf2Ptr);
    }
    
    FILE *cf3Ptr;
    if ((cf3Ptr = fopen("pilotos.txt", "r")) == NULL) {
      puts("File could not be opened");
    } 
    else {  
    printf("Pilotos: \n");
    while (!feof(cf3Ptr)){
    for(int i=0; i<4; i++){
        fscanf(cfPtr, "%s", p[i].nom); 
        printf("#%d:\n nombre-%s ", i+1, p[i].nom);
        for(int j=0; j<5; j++){
            fscanf(cfPtr, "%u", &p[i].ta[j]); 
            printf("%u ", p[i].ta[j]);
        }
        fscanf(cfPtr, "%u %u", &p[i].disp, &p[i].tv); 
        printf("%u %u", p[i].disp, p[i].tv);
        printf("\n");
      }
    }
    fclose(cf3Ptr);
    }
}

char* buscarPiloto(Pilotos p[], Aeronaves a){
    for(int i=0; i<5 ; i++){
        if (p[i].disp==0){
        if((p[i].tv==2 || p.tv == a.tv) && p[i].ta[i]==a.ta){
            p.disp=1;
            return p.nom;
        }
        }
        else{
            return 0;
    }
    }
}

unsigned asignarAeronave(Vuelos v[4], Aeronaves a[6], Pilotos p[5]){
    unsigned vuCan=0;
    unsigned smin=0, amin=0;
    char piloto[15];
    for(int i=0; i<4; i++){
        for(int j=0; j<6; j++){
            if(a[j].disp > 0 && v[i].tv == a[j].tv && v[i].ct < a[j].cs){
                if(smin > a[j].cs){
                    smin = a[j].cs;
                    amin = j;
                }
            }
        }
        piloto[15]=buscarPiloto(p, a[amin]);
        int pil=0;
        for(int j=0; j<6; j++){
            if(piloto == p[j].nom){
                p[j].disp=1;
                a[amin].disp=1;
            }
        }
        if(pil != 1){
            vuCan++;
        }
    }
    return vuCan;
}