#include "tarefasoma.h"
#include <stdlib.h>
#include <stdio.h>

struct soma{
    float num_1;
    float num_2;
};

/**
 * @brief Cria uma tarefa do tipo soma de dois números
 * 
 * @param n1 - Primeiro número que será somado quando a tarefa for executada
 * @param n2 - Segundo número que será somado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tSoma* CriaTarefaSoma(float n1, float n2){
    tSoma* soma = (tSoma*) malloc (sizeof(tSoma));

    soma->num_1 = n1;
    soma->num_2 = n2;

    return soma;
}

/**
 * @brief Função que executa uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaSoma(void *sum){
    tSoma* sumTipado = (tSoma*) sum;
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f", sumTipado->num_1, sumTipado->num_2, sumTipado->num_1 + sumTipado->num_2);
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de soma de dois números
 *
 * @param sum - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaSoma(void *sum){
    //tSoma* sumTipado = (tSoma*) sum;
    if(sum != NULL) free((tSoma*) sum);
}