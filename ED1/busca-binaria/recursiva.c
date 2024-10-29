#include <stdio.h>
#include <stdlib.h>

int buscaBinaria(int V[], int ch, int inicio, int fim){
    int meio = (inicio + fim)/2;;

    if (V[meio] == ch || inicio>fim){
        return meio;
    }
    if(V[meio] < ch) return buscaBinaria(V, ch, meio+1, fim);
    if(V[meio] > ch) return buscaBinaria(V, ch, inicio, meio-1);

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

    x = buscaBinaria(V, ch, 0, tam-1);
    if(V[x] == ch){
        printf("A posicao %d contem o valor %d\n", x, V[x]);
    }
    else{
        printf("Valor não encontrado!\n");
    }

}