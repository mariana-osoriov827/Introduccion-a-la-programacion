# Carreras de caballos

En un torneo hípico se registra la información de las carreras del torneo, indicando el código del jockey ganador, el tiempo del ganador (en segundos), el código del jockey que llegó en segundo lugar y el tiempo empleado por este (en segundos). La información se encuentra registrada en un arreglo del estilo:

```text
|Ganador | Tiempo Ganador | Segundo | Tiempo Segundo | Ganador | Tiempo Ganador | Segundo | Tiempo Segundo ... |
|   3    |      120       |    1    |      124       |    2    |      185       |    3    |       191 ...      |
```
Note que este arreglo tiene la información de dos carreras: mientras la primera carrera se caracteriza por los primeros 4 datos, la segunda carrera se caracteriza por 4 los datos siguientes. El arreglo puede contener la información de N carreras. Además, se tiene un arreglo donde están almacenados los nombres de los jockeys. El código del jockey es la posición que ocupa en el arreglo.

```text
|   0   |    1    |  2   |   3   |   4    |   5   |    6    | 
| JuanR | MiguelP | AnaM | LuisG | PedroJ | LinaQ | CarlosS |
```

Así, el código de JuanR es 0, el código de MiguelP es 1 y así sucesivamente.
Teniendo en cuenta la información disponible, lo que se solicita es:

1. (10%) Elabore una función que retorne el nombre del jockey que ganó más carreras en el torneo. Tenga cuidado al definir los parámetros.

2. (20%) Elabore una función que genere un arreglo nuevo donde se consigne la puntuación que se da a los jockeys participantes. Asegúrese que el nuevo arreglo esté disponible para las demás funciones. Tenga en cuenta que algún jockey podría no tener puntos. El esquema de puntuación es el siguiente: (a) Por cada carrera ganada se le otorgan 5 puntos. Si la diferencia de tiempo entre el ganador y el segundo puesto es mayor a 5 segundos se le otorga un punto adicional al ganador. (b) Por cada vez que ocupa el segundo puesto se le otorgan 3 puntos.

3. (25%) Elabore una función que produzca el reporte del torneo. El reporte debe incluir el nombre del jockey y los puntos obtenidos, ordenado de manera descendente teniendo como criterio los puntos.

## Función ganador

Retorna el nombre del jockey que ganó más carreras en el torneo. 

### Entradas
`*nom[]`: String que almacena nombres de los jockeys. 
`reCarr[]`: String que almacena ganadores.
`n`: Entero que almacena número de carreras. 
`m`: Entero que almacena número de jinetes.

### Salidas
`ganador`: Arreglo tipo char que almacena nombre de ganador de más carreras en el torneo. 

1. Declaro `ganador`
1. Declaro `vecesGanadas`
1. Declaro `i` y `j`
1. Para `i`=0, `i`<`n`, `i`++
    1. Calculo `ganador` de cada carrera
1. Para `i`=0, `i`<`m`, `i`++
	1. Asigno 0 a `vecesGanadas[i]` 
	1. Para j=0, j<n, j++
	    1. Si `ganador[i]` = `i`
	        1. Incremento `vecesGanadas[i]`
1. Declaro `mayor` y `gana`
1. Asigno `vecesGanadas[0]` a `mayor`
1. Asigno 0 a `gana`
1. Para `i`=0, `i`<`m`, `i`++
	1. Si `vecesGanadas[i]`>`mayor`
	    1. Asigno vecesGanadas[i]` a `mayor`
        1. Asigno `i` a `gana`
1. Retorno `nom[gana]`

## Función puntuacionJinetes
Consigna la puntuación que se da a los jockeys participantes.

### Entradas
`*nom[]`: String que almacena nombres de los jockeys. 
`reCarr[]`: String que almacena ganadores.
`n`: Entero que almacena número de carreras. 
`m`: Entero que almacena número de jinetes.

### Salidas
`puntuacion`: Arreglo tipo int que almacena puntuaciones. 

1. Declaro `i`, `j`
1. Declaro c
1. Para `i`=0, `i`<`m`, `i`++
	1. Asigno `puntuacion`=0
	1. Para `j`=0, `j`<`n`, `j`++
		1. Si `reCarr[4*j]` = `i`
			1. Sumo 5 a `puntuacion[i]`
		1. Si `reCarr[4*j]` = i y si `reCarr[4*j+3]` 
			1. Sumo 1 a `puntuacion[i]`
		1. Si `reCarr[4*j+2]` = i
			1. Sumo 3 a `puntuacion[i]`
1. Retornar `puntuacion`


## Función reporte
Produce reporte del torneo.

### Entradas
`*nom[]`: String que almacena nombres de los jockeys. 
`a[]`: String que almacena puntuaciones.
`n`: Entero que almacena número de carreras.  

### Salidas
Void

1. Declaro `i`, `j`, `v[n]`
1. Imprimo espacio
1. Para `i`=0, `i`<`n`, `i`++
    1. Asigno `i` a `v[i]`
    1. Imprimo primera línea tabla
    1. Para `i`=0, `i`<`n`, `i`++ 
		1. Asigno `i` a `indiceMayor`
        1. Para `j`= `i`+1, `j`<`n`, `j`++
        	1. Si `a[j]` = `a[indiceMayor]`
           		1. Asigno `j` a `indiceMayor`
        	1. Si `i` != `indiceMayor`
            	1. Declaro `aux` = `a[i]` y `aux2` = `v[i]`
                1. Asigno `a[indiceMayor]` a `a[i]`
                1. Asigno `v[indiceMayor]` a `v[i]`
                1. Asigno `aux` a `a[indiceMayor]`
                1. Asigno `aux2` a `v[indiceMayor]` 
    1. Para `i`=0, `i`<`n`, `i`++
	1. Imprimo línea de tabla 