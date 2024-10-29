#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int V[], int ch, int tam){
    int inicio = 0;
    int fim = tam-1;
    int meio = (inicio + fim)/2;;


    while(V[meio] != ch){

        if (V[meio] > ch){
        fim = meio-1;
        }
        if (V[meio] < ch){
            inicio = meio+1;
        }
        if(fim<inicio){
            break;
        }

        meio = (inicio + fim)/2;

    }
    return meio;

}

int main(){

    int tam, ch, x;
    printf("Digite o tamanho do vetor: \n");
    scanf("%d", &tam);

    int *V = malloc(tam*sizeof(int));
    if(!V){
        printf("Erro em alocar de memoria");
        exit(1);
    }

    for(int i=0; i<tam; i++){
        printf("Digite um valor para a posicao %d do vetor: \n", i);
        scanf("%d", &V[i]);
    }
    for(int i=0; i<tam; i++){
        printf("%d ", V[i]);
    }
    printf("\n");

    printf("Digite um valor para buscar no vetor: \n");
    scanf("%d", &ch);
    x = buscaBinaria(V, ch, tam);
    if(V[x] == ch){
        printf("A posicao %d contem o valor %d\n", x, V[x]);
    }
    else{
        printf("Valor não encontrado!\n");
    }

}