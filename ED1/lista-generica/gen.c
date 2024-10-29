#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    void *info;
    struct No *prox;
}no;

no *criaNo(void *info){
    no *novo = (no*)malloc(sizeof(no));
    if(novo == NULL){
        printf("Erro de alocação");
        exit(1);
    }
    novo->info = info;
    novo->prox = NULL;
    return novo;
}
no *insereInicio(no *L,void *info){
    no *novo = criaNo(info);
    if(L == NULL) return novo;
    novo->prox  = L;
    return novo;
}
void imprime(no*L){
    no *aux = L;
    while(aux != NULL){
        printf("%d ", aux->info);
        aux = aux->prox;
    }
}
void imprimeListaGen(no *L, void (*cb) (void *)){
    no *aux = L;
    while(aux != NULL){
        cb(aux->info);
        aux = aux->prox;
    }
}
void imprimeInt(void *info){
    printf("%i ",info);
}
int main(){
    no *L = NULL;
    L = insereInicio(L,1);
    L = insereInicio(L,2);
    L = insereInicio(L,3);
    imprimeListaGen(L, imprimeInt);
    return 0;
}