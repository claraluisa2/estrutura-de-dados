#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esq, *dir;
}No;

No *criaNo(int valor){
    No *novo = (No*) calloc(1, sizeof(No));
    if(!novo){
        printf("\nErro ao alocar memoria.");
        exit(1);
    }
    novo->chave = valor;
    return novo;
}

No *buscaArvore(No *T, No **pred, int valor){
    No *aux = T;
    *pred = NULL;
    while (aux != NULL){
        if (aux->chave == valor) return aux;
        else if (aux->chave > valor){
            *pred = aux;
            aux = aux->esq;
        }
        else{
            *pred = aux;
            aux = aux->dir;
        }
    }
    return aux;
}

No *insereNo(No *T, int valor){
    No *pred;
    No *aux = buscaArvore(T, &pred, valor);
    if (aux != NULL) return T;
    else{
        No *novo = criaNo(valor);
        if(pred == NULL) return novo;
        else if (pred->chave < valor){
            pred->dir = novo;
        }else{
            pred->esq = novo;
        }
    }
    return T;
}

No *exluiNo(No *T, int valor){
    No *aux1, *aux2, *pred1 = NULL, *pred2 = NULL;
    aux1 = buscaArvore(T, &pred1, valor);
    if(aux1 == NULL) {
        printf("\nChave não encontrada.");
        return T;
    }
    else{
        // caso1: chave a ser excluída for uma folha
        if (aux1->dir == NULL && aux1->esq == NULL){
            if(pred1 == NULL){ // no a ser excluído é a raiz
                free(aux1);
                return NULL;
            }else if(pred1->dir == aux1){
                pred1->dir = NULL;
                free(aux1);
                return T;

            }else{
                pred1->esq = NULL;
                free(aux1);
                return T;
            }
        }
        //caso2: chave a ser excluída tem apenas um nó filho.
        if(aux1->dir == NULL){ // nó filho está a esquerda
            if (pred1 == NULL){ //verificando se é a raiz
                aux2 = aux1->esq;
                free(aux1);
                return aux2;
            }else{
                if (pred1->esq == aux1){ // verficando se o nó a ser excluído está a esquerda do seu predecessor
                    pred1->esq = aux1->esq;
                }else{ // o nó a ser excluído está a direita do seu predecessor
                    pred1->dir = aux1->esq;
                }
                return T;
            }
        }

        if(aux1->esq == NULL){ // nó filho está a direita
            if (pred1 == NULL){ //verificando se é a raiz
                aux2 = aux1->dir;
                free(aux1);
                return aux2;
            }else{
                if (pred1->esq == aux1){ // verficando se o nó a ser excluído está a esquerda do seu predecessor
                    pred1->esq = aux1->dir;
                }else{ // o nó a ser excluído está a direita do seu predecessor
                    pred1->dir = aux1->dir;
                }
                return T;
            }
        }
        //caso3: chave a ser excluída tem dois nós filhos
        pred2 = aux1;
        aux2 = aux1->dir;
        while(aux2->esq!= NULL){
            pred2 = aux2;
            aux2 = aux2->esq;
        }
        aux1->chave = aux2->chave; //copiando o valor de aux2 para aux1

        if (pred2->esq == aux2){
            pred2->esq = aux2->dir;
        }else{
            pred2->dir = aux2->dir;
        }
        //free(aux2);
        return T;

    }
}

void imprimeArvore(No *T, int nivel){
    if (T != NULL){
        imprimeArvore(T->dir, nivel+1);
        for (int i=0; i<nivel; i++){
            printf("    ");
        }
        printf("%d\n", T->chave);
        imprimeArvore(T->esq, nivel+1);
    }
}

int alturaArvore(No *T){
    if (T != NULL){
        int i = alturaArvore(T->dir);
        int j = alturaArvore(T->esq);

        if(i > j) return i+1;
        else return j+1;
    }
    return 0;
}

void imprimeAlturaNo(No *T, int nivel){
    if (T != NULL){
        imprimeAlturaNo(T->dir, nivel+1);
        int j = alturaArvore(T);
        for (int i=0; i<nivel; i++){
            printf("    ");
        }
        printf("%d (%d)\n", T->chave, j);
        imprimeAlturaNo(T->esq, nivel+1);
    }
}


int main(){
    No *T = NULL;
    T = insereNo(T, 50);
    T = insereNo(T, 42);
    T = insereNo(T, 71);
    T = insereNo(T, 48);
    T = insereNo(T, 36);
    T = insereNo(T, 68);
    T = insereNo(T, 75);
    //imprimeArvore(T, 0);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\n");
    //T = exluiNo(T, 71);

    imprimeAlturaNo(T, 0);
    //int i = alturaArvore(T);
    //printf("\n\n\n\n%d\n", i);
    return 0;
}