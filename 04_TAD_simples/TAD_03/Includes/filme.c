#include <stdio.h>
#include "filme.h"

tFilme lerFilme (){
    tFilme filme;

    int codigo, valor, qtd;
    char nome[MAX_CARACTERES];
    scanf("%d,%s,%d,%d", &codigo, &nome, &valor, &qtd);
    
    filme = criarFilme(nome, codigo, valor, qtd);

    return filme;
}

tFilme criarFilme (char* nome, int codigo, int valor, int quantidade);