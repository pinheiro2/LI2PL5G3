/**
@file listas_ligadas.h
Definição de listas genéricas e das funções que as manipulam
*/

#ifndef PROJETO_LISTAS_LIGADAS_H
#define PROJETO_LISTAS_LIGADAS_H

/**
\brief Tipo lista genérica
*/
typedef struct list{
    void *cabeca;
    struct list *cauda;
} *LISTA, lista;

/**
\brief Cria uma lista
@returns Apontador para a lista
*/
LISTA criar_lista();

/**
\brief insere uma cabeça na lista
@param L Apontador para a lista
@param valor Apontador 
@returns Apontador para a lista
*/
LISTA insere_cabeca(LISTA L, void *valor);

/**
\brief Devolve a cabeça da lista
@param L Apontador para a lista
@returns Apontador para a lista
*/
void *devolve_cabeca(LISTA L);

/**
\brief Devolve a cauda da lista
@param L Apontador para a lista
@returns Apontador para a lista
*/
LISTA proximo(LISTA L);

/**
\brief Remove a cabeça da lista (libertando o espaço ocupado) e devolve a cauda
@param L Apontador para a lista
@returns Apontador para a lista
*/
LISTA remove_cabeca(LISTA L);

/**
\brief Devolve verdareiro se a lista é vazia
@param L Apontador para a lista
@returns 1 caso esteja limpa; 0 caso contrário
*/
int lista_esta_vazia(LISTA L);

/**
\brief Liberta toda a memória ocupada pela lista
@param L Apontador para a lista
*/
void limpar_lista (LISTA L);

/**
\brief Devolve o número de elementos da lista
@param L Apontador para a lista
@returns número de elementos da lista
*/
int conta_listas (LISTA L);

#endif