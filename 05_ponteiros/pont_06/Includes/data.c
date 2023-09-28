#include <stdio.h> 
#include <stdlib.h> 
#include "data.h" 

int EhBissexto( tData *data){
    //DEPOIS VE SE FUNCIONA COM data->ano
    tData *p = &data;

    if ((p->ano % 4 == 0 && p->ano % 100 != 0) || (p->ano % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

void InicializaDataParam( int dia, int mes, int ano, tData *data){
    tData *p = &data;
    p->dia = dia;
    p->mes = mes;

    if(dia<=0){
        p->dia = 1;
    } else if(dia>InformaQtdDiasNoMes(&data)){
        p->dia = InformaQtdDiasNoMes(&data);
    } else{
        p->dia = dia;
    }
    if(mes<=0){
        p->mes = 1;
    } else if(mes>12){
        p->mes = 12;
    } else{
        p->mes = mes;
    }
    p->ano = ano;
}

void LeData( tData *data){
    int dia, mes, ano;
    scanf("%d %d %d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, &data);
}

int EhIgual( tData *data1, tData *data2){
    tData *p1 = &data1, *p2 = &data2; 
    if(p1->dia == p2->dia && p1->mes == p2->mes && p1->ano == p2->ano){
        return 1;
    } else{
        return 0;
    }
}

void ImprimeData( tData *data){
    tData *p = &data;
    printf("'%d/%d/%d'\n", p->dia, p->mes, p->ano);
}

int InformaQtdDiasNoMes( tData *data){

    tData *p = &data;
    int diasNoMes;

    switch (p->mes) {
        case 2:
            if(EhBissexto){
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
    tData *p = &data;

    if((p->dia)+1 <= InformaQtdDiasNoMes(&data)){
        p->dia++;
    } else if(p->mes+1 <= 12){
        p->mes++;
    } else{
        p->ano++;
    }
}
