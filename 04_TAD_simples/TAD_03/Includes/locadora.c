#include <stdio.h>
#include "filme.h"
#include "locadora.h"

tLocadora criarLocadora (){
    tLocadora locadora;

    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

int verificarFilmeCadastrado (tLocadora locadora, int codigo){

    int codigo_atual;

    for(int i=0; i < locadora.numFilmes; i++){
        codigo_atual = obterCodigoFilme(locadora.filme[i]);
        if(codigo_atual == codigo){
            return 1;
        }
    }

    return 0;
}

tLocadora lerCadastroLocadora (tLocadora locadora){

    // int codigo, valor, qtd;
    // char nome[MAX_CARACTERES];
    // scanf("%d,%s,%d,%d", &codigo, &nome, &valor, &qtd);
    locadora = cadastrarFilmeLocadora (locadora, nome, codigo, valor, qtd);

    return locadora;
}

tLocadora cadastrarFilmeLocadora (tLocadora locadora, char* nome, int codigo, int valor, int quantidade){

    int i=0;
    while(nome[i] != '\0'){
        locadora.filme[locadora.numFilmes].nome[i] = nome[i];
        i++;
    }
    locadora.filme[locadora.numFilmes].nome[i] = '\0';
    locadora.filme[locadora.numFilmes].codigo = codigo;
    locadora.filme[locadora.numFilmes].valor = valor;
    locadora.filme[locadora.numFilmes].qtdEstoque++;

    return locadora;
}

void consultarEstoqueLocadora (tLocadora locadora){
    printf("~ESTOQUE~\n");
    for(int i=0; i<locadora.numFilmes; i++){
       printf("%d - %s Fitas em estoque: %d\n", locadora.filme[i].codigo, locadora.filme[i].nome, locadora.filme[i].qtdEstoque); 
    }
    
}