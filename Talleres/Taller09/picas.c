unsigned picas(unsigned numS[], unsigned jug[]){
    unsigned i, j, pic=0; // Declaro `i`, `j`, `pic`=0.
    for (i=0; i<4; i++){ // Para `i`=0; `i`<4; `i`++
        for (j=0; j<4; j++){ // Para `j`=0; `j`<4, `j`++
            if (numS[i]==jug[j] && i !=j){ // Si `numS[i]` = `jug[j]` y `i` != `j`
            pic++; // `pic`++
            }
        }
    }
    return pic; //Retorno `pic`
}