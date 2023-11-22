#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tAluno.h"

struct _tAluno {
    char nome[50];
    int idade;
    float *notas;
    int quantidade;
};

tAluno *LeAluno() {
    tAluno *novoAluno = (tAluno *)calloc(1, sizeof(tAluno));

    if (novoAluno == NULL) {
        perror("Erro ao alocar memória para novo aluno");
        exit(EXIT_FAILURE);
    }

    printf("Nome do aluno: ");
    scanf("%s", novoAluno->nome);

    printf("Idade do aluno: ");
    scanf("%d", &novoAluno->idade);

    printf("Quantidade de notas: ");
    scanf("%d", &novoAluno->quantidade);

    novoAluno->notas = (float *)malloc(sizeof(float) * novoAluno->quantidade);

    printf("Notas do aluno:\n");
    for (int i = 0; i < novoAluno->quantidade; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &novoAluno->notas[i]);
    }

    return novoAluno;
}

void exibirAluno(tAluno *aluno) {
    printf("Nome: %s\n", aluno->nome);
    printf("Idade: %d\n", aluno->idade);

    printf("Notas: ");
    for (int i = 0; i < aluno->quantidade; i++) {
        printf("%.2f ", aluno->notas[i]);
    }

    printf("\nMédia: %.2f\n", calcularMedia(aluno));
    printf("\n");
}

float calcularMedia(tAluno *aluno) {
    float soma = 0;

    for (int i = 0; i < aluno->quantidade; i++) {
        soma += aluno->notas[i];
    }

    if (aluno->quantidade)
        return (soma / aluno->quantidade);
    else
        return 0;
}

void liberarAluno(tAluno *aluno) {
    if (!aluno) return;
    
    if (aluno->notas) free(aluno->notas);
    free(aluno);
}

void salvarAluno(tAluno *aluno, FILE *arquivo) {
    fwrite(aluno, sizeof(tAluno), 1, arquivo); 
    if (aluno->quantidade) fwrite(aluno->notas, sizeof(*(aluno->notas)), aluno->quantidade, arquivo);
}

tAluno *recuperarAluno(FILE *arquivo) {
    tAluno *aluno = (tAluno *)malloc(sizeof(tAluno));
    if (aluno == NULL) {
        perror("Erro ao alocar memória para abrir aluno");
        exit(EXIT_FAILURE);
    }

    fread(aluno, sizeof(tAluno), 1, arquivo);

    aluno->notas = (float *)malloc(sizeof(float) * aluno->quantidade);
    fread(aluno->notas, sizeof(float), aluno->quantidade, arquivo);

    return aluno;
}

