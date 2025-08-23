# Enunciado

En un torneo hípico se registra la información de las carreras del torneo,
indicando el código del jockey ganador, el tiempo del ganador (en segundos), el
código del jockey que llegó en segundo lugar y el tiempo empleado por este (en
segundos). La información se encuentra registrada en un arreglo del estilo:

```text
Ganador | T. Ganador | Segundo | T. Segundo | Ganador | T. Ganador | Segundo | T. Segundo | ...
   3    |     120    |    1    |     124    |    2    |     185    |    3    |      191   | ...
```

Note que este arreglo tiene la información de dos carreras: mientras la primera
carrera se caracteriza por los primeros 4 datos, la segunda carrera se
caracteriza por 4 los datos siguientes. El arreglo puede contener la
información de N carreras. Además, se tiene un arreglo donde están almacenados
los nombres de los jockeys. El código del jockey es la posición que ocupa en el
arreglo.

```text
   0   |    1    |   2  |   3   |   4    |   5   |    6    | 
 JuanR | MiguelP | AnaM | LuisG | PedroJ | LinaQ | CarlosS |
```

Así, el código de JuanR es 0, el código de MiguelP es 1 y así sucesivamente.

Teniendo en cuenta la información disponible, lo que se solicita es:

1. Elabore una función que retorne el nombre del jockey que ganó más carreras
   en el torneo. Tenga cuidado al definir los parámetros.

2. Elabore una función que genere un arreglo nuevo donde se consigne la
   puntuación que se da a los jockeys participantes. Asegúrese que el nuevo
   arreglo esté disponible para las demás funciones. Tenga en cuenta que algún
   jockey podría no tener puntos. El esquema de puntuación es el siguiente: 

   1. Por cada carrera ganada se le otorgan 5 puntos. Si la diferencia de
   tiempo entre el ganador y el segundo puesto es mayor a 5 segundos se le
   otorga un punto adicional al ganador. 

   1. Por cada vez que ocupa el segundo puesto se le otorgan 3 puntos.

3. Elabore una función que produzca el reporte del torneo. El reporte debe
   incluir el nombre del jockey y los puntos obtenidos, ordenado de manera
   descendente teniendo como criterio los puntos.

## Refinamiento Definición estructura

## Refinamiento inicialización de arreglo

## Función: `generarCarreras`

Asigna tiempos aleatorios entre 100 y 200 segundos por cada carrera de un jinete . Esta función debe recibir como parámetro el arreglo de participantes , la cnatidad de jinetes y carreras.

### Entradas
- Arreglo de participantes.
- Cantidad de jinetes.
- Cantidad de carreras.

### Salidas

- Ninguna.

### Pseudo-código

1. Para cada jinete.
   1. Para cada carrera
   1. Asigno tiempo aleato

## Función: `imprimirCarreras`

Lista en pantalla el podio de todas las carreras y almacena en la matriz podios los identificadores de cada jinete. El listado incluye el número de carrera, el nombre del jinete, el tiempo en segundos y la posición.

### Entradas

- Arreglo de participantes.
- Arreglo de podio. 
- Cantidad de jinetes.
- Cantidad de carreras.

### Salida

- Ninguna 

### Pseudo-código

1. Declaro `aux` y `aux2`
1. Declaro int `car[]` y `ji[jin]`
1. Para `i`=0; `i` < `n`, `i`++
	1. Para `j`=0; `j` < `jin`, `j`++	
		1. Asigno identificación de primer participante a `ji[j]` 
		1. Asigno tiempo de primer participante a `car[j]`	car[j] = participantes[j].carr[i];
	1. Para `j`=0; `j` < `jin`, `j`++		
      1. Declaro `indiceMayor` y asigno `j`
      1. Para `k`=0; `k` < `j`+1, `k`++
         1. Si `car[k]` > `car[indiceMayor]`
            1. Asigno `k` a `indiceMayor`
            1.Si `j` es diferente de `indiceMayor`
               1. Declaro e inicializo `aux` = `car[j]` y `aux2` = `ji[j]`
				   1. Asigno `car[indiceMayor]` a `car[j]` 
				   1. Asigno `ji[indiceMayor]` a `ji[j]` 
				   1. Asigno `aux` a `car[indiceMayor]` 
				   1. Asigno `aux2` a `ji[indiceMayor]` 
      1. Para `x`=0; `x` < 3, `x`
			1. Asigno `ji[x]` a `pod[x][i]`
	
1. Imprimo cabecera de tabla
1. Imrimo tabla 
	1. Para `j`=0; `j` < `n`, `j`++
		1. Imprimo número de carrera
		1. Imprimo nombre del ganador 
		1. Imprimo tiempo del ganador
		1. Imprimo nombre del segundo puesto 
		1. Imprimo tiempo del segundo puesto 
		1. Imprimo nombre del tercer puesto
		1. Imprimo tiempo del tercer puesto
	}
}