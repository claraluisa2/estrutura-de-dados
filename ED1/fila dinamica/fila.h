#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct no{
    int chave;
    struct no *prox;
}No;

typedef struct fila{
    No *prim;
    No *ult;
    int tamanho;
} Fila;

Fila *criaFila();
No *criaNo(int ch);
void enfila(Fila *F, int ch);
void desenfila(Fila *F);
void imprimeFila(Fila *F);
int vazia(Fila *F);
void esvazia(Fila *F);

#endif