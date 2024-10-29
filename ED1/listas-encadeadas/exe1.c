/*  SIMPLISMENTE ENCADEADA - SEM NÓ CABEÇA
    1 Escrever uma função que recebe duas listas L1 e L2 e as
    concatena.
    2 Escrever uma função que recebe uma lista L e exclui as chaves
    repetidas da lista. Ou seja, se houver mais de uma ocorrência de
    uma chave x, a função deixará apenas uma ocorrência de x em L.
    3 Escreve uma função que recebe duas listas simplesmente
    encadeadas e ordenadas, L1 e L2, com n e m nós,
    respectivamente, e realiza a “fusão” das listas de forma que o
    resultado seja ordenado. Não devem ser alocados (criados) nós
    extras. Os nós deverão ser religados para compor a nova lista.
    Sua função deve ter complexidade de tempo O(n + m).
    4 Apresente todos os cálculos da complexidade de tempo da
    função implementada na questão 3.

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

No *criaNo (int valor){
    No *novo = (No*) malloc(sizeof(No));
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


void imprimeLista(No *L){
    No *aux = L;
    while(aux != NULL){
        printf("%d ", aux->chave);
        aux = aux->prox;
    }
    printf("\n");
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

No *concatena(No *L, No *M){
    No *aux = L;
    if (L == NULL) return M;
    if (M == NULL) return L;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = M;
    return L;
}

No *excluiRepetido(No *L){
    No *aux = L;
    while( aux != NULL){
        No *aux2 = aux;
        while(aux2->prox != NULL){
            if(aux->chave == aux2->prox->chave){
                No *temp = aux2->prox;
                aux2->prox = aux2->prox->prox;
                free(temp);
            }else {
                aux2=aux2->prox;
            }
        }
        aux = aux->prox;
    }

    return L;
}

No *fusao(No *L1, No *L2){
    No F;
    No *aux = &F;
    while(1){ // o loop vai continuar enquanto não houver um break

        if(L1 == NULL){
            aux->prox = L2;
            break;
        }

        /*Se L1 é nulo, todos os elementos de L1 já foram adicionados à lista fundida. Nesse caso, simplesmente anexamos o restante dos elementos de L2 à lista fundida, ajustando o campo prox do aux para apontar para L2, e encerramos o loop. Idem para o prox if.*/

        if(L2 == NULL){
            aux->prox = L1;
            break;
        }

        if(L1->chave <= L2->chave){
            aux->prox = L1;
            L1 = L1->prox;
        }else{
            aux->prox = L2;
            L2 = L2->prox;
        }

        aux=aux->prox;

    }

    return F.prox;
}

int main(){
    No *L1, *L2;
    L1 = insereInicio(L1, 4);
    L1 = insereInicio(L1, 3);
    L1 = insereInicio(L1, 1);
    L2 = insereInicio(L2, 6);
    L2 = insereInicio(L2, 4);
    L2 = insereInicio(L2, 2);
    L1 = fusao(L1, L2);
    imprimeLista(L1);
}

