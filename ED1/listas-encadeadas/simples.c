#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaNo (int valor){
    No *novo = (No *) malloc(sizeof(No));
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
    novo->prox = L;
    L = novo;
    return L;
}

No *insereFinal(No *L, int valor){
    No *novo = criaNo(valor);
    No *aux = L;
    if (L == NULL) L = novo;
    else{
        while(aux->prox != NULL) aux = aux->prox;
        aux->prox = novo;
    }
    return L;
}

/*
    Para listas não ordenadas. Retorna NULL se a chave não existir ou se a listar estiver vazia, retorna a chave buscada se ela existir.
*/

No *buscaChaveNaoOrdenada(No *L, int valor){
    No *aux = L;
    if (L == NULL) return NULL;
    else{
        while(aux != NULL){
            if (aux->chave == valor) break;
            aux = aux->prox;
        }
        return aux;
    }
}

No *excluiChave(No *L, int valor){
    No *aux = L;
    No *pred = NULL;
    if (L == NULL) return NULL;
    while(aux != NULL && valor != aux->chave){
        pred = aux;
        aux = aux->prox;
    }
    if (pred == NULL) L = aux->prox;
    else pred->prox = aux->prox;
    free(aux);
    return L;
}

void imprimeLista(No *L){
    No *aux = L;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

/*
    Retorna NULL caso a lista esteja vazia, retorna a chave caso ela exista e se não existir retorna a primeira chave maior que a procurada.
*/

No *buscaChaveOrd(No *L, int valor){
    No *aux = L;
    if (L == NULL) return NULL;
    else{
        while(aux != NULL ){
            if (valor <= aux->chave) break;
            aux = aux->prox;
        }
        return aux;
    }
}

/*
    Se a lista está vazia retorna NULL, se a chave existe retorna aux apontando para a chave e pred para a chave anterior, se a chave não existe retorna aux apontando para a primeira chave maior que a buscada e pred para a anterior.
*/

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

No *insereListaOrd(No *L, int valor){
    No *novo = criaNo(valor);
    No *pred = NULL;
    No *aux = buscaListaOrd(L, valor, &pred);
    if (pred == NULL) {
        novo ->prox = aux;
        L = novo;
    }else{
        novo->prox = aux;
        pred->prox = novo;
    }
    return L;
}

No *exluiListaOrd(No *L, int valor){
    No *pred = NULL;
    No *aux = buscaListaOrd(L, valor, &pred);
    printf("%d\n", aux->chave);
    if (aux != NULL && aux->chave == valor){
        if (pred == NULL) L = aux->prox;
        else pred->prox = aux->prox;
        free(aux);
    }
    return L;
}

int main(){
    No *L = NULL;
    L = insereListaOrd(L, 5);
    L = insereListaOrd(L, 15);
    L = insereListaOrd(L, 50);
    L = exluiListaOrd(L, 15);
    imprimeLista(L);
}