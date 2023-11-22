#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(){

    int n, num_aprovados=0;
    scanf("%d", &n);
    tAluno *aluno, *vetor_alunos[n];

    for(int i=0; i<n; i++){

        aluno = CriaAluno();
        LeAluno(aluno);

        if(VerificaAprovacao(aluno)){
            vetor_alunos[num_aprovados] = aluno;
            num_aprovados++;
        }
    }

    for(int i=0; i<num_aprovados; i++){
        for(int j=i+1; j<num_aprovados; j++){
            if(ComparaMatricula(vetor_alunos[i], vetor_alunos[j]) == 1){
                tAluno* temp = vetor_alunos[i];
                vetor_alunos[i] = vetor_alunos[j];
                vetor_alunos[j] = temp;
            }
        }
    }

    for(int i=0; i<num_aprovados; i++){
        ImprimeAluno(vetor_alunos[i]);
        ApagaAluno(vetor_alunos[i]);
    }

    return 0;
}