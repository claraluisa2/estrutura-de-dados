#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaNo(int valor){
    No *novo;
    novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        printf("Erro de alocacao de memoria");
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

void imprimeLista(No *L){
    No *aux = L;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
}

int ocorrencias(No *L, int valor){
    No *aux = L;
    int cont = 0;
    while(aux != NULL){
        if(aux->chave == valor){
            cont++;
        }
        aux=aux->prox;
    }
    return cont;
}

int ultimo(No *L){
    No *aux = L;
    while (aux->prox != NULL){
        aux=aux->prox;
    }
    
    return aux->chave;

    
}

No *inversa(No *L){
    No *aux = L, *M = NULL;
    while(aux != NULL){
        M = insereInicio(M, aux->chave);
        aux = aux->prox;
    }

    return M;
}

int soma(No *L){
    No *aux = L;
    if (aux->prox != NULL){ 
        return aux->chave + soma(aux->prox);
    }
    return aux->chave;



}

void substitui(No **L, int x, int y){
    if ((*L)->prox != NULL){
        if ((*L)->chave == x){
            (*L)->chave = y;
        }
        return substitui((&(*L)->prox), x, y);
    }
}

int igual(No *L, No *M){
    if (L->chave != M->chave) return 1;
    igual(L->prox, M->prox);
    return 0;
}

int iesimoIgual(No *L,No *M, int i){
    No *aux1 = L;
    No *aux2 = M;
    printf("%d ", aux1->chave);
    printf("%d ", aux2->chave);
    while(i>1){
        aux1 = aux1->prox;
        aux2 = aux2->prox;
        i--;
    }
    printf("\n%d ", aux1->chave);
    printf("%d ", aux2->chave);
    if (aux1->chave == aux2->chave) return 0;
    return 1;
}

int main(){
    No *L = NULL;
    No *M = NULL;
    int cont;
    L = insereInicio(L,1);
    L = insereInicio(L,2);
    L = insereInicio(L,4);
    M = insereInicio(M,1);
    M = insereInicio(M,3);
    M = insereInicio(M,3);
    imprimeLista(L);
    imprimeLista(M);
    //cont = ocorrencias(L,5);
    //printf("%d\n", cont);
    //cont = ultimo(L);
    //printf("%d\n", cont);
    //M = inversa(L);
    //imprimeLista(M);
    //cont = soma(L);
    //printf("%d\n", cont);
    //substitui(&L, 7, 6);
    //imprimeLista(L);
    cont = iesimoIgual(L, M, 3);
    printf("%d", cont);
    return 0;

}



