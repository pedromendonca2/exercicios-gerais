#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

void LeAluno(tAluno *aluno){
    
    //aluno->nome = (char*)malloc(100 * sizeof(char));
    
    scanf(" %[^\n]%*c", aluno->nome);
    scanf("%d%*c", &aluno->matricula);
    scanf("%d %d %d%*c", &aluno->n1, &aluno->n2, &aluno->n3);
}

tAluno* CriaAluno(){
    
    //tAluno *aluno;
    tAluno *aluno = (tAluno *) malloc(sizeof(tAluno));

    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;
}

int CalculaMediaAluno(tAluno *aluno){
    return (aluno->n1 + aluno->n2 + aluno->n3)/3;
}

int ComparaMatricula(tAluno *aluno1, tAluno *aluno2){

    if(aluno1->matricula > aluno2->matricula){
        return 1;
    } else if (aluno1->matricula < aluno2->matricula){
        return -1;
    } else{
        return 0;
    }

}

int VerificaAprovacao(tAluno *aluno){

    if(CalculaMediaAluno(aluno) >= 7){
        return 1;
    } else{
        return 0;
    }

}

void ImprimeAluno(tAluno *aluno){
    printf("%s\n", aluno->nome);
}

void ApagaAluno(tAluno *aluno){
    free(aluno->nome);
    //free(aluno);
} 
