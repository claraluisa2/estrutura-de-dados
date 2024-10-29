#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct pilha{
    int topoA; //posição do topo da pilha A
    int topoB; //posição do topo da pilha A
    int elementos[MAX];

}Pilha;

Pilha criaPilha(Pilha P){
    P.topoA = -1;
    P.topoB = MAX;
    return P;
}

int Avazia(Pilha P){
    if (P.topoA = -1) return 1;
    else return 0;
}

int Bvazia(Pilha P){
    if (P.topoB = MAX) return 1;
    else return 0;
}

int cheias(Pilha P){
    if(P.topoB == (P.topoA+1)) return 1;
    else return 0;
}

void empilhaA(Pilha *P, int valor){
    if (!cheias(*P)){
        P->elementos[P->topoA+1] = valor;
        P->topoA++;
    }else{
        printf("Pilha cheia!");
    }
}

void empilhaB(Pilha *P, int valor){
    if (!cheias(*P)){
        P->elementos[P->topoB-1] = valor;
        P->topoB--;
    }else{
        printf("Pilha cheia!\n");
    }
}

void desempilhaA(Pilha *P){
    if(Avazia(*P)){
        P->topoA--;
    }
}

void desempilhaB(Pilha *P){
    if(Avazia(*P)){
        P->topoB++;
    }
}

void imprimePilhaA(Pilha P){

    for(int i=0; i<=P.topoA; i++){
        printf("%d° elemento - %d\n",i, P.elementos[i]);
    }
}

void imprimePilhaB(Pilha P){

    for(int i=MAX-1; i>=P.topoB; i--){
        printf("%d° elemento - %d\n", i, P.elementos[i]);
    }
}

int main(){
    Pilha P = criaPilha(P);
    empilhaA(&P, 1);
    empilhaA(&P, 2);
    empilhaA(&P, 3);
    empilhaA(&P, 4);
    empilhaA(&P, 5);
    empilhaB(&P, 5);
    empilhaB(&P, 4);
    empilhaB(&P, 3);
    empilhaB(&P, 2);
    empilhaB(&P, 1);
    imprimePilhaA(P);
    desempilhaA(&P);
    desempilhaA(&P);
    desempilhaA(&P);
    desempilhaA(&P);
    desempilhaA(&P);
    imprimePilhaA(P);


}
