#include <stdio.h>
#include <stdlib.h>
#include "filme.h"
#include "locadora.h"

int main(){
    tFilme Filme;
    tLocadora Locadora;
    char comando[MAX_CARACTERES], caracter;
    int codigo_filme;

    Locadora = criarLocadora();

    while(scanf("%s", comando)){
        if(comando == 'Cadastrar'){
            while(1){
                Filme = lerFilme(); //aqui entra criarFilme()
                codigo_filme = obterCodigoFilme(Filme);
                if(verificarFilmeCadastrado(Locadora, codigo_filme)){
                    printf("Filme ja cadastrado no estoque\n");
                } else{
                    Locadora = lerCadastroLocadora(Locadora); //aqui entra cadastrarFilmeLocadora()
                }
                
            }
        } else if(comando == 'Estoque'){
            consultarEstoqueLocadora(Locadora);
            if(scanf("%c", &caracter) == 1 && caracter == '#'){
                exit(0);
            }
        }
    }

    return 0;
}