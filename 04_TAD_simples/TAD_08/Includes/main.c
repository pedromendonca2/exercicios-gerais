#include <stdio.h>
#include "departamento.h"

int main(){

    int n, media_1, media_2, media_3;
    char departamento[STRING_MAX], nome[STRING_MAX], curso_1[STRING_MAX], curso_2[STRING_MAX], curso_3[STRING_MAX];
    tDepartamento Departamento;

    for(int i=0; i<n; i++){
        scanf("%s %s %s %s %s %d %d %d", departamento[STRING_MAX], nome[STRING_MAX], curso_1[STRING_MAX], curso_2[STRING_MAX], curso_3[STRING_MAX], &media_1, &media_2, &media_3);
        Departamento = criaDepartamento(curso_1[STRING_MAX], curso_2[STRING_MAX], curso_3[STRING_MAX], departamento[STRING_MAX], media_1, media_2, media_3, nome[STRING_MAX]);
        imprimeAtributosDepartamento(Departamento);
    }

    return 0;
}