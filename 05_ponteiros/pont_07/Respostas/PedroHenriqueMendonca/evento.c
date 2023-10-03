#include <stdio.h> 
#include <string.h>
#include "evento.h" 

void cadastrarEvento(Evento* eventos, int* numEventos){
    if((*numEventos)+1 > MAX_EVENTOS){
        printf("Limite de eventos atingido!\n");
    } else{
        scanf("%s %d %d %d", eventos[*numEventos].nome, &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
        printf("Evento cadastrado com sucesso!\n"); 
        (*numEventos)++;
    }
}

void exibirEventos(Evento* eventos, int* numEventos){
    if(*numEventos == 0){
        printf("Nenhum evento cadastrado.\n");
    } else{
        printf("Eventos cadastrados:\n");
        for(int i=0; i<*numEventos; i++){
            printf("%d - %s - %d/%d/%04d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
        }
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos){
    int num, dia, mes, ano;
    scanf("%d", &num);
    if((num > *numEventos) || (*numEventos == 0 && num == 0)){
        printf("Indice invalido!\n");
    } else{
        scanf("%d %d %d", &dia, &mes, &ano);
        printf("Data modificada com sucesso!\n");
        eventos[num].dia = dia;
        eventos[num].mes = mes;
        eventos[num].ano = ano; 
    }
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos){
    if(*indiceA < 0 || *indiceA >= *numEventos || *indiceB < 0 || *indiceB >= *numEventos){
        printf("Indices invalidos!\n");
    } else{
        printf("Eventos trocados com sucesso!\n");
    }

    int salva_dia = eventos[*indiceA].dia;
    int salva_mes = eventos[*indiceA].mes;
    int salva_ano = eventos[*indiceA].ano;
    char salva_nome[50];
    strcpy(salva_nome, eventos[*indiceA].nome);

    eventos[*indiceA].dia = eventos[*indiceB].dia;
    eventos[*indiceA].mes = eventos[*indiceB].mes;
    eventos[*indiceA].ano = eventos[*indiceB].ano;
    strcpy(eventos[*indiceA].nome, eventos[*indiceB].nome);

    eventos[*indiceB].dia = salva_dia;
    eventos[*indiceB].mes = salva_mes;
    eventos[*indiceB].ano = salva_ano;
    strcpy(eventos[*indiceB].nome, salva_nome);
}
