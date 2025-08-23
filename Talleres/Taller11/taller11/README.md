# Taller11

## 1 (55%) Asignación de vuelos
Teniendo en cuenta la problemática reciente en el manejo de los vuelos, la entidad administradora del transporte aéreo ha decidido contratar la elaboración de un sistema de información para la asignación diaria de vuelos. Para cada vuelo se conoce su número (identificador), la hora de salida, la ciudad de destino, el tipo de vuelo (nacional o internacional), la cantidad de tiquetes vendidos y el estado del vuelo: sin asignar (al inicio), programado o cancelado.
Una vez se asigna el vuelo, se conoce el tipo de avión y el nombre del piloto. Cada tipo de aeronave se representa con la descripción del tipo de avión, la capacidad de sillas (máximo 500 sillas) y la cantidad de aviones disponibles de ese tipo. A su vez, cada piloto se representa por su nombre, los tipos de avión que puede pilotar (hasta 5 tipos diferentes), su disponibilidad actual y los tipos de vuelo que puede pilotar (nacional, internacional o ambos).

1. (10%) Identifique todas las estructuras de datos (arreglos, matrices, estructuras) que necesita para representar los datos del sistema de información.
2. (20%) Proponga la función «buscarPiloto», la cual, dado el tipo de avión y el tipo de vuelo (nacional o internacional), indique si hay un piloto disponible. La función debe retornar el nombre del piloto y un indicador de encontrado; además, debe establecer la disponibilidad del piloto como ocupado.
3. (25%) Elabore la función «asignarAeronave» que, dada la información de los vuelos y la información de los aviones, asigne un tipo de avión a cada vuelo. Se debe asignar el tipo de avión más pequeño que pueda llevar a todos los pasajeros del vuelo. Si el tipo de avión está disponible, sólo se asigna si hay un piloto disponible que cumpla con las condiciones y pueda pilotarlo (requiere la función anterior). Recuerde actualizar la información del vuelo y de los tipos de avión. Si no encuentra aeronaves o pilotos disponibles, el vuelo se cancela. La función debe retornar la cantidad de vuelos cancelados.

    
### Estructuras

#### Vuelos
Estructura con:
1. Número identificador de vuelo: unsigned `id`
1. Hora de salida: unsigned `hora`
1. Ciudad de destino: string `cd`
1. Tipo de vuelo(Nacional - 0, Internacional - 1): unsigned `tv`
1. Cantidad de tiquetes vendidos: unsigned `ct`
1. Estado del vuelo(Sin asignar - 0, Programado - 1, Cancelado - 2): unsigned `ev`

#### Aeronaves
1. Descripción del tipo de avión: unsigned `ta`
1. Capacidad de sillas (máximo 500 sillas): unsigned `cs` 
1. Tipo de vuelo(Nacional - 0, Internacional - 1): unsigned `tv`
1. Disponibilidad actual: unsigned `disp`

#### Pilotos
1. Nombre: string `nom`
1. Tipos de avión: unsigned `ta`
1. Disponibilidad actual(Disponible - 0, Ocupado - 1): unsigned `disp`
1. Tipo de vuelo(Nacional - 0, Internacional - 1, Ambos - 2): unsigned `tv`

## 2 (45%) Formación de ejércitos
Cualquier ejército del mundo hace gala de su disciplina y organización en cualquier ocasión. El momento más común es en algún desfile donde se conmemore la fiesta nacional del país al que pertenece. Una característica importante a tener en cuenta es la estética del desfile: normalmente, los miembros de un escuadrón son formados en un rectángulo de n filas de m soldados, que deberían estar ordenados de tal forma que las personas más altas no estén rodeadas de personas mucho más bajas. Esto puede hacer que el orden del desfile no sea el apropiado. Sin embargo, como no todas las personas tienen exactamente la misma altura, se debe tener en cuenta un cierto margen de holgura en la diferencia de alturas.
De esta forma, el orden de formación se considera correcto cuando para cada persona en la formación, la diferencia de alturas con aquellas personas que la rodean (vecinos directos) está dentro del rango de holgura. 
Ejemplo: asumiendo un margen de holgura de 2 centímetros, la primera formación está correcta, mientras que la segunda no es aceptable.

```text 
Formación correcta
171 171 172
172 172 170
170 170 171
```

```text 
Formación incorrecta
179 178 174
177 180 175
176 174 173
```

Teniendo en cuenta esto, proponga la función «EsOrdenCorrecto» que reciba una formación posible de personas (donde cada persona está identificada únicamente por su altura en centímetros) y un valor de holgura (dado en centímetros); e indique si el orden de esa formación es correcto. 




