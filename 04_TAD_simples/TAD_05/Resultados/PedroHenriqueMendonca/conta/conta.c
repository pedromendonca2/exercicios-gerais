#include <stdio.h>
#include "usuario.h"
#include "conta.h"

tConta CriaConta(int numero, tUsuario user){
    tConta conta;

    conta.numero = numero;
    conta.user = user;
    conta.saldo = 0;

    return conta;
}

tConta SaqueConta(tConta conta, float valor){

    conta.saldo = conta.saldo - valor;

    return conta;
}

tConta DepositoConta(tConta conta, float valor){

    conta.saldo = conta.saldo + valor;
    
    return conta;
}

void ImprimeConta(tConta conta){
    printf("Conta: %d\nSaldo: R$ %.2f\n", conta.numero, conta.saldo);
    ImprimeUsuario(conta.user);
}

int VerificaConta(tConta conta, int numero){
    if(conta.numero == numero){
        return 1;
    } else{
        return 0;
    }
}