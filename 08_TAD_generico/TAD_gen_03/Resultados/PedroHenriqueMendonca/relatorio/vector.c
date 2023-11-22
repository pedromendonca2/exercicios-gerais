#include "vector.h"
#include <stdlib.h>

struct Vector{
    int tamanho;
    void** vetor;
};

/**
 * @brief Cria um vetor vazio
 * 
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
*/
Vector *VectorConstruct(){
    Vector* vetor = (Vector*) calloc (1, sizeof(Vector));

    vetor->vetor = (void**) calloc (1, sizeof(data_type));

    return vetor;
}

/**
 * @brief Adiciona um elemento no final do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
*/
void VectorPushBack(Vector *v, data_type val){
    v->tamanho++;
    v->vetor = (void**) realloc (v->vetor, v->tamanho*sizeof(data_type));
    v->vetor[v->tamanho - 1] = val;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 * 
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
*/
data_type VectorGet(Vector *v, int i){
    return v->vetor[i];
}

/**
 * @brief Retorna o tamanho do vetor
 * 
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
*/
int VectorSize(Vector *v){
    return v->tamanho;
}

/**
 * @brief Libera a memória alocada para o vetor
 * 
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
*/
void VectorDestroy(Vector *v, void (*destroy)(data_type)){
    if(v != NULL){
        for(int i=0; i<v->tamanho; i++){
           destroy(v->vetor[i]);
        }
        free(v->vetor);
        free(v);
    }
}