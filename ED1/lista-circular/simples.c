#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro: problema de alocacao de memoria");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}

No *insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    if(aux == NULL){
        L = novo;
        novo->prox = L;
        return novo;
    }
    novo->prox = aux->prox;
    aux->prox = novo;
    return aux;
}



No *insereFinal(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    if(aux == NULL){
        L = novo;
        novo->prox = L;
        return novo;
    }
    while(aux->prox != L){
        aux = aux->prox;
    }
    //printf("aux e %d", aux->chave);
    aux->prox = novo;
    novo->prox = L;
    return L;
}

void imprimeLista(No *L){
    No *aux = L;
    do{
        printf("%d ", aux->chave);
        aux = aux->prox;
    }while(aux->prox != L->prox);
}

int main(){
    No *L;
    L = insereFinal(L, 1);
    L = insereFinal(L, 2);
    L = insereFinal(L, 3);
    L = insereFinal(L, 4);
    L = insereFinal(L, 5);
    L = insereFinal(L, 6);
    // L = insereInicio(L,1);
    // L = insereInicio(L,2);
    // L = insereInicio(L,3);
    // L = insereInicio(L,4);
    imprimeLista(L);
}

