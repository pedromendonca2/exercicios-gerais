#include <stdio.h>
#include "usuario.h"


tUsuario CriaUsuario(char nome[20], char cpf[15]){
    tUsuario usuario;
    int i=0;

    while(cpf[i] != '\0'){
        usuario.cpf[i] = cpf[i];
        i++;
    }
    usuario.cpf[i] = '\0';

    i=0;
    while(nome[i] != '\0'){
        usuario.nome[i] = nome[i];
        i++;
    }
    usuario.nome[i] = '\0';

    return usuario;
}

void ImprimeUsuario(tUsuario user){
    printf("Nome: %s\nCPF: %s\n", user.nome, user.cpf);
}