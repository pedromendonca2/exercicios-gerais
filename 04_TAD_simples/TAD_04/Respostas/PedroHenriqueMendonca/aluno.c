#include <stdio.h>
#include "aluno.h"

tAluno LeAluno(){
    char nome[50];
    int matricula, n1, n2, n3;
    tAluno aluno;

    scanf("%s %d %d %d %d", nome, &matricula, &n1, &n2, &n3);
    aluno = CriaAluno(nome, matricula, n1, n2, n3);

    return aluno;
}

tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3){
    tAluno aluno;
    int i=0;

    while(nome[i] != '\0'){
        aluno.nome[i] = nome[i];
        i++;
    }
    aluno.nome[i] = '\0';
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

int CalculaMediaAluno(tAluno aluno){
    return (aluno.n1 + aluno.n2 + aluno.n3)/3;
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2){

    if(aluno1.matricula > aluno2.matricula){
        return 1;
    } else if (aluno1.matricula < aluno2.matricula){
        return -1;
    } else{
        return 0;
    }

}

int VerificaAprovacao(tAluno aluno){

    if(CalculaMediaAluno(aluno) >= 7){
        return 1;
    } else{
        return 0;
    }

}

void ImprimeAluno(tAluno aluno){
    printf("%s\n", aluno.nome);
}