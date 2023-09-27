#include <stdio.h> 
#include <stdlib.h> 
#include "vetor.h" 

void LeDadosParaVetor(int * vet, int tam){
    int n;

    for(int i=0; i<tam; i++){
        scanf("%d", &n);
        vet[i] = n;
    }
}

void ImprimeDadosDoVetor(int * n, int tam){
    for(int i=0; i<tam; i++){
        printf("%d ", n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int * vet, int tam, int * paraTrocar){

    int savevalue;

    for(int i=0; i<tam-1; i++){
        for(int j=i+1; j<tam; j++){
            if(vet[i] > vet[j]){
                paraTrocar = vet;
                savevalue = *(paraTrocar+j);
                *(paraTrocar+j) = vet[i];
                vet[i] = savevalue;
            }
        }
    }
}

void OrdeneCrescente(int * vet, int tam){

    int *paraTrocar;
    TrocaSeAcharMenor(vet, tam, paraTrocar);

}