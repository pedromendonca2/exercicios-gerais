#include "tarefamultiplica.h"
#include <stdlib.h>
#include <stdio.h>


struct mult{
    float num_1;
    float num_2;
};

/**
 * @brief Cria uma tarefa do tipo multiplicação de dois números
 * 
 * @param n1 - Primeiro número que será multiplicado quando a tarefa for executada
 * @param n2 - Segundo número que será multiplicado quando a tarefa for executada
 *
 * @return Um ponteiro para a tarefa criada
 */
tMult* CriaTarefaMultiplicar(float n1, float n2){
    tMult* multiplicacao = (tMult*) malloc (sizeof(tMult));

    multiplicacao->num_1 = n1;
    multiplicacao->num_2 = n2;

    return multiplicacao;
}

/**
 * @brief Função que executa uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaMultiplicar(void *mult){
    tMult* multTipado = (tMult*) mult;
    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f", multTipado->num_1, multTipado->num_2, multTipado->num_1 + multTipado->num_2); 
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de multiplicação de dois números
 *
 * @param mult - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaMultiplicar(void *mult){
    if(mult != NULL) free((tMult*) mult);
}