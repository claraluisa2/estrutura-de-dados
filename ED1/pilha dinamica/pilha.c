#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *criaPilha(){
    Pilha *P = (Pilha*) malloc(sizeof(Pilha));
    if (P == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }
    P->tamanho = 0;
    P->topo = NULL;
    return P;

}

No *criaNo(int ch){
    No *P = (No*) malloc(sizeof(No));
    if (P == NULL){
        printf("Erro de alocacao de memoria");
        exit(1);
    }
    P->chave = ch;
    P->prox = NULL;
    return P;
}

void empilha(Pilha *P, int ch){
    No *novo = criaNo(ch);
    novo->prox = P->topo;
    P->topo = novo;
    P->tamanho++;
}

void desempilha(Pilha *P){
    No *aux = P->topo;
    if(aux != NULL){
        P->topo = aux->prox;
        P->tamanho--;
        free(aux);
    }

}

int vazia(Pilha *P){
    if (P->topo == NULL) return 1;
    return 0;
}

void esvazia(Pilha *P){
    while(!vazia(P)){
        desempilha(P);
    }
}

void imprimePilha(Pilha *P){
    No *aux = P->topo;
    printf("Esta pilha tem %d elementos", P->tamanho);
    while( aux != NULL){
        printf("\n%d", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}