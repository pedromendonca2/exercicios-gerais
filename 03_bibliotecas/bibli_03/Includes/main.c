#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main(){

    int dia_1, mes_1, ano_1, dia_2, mes_2, ano_2;

    scanf("%d/%d/%d", &dia_1, &mes_1, &ano_1);
    if(!(verificaDataValida(dia_1, mes_1, ano_1))){
        printf("A primeira e/ou segunda data(s) invalida(s)");
        exit(0);
    } else{
        printf("Primeira data: ");
        imprimeDataExtenso(dia_1, mes_1, ano_1);
    }

    scanf("%d/%d/%d", &dia_2, &mes_2, &ano_2);
    if(!(verificaDataValida(dia_2, mes_2, ano_2))){
        printf("Ap rimeira e/ou segunda data(s) invalida(s)");
        exit(0);
    } else{
        printf("Segunda data: ");
        imprimeDataExtenso(dia_2, mes_2, ano_2);
    }

    if(comparaData(dia_1, mes_1, ano_1, dia_2, mes_2, ano_2) == 1){
        printf("A segunda data eh mais antiga\n");
    } else if(comparaData(dia_1, mes_1, ano_1, dia_2, mes_2, ano_2) == -1){
        printf("A primeira data eh mais antiga\n");
    } else if(comparaData(dia_1, mes_1, ano_1, dia_2, mes_2, ano_2) == 0){
        printf("As datas sao iguais\n");
    }

    printf("A diferenca em dias entre as datas eh: %d dias\n", calculaDiferencaDias(dia_1, mes_1, ano_1, dia_2, mes_2, ano_2));
    
    return 0;
}