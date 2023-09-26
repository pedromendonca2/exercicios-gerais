#include <stdio.h>
#include "matrix_utils.h"

int main(){

    int l1, c1, l2, c2, digito, escalar, escolha;

    scanf("%d %d", &l1, &c1);
    int matriz1[l1][c1];
    matrix_read(l1, c1, matriz1);

    scanf("%d %d", &l2, &c2);
    int matriz2[l2][c2];
    matrix_read(l2, c2, matriz2);

    int matrizfinal[l1][c1];

    while(1){
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\nOpcao escolhida:\n");
        scanf("%d", &digito);

        if(digito == 1){
            if(possible_matrix_sum(l1, c1, l2, c2)){
                matrix_add(l1, c1, matriz1, l2, c2, matriz2, matrizfinal);
                matrix_print(l1, c1, matrizfinal);
            } else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        } else if(digito == 2){
            if(possible_matrix_sub(l1, c1, l2, c2)){
                matrix_sub(l1, c1, matriz1, l2, c2, matriz2, matrizfinal);
                matrix_print(l1, c1, matrizfinal);
            } else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        } else if(digito == 3){
            if(possible_matrix_multiply(c1, l2)){
                matrix_multiply(l1, c1, matriz1, l2, c2, matriz2, matrizfinal);
                matrix_print(l1, c2, matrizfinal);
            } else{
                printf("Erro: as dimensoes da matriz nao correspondem");
            }
        } else if(digito == 4){
            scanf("%d %d", &escalar, &escolha);
            if(escolha == 1){
                scalar_multiply(l1, c1, matriz1, escalar);
                matrix_print(l1, c1, matriz1);
            } else{
                scalar_multiply(l2, c2, matriz2, escalar);
                matrix_print(l2, c2, matriz2);
            }
        } else if(digito == 5){
            transpose_matrix(l1, c1, matriz1, matrizfinal);
            matrix_print(l1, c1, matrizfinal);
            transpose_matrix(l2, c2, matriz2, matrizfinal);
            matrix_print(l2, c2, matrizfinal);
        } else if(digito == 6){
            break;
        } 
    }

    return 0;
}
