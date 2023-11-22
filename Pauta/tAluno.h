#ifndef ALUNO_H
#define ALUNO_H

typedef struct _tAluno tAluno;

tAluno *LeAluno();
void exibirAluno(tAluno *aluno);
float calcularMedia(tAluno *aluno);
void liberarAluno(tAluno *aluno);
void salvarAluno(tAluno *aluno, FILE *arquivo);
tAluno *recuperarAluno(FILE *arquivo);

#endif