#include <stdio.h>
#include <stdlib.h>

/*
    a) Declare uma estrutura para implementar uma lista simplesmente encadeada
    de números inteiros;
    b) Escreva uma função, de complexidade de tempo linear, que recebe duas listas
    encadeadas ordenadas de forma não decrescente (do menor para o maior)
    e retorna uma lista resultante da intercalação invertida entre as duas listas
    fornecidas. Ou seja, a lista resultante deve ter os elementos na ordem do
    maior para o menor. Utilize a estrutura declarada no item a.
    c) Calcule a complexidade da função implementada. Apresente os cálculos.
    d) Escreva a função main para testar a função implementada.
*/

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaLista(No *L){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
		printf("Erro");
		exit(1);
	}
    novo->chave = 0;
    novo->prox = NULL;
}

No *criaNo(No *L, int valor){
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL){
		printf("Erro");
		exit(1);
	}
    novo->chave = valor;
    novo->prox = NULL;
}


void insereInicio(No *L, int valor){
    No *novo = criaNo(L, valor);
    novo->prox = L->prox;
    L->prox = novo;
}

void insereFinal(No *L, int valor){
    No *novo = criaNo(L, valor);
    No *aux = L;
    while(aux->prox != NULL){
        aux=aux->prox;
    }
    aux->prox = novo;

}

void imprimeLista(No *L){
    No *aux = L->prox;
    while (aux != NULL){
        printf("%d ", aux->chave);
        aux=aux->prox;
    }

    printf("\n");

}

No *fusao(No *L1, No *L2){
 //variável do tipo No. Não será parte da lista fundida final, mas serve como ponto de partida para construi-la
    No *nova = criaLista(nova); //nó auxiliar 2 recebendo o endereço de F, nesse podemos fazer manipulações sem perder a referencia de F
    No *aux1 = L1->prox;
    No *aux2 = L2->prox;
    while( aux1 != NULL && aux2 != NULL){ // o loop vai continuar enquanto não houver um break

        if(aux1->chave <= aux2->chave){
            //printf("\n%d\n ", aux1->chave);
            insereInicio(nova, aux1->chave);
            //imprimeLista(nova);
            aux1 = aux1->prox;
        }else{
            insereInicio(nova, aux2->chave);
            aux2 = aux2->prox;
        }

    }

    while (aux1 != NULL) {
        insereInicio(nova, aux1->chave);
        aux1 = aux1->prox;
    }

    while (aux2 != NULL) {
        insereInicio(nova, aux2->chave);
        aux2 = aux2->prox;
    }

    return nova;
}


int main(){
    No *L = criaLista(L);
    No *M = criaLista(M);
    insereFinal(L, 1);
    insereFinal(L, 2);
    insereFinal(L, 4);
    insereFinal(L, 6);
    insereFinal(M, 3);
    insereFinal(M, 5);
    insereFinal(M, 7);
    insereFinal(M, 8);
    imprimeLista(L);
    imprimeLista(M);
    L = fusao(L,M);
    imprimeLista(L);
}