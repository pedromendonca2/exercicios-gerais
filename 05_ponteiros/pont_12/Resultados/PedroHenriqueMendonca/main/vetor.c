#include <stdio.h>
#include "vetor.h"

void LeVetor(Vetor *vetor){
    int num;

    scanf("%d", &num);
    vetor->tamanhoUtilizado = num;

    for(int i=0; i<num; i++){
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op){
    int operacao=vetor->elementos[0];
    
    for(int i=1; i<vetor->tamanhoUtilizado; i++){
        operacao = op(operacao, vetor->elementos[i]);
    }

    return operacao;
}
