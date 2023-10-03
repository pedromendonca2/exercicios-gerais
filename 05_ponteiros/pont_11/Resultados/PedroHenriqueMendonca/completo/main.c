#include <stdio.h>
#include "calculadora.h"

float adicao(float num1, float num2){
    return num1 + num2;
}

float subtracao(float num1, float num2){
    return num1 - num2;
}

float multiplicacao(float num1, float num2){
    return num1 * num2;
}

float divisao(float num1, float num2){
    return num1 / num2;
}

int main(){

    char letra;
    float n1, n2;

    while(1){
        scanf("%c", &letra);
        if(letra == 'f'){
            break;
        }
        scanf("%f %f", &n1, &n2);
        if(letra == 'a'){
           printf("%.2f + %.2f = %.2f\n", n1, n2, Calcular(n1, n2, adicao));
        } else if(letra == 's'){
            printf("%.2f - %.2f = %.2f\n", n1, n2, Calcular(n1, n2, subtracao));
        } else if(letra == 'm'){
            printf("%.2f x %.2f = %.2f\n", n1, n2, Calcular(n1, n2, multiplicacao));
        } else if(letra == 'd'){
            printf("%.2f / %.2f = %.2f\n", n1, n2, Calcular(n1, n2, divisao));
        }
        
    }

    return 0;
}