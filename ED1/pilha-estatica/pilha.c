#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct pilha{
    int topo; //posição do topo da pilha
    int elementos[MAX];

}Pilha;

int vazia(Pilha P){ 
    if (P.topo == -1) return 1;
    return 0;
}



int cheia(Pilha P){
    if(P.topo == (MAX-1)) return 1;
    return 0;
}

void empilha(Pilha *P, int x){
    if(cheia(*P)){ //verifica se a pilha está cheia
        printf("Pilha cheia\n");
    }else{
        P->elementos[(P->topo)+1] = x;
        P->topo++;
    }
}

void desempilha(Pilha *P){
    P->topo--;
}

void imprimePilha(Pilha P){
    int i = P.topo;
    printf(" O topo da pilha eh %d e ocupa a posicao %d do vetor\n", P.elementos[P.topo], P.topo);
    if(P.topo >= 0){
        for(i; i>=0; i--){
            printf("%d\n", P.elementos[i]);
        }
    }
}

int main(){
    Pilha P;
    P.topo = -1;
    empilha(&P, 1);
    empilha(&P, 2);
    empilha(&P, 3);
    empilha(&P, 4);
    empilha(&P, 5);
    empilha(&P, 6);
    empilha(&P, 7);
    empilha(&P, 8);
    empilha(&P, 9);
    empilha(&P, 6);
    empilha(&P, 6);
    desempilha(&P);
    empilha(&P, 10);

    imprimePilha(P);

}

/*
*/