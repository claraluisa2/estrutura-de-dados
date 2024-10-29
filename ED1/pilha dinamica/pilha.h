#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct no{
    int chave;
    struct no *prox;
}No;

typedef struct pilha{
    No *topo;
    int tamanho;
} Pilha;


Pilha *criaPilha();
No *criaNo(int ch);

/* A função empilha funciona de modo semelhante a insereInicio, sempre acrescenta um novo nó no inicio da Lista (ou um novo nó no topo da Pilha )*/
void empilha(Pilha *P, int ch);

/* A função desempilha funciona de modo semelhante a removeInicio, sempre excluindo um novo nó do inicio da Lista (ou desempilhando um nó do topo da Pilha )*/
void desempilha(Pilha *P);

int vazia(Pilha *P); // verifica se a pilha está vazia
void esvazia(Pilha *P);
void imprimePilha(Pilha *P);
#endif