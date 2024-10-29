#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox, *ant;
}No;

No *buscaLista(No *L, int ch){
    No *aux = L;
    while (aux != NULL && ch != aux->chave){
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }
    return aux;
}

/*
    Retorna NULL caso a lista esteja vazia, retorna a chave caso ela exista e se não existir retorna a primeira chave maior que a procurada.
*/

No *buscaOrd(No *L, int ch){
    No *aux = L;
    while (aux != NULL && ch > aux->chave){
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }
    return aux;
}

No *insereInicio(No *L, int ch){
    No *novo = criaNo(ch);
    novo->prox = L;
    if (L != NULL) L->ant = novo; // se a lista não estiver vazia
    return novo;
}

No *insereFinal(No *L, int ch){
    No *novo = criaNo(ch);
    No *aux = L;
    if (L == NULL) L = novo;
    else{
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }
    return L;
}

No *insereOrd(No *L, int ch){
    No *novo = criaNo(ch);
    No *aux = buscaOrd(L, ch);
    if (aux == NULL) L = novo; /* lista vazia */
    else{
        if (aux->chave < ch){ // a nova chave é maior que todos na lista (a função de busca me retornou o ultimo no da lista)
            aux->prox = novo;
            novo->ant = aux;
        }else{ // a nova chave é menor do que a chave encontrada pela função de busca
            novo->prox = aux;
            if(aux->ant == NULL) L = novo; // a nova chave é menor do que todos na lista, ou seja, será a primeira
            else{ // a nova chave será inserida no meio da lista
                aux->ant->prox = novo;
                novo->ant = aux -> ant;
            }
            aux->ant = novo;
        }
    }
    return L;
}

No *excluiInicio(No *L){
    No *aux = L;
    if (L == NULL) return NULL;
    L = aux->prox;
    if (L != NULL) L->ant = NULL;
    free(aux);
    return L;
}

No *excluiFinal(No *L){
    No *aux = L;
    if (L == NULL) return NULL;
    while( aux->prox != NULL) aux = aux->prox;
    if(aux->ant == NULL) L = NULL; // lista não vazia com um único elemento
    else aux->ant->prox = NULL;  // lista não vazia com vários elementos
    free(aux);
    return L;
}

No *excluiChave(No *L, int ch){
    No *aux = buscaLista(L, ch);
    if (aux == NULL || aux->chave != ch)
        printf("Chave Inexistente.\n");
    else{
        if(aux != NULL){
            if (aux->ant == NULL) L = aux->prox;
            else aux->ant->prox = aux->prox;
            if (aux->prox != NULL)
            aux->prox->ant = aux->ant;
            free(aux);
        }
    }
    return aux;

}