#include <stdio.h>
int main (void) {
    int valor, m500, m200, m100, op, saldo; //Declaro variable `valor`, `m500`, `m200`, `m100`, `op`, `saldo`.
    int 1=1200, 2=2500, 3=1800, 4=1700, 5=2000, 6=1600, 7=1000, 8=200; //Asigno valor a productos.

    printf("+----------------------------------+"); //Imprimo menú.
    printf("| Máquina Dispensadora "El Puente" |");
    printf("| 1 | Papas Fritas         | $1200 |");
    printf("| 2 | Sándwich Combinado   | $2500 |");
    printf("| 3 | Pescadito            | $1800 |");
    printf("| 4 | Empanada             | $1700 |");
    printf("| 5 | Arepa                | $2000 |");
    printf("| 6 | Gaseosa              | $1600 |");
    printf("| 7 | Vaso de Té           | $1000 |");
    printf("| 8 | Dulce                | $200  |");
    printf("| 9 | Salir                +       |");
    printf("+---+------------------------------+");

    printf("Digite su opción >"); //Solicito valor al usuario.
    scanf("%d", &valor); //Asigno monto a `valor`.
    if (200 <= valor >= 2500) //Si 200 <= `valor` >= 2500.
    1. No, retorno 0.
    2. Sí, solicito producto.
6. Asigno valor a `op`.
7. Si `op` = 9, imprimir "Gracias por su visita, vuelva pronto"
8. Si `op` =! 9.
    1. `valor` <= opción
        1. No, imprimir "Saldo insuficiente, intente de nuevo"
        2. Sí, calcular devuelta.
8. Calcular monedas de 500 y asignar variable `m500`.
9. Calcular monedas de 200 y asignar variable `m200`.
10. Calcular monedas de 100 y asignar variable `m100`.
11. Imprimir resultado. 

}