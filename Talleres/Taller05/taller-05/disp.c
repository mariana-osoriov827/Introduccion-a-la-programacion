#include <stdio.h>

unsigned short menuComida (void); // Declaro función menuComida. 
unsigned int asignarCosto (unsigned short opcion); // Declaro función asignarCosto.
void cambioMonedas (unsigned int costo, unsigned int saldo); // Declaro función cambioMonedas.

int main(void){
    
	unsigned short saldo;	// Declaro variable saldo de tipo _unsigned int_.
	unsigned int opcion;	// Declaro variable opcion de tipo _unsigned int.
	unsigned int costo;		// Declaro variable costo de tipo _unsigned int_.

	printf("%s", "Ingresa cantidad de dinero: $");	// Pregunto al usuario cantidad de dinero.
	scanf("%hu", &saldo);	// Obtengo del usuario  cantidad de dinero y asigno a saldo.

	if (saldo >= 200 && saldo <= 2500 && saldo % 100 == 0){	// Si saldo es válido
		opcion = menuComida();
		
		if (opcion >= 1 && opcion <= 8){	// Si opcion es mayor o igual a 1 y opcion es menor o igual a 8:
		costo = asignarCosto(opcion);

			if (costo <= saldo){			// Si costo es menor o igual a saldo:
			cambioMonedas(costo, saldo);
			
			}

			else{	// De lo contrario costo es mayor a saldo
				puts("Error: No cuentas con saldo suficiente.");	// Imprimo error de saldo insuficiente.
				printf("Devolviendo saldo: $%u\n", saldo);
			}
		}

		else if (opcion == 9){		// De lo contrario, si usuario escoge salir
			puts("Saliendo...");	// Imprimo salida y devuelvo monedas.
			printf("Devolviendo saldo: $%u\n", saldo);
		} 
		
		else {	// De lo contrario opción escogida **no** es válida
			printf("Error: %u no es una opción válida\n", opcion);	// Imprimo en pantalla error por escoger opción que no se encuentra de 1 a 9.
			printf("Devolviendo saldo: $%u\n", saldo);
		}
	}
	
	else{	// De lo contrario saldo inválido
		printf("Error: el monto $%d no es válido\n", saldo);	// Imprimo error de monto no aceptado y devuelvo monedas.
		printf("Devolviendo saldo: $%u\n", saldo);
	}
}


unsigned short menuComida (void){
	unsigned short op;
	puts("Máquina Dispensadora El Puente");	// Imprimo en pantalla encabezado de menú.
	puts("1 Papas Fritas          $1200");		// Imprimo en pantalla entrada de menú 1.
	puts("2 Sándwich Combinado    $2500");		// Imprimo en pantalla entrada de menú 2.
	puts("3 Pescadito             $1800");		// Imprimo en pantalla entrada de menú 3.
	puts("4 Empanada              $1700 ");		// Imprimo en pantalla entrada de menú 4.
	puts("5 Arepa                 $2000");		// Imprimo en pantalla entrada de menú 5.
	puts("6 Gaseosa               $1600");		// Imprimo en pantalla entrada de menú 6.
	puts("7 Vaso de Té            $1000");		// Imprimo en pantalla entrada de menú 7.
	puts("8 Dulce                  $200");		// Imprimo en pantalla entrada de menú 8.
	puts("9 Salir");				// Imprimo en pantalla entrada de menú 9.

	printf("%s", "Digite su opción > ");		// Pregunto al usuario opción.
	scanf("%hu", &op);				// Obtengo del usuario opcion de producto.
	printf("La opción elegida fue: %hu", op);
	return op;
}

unsigned int asignarCosto (unsigned short opcion){
	unsigned int costo;
	switch(opcion){
		case 1:			// Si opción es igual a 1:
			costo = 1200;	// Asigno 1200 a costo 
			break;

		case 2:			// Si opción es igual a 2:
			costo = 2500;	// Asigno 2500 a costo 
			break;

		case 3:			// Si opción es igual a 3:
			costo = 1800;	// Asigno 1800 a costo 
			break;

		case 4:			// Si opción es igual a 4:
			costo = 1700;	// Asigno 1700 a costo 
			break;

		case 5:			// Si opción es igual a 5:
			costo = 2000;	// Asigno 2000 a costo 
			break;

		case 6:			// Si opción es igual a 6:
			costo = 1600;	// Asigno 1600 a costo 
			break;

		case 7:			// Si opción es igual a 7:
			costo = 1000;	// Asigno 1000 a costo 
			break;

		case 8:			// Si opción es igual a 8:
			costo = 200;	// Asigno 200 a costo 
			break;
		}
		return costo;
}

void cambioMonedas (unsigned int costo, unsigned int saldo){
	unsigned int m500, m200, m100;

	puts("Entregando producto...");	// Imprimo en pantalla la entrega del producto.
	saldo -= costo;			// Resto a saldo el costo del producto y asigno a saldo.
	
	printf("%s\t%s\n", "Moneda", "Cantidad"); // Imprimo encabezado de cambio.
	
	m500 = saldo / 500;		// Calculo cantidad de de monedas de quinientos y asigno a m500.
	saldo %= 500;			// Calculo nuevo saldo
	printf("$500\t%hu\n", m500);	// Imprimo cantidad de monedas de quinientos m500.

	m200 = saldo / 200;		// Calculo cantidad de de monedas de docientos 
	saldo %= 200;			// Calculo nuevo saldo 
	printf("$200\t%hu\n", m200);	// Imprimo cantidad de monedas de docientos

	m100 = saldo / 100;		// Calculo cantidad de de monedas de cien 
	saldo %= 100;			// Calculo nuevo saldo
	printf("$100\t%hu\n", m100);	// Imprimo cantidad de monedas de cien 
}
