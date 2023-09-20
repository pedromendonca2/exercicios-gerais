#include "empresa.h"
#include "funcionario.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id){
    tEmpresa empresa;

    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    return empresa;
}

tEmpresa leEmpresa(){

    tEmpresa empresa;
    int id_empresa;

    scanf("%d", &id_empresa);
    empresa = criaEmpresa(id_empresa);

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario){

    int flag=0;
    for(int i=0; i<empresa.qtdFuncionarios; i++){
        int id = getIdFuncionario(empresa.funcionarios[i]);
        if(funcionario.id == id){
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, empresa.funcionarios[i].id);
            flag=1;
        }
    }
    if(flag==0){
        empresa.qtdFuncionarios++;
        empresa.funcionarios[empresa.qtdFuncionarios] = funcionario; 
    }

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa){

    printf("Empresa %d:\n", empresa.id);
    for(int i=1; i<=empresa.qtdFuncionarios; i++){
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}