int maquina (int num){
    char sec[]; // Declarar arreglo tipo char `sec`.
    int i=0; // Declarar e inicializar entero `i`=0.
    
    while (num>0){ // Mientras `num`>=0.
        if (num%2 == 0){ // Si `num` es par.
            sec[i] = 'A'; // Asignar A a la posición i de `sec`.
            num /= 2; // Dividir `num` entre 2.
        }
        else if(num%2 != 0) { // Si `num` es impar.
            sec[i] = 'B'; // Asignar B a la posición i de `sec`.
            num -= 1; // Disminuir `num` en 1.
        }
        i++; // Incrementar `i` en 1. 
    }
    printf("Secuencia de As y Bs: "); // Imprimir `sec`
    for(int j=i-1; j>=0; j--){
        printf("%c", sec[j]);
    }

    printf("\nLongitud mínima a devolver: %d", i); // Imprimir `i`
    return i; // Retorno `i`
}