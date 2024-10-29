#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct no{
    int fila[MAX];
    int inicio;
    int fim;
    int capacidade;
    int tamanho;

}No;

No iniciaLista(No L){
    L.capacidade = MAX;
    L.fim = 0;
    L.inicio = 0;
    L.tamanho = 0;
    return L;
}

void insereFinal(No *L, int chave){
    if( L->tamanho != L->capacidade){
        L->fila[L->fim] = chave;
        L->tamanho++;
        if((L->fim) == L->capacidade-1) L->fim = 0; // Se o fim for igual a capacidade -1 (ou seja, for o fim do vetor), fim passa a ser 0
        else L->fim++;
    }
}

void removeInicio(No *L){
    if(L->tamanho != 0){
        L->tamanho--;
        if(L->inicio == L->capacidade-1) L->inicio = 0; // Se o inicio for igual a capacidade -1, fim passa a ser 0
        else L->inicio++;
    }
}

void imprimeFila(No L){
    int i = L.inicio;
    int n, j, k;
    if(L.fim > L.inicio) n = L.fim; // se o fim for maior que o inicio n = fim
    else{
        n = L.capacidade;
        j = L.fim;
        k = 0;
    }

    for(i; i<n; i++){
        printf("%d ", L.fila[i]);
    }

    if(L.fim < L.inicio){
        for(k; k<j; k++){
        printf("%d ", L.fila[k]);
    }
    }


}

int main(){
    No L;
    L = iniciaLista(L);
    insereFinal(&L, 1);
    insereFinal(&L, 2);
    insereFinal(&L, 3);
    insereFinal(&L, 4);
    insereFinal(&L, 5);
    insereFinal(&L, 1);
    insereFinal(&L, 2);
    insereFinal(&L, 3);
    insereFinal(&L, 4);
    insereFinal(&L, 5);
    removeInicio(&L);
    removeInicio(&L);
    removeInicio(&L);
    insereFinal(&L, 100);
    removeInicio(&L);
    removeInicio(&L);
    removeInicio(&L);
    removeInicio(&L);
    removeInicio(&L);
    removeInicio(&L);



    imprimeFila(L);

}