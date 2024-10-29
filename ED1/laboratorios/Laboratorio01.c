#include <stdio.h>
#include <stdlib.h>

void ConverteDecimalBinario(int n){
    if (n>0){
        ConverteDecimalBinario(n/2);
        printf("%d", n%2);
    }
}

void MDC(int x, int y){
    if (x==y){
        printf("\n%d", x);
    }else{
        if(x>y){
            MDC(x-y, y);
        }else{
            MDC(y-x, x);
        }
    }
}

int main(){
    int x,y;
    ConverteDecimalBinario(10);
    printf("\nDigite dois valores: ");
    scanf("%d %d", &x, &y);
    MDC(x,y);
}