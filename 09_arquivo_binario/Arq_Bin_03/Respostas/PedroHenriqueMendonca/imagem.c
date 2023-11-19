#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

struct tImagem{
    int linhas;
    int colunas;
    Tipo tipo;
    void* valores;
};

/**
 * @brief Função para ler uma imagem de um arquivo binário e aloca-la na memória.
 * @param path O caminho para o arquivo de imagem.
 * @return Um ponteiro para a imagem lida. Se houver erro (de leitura ou alocação de memória), a função imprime uma mensagem de erro e termina o programa.
 */
Imagem *LerImagem(const char *caminho){
    FILE* file = fopen(caminho, "rb");

    Imagem* imagem = (Imagem*) calloc (1, sizeof(Imagem));
    if (imagem == NULL) {
        perror("Erro na alocação de memória");
        exit(EXIT_FAILURE);
    }

    fread(&imagem->linhas, sizeof(int), 1, file);
    fread(&imagem->colunas, sizeof(int), 1, file);
    fread(&imagem->tipo, sizeof(int), 1, file);

    int totalPixels = imagem->linhas * imagem->colunas;
    if(imagem->tipo == FLOAT){
        imagem->valores = calloc (totalPixels, (sizeof(float)));
        fread(imagem->valores, sizeof(float), totalPixels, file);
    } else if(imagem->tipo == INT){
        imagem->valores = calloc (totalPixels, (sizeof(int)));
        fread(imagem->valores, sizeof(int), totalPixels, file);
    }

    fclose(file);
    return imagem;
}

/**
 * @brief Função para destruir uma imagem.
 * @param img A imagem a ser destruída.
 */
void DestruirImagem(Imagem *img){
    if(img != NULL){
        if(img->valores != NULL){
            if(img->tipo == FLOAT){
                free((float*)img->valores);
            } else if(img->tipo == INT){
                free((int*)img->valores);
            }
        }
        free(img);
    }
}

/**
 * @brief Função para obter a altura de uma imagem.
 * @param img A imagem.
 * @return A altura da imagem.
 */
int ObterAlturaImagem(Imagem *img){
    return img->linhas;
}

/**
 * @brief Função para obter a largura de uma imagem.
 * @param img A imagem.
 * @return A largura da imagem.
 */
int ObterLarguraImagem(Imagem *img){
    return img->colunas;
}

/**
 * @brief Função para obter o tipo de uma imagem.
 * @param img A imagem.
 * @return O tipo da imagem.
 */
Tipo ObterTipoImagem(Imagem *img){
    return img->tipo;
}

/**
 * @brief Função para obter os dados de uma imagem.
 * @param img A imagem.
 * @return Um ponteiro para os dados da imagem.
 */
void *ObterDadosImagem(Imagem *img){
    return img->valores;
}