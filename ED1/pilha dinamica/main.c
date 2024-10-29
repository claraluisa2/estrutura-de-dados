#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main(){
    Pilha *P = NULL;
    P = criaPilha(P);
    empilha(P, 1);
    empilha(P, 2);
    empilha(P, 3);
    empilha(P, 4);
    empilha(P, 5);
    empilha(P, 6);
    imprimePilha(P);
    esvazia(P);
    imprimePilha(P);
}
