#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

    int qtd_alunos;
    scanf("%d", &qtd_alunos);

    tAluno* alunos[qtd_alunos];

    for(int i=0; i<qtd_alunos; i++){
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    for(int i=0; i<qtd_alunos; i++){
        for(int j=i+1; j<qtd_alunos; j++){
            if(ComparaMatricula(alunos[i], alunos[j]) == 1){
                tAluno* temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    for(int i=0; i<qtd_alunos; i++){
        if(VerificaAprovacao(alunos[i])) ImprimeAluno(alunos[i]);
        ApagaAluno(alunos[i]);
    }

    return 0;
}