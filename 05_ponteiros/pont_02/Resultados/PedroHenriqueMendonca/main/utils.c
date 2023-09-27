#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void LeIntervalo(int * m, int * n){
    int n1, n2;

    scanf("%d %d", &n1, &n2);

    *m = n1;
    *n = n2;
}   

int EhPrimo(int n){

    if (n <= 1) {
        return 0;
    }

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior){

    int vetor[n-m+1];
    int i, j=0;

    for(i=m; i<=n; i++){
        if(EhPrimo(i)){
            vetor[j] = i;
            j++;
        }
    }

    *menor = vetor[0];
    *maior = vetor[j-1];
}
