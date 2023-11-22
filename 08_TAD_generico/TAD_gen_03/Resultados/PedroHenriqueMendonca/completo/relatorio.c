#include "relatorio.h"
#include "aluno.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 * 
 * @param alunos Ponteiro para o vetor de alunos.
*/

void ImprimeRelatorio(Vector *alunos){
    float media = 0, aprovados=0, masculino=0, feminino=0, outros=0;

    int tamanho_vetor = VectorSize(alunos);

    for(int i=0; i < tamanho_vetor; i++){
        tAluno* aluno = VectorGet(alunos, i); //Isso é um atributo da strcut vector, o void*, dado que possui posicao
        media += GetNotaAluno(aluno);
        if(GetNotaAluno(aluno) >= 6){
            aprovados++;
        }
        if(GetGeneroAluno(aluno) == 'M'){
            masculino++;
        }
        if(GetGeneroAluno(aluno) == 'F'){
            feminino++;
        }
        if(GetGeneroAluno(aluno) == 'O'){
            outros++;
        }
    }
    media = media/tamanho_vetor;
    float porc_aprovados = aprovados/tamanho_vetor;
    porc_aprovados = porc_aprovados*100;
    float porc_masculino = masculino/tamanho_vetor;
    porc_masculino = porc_masculino*100;
    float porc_feminino = feminino/tamanho_vetor;
    porc_feminino = porc_feminino*100;
    float porc_outros = outros/tamanho_vetor;
    porc_outros = porc_outros*100;

    printf("Media das notas: %.2f\n", media);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", porc_aprovados);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", porc_masculino);
    printf("Feminino: %.2f%%\n", porc_feminino);
    printf("Outro: %.2f%%\n", porc_outros);

    //VectorDestroy(alunos, DestroiAluno);
}