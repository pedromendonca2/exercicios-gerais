#ifndef PAUTA_H
#define PAUTA_H

#include "tAluno.h"

typedef struct _tPauta tPauta;

tPauta *criarPauta();
void adicionarAlunoPauta(tPauta *pauta, tAluno *aluno);
void exibirPauta(tPauta *pauta);
void liberarPauta(tPauta *pauta);
void salvarPauta(tPauta *pauta);
tPauta *recuperarPauta();

#endif
