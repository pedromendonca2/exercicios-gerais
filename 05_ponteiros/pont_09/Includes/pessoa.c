#include <stdio.h>
#include "pessoa.h"

tPessoa CriaPessoa(){
    tPessoa pessoa;
    // tPessoa *p = &pessoa;
    // p->pai->nome = NULL;
    // p->mae = NULL;
    //pessoa.pai->nome = NULL;
    //pessoa.mae->nome = NULL;
    // scanf("%100[^\n]", p->nome);
    LePessoa(&pessoa);

    return pessoa;
}

void LePessoa(tPessoa *pessoa){
    scanf("%100[^\n]", &pessoa->nome);
}