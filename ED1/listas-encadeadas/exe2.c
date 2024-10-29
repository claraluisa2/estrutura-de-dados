/*  DUPLAMENTE ENCADEADA
    1 Considere a estrutura de uma lista duplamente encadeada
    apresentada na aula.
        a Implemente uma função que recebe uma lista duplamente
        encadeada e retira e retorna o i-ésimo nó da lista. Tenha certeza
        de que tal nó existe. A lista e o número inteiro i deverão ser
        passados para a função.
        b Implemente uma funçaõ que faça a fusão de duas listas
        duplamente encadeadas ordenadas de inteiros em uma única lista
        ordenada.
        c Escreva uma função que recebe as listas L1 e L2, e remove da lista
        L1 os nós cujas posições devem ser encontradas na lista ordenada
        L2. Por exemplo, se L1 = (A B C D E) e L2 = (2 4 8), então o
        segundo e o quarto nós devem ser removidos da lista L1 (o oitavo
        nó não existe) e, depois da remoção, L1 = (A C E).
        d Escreva uma função que verifica se duas listas têm o mesmo
        conteúdo.
        e Escreva a função main com um menu para o usuário testar as
        funções implementadas acima.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *prox, *ant;
}No;

No *criaNo (int valor){
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro: problema de alocacao de memoria");
        exit(1);
    }
    novo->chave = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

