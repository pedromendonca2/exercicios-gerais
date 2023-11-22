#include <stdio.h>
#include "pessoa.h"

int main(){

    int num_pessoas;

    scanf("%d", &num_pessoas);
    tPessoa pessoas[num_pessoas];

    for(int i=0; i<num_pessoas; i++){
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas, num_pessoas);

    for(int i=0; i<num_pessoas; i++){
        ImprimePessoa(&pessoas[i]); 
    }

    return 0;
}