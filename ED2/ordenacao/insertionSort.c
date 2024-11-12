/* Este método é usualmente utilizado para ordenar cartas de
baralho: Considere um elemento por vez, insira cada carta em
sua “posição correta” entre os elementos já considerados de
forma a mantê-los ordenados.
Para colocar o elemento considerado em sua posição “correta”,
basta movimentar os elementos maiores que ele dentre aqueles
já considerados (ordenados) uma posição para a direita e, então,
inserir o elemento considerado na posição vaga resultante.*/

#include <stdio.h>

void insertionSort(int vet[], int tam){
    int chave, i, j;
    for(j=1; j<tam; j++){
        chave = vet[j];
        i = j-1;
        while(i>=0 && vet[i]>chave){
            vet[i+1] = vet[i];
            i = i-1;
        }
        vet[i+1] = chave;
    }
}
void imprimeVetor(int V[], int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", V[i]);
    }
    printf("\n");
}
int main(){
    int vet[7] = {7, 4, 3, 8, 2, 5, 3};
    imprimeVetor(vet, 7);
    insertionSort(vet, 7);
    imprimeVetor(vet, 7);
    return 0;
}