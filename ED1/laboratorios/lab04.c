#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char c;
    struct no *prox, *ant;

}No;

No *criaNo(char info){
    No *novo = (No*)malloc(sizeof(No));
    if(novo==NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }
    novo->c = info;
    novo->ant = NULL;
    novo->prox = NULL;
    return novo;
}

No *insereInicio(No *L, char info){
    No *novo = criaNo(info);
    novo->prox = L;
    if (L != NULL){
        L->ant=novo;
    }
    return novo;
}

No *buscaLista(No *L, char ch){
    No *aux = L;
    while (aux != NULL && ch != aux->c){
        if (aux->prox = NULL) break;
        aux = aux->prox;
    }
    return aux;
}

void imprimeLista(No *L){
    No *aux = L;
    while(aux != NULL){
        printf("%c ", aux->c);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    No *L = NULL;
    L = insereInicio(L,'a');
    L = insereInicio(L,'b');
    imprimeLista(L);

}