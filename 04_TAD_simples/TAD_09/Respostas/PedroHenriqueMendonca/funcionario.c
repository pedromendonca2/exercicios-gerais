#include "funcionario.h"
#include <stdio.h>

tFuncionario criaFuncionario(int id, float salario){
    tFuncionario funcionario;

    funcionario.id = id;
    funcionario.salario = salario;

    return funcionario;
}

int getIdFuncionario(tFuncionario funcionario){

    int id = funcionario.id;

    return id;
}

tFuncionario leFuncionario(){
    tFuncionario funcionario;
    int id_funcionario, salario;

    scanf("%d %d", &id_funcionario, &salario);
    funcionario = criaFuncionario(id_funcionario, salario);

    return funcionario;
}

void imprimeFuncionario(tFuncionario funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario.id, funcionario.salario);
}