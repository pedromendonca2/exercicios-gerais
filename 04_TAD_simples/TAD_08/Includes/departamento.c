#include <stdio.h>
#include <math.h>
#include "departamento.h"

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor){
    tDepartamento departamento;
    
    int i=0;
    while(c1[i] != '\0'){
        departamento.c1[i] = c1[i];
        i++;
    }
    departamento.c1[i] = '\0';
    i=0;
    while(c2[i] != '\0'){
        departamento.c2[i] = c2[i];
        i++;
    }
    departamento.c2[i] = '\0';
    i=0;
    while(c3[i] != '\0'){
        departamento.c3[i] = c3[i];
        i++;
    }
    departamento.c3[i] = '\0';
    i=0;
    while(nome[i] != '\0'){
        departamento.nome[i] = nome[i];
        i++;
    }
    departamento.nome[i] = '\0';
    i=0;
    while(diretor[i] != '\0'){
        departamento.diretor[i] = diretor[i];
        i++;
    }
    departamento.diretor[i] = '\0';

    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    departamento.media_geral = calculaMediaGeralDepartamento(departamento);

    return departamento;
}

void imprimeAtributosDepartamento (tDepartamento depto){
    if(validaMediaDepartamento(depto.media_geral)){
        printf("ATRIBUTOS:\ndepartamento => %s\ndiretor => %s\ncurso1 => %s, media1 => %d\ncurso2 => %s, media2 => %d\ncurso3 => %s, media3 => %d\nmedia geral => %.2lf\ndesvio padrao => %.2lf\n\n", depto.nome, depto.diretor, depto.c1, depto.m1, depto.c2, depto.m2, depto.c3, depto.m3, depto.media_geral, calculaDesvioPadraoDepartamento(depto));
    }
}

double calculaDesvioPadraoDepartamento(tDepartamento depto){
    return sqrt((pow(depto.m1-depto.media_geral, 2)+pow(depto.m2-depto.media_geral, 2)+pow(depto.m3-depto.media_geral, 2))/3);
}

double calculaMediaGeralDepartamento(tDepartamento depto){
    depto.media_geral = (double)(depto.m1 + depto.m2 + depto.m3)/3;
    return depto.media_geral;
}

int validaMediaDepartamento (int media){
    if(media >=0 && media <=10){
        return 1;
    }
    return 0;
}
