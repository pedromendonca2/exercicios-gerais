#include "histograma.h"
#include <stdio.h>
#include <stdlib.h>

struct tHistograma{
    int* numPixels;
    int numIntervalos;
    int tamIntervalo;
};

/**
 * @brief Função para calcular um histograma a partir de uma imagem.
 * @param image A imagem para calcular o histograma.
 * @param n_buckets O número de intervalos no histograma.
 * @return Um ponteiro para o histograma calculado.
 */
Histograma *CalcularHistograma(Imagem *img, int nIntervalos){
    Histograma* histograma = (Histograma*) calloc (1, sizeof(Histograma));

    histograma->numIntervalos = nIntervalos;
    histograma->tamIntervalo = (int)((ObterAlturaImagem(img)*ObterLarguraImagem(img))/histograma->numIntervalos);
    histograma->numPixels = calloc (histograma->numIntervalos, sizeof(float));

    if(ObterTipoImagem(img) == FLOAT){
        float* pixels = ObterDadosImagem(img);
        for(int i=0; i<histograma->numIntervalos; i++){
            for(int j=histograma->tamIntervalo*i; j<histograma->tamIntervalo*(i+1); j++){
                histograma->numPixels[i] += (int)(pixels[j] * 255);
            }
        }
    } else if(ObterTipoImagem(img) == INT){
        int* pixels = ObterDadosImagem(img);
        for(int i=0; i<histograma->numIntervalos; i++){
            for(int j=histograma->tamIntervalo*i; j<histograma->tamIntervalo*(i+1); j++){
                histograma->numPixels[i] += pixels[j];
            }
        }
    }

    return histograma;
}

/**
 * @brief Função para exibir um histograma na tela.
 * @param histogram O histograma a ser exibido.
 */
void MostrarHistograma(Histograma *histograma){
    for(int i=0; i<histograma->numIntervalos; i++){
        printf("[%d, %d) = %d\n", histograma->tamIntervalo*i, histograma->tamIntervalo*(i+1), histograma->numPixels[i]);
    }
}

/**
 * @brief Função para destruir um histograma.
 * @param histogram O histograma a ser destruído.
 */
void DestruirHistograma(Histograma *histograma){
    if(histograma != NULL){
        if(histograma->numPixels != NULL){
            free(histograma->numPixels);
        }
        free(histograma);
    }
}