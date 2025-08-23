#include <iostream>

using namespace std;

int main(void){
	unsigned int saldo;	// Declaro variable saldo de tipo _unsigned int_.
	unsigned short opcion;	// Declaro variable opcion de tipo _unsigned short.

	cout << "Ingresa cantidad de dinero: $";	// Pregunto al usuario cantidad de dinero.
	cin >> saldo;	// Obtengo del usuario  cantidad de dinero y asigno a saldo.

	if (saldo >= 200 && saldo <= 2500 && saldo % 100 == 0){	// Si saldo es válido
		cout << "Máquina Dispensadora “El Puente”\n";		// Imprimo en pantalla encabezado de menú.
		cout << "1 Papas Fritas          $1200\n";		// Imprimo en pantalla entrada de menú 1.
		cout << "2 Sándwich Combinado    $2500\n";		// Imprimo en pantalla entrada de menú 2.
		cout << "3 Pescadito             $1800\n";		// Imprimo en pantalla entrada de menú 3.
		cout << "4 Empanada              $1700\n";		// Imprimo en pantalla entrada de menú 4.
		cout << "5 Arepa                 $2000\n";		// Imprimo en pantalla entrada de menú 5.
		cout << "6 Gaseosa               $1600\n";		// Imprimo en pantalla entrada de menú 6.
		cout << "7 Vaso de Té            $1000\n";		// Imprimo en pantalla entrada de menú 7.
		cout << "8 Dulce                  $200\n";		// Imprimo en pantalla entrada de menú 8.
		cout << "9 Salir" << endl;				// Imprimo en pantalla entrada de menú 9.

		cout << "Digite su opción > ";		// Pregunto al usuario opción
		cin >> opcion;				// Obtengo del usuario opcion de producto

		if (opcion >= 1 && opcion <= 8){	// Si opcion es mayor o igual a 1 y opcion es menor o igual a 8:
			unsigned int costo;		// Declaro variable costo de tipo _unsigned int_.

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

			if (costo <= saldo){			// Si costo es menor o igual a saldo:
				cout << "Entregando producto...\n";	// Imprimo en pantalla la entrega del producto.
				saldo -= costo;			// Resto a saldo el costo del producto y asigno a saldo.

				unsigned short m500;		// Declaro variable m500
				unsigned short m200;		// Declaro variable m200 
				unsigned short m100;		// Declaro variable m100

				cout << "Moneda\tCantidad\n"; // Imprimo encabezado de cambio.

				m500 = saldo / 500;		// Calculo cantidad de de monedas de quinientos y asigno a m500.
				saldo %= 500;			// Calculo nuevo saldo
				cout << "$500\t" << m500 << "\n";	// Imprimo cantidad de monedas de quinientos m500.

				m200 = saldo / 200;		// Calculo cantidad de de monedas de docientos 
				saldo %= 200;			// Calculo nuevo saldo 
				cout << "$200\t" << m200 << "\n";	// Imprimo cantidad de monedas de docientos

				m100 = saldo / 100;		// Calculo cantidad de de monedas de cien 
				saldo %= 100;			// Calculo nuevo saldo
				cout << "$100\t" << m100 << endl;	// Imprimo cantidad de monedas de cien 
			}

			else{	// De lo contrario costo es mayor a saldo
				cout << "Error: No cuentas con saldo suficiente.\n";	// Imprimo error de saldo insuficiente.
				cout << "Devolviendo saldo: $" << saldo << endl;
			}
		}

		else if (opcion == 9){		// De lo contrario, si usuario escoge salir
			cout << "Saliendo...\n";	// Imprimo salida y devuelvo monedas.
			cout << "Devolviendo saldo: $" << saldo << endl;
		}

		else{	// De lo contrario opción escogida **no** es válida
			cout << "Error: " << opcion << " no es una opción válida\n";	// Imprimo en pantalla error por escoger opción que no se encuentra de 1 a 9.
			cout << "Devolviendo saldo: $" << saldo << endl;
		}
	}

	else{	// De lo contrario saldo inválido
		cout << "Error: el monto $" << saldo << " no es válido\n";	// Imprimo error de monto no aceptado y devuelvo monedas.
		cout << "Devolviendo saldo: $" << saldo << endl;
	}
}
