#include <stdio.h>
#include "departamento.h"

int main(){

    int n, media_1, media_2, media_3;
    char departamento[STRING_MAX], nome[STRING_MAX], curso_1[STRING_MAX], curso_2[STRING_MAX], curso_3[STRING_MAX];

    scanf("%d", &n);
    tDepartamento vetor_Departamento[n], saveDepartamento;
    int media[n], savevalue;

    for(int i=0; i<n; i++){
        scanf("%s %s %s %s %s %d %d %d", departamento, nome, curso_1, curso_2, curso_3, &media_1, &media_2, &media_3);
        vetor_Departamento[i] = criaDepartamento(curso_1, curso_2, curso_3, departamento, media_1, media_2, media_3, nome);
        media[i] = calculaMediaGeralDepartamento(vetor_Departamento[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(media[i] < media[j]){
                saveDepartamento = vetor_Departamento[i];
                vetor_Departamento[i] = vetor_Departamento[j];
                vetor_Departamento[j] = saveDepartamento;
                savevalue = media[i];
                media[i] = media[j];
                media[j] = savevalue;
            }
        }    
    }

    for(int i=n-1; i>=0; i--){
        imprimeAtributosDepartamento(vetor_Departamento[i]);        
    }


    return 0;
}