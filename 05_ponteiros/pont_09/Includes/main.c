#include <stdio.h>
#include "pessoa.h"

int main(){

    tPessoa pessoas[100];
    int num_pessoas;

    scanf("%d", &num_pessoas);

    for(int i=0; i<num_pessoas; i++){
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(&pessoas);

    for(int i=0; i<num_pessoas; i++){
        ImprimePessoa(&pessoas[i]);
    }

    return 0;
}