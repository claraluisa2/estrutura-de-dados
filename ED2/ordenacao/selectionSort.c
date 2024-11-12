/*
Funcionamento: primeiro, encontre o menor elemento no arranjo
e troque-o com o elemento na primeira posição. Depois,
encontre o segundo menor elemento do arranjo e troque-o com o
elemento na segunda posição. Continue o processo até que todo
o arranjo esteja ordenado.
Tal procedimento é chamado de “ordenação por seleção” porque
ele “seleciona” o menor dos elementos do arranjo que ainda não
foram ordenados.

Considerações: - é um algorítimo estavel, ou seja, preserva a posição relativa dos elementos iguais, já que 
ele seleciona o primeiro menor elemento e compara os seguintes para ver se é maior ou não e depois não muda a posição do mesmo após por ele na posição do vetor subordenado.
 */

#include <stdio.h>

void selectionSort(int vet[], int tam){

    int i, j, min, t;

    for(i=0; i<tam; i++){
        min = i;
        for(j=i+1; j<tam; j++){
            if(vet[j] < vet[min]){
                min = j;
            }
        }
        t = vet[min];
        vet[min] = vet[i];
        vet[i] = t;
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
    selectionSort(vet, 7);
    imprimeVetor(vet, 7);
    return 0;
}


