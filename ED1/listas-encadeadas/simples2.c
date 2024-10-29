#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaNo (int valor){
    No *novo = (No *) malloc (sizeof(No));
    if (novo == NULL){
        printf("Erro: problema de alocacao de memoria");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    return novo;
}

No *buscaListaOrd(No *L, int valor, No **pred){
    No *aux = L;
    (*pred) = NULL;
    if (L == NULL) return NULL;
    while (aux != NULL && valor > aux->chave){
        (*pred) = aux;
        aux = aux->prox;
    }
    return aux;
}



void insereListaOrd(No **L, int valor){
    No *novo = criaNo(valor);
    No *pred = NULL;
    No *aux = buscaListaOrd(*L, valor, &pred);
    novo->prox = aux;
    if (pred == NULL) *L = novo;
    else pred->prox = novo;
}

void exluiListaOrd(No **L, int valor){
    No *pred = NULL;
    No *aux = buscaListaOrd(*L, valor, &pred);
    if (aux != NULL && aux->chave == valor){
        if (pred == NULL) *L = aux->prox;
        else pred->prox = aux->prox;
        free(aux);
    }
}

void imprimeLista(No *L){
    No *aux = L;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int main(){
    No *L = NULL;
    insereListaOrd(&L, 6);
    insereListaOrd(&L, 5);
    insereListaOrd(&L, 4);
    insereListaOrd(&L, 8);
    imprimeLista(L);
    exluiListaOrd(&L, 6);
    imprimeLista(L);

}