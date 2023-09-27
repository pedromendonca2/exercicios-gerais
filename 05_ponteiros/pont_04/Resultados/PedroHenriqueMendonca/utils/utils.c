#include <stdio.h> 
#include <stdlib.h> 
#include "utils.h" 

void LeNumeros(int *array, int tamanho){
    int n;
    for(int i=0; i<tamanho; i++){
        scanf("%d", &n);
        array[i] = n;
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media){
    int soma = 0;
    *menor = array[0];
    *maior = array[0];

    for(int i=0; i<tamanho; i++) {
        if (array[i] < *menor) {
            *menor = array[i];
        } else if(array[i] > *maior){
            *maior = array[i];
        }
        soma += array[i];
    }

    *media = (float) soma/(tamanho);

}