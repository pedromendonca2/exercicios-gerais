#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "relatorio.h"

int main(){

    int qtd_alunos;
    Vector* alunos = VectorConstruct();

    scanf("%d", &qtd_alunos);

    for(int i=0; i<qtd_alunos; i++){
        //data_type aluno_atual = VectorGet(alunos, i); 
        tAluno* aluno = CriaAluno();
        LeAluno(aluno);
        VectorPushBack(alunos, (data_type)aluno);
    } 

    ImprimeRelatorio(alunos);

    VectorDestroy(alunos, DestroiAluno);

    return 0;
}