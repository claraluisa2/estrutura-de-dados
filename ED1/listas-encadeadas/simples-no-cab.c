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

No *criaLista(No *L){
    No *novo = (No*)calloc(1, sizeof(No));
    L = novo;
    return L;
}

void imprimeLista(No *L){
    No *aux = L->prox;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

void insereInicio(No *L, int valor){
    No *novo = criaNo(valor);
    novo->prox = L->prox;
    L->prox = novo;
}

void insereFinal(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    while(aux->prox != NULL) aux = aux->prox;
    aux->prox = novo;
}

void excluiInicio(No *L){
    No *aux = L->prox;
    if (aux != NULL){
        L->prox = aux->prox;
        free(aux);
    }
}

void excluiFinal(No *L){
    No *pred = L;
    No *aux = L->prox;
    if (aux!= NULL){
        while (aux->prox != NULL){
            pred = aux;
            aux = aux->prox;
        }
        pred->prox = NULL;
        free(aux);
    }
}

No *buscaListaOrd(No *L, int valor, No **pred){
    No *aux = L->prox;
    (*pred) = L;
    while (aux != NULL){
        if (valor <= aux->chave) break;
        (*pred) = aux;
        aux = aux->prox;
    }
    return aux;

}

void insereOrd(No *L, int ch){
    No *novo = criaNo(ch);
    No *pred = NULL;
    No *aux = buscaListaOrd(L, ch, &pred);
    novo->prox = aux;
    pred->prox = novo;
}

void excluiOrd(No *L, int ch){
    No *pred = NULL;
    No *aux = buscaListaOrd(L, ch, &pred);
    if (aux != NULL && aux->chave == ch){
        if (pred == NULL) L->prox = aux->prox;
        else pred->prox = aux->prox;
        free(aux);
    }
}

int main(){
    No *L = NULL;
    L = criaLista(L);
    insereOrd(L,40);
    insereOrd(L,70);
    insereOrd(L,30);
    imprimeLista(L);
    excluiOrd(L, 30);
    imprimeLista(L);
    return 0;
}


