#include <stdio.h>
#include <stdlib.h>
#include "tPauta.h"
#include "tAluno.h"

struct _tPauta {
    tAluno **alunos;
    int quantidade;
};

tPauta *criarPauta() {
    tPauta *novaPauta = (tPauta *)malloc(sizeof(tPauta));

    if (novaPauta == NULL) {
        perror("Erro ao alocar memória para nova pauta");
        exit(EXIT_FAILURE);
    }

    novaPauta->alunos = NULL;
    novaPauta->quantidade = 0;

    return novaPauta;
}

void adicionarAlunoPauta(tPauta *pauta, tAluno *aluno) {
    pauta->quantidade++;
    pauta->alunos = (tAluno **)realloc(pauta->alunos, sizeof(tAluno*) * pauta->quantidade);
    pauta->alunos[pauta->quantidade - 1] = aluno;
}

void exibirPauta(tPauta *pauta) {
    for (int i = 0; i < pauta->quantidade; i++) {
        printf("Aluno (%d):\n", i+1);
        exibirAluno(pauta->alunos[i]);
    }
    if (pauta->quantidade == 0) printf("Pauta vazia\n");
}

void liberarPauta(tPauta *pauta) {
    if (!pauta) return;
        
    for (int i = 0; i < pauta->quantidade; i++) {
        liberarAluno(pauta->alunos[i]);
    }
    if (pauta->alunos) free(pauta->alunos);
    free(pauta);
}

void salvarPauta(tPauta *pauta) {
    FILE *arquivo = fopen("pauta.bin", "wb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para salvar");
        exit(EXIT_FAILURE);
    }

    fwrite(&pauta->quantidade, sizeof(int), 1, arquivo);

    for (int i = 0; i < pauta->quantidade; i++) {
        exibirAluno(pauta->alunos[i]);
        salvarAluno(pauta->alunos[i], arquivo);
    }

    fclose(arquivo);
}

tPauta *recuperarPauta() {
    FILE *arquivo = fopen("pauta.bin", "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo para abrir");
        exit(EXIT_FAILURE);
    }

    tPauta *pauta = criarPauta();

    fread(&pauta->quantidade, sizeof(int), 1, arquivo);

    pauta->alunos = (tAluno **)malloc(sizeof(tAluno*) * pauta->quantidade);

    for (int i = 0; i < pauta->quantidade; i++) {
        pauta->alunos[i] = recuperarAluno(arquivo);
    }

    fclose(arquivo);

    return pauta;
}

