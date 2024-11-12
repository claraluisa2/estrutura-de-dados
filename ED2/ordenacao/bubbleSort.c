/*
Funcionamento básico:
Percorra o vetor e compare cada par de elementos adjacentes.
Se o elemento atual for maior (ou menor, dependendo da ordenação desejada) que o próximo, troque-os de posição.
Repita esse processo para todos os elementos do vetor.
A cada passagem, o próximo maior elemento é colocado na posição correta, então o número de elementos a serem verificados diminui.
Complexidade:
Pior e médio caso: O(n²), pois exige comparações repetidas para cada par de elementos.
Melhor caso: O(n), quando o vetor já está ordenado (com uma verificação adicional para parar o loop).
*/
#include <stdio.h>

void bubbleSort(int vet[], int size){
    int i, j, t;
    for(i=size; i>=0; i--){
        for(j=1; j<i; j++){
            if (vet[j-1]>vet[j]){
                t = vet[j-1];
                vet[j-1] = vet[j];
                vet[j] = t;
            }
        }
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
    bubbleSort(vet, 7);
    imprimeVetor(vet, 7);
    return 0;
}