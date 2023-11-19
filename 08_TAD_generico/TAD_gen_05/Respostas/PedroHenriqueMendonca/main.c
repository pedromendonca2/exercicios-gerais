#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"
#include "agendatarefas.h"

int main(){

    char operacao, msg[101];
    int numElem, prioridade;
    float n1, n2;
    printf("Digite o numero de tarefas: ");
    scanf("%d", &numElem);

    tAgendaTarefas* agenda = CriaAgendaDeTarefas(numElem);

    for(int i=0; i<numElem; i++){
        scanf("%d %c ", &prioridade, &operacao);
        if(operacao != 'S' && operacao != 'I' && operacao != 'M'){
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^\n]");
            scanf("%*c");
        }
        switch(operacao){
            case('I'): 
            scanf("%[^\n]", msg);
            tImpr* imprime = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(agenda, prioridade, imprime, ExecutaTarefaImprimir, DestroiTarefaImprimir);
            break;
            case('M'): 
            scanf("%f %f", &n1, &n2);
            tMult* multiplicacao = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, multiplicacao, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
            break;
            case('S'): 
            scanf("%f %f", &n1, &n2);
            tSoma* soma = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(agenda, prioridade, soma, ExecutaTarefaSoma, DestroiTarefaSoma);
            break;
        }
    }

    ExecutarTarefasDaAgenda(agenda);
    DestroiAgendaDeTarefas(agenda);

    return 0;
}