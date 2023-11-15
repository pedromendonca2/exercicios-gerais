#include "ponto.h"
#include <stdlib.h>
#include <math.h>

/* TAD Opaco */
struct ponto {
    float x, y;
};

tPonto Pto_Cria (float x, float y){
    tPonto ponto = (tPonto) malloc (sizeof(struct ponto));
    if(ponto == NULL){
        return NULL;
    }
    Pto_Atribui_x(ponto, x);
    Pto_Atribui_y(ponto, y);
    return ponto;
}

void Pto_Apaga (tPonto p){
    free(p);
}

/**
 * @brief Função que acessa a coordenada "x" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @return O valor da coordenada x de um ponto p
 */
float Pto_Acessa_x (tPonto p){
    return p->x;
}

/**
 * @brief Função que acessa a coordenada "y" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @return O valor da coordenada y de um ponto p
 */
float Pto_Acessa_y (tPonto p){
    return p->y;
}

/**
 * @brief Função que atribui a coordenada "x" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @param x O novo valor da coordenada x do ponto p
 */
void Pto_Atribui_x (tPonto p, float x){
    p->x = x;
}

/**
 * @brief Função que atribui a coordenada "y" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @param y O novo valor da coordenada y do ponto p
 */
void Pto_Atribui_y (tPonto p, float y){
    p->y = y;
}

/**
 * @brief Função que calcula a distância euclidiana entre dois pontos: p1 e p2
 * @param p1 A variável que representa um primeiro ponto
 * @param p2 A variável que representa um segundo ponto
 * @return A distância euclidiana entre p1 e p2
 */
float Pto_Distancia (tPonto p1, tPonto p2){
    float distancia = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    return distancia;
}