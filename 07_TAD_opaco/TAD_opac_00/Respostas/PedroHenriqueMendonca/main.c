#include "circulo.h"
#include <stdio.h>

int main(){

    float centro_x, centro_y, raio, ponto_x, ponto_y;

    scanf("%f %f %f %f %f", &centro_x, &centro_y, &raio, &ponto_x, &ponto_y);

    tCirculo circulo = Circulo_Cria(centro_x, centro_y, raio);
    tPonto ponto = Pto_Cria(ponto_x, ponto_y);

    if(Circulo_Interior(circulo, ponto)){
        printf("1\n");
    } else{
        printf("0\n");
    }

    Circulo_Apaga(circulo);
    Pto_Apaga(ponto);

    return 0;
}