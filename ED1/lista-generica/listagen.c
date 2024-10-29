#include <stdio.h>
#include <stdlib.h>

typedef struct listagen{
    void *info;
    struct listagen *prox;
}ListaGen;

ListaGen *criaListaGen(void *v){
    ListaGen *novo = (ListaGen*)calloc(1, sizeof(ListaGen));
    if(!novo){
        printf("Erro ao alocar memoria\n");
        exit(1);
    }
    novo->info = v;
    return novo;
}

ListaGen *insereListaGen(ListaGen *L, void *v){
    ListaGen *novo = criaListaGen(v);
    novo->prox = L;
    return novo;
}

void percorreListaGen(ListaGen *L, void(*cb)(void *)){
    ListaGen *aux = L;
    while(aux != NULL){
        cb(aux->info);
        aux = aux->prox;
    }
}

void imprime_int(void *info){
    printf("%d\n", info);
}

/*Exemplo de chamada da função acima
    percorreListaGen(L, imprime_int)
*/

int main(){
    
}