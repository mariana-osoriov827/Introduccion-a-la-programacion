#include <stdio.h>

int main (void){
    unsigned short n, m, res, acum; // Declaro variables `n`, `m`, `res`, `acum`.

    for (n = 2; n <= 30; n++){ // Para `n` = 2; `n` <= 30; `n`++.
        acum=0; // Asignar valor `acum` = 0.
        for (m = 1; m < n; m++){ // Para `m` = 1; `m` <= `n`-1; `m`++.
            res = n % m; // Calculo `res`.
            if (res == 0){ // Si `res` = 0.
                acum += m; // Calculo `acum`.
            }
        }
        if (acum < n){ // Si `acum` < `n`.
            printf("%d es un número deficiente ya que la suma de sus divisores es %d. \n", n, acum); // Imprimo resultado de número deficiente.
        }
        else if (acum == n){ // Si `acum` == `n`.
            printf("%d es un número perfecto ya a que la suma de sus divisores es %d. \n", n, acum); // Imprimo resultado de número perfecto.
        }
        else if (acum > n){ // Si `acum` > `n`.
            printf("%d es un número abundante ya a que la suma de sus divisores es %d. \n", n, acum); // Imprimo resultado de número abundante.
        }
    }

}
