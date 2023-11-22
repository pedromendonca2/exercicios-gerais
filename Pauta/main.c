#include <stdio.h>
#include "tAluno.h"
#include "tPauta.h"


void exibirMenu(){
        printf("\n--- Menu ---\n");
        printf("1. Adicionar Aluno\n");
        printf("2. Exibir Pauta\n");
        printf("3. Salvar Pauta\n");
        printf("4. Recuperar Pauta\n");
        printf("5. Sair\n");
}

int main() {
    tPauta *pauta = criarPauta();

    int escolha;
    do {
        exibirMenu();
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                tAluno * aluno = LeAluno();
                adicionarAlunoPauta(pauta, aluno);
                break;
            case 2:
                exibirPauta(pauta);
                break;
            case 3:
                salvarPauta(pauta);
                break;
            case 4:
                liberarPauta(pauta);
                pauta = recuperarPauta();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 5);

    liberarPauta(pauta);

    return 0;
}

