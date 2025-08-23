unsigned fijas(unsigned numS[], unsigned jug[]){
    unsigned i, fij=0; // Declaro `i`, `fijas`=0.
    for (i=0; i<4; i++){ // Para `i`=0; `i`<4; `i`++
        if (numS[i] == jug[i]){ // Si `numS[i]` = `jug[i]`
        fij++; // `fij`++
        }
    }
    return fij; // Retorno `fij`
}