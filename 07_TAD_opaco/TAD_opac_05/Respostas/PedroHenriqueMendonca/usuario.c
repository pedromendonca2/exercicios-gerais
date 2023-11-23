#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "usuario.h"

struct Usuario{
    char* nome;
    int CPF;
};

/**
 * @brief Cria um novo usuário.
 * Se não for possível alocar memória, o programa é encerrado.
 * 
 * @return Um ponteiro para o novo usuário criado.
 */
tUsuario *CriaUsuario(){
    tUsuario* usuario = malloc (sizeof(tUsuario));

    if(usuario == NULL) exit(0);

    usuario->nome = NULL;
    usuario->CPF = 0;

    return usuario;
}

/**
 * @brief Desaloca a memória de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser destruído.
 */
void DestroiUsuario(tUsuario *user){
    if(user != NULL){
        if(user->nome != NULL) free (user->nome);
        free(user);
    }
}

/**
 * @brief Lê os dados de um usuário da entrada padrão.
 * 
 * @param user Ponteiro para o usuário a ser lido.
 */
void LeUsuario(tUsuario *user){
    char nome[100];
    scanf(" %[^\n]", nome);
    scanf(" %d", &user->CPF);

    user->nome = malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(user->nome, nome);
}

/**
 * @brief Imprime os dados de um usuário.
 * 
 * @param user Ponteiro para o usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario *user){
    printf("Nome: %s\nCPF: %d\n", user->nome, user->CPF);
}