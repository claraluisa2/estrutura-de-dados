#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

Fila *criaFila(){
    Fila *F = (Fila*)malloc(sizeof(Fila));
    if (F == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }
    F->prim = NULL;
    F->tamanho = 0;
    F->ult = NULL;

    return F;
}

No *criaNo(int ch){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }
    novo->chave = ch;
    novo->prox = NULL;
    return novo;
}

void enfila(Fila *F, int ch){
    No *novo = criaNo(ch);
    if (F->prim == NULL){
        F->prim = novo;
        F->ult = novo;
        F->tamanho++;
    }else{
        F->ult->prox = novo;
        F->ult = novo;
        F->tamanho++;
    }
}

void desenfila(Fila *F){
    No *aux = F->prim;
    if(aux != NULL){
        F->prim = aux->prox;
        free(aux);
        F->tamanho--;
    }
}

void imprimeFila(Fila *F){
    No *aux = F->prim;
    printf("Esta fila tem %d elementos\n", F->tamanho);
    while( aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int vazia(Fila *F){
    if(F->prim == NULL) return 1;
    return 0;
}

void esvazia(Fila *F){
    while(!vazia(F)){
        desenfila(F);
    }
}