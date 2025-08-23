# Caracterización y limpieza de una muestra

Una secuencia (arreglo) de $`n`$ números reales (_float_) se puede caracterizar
y limpiar usando el promedio y la desviación estándar. El promedio de una
secuencia de números se define como:

```math
\mu = \frac{1}{n} \sum_{i = 0}^{n - 1}x_i
```

y la desviación estándar se puede definir como:

```math
\sigma = \sqrt{\frac{1}{n} \sum_{i = 0}^{n - 1}(x_i - \mu)^2}
```

La limpieza de la secuencia de números se hace informando cuáles de ellos
tienen valores en el rango ( $`\mu - \alpha \cdot \sigma`$,  $`\mu + \alpha
\cdot \sigma`$) , donde $`\alpha`$ es un número dado por el usuario.

1. Proponga una función que calcule el promedio de un arreglo de números
   reales. Esta función no debe imprimir nada por pantalla ni pedir entradas
   por el teclado.

1. Proponga una función que calcule la desviación estándar de un arreglo de
   números reales. Esta función no debe imprimir nada por pantalla ni pedir
   entradas por el teclado

   > **Nota:** la función `float sqrt(float a)` calcula la raíz
cuadrada de un número.

1. Proponga una función que imprima por pantalla la limpieza de un arreglo de
   números reales. Esta función no debe pedir entradas por el teclado.

## Refinamiento función promedio

### Entradas
`numeros[]`: arreglo de números reales. 

### Salidas
`prom`: dato tipo float que almacena el promedio del arreglo de números reales.

1. Declaro `sum` y asigno valor 0.
1. Declaro `prom`.  
1. Para i=0; i<size; i++ 
   1. Sumo número en posición i del arreglo. 
1. Calculo `prom` dividiendo sumatoria entre size. 
1. Retorno `prom`

## Refinamiento función desviación estándar 

### Entradas
`promedi`: dato tipo float que almacena el promedio del arreglo de números reales.
`numeros[]`: arreglo de números reales. 

### Salidas 
`desvest`: dato tipo float que almacena la desviación estándar del arreglo de números reales. 

1. Declaro `dis` y `desvest`
1. Declaro `sum` y asigno valor 0.
1. Para i=0; i<SIZE; i++
   1. Calculo `dis` para cada número del arreglo. 
   1. Elevo `dis` al cuadrado. 
   1. Sumo valor `dis` al acumulado `sum`
1. Calculo `desvest`. 
1. Retorno `desvest`. 

## Refinamiento función limpieza

### Entradas
`num`: número dado por el usuario
`promedi`: dato tipo float que almacena el promedio del arreglo de números reales.
`desv`: dato tipo float que almacena la desviación estándar del arreglo de números reales. 
`numeros[]`: arreglo de números reales.

### Salidas
void

1. Declaro `x` y `y`
1. Calculo `x`
1. Calculo `y`
1. Para i=0; i<SIZE; i++
   1. numeros[i] > `x` y numeros[i] < `y`
      1. Sí, imprimo valor. 
1. Retorno 0.