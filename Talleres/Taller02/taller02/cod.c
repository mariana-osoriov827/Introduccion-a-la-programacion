#include <stdio.h>
int main (void) {
    int valor, m500, m200, m100, op, saldo, precio; //Declaro variable `valor`, `m500`, `m200`, `m100`, `op`, `saldo`, `precio`.

    printf("+--------------------------------+\n"); //Imprimo menú.
    printf("| Máquina Dispensadora El Puente |\n");
    printf("| 1 | Papas Fritas       | $1200 |\n");
    printf("| 2 | Sándwich Combinado | $2500 |\n");
    printf("| 3 | Pescadito          | $1800 |\n");
    printf("| 4 | Empanada           | $1700 |\n");
    printf("| 5 | Arepa              | $2000 |\n");
    printf("| 6 | Gaseosa            | $1600 |\n");
    printf("| 7 | Vaso de Té         | $1000 |\n");
    printf("| 8 | Dulce              | $200  |\n");
    printf("| 9 | Salir              |       |\n");
    printf("+---+--------------------+-------+\n");
    
    printf("Digite saldo entre $200 y $2500:"); //Solicito valor al usuario.
    scanf("%d", &valor); //Asigno monto a `valor`.

    if (200 > valor || valor> 2500){ //Si 200 > `valor` || `valor` > 2500.
    printf("El monto introducido no corresponde a lo solicitado"); 
    return 0; //Sí, retorno 0
    } 
        else //No, solicito producto.
        printf("Digite su opción:"); 
        scanf("%d", &op); //Asigno valor a `op`.
        
        if  (op == 1) {precio = 1200;} //Asigno valor a precio
        if  (op == 2) {precio = 2500;}
        if  (op == 3) {precio = 1800;}
        if  (op == 4) {precio = 1700;}
        if  (op == 5) {precio = 2000;}
        if  (op == 6) {precio = 1600;}
        if  (op == 7) {precio = 1000;}
        if  (op == 8) {precio = 200;}
        
        if (op == 9){ //Si `op` = 9, imprimir "Gracias por su visita, vuelva pronto"
        printf("Gracias por su visita, vuelva pronto");
        }
        else if (valor < precio){ //Si `op` =! 9. Si `valor` > opción
            printf("Saldo insuficiente, intente de nuevo"); //No, imprimir "Saldo insuficiente, intente de nuevo"
           } 
           else if (valor >= precio){ //Sino, calcular devuelta.
           saldo = valor - precio; //Calcular saldo
           m500 = saldo / 500; //Calcular monedas de 500 y asignar variable `m500`.
           saldo = saldo % 500;
           m200 = saldo / 200; //Calcular monedas de 200 y asignar variable `m200`.
           saldo = saldo % 200;
           m100 = saldo / 100; //Calcular monedas de 100 y asignar variable `m100`.
           
           printf("Gracias por su compra, su devuelta son %d monedas de $500, %d monedas de $200 y %d monedas de $100.", m500, m200, m100); // Imprimir resultado. 
           
           }
           return 0;
}