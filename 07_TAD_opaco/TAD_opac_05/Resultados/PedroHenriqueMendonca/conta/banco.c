#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "banco.h"
#include "conta.h"

struct Banco{
    tConta** contas;
    int qtd_contas;
};

/**
 * @brief Cria um novo banco, com 5 contas alocadas e nenhuma conta aberta.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo banco criado.
 */
tBanco *CriaBanco(){
    tBanco* banco = malloc (sizeof(tBanco));
    if(banco == NULL) exit(0);

    banco->contas = malloc (5*sizeof(tConta*));
    if(banco->contas == NULL){
        free(banco);
        exit(0);
    }

    // for(int i=0; i<5; i++){
    //     banco->contas[i] = CriaConta();
    // }

    banco->qtd_contas = 0;

    return banco;
}

/**
 * @brief Desaloca a memória de um banco e de todas as suas contas.
 * 
 * @param banco Ponteiro para o banco a ser destruído.
 */
void DestroiBanco(tBanco *banco){
    if(banco != NULL){
        for(int i=0; i<5; i++){
            DestroiConta(banco->contas[i]);
        }
        free(banco->contas); //VERIFICA SE EH NECESSARIO MESMO
        free(banco);
    }
}

/**
 * @brief Abre uma nova conta no banco e a adiciona ao vetor de contas.
 * 
 * @param banco Ponteiro para o banco onde a conta será aberta.
 */
void AbreContaBanco(tBanco *banco){
    if(banco->qtd_contas > 4){
        banco->contas = realloc(banco->contas, sizeof(tConta*));
        if(banco->contas == NULL){
            exit(0);
        }
    }
    banco->contas[banco->qtd_contas] = CriaConta();
    LeConta(banco->contas[banco->qtd_contas]);
    (banco->qtd_contas)++;
}

/**
 * @brief Realiza um saque em uma conta do banco se ela existir e tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta e o valor do saque.
 * 
 * @param banco Ponteiro para o banco onde a conta será sacada.
 */
void SaqueContaBanco(tBanco *banco){
    int numConta;
    float valor;

    scanf("%d %f\n", &numConta, &valor);

    SaqueConta(banco->contas[numConta-1], valor);
}

/**
 * @brief Realiza um depósito em uma conta do banco se ela existir.
 * Nessa função é necessário ler o número da conta e o valor do depósito. 
 * 
 * @param banco Ponteiro para o banco onde a conta será depositada.
 */
void DepositoContaBanco(tBanco *banco){
    int numConta;
    float valor;

    scanf("%d %f\n", &numConta, &valor);

    DepositoConta(banco->contas[numConta-1], valor);
}

/**
 * @brief Realiza uma transferência entre duas contas do banco se elas existirem e a conta de origem tiver saldo suficiente.
 * Nessa função é necessário ler o número da conta de origem, o número da conta de destino e o valor da transferência.
 * 
 * @param banco Ponteiro para o banco onde as contas estão.
 */
void TransferenciaContaBanco(tBanco *banco){
    int numConta_1, numConta_2;
    float valor;

    scanf("%d %d %f\n", &numConta_1, &numConta_2, &valor);

    if(numConta_1-1 <= banco->qtd_contas && numConta_1-1 > 0 && numConta_2-1 <= banco->qtd_contas && numConta_2-1 > 0){
        TransferenciaConta(banco->contas[numConta_2-1], banco->contas[numConta_1-1], valor);
    }
}

/**
 * @brief Imprime o relatório do banco, com todas as contas e seus respectivos dados.
 * 
 * @param banco Ponteiro para o banco a ser impresso.
 */
void ImprimeRelatorioBanco(tBanco *banco){
    printf("===| Imprimindo Relatorio |===\n");
    for(int i=0; i<banco->qtd_contas; i++){
        ImprimeConta(banco->contas[i]);
    }
}

