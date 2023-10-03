#include <stdio.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa pessoa;
    char mensagem[20] = "NAO INFORMADO";
    strcpy(pessoa.mae->nome, mensagem);
    strcpy(pessoa.pai->nome, mensagem);
    LePessoa(&pessoa);

    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    scanf("%100[^\n]", pessoa->nome);
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int qtd, mae, pai, filho;
    scanf("%d", &qtd);

    for(int i=0; i<qtd; i++){
        scanf("mae: %d, pai: %d, filho: %d", &mae, &pai, &filho); 
        if(pai != -1){
            strcpy(pessoas[filho].pai->nome, pessoas[mae].nome);
        } 
        if(mae != -1){
            strcpy(pessoas[filho].mae->nome, pessoas[mae].nome);
        }   
    }
    
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa){
    if(pessoa->pai != NULL || pessoa->mae != NULL){
        return 1;
    } else{
        return 0;
    }
}

void ImprimePessoa(tPessoa *pessoa){
    printf("NOME COMPLETO: %s\nPAI: %s\nMAE: %s\n", pessoa->nome, pessoa->pai->nome, pessoa->mae->nome);
}