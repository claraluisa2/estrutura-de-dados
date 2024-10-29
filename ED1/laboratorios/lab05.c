#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int chave;
	struct no *prox, *ant;
}No;

No *criaNo(int ch){
	No *novo = (No*)malloc(sizeof(No));
	if (novo == NULL){
		printf("Erro");
		exit(1);
	}
	novo->ant = NULL;
	novo->prox = NULL;
	novo->chave = ch;
	return novo;
}

No *insereInicio(No *L, int ch){
	No *novo = criaNo(ch);
	novo->prox = L;
	if (L == NULL){
		L = novo;
		novo->ant = L;
	}else{
		L->ant->prox = novo;
		novo->ant = L->ant;
	}
	return novo;
}

void imprimeLista(No *L){
	No *aux = L;
	do{
		printf("%d ", aux->chave);
		aux = aux->prox;
	}while (aux != L);
	printf("\n");

}

int tamanho(No *L){
	int cont = 0;
	No *aux = L;
	if (L == NULL) return 0;
	do{
		cont ++;
		aux = aux->prox;
	}while (aux != L);

    return cont;
}

int elimina(No *L, int x){
    int cont = 0;
    No *aux = L, *aux1= L;
    if(L == NULL) return 0;
    do{
        if(aux->chave == x){
            aux1->ant->prox = aux1->prox;
            aux1->prox->ant = aux1->ant;
            aux1 = aux1->prox;
            aux = aux->prox;
            printf("aaaaaaaaa ");
            //imprimeLista(L);
            cont ++;

        }else{
        aux1 = aux1->prox;
		aux = aux->prox;
        }
        printf("\n%d ", aux->chave);

	}while (aux != L);
    return cont;
}

int main(){
    No *L = NULL;
    L = insereInicio(L, 1);
    L = insereInicio(L, 2);
    L = insereInicio(L, 3);
    L = insereInicio(L, 3);
    L = insereInicio(L, 3);
    L = insereInicio(L, 4);

    imprimeLista(L);
    int cont = tamanho(L);
    cont = elimina(L, 3);
    //printf("\n%d\n", cont);
    //imprimeLista(L);

}
