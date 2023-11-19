#include "tarefaimprime.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct impr{
    char* mensagem;
};

/**
 * @brief Cria uma tarefa do tipo impressão em tela
 * 
 * @param msg - A mensagem que deve ser impressa em tela
 *
 * @return Um ponteiro para a tarefa criada
 */
tImpr* CriaTarefaImprimir(char *msg){
    tImpr* impressao = (tImpr*) malloc (sizeof(tImpr));

    impressao->mensagem = malloc ((strlen(msg)+1)*sizeof(char));
    strcpy(impressao->mensagem, msg);
    //memcpy(impressao->mensagem, msg, tamBytesMsg);

    return impressao;
}

/**
 * @brief Função que executa uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser executada
 *
 */
void ExecutaTarefaImprimir(void *imp){
    tImpr* impTipado = (tImpr*) imp;
    printf("\n%s", impTipado->mensagem); 
}

/**
 * @brief Função que destrói (libera a memória) uma tarefa de impressão em tela
 *
 * @param imp - Ponteiro para a tarefa a ser destruída
 *
 */
void DestroiTarefaImprimir(void *imp){
    tImpr* impTipado = (tImpr*) imp;
    if(impTipado != NULL){
        if(impTipado->mensagem != NULL) free(impTipado->mensagem);
        free(impTipado);
    } 
}