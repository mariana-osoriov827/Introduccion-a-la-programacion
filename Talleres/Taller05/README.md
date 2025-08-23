# Taller05

Usando como punto de partida la solución propuesta para el taller02[2], modifica el programa usando las siguiente funciones:

menuComida: imprime en pantalla las opciones de comida y retorna la opción escogida por el usuario.
asignarCosto: recibe opción de menú validado y retorna costo de producto.
cambioMonedas: recibe costo de producto y saldo a favor; imprime en pantalla cambio en monedas de mayor valor.

## Refinamiento función `menuComida`
Imprime en pantalla las opciones de comida y retorna la opción escogida por el usuario.

### Entradas: 
`opcion`: entero positivo que representa opción elegida por el usuario.

### Salidas:
`opcion`: entero positivo que representa opción elegida por el usuario.

1. Declaro opción unsigned short
2. Imprimo en pantalla encabezado de menú.
3. Imprimo en pantalla entrada de menú 1.
4. Imprimo en pantalla entrada de menú 2.
5. Imprimo en pantalla entrada de menú 3.
6. Imprimo en pantalla entrada de menú 4.
7. Imprimo en pantalla entrada de menú 5.
8. Imprimo en pantalla entrada de menú 6.
9. Imprimo en pantalla entrada de menú 7.
10.Imprimo en pantalla entrada de menú 8.
11. Imprimo en pantalla entrada de menú 9.
12. Pregunto al usuario `opcion`.
13. Obtengo del usuario `opcion` de producto.
14. Imprimo `opcion` elegida. 

## Refinamiento función `asignarCosto`
Recibe opción de menú validado y retorna costo de producto.

### Entradas:
`opcion`: entero positivo que representa opción elegida por el usuario.

### Salidas: 
`costo`: entero positivo que representa el costo de la opción elegida por el usuario.
 
1. Obtengo del usuario opcion de producto. 
2. Si opcion >= 1 && opcion <= 8:
3. Declaro variable costo de tipo unsigned int.
4. Si opción == 1:
    1. Asigno 1200 a costo
5. Si opción == 2:
    1. Asigno 2500 a costo
6. Si opción == 3:
    1. Asigno 1800 a costo
7. Si opción == 4:
    1. Asigno 1700 a costo
8. Si opción == 5:
    1. Asigno 2000 a costo
9. Si opción == 6:
    1. Asigno 1600 a costo
10. Si opción == 7:
    1. Asigno 1000 a costo
11. Si opción == 8:
    1. Asigno 200 a costo
12. De lo contrario (costo es mayor a saldo):
    1. Imprimo error de saldo insuficiente.
13. De lo contrario, si opción == 9 (usuario escoge salir):
    1. Imprimo salida y devuelvo monedas.
14. Imprimo costo. 

## Refinamiento función `cambioMonedas`
Recibe costo de producto y saldo a favor; imprime en pantalla cambio en monedas de mayor valor.

### Entradas: 
`costo`: entero positivo que representa el costo de la opción elegida por el usuario.

### Salidas:
`saldo`: entero positivo que representa el cambio devuelto al usuario. 

1. Si costo <= saldo:
2. Imprimo en pantalla la entrega del producto.
3. Resto a saldo el costo del producto y asigno a saldo.
4. Declaro variable m500 de tipo unsigned char.
5. Declaro variable m200 de tipo unsigned char.
6. Declaro variable m100 de tipo unsigned char.
7. Imprimo encabezado de cambio.
8. Calculo cantidad de de monedas de quinientos (saldo / 500) y asigno a m500.
9. Calculo nuevo saldo (saldo %= 500).
10. Imprimo cantidad de monedas de quinientos m500.
11. Calculo cantidad de de monedas de docientos (saldo / 200) y asigno a m200.
12. Calculo nuevo saldo (saldo %= 200).
13. Imprimo cantidad de monedas de docientos m200.
14. Calculo cantidad de de monedas de cien (saldo / 100) y asigno a m100.
15. Calculo nuevo saldo (saldo %= 100).
16. Imprimo cantidad de monedas de cien m100.



