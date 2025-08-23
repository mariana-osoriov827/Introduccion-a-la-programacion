#include <stdio.h>

int main(void){
    float est; //Defino variable 1 'est'
    float peso; //Defino variable 2 'peso'
    float IMC; //Defino variable 3 'IMC'

    printf("Ingrese su estatura en metros: "); //Solicito estatura a usuario 
    scanf("%f", &est); //Obtengo valor y asigno variable 'est'

    printf("Ingrese su peso en kg: "); //Solicito peso a usuario
    scanf("%f", &peso); //Obtengo valor y asigno variable 'peso'

    IMC=peso/(est*est); //Obtengo cociente de 'peso' entre la potencia de 'est' y asigno variable 'IMC'
    printf("Su IMC es %f, tome en cuenta la siguiente tabla para su interpretación:\n", IMC); //Imprimo tabla 
    printf("MC Nivel de peso\n");
    printf("Por debajo de 18.5 Bajo peso\n");
    printf("18.5 – 24.9 Normal\n");
    printf("25.0 – 29.9 Sobrepeso\n");
    printf("30.0 o más Obesidad\n");

    if (IMC <18.5){ //Aplico condicional para IMC 'Peso bajo'
        puts("Según la tabla de medición, usted se encuentra en un peso bajo"); //Si IMC='Peso bajo', imprimo resultado.
        }
        else if (IMC >= 18.5 && IMC <= 24.9){ //Aplico concicional para IMC 'Peso normal'
            puts("Según la tabla de medición, usted se encuentra en un peso normal"); //Si IMC='Peso normal', imprimo resultado.
            }
            else if (IMC > 24.9 && IMC <= 29.9){ //Aplico condicional para IMC 'Sobrepeso'
                puts ("Según la tabla de medición, usted se encuentra en un sobrepeso"); //Si IMC='Sobrepeso', imprimo resultado.
            }
            else if (IMC > 29.9){ //Aplico condicional para IMC 'Obesidad'
                 puts ("Según la tabla de medición, usted se encuentra en obesidad"); //Si IMC='Obesidad', imprimo resultado.
            }
            return 0;
}