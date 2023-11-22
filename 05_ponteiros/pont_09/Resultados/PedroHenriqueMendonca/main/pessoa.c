#include <stdio.h>
#include <string.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa pessoa;
    
    pessoa.pai = NULL;
    pessoa.mae = NULL;
    pessoa.nome[0] = '\0'; //INVESTIGA ISSO

    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    scanf("\n%[^\n]", pessoa->nome);
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas){
    int qtd, mae, pai, filho;
    scanf("%d\n", &qtd);

    for(int i=0; i<qtd; i++){
        scanf("mae: %d, pai: %d, filho: %d%*c", &mae, &pai, &filho); 
        if(pai != -1){
            pessoas[filho].pai = &pessoas[pai];
        } 
        if(mae != -1){
            pessoas[filho].mae = &pessoas[mae];
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

    if(VerificaSeTemPaisPessoa(pessoa)){
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        if(pessoa->pai != NULL){
            printf("PAI: %s\n", pessoa->pai->nome);
        } else{
            printf("PAI: NAO INFORMADO\n");
        }

        if(pessoa->mae != NULL){
            printf("MAE: %s\n\n", pessoa->mae->nome);
        } else{
            printf("MAE: NAO INFORMADO\n\n");
        }
    }

}