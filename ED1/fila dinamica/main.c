#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main(){
    Fila *F = criaFila();
    enfila(F, 1);
    enfila(F, 2);
    enfila(F,3);
    imprimeFila(F);
    desenfila(F);
    imprimeFila(F);
    esvazia(F);
    imprimeFila(F);
}
