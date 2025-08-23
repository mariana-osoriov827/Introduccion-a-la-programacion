void subcadena(char letras[], int n){

int i, aux, cad=0, cad2=0; // Declaro `i`, `aux`, `cad=0`, `cad2=0`.
for (i=1; i<=n-1; i++){ // Para `i`=0; `i`<`n`, `i`++
  if (letras[i] > letras[i-1]){ // Si `letras[i]` < `letras[i]`
    cad++; //Incremento `cad` en 1
  }
  else if (cad >=cad2){ // Sino, Si `cad` > `cad2`
    cad2=cad; // Asigno `cad` a `cad2`
    aux=i; // Asigno `i` a `aux`
    cad=1; // Asigno `1` a `cad`
  }  
}
  if (cad > cad2){ // Sino, Si `cad` > `cad2`
    cad2=cad; // Asigno `cad` a `cad2`
    aux=n; // Asigno `i` a `aux`
  }

printf("La subcadena más larga tiene: %d caracteres.\n", cad2); // Imprimo longitud de cadena
printf("La subcadena más larga es: "); // Imprimo subcadena 
for(i=aux-cad2; i<aux; i++){
  printf("%c", letras[i]);
  }
}

      