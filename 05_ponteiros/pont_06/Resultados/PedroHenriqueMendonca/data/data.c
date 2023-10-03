#include <stdio.h> 
#include <stdlib.h> 
#include "data.h" 

int EhBissexto( tData *data){
    //DEPOIS VE SE FUNCIONA COM data->ano
    // tData *p = &data;

    if ((data->ano % 4 == 0 && data->ano % 100 != 0) || (data->ano % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    // tData *p = &data;
    data->dia = dia;
    data->mes = mes;

    if(dia<=0){
        data->dia = 1;
    } else if(dia>InformaQtdDiasNoMes(data)){
        data->dia = InformaQtdDiasNoMes(data);
    } 

    if(mes<=0){
        data->mes = 1;
    } else if(mes>12){
        data->mes = 12;
    } 

    data->ano = ano;
}

void LeData( tData *data){
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);
}

int EhIgual( tData *data1, tData *data2){
    // tData *p1 = &data1, *p2 = &data2; 
    if(data1->dia == data2->dia && data1->mes == data2->mes && data1->ano == data2->ano){
        return 1;
    } else{
        return 0;
    }
}

void ImprimeData( tData *data){
    // tData *p = &data;
    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}

int InformaQtdDiasNoMes( tData *data){

    // tData *p = &data;
    int diasNoMes;

    switch (data->mes) {
        case 2:
            if(EhBissexto(data)){
                diasNoMes = 29;
            } else{
                diasNoMes = 28;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            diasNoMes = 30; // Abril, junho, setembro e novembro têm 30 dias.
            break;
        default:
            diasNoMes = 31; // Todos os outros meses têm 31 dias.
            break;
    }

    return diasNoMes;
}

void AvancaParaDiaSeguinte( tData *data){
    // tData *p = &data;

    if((data->dia)+1 <= InformaQtdDiasNoMes(data)){
        data->dia++;
    } else if(data->mes+1 <= 12){
        data->mes++;
        data->dia = 1;
    } else{
        data->ano++;
        data->dia = 1;
        data->mes = 1;
    }
}
