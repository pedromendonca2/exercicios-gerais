#include <stdio.h>
#include "data.h"


int Reverte(int i){
    if(i<0){
        return 2*i*(-1);
    } else{
        return 0;
    }
}

int verificaBissexto(int ano){

    if (ano % 400 == 0) {
        return 1;
    } else if (ano % 100 == 0) {
        return 0;
    } else if (ano % 4 == 0) {
        return 1;
    } else {
        return 0;
    }

}

int verificaDataValida(int dia, int mes, int ano){
    if(ano <= 0){
        return 0;
    } else if(mes <= 0 || mes > 12){
        return 0;
    } else if(dia <= 0){
        return 0;
    } else if(mes == 2 && verificaBissexto(ano) && dia >= 30){
        return 0;
    } else if(mes == 2 && !(verificaBissexto(ano)) && dia >= 29){
        return 0;
    } else if((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia > 31){
        return 0;
    } else if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30){
        return 0;
    } else{
        return 1;
    }
}

void imprimeMesExtenso(int mes){
    if(mes == 1){
        printf("Janeiro");
    } else if(mes == 2){
        printf("Fevereiro");
    }
    else if(mes == 3){
        printf("Março");
    }
    else if(mes == 4){
        printf("Abril");
    }
    else if(mes == 5){
        printf("Maio");
    }
    else if(mes == 6){
        printf("Junho");
    }
    else if(mes == 7){
        printf("Julho");
    }
    else if(mes == 8){
        printf("Agosto");
    }
    else if(mes == 9){
        printf("Setembro");
    }
    else if(mes == 10){
        printf("Outubro");
    }
    else if(mes == 11){
        printf("Novembro");
    }
    else if(mes == 12){
        printf("Dezembro");
    }
}

void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    if(ano1 > ano2){
        return 1;
    } else if(ano1 < ano2){
        return -1;
    } else if(ano1 == ano2){
        if(mes1 > mes2){
            return 1;
        } else if(mes1 < mes2){
            return -1;
        } else if(mes1 == mes2){
            if(dia1 > dia2){
                return 1;
            } else if(dia1 < dia2){
                return -1;
            } else{
                return 0;
            }
        }
    }
}

int numeroDiasMes(int mes, int ano){
    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        return 31;
    } else if(mes == 4 || mes == 6 || mes == 9 || mes == 11){
        return 30;
    } else if(!(verificaBissexto(ano))){
        return 28;
    } else{
        return 29;
    }
}

int calculaDiasAteMes(int mes, int ano){

    int dias=0;

    for(int i=1; i<=mes; i++){
        dias += numeroDiasMes(i, ano);
    }

    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){

    int diferenca=0;

    if(ano1 == ano2 && mes1 == mes2 && dia1 == dia2){
        return 0;
    }

    if(ano1 == ano2){
        if(mes1 != mes2){
          diferenca += numeroDiasMes(mes1, ano1) - dia1;
          diferenca += Reverte(diferenca);
          if(mes2-mes1 >= 2){
            for(int i=mes1+1; i<mes2; i++){
                diferenca += numeroDiasMes(i, ano1);
            }
          } else if(mes1-mes2 >= 2){
            for(int i=mes2+1; i<mes1; i++){
                diferenca += numeroDiasMes(i, ano1);
            }
          }
          diferenca += dia2;
        } else{
            diferenca += dia1 - dia2;
            diferenca += Reverte(diferenca);
        }        
    } else{
        if(verificaBissexto(ano1)){
            diferenca += 366 - calculaDiasAteMes(mes1, ano1);
        } else{
            diferenca += 365 - calculaDiasAteMes(mes1, ano1);
        }
        if(ano1-ano2 >= 2){
            for(int i=ano2+1; i<=ano1-1; i++){
                if(verificaBissexto(i)){
                    diferenca += 366;
                } else{
                    diferenca += 365;
                }
            }
            diferenca += calculaDiasAteMes(mes1, ano1);
            diferenca += dia1;
        } else if(ano2-ano1 >= 2){
            for(int i=ano1+1; i<=ano2-1; i++){
                if(verificaBissexto(i)){
                    diferenca += 366;
                } else{
                    diferenca += 365;
                }
            }
            diferenca += calculaDiasAteMes(mes2, ano2);
            diferenca += dia2;
        }
    }

    return diferenca;
}
