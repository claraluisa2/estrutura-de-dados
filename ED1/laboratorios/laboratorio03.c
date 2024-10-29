#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int chave;
    struct no *prox;
}No;

typedef struct candidato{
    char nome[50];
    struct candidato *prox;
}Candidato;

typedef struct partido{
    char sigla[5];
    Candidato *cand;
    struct partido *prox;
}Partido;


Partido *criaPartido(char *s){
    Partido *novo;
    novo = (Partido*)malloc(sizeof(Partido));
    if (novo == NULL){
        printf("Erro: problema de alocacao de memoria");
        exit(1);
    }
    strcpy(novo->sigla, s);
    novo->cand = NULL;
    novo->prox = NULL;
    return novo;
}

Partido *cadastraPartido(Partido *P, char *s){
    Partido *novo = criaPartido(s);
    novo->prox = P;
    P = novo;
    return P;
}

void imprimePartido(Partido *P){
    Partido *aux = P;
    while(aux != NULL){
        printf("%s ", aux->sigla);
        aux = aux->prox;
    }
    printf("\n");
}

Candidato *criaCandidato(char *n){
    Candidato *novo = (Candidato*)malloc(sizeof(Candidato));
    if (novo == NULL){
        printf("Erro: problema de alocacao de memoria");
        exit(1);
    }
    strcpy(novo->nome, n);
    novo->prox = NULL;
    return novo;
}

void cadastraCandidato(Partido **P, char *n, char *s){
    Candidato *novo = criaCandidato(n);
    Partido *aux = *P;
    while(aux != NULL && strcmp(aux->sigla, s) != 0){
        aux = aux->prox;
    }

    if(strcmp(aux->sigla, s) == 0){
        if (aux->cand == NULL ) aux->cand = novo;
        else {
            novo->prox = aux->cand;
            aux->cand = novo;
        }
    }

}

void imprimeCandidato(Partido *P, char *s){
    Partido *aux = P;
    while(aux != NULL && strcmp(aux->sigla, s) != 0){
        aux = aux->prox;
    }
    while(aux->cand != NULL){
        printf("%s ", aux->cand->nome);
        aux->cand = aux->cand->prox;
    }
    printf("\n");
}

void migraDeputado(Partido *P, int num, char *n, char *atual, char *dest){
    Partido *aux1 = P, *aux2 = P;
    

}


int main(){
    Partido *P = NULL;
    P = cadastraPartido(P,"PT");
    P = cadastraPartido(P,"PTS");
    imprimePartido(P);
    cadastraCandidato(&P, "Primeiro", "PTS");
    cadastraCandidato(&P, "Geraldo", "PTS");
    cadastraCandidato(&P, "Adalberto", "PT");
    cadastraCandidato(&P, "Arto", "PT");
    cadastraCandidato(&P, "Ultimo", "PT");
    imprimeCandidato(P, "PTS");

}