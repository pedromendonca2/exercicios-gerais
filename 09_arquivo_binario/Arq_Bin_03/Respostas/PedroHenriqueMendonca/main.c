#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>

int main(){

    char caminho[100];
    scanf("%s", caminho);

    Imagem* imagem = LerImagem(caminho);

    int numIntervalos;
    scanf("%d", &numIntervalos);

    Histograma* histograma = CalcularHistograma(imagem, numIntervalos);
    MostrarHistograma(histograma);

    DestruirImagem(imagem);
    DestruirHistograma(histograma);

    return 0;  
}