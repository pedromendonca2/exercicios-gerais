#include <stdio.h>
#include <stdio.h>
#include "empresa.h"
#include "funcionario.h"

int main(){

    int qtd_geral, qtd_funcionarios, id_empresa, id_funcionario, salario;
    tEmpresa empresa;
    tFuncionario funcionario;

    scanf("%d", &qtd_geral);

    for(int i=1; i<=qtd_geral; i++){

        empresa = leEmpresa();

        scanf("%d", &qtd_funcionarios);

        for(int j=0; j<qtd_funcionarios; j++){
            funcionario = leFuncionario();
            empresa = contrataFuncionarioEmpresa(empresa, funcionario);
        }
        
        imprimeEmpresa(empresa);
    }

    return 0;
}