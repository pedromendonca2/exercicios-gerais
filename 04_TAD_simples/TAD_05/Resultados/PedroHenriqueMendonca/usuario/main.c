#include <stdio.h>
#include "usuario.h"
#include "conta.h"

int main(){

    char nome[50], cpf[15];
    int n, num, num_conta;
    float valor;
    scanf("%d", &n);
    tConta vetor_contas[n];
    tUsuario usuario;

    for(int i=0; i<n; i++){
        if(scanf("%d", &num) == 1 && num == 3){
            scanf(" %s", nome);
            scanf(" %s", cpf);
            scanf("%d", &num_conta);
            usuario = CriaUsuario(nome, cpf);
            vetor_contas[num_conta-1] = CriaConta(num_conta, usuario); 
        }
    }

    while(1){
        scanf("%d", &num);
        if(num == 1){
            scanf("%d %f", &num_conta, &valor);
            for(int i=0; i<n; i++){
                if(VerificaConta(vetor_contas[i], num_conta)){
                    vetor_contas[i] = SaqueConta(vetor_contas[i], valor);
                }
            }
        } else if(num == 2){
            scanf("%d %f", &num_conta, &valor);
            for(int i=0; i<n; i++){
                if(VerificaConta(vetor_contas[i], num_conta)){
                    vetor_contas[i] = DepositoConta(vetor_contas[i], valor);
                }
            }
        } else if(num == 4){
            printf("===| Imprimindo Relatorio |===\n");
            for(int i=0; i<n; i++){
                ImprimeConta(vetor_contas[i]);
                printf("\n"); 
            }
        } else if(num == 0){
            break;
        }
    }

    return 0;
}