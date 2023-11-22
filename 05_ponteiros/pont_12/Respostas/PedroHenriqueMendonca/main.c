#include <stdio.h>
#include "vetor.h"

int soma(int n1, int n2){
    return n1+n2;
}

int produto(int n1, int n2){
    return n1*n2;
}

int main(){

    Vetor vetor;

    LeVetor(&vetor);

    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, soma));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, produto));

    return 0;
}