/**
@file Logica.h
Funções relativas às jogadas
*/

#ifndef PROJETO_LOGICA_H
#define PROJETO_LOGICA_H
#include "listas_ligadas.h"

/**
\brief Dá-nos a informação se a coordenada jogada existe no tabuleiro
@param c A coordenada
@returns 1 se a jogada for possível; 0 senão
*/
int check_tabuleiro (COORDENADA c);

/**
\brief Dá-nos a informação se a coordenada jogada esta a "1" de distância da posição atual
@param e Apontador para o estado
@param c A coordenada
@returns 1 se a jogada for possível; 0 senão 
*/
int check_proximidade (ESTADO *e, COORDENADA c);

/**
\brief Dá-nos a informação se a CASA da coordenada jogada é jogável (UM, DOIS, VAZIO)
@param e Apontador para o estado
@param c A coordenada
@returns 1 se a jogada for possível; 0 senão
*/
int check_casa (ESTADO *e, COORDENADA c);

/**
\brief Verifica se a JOGADA é válida
@param e Apontador para o estado
@param c A coordenada
@returns 1 se a jogada for possível; 0 senão
*/
int jogada_valida (ESTADO *e, COORDENADA c);

/**
\brief Realiza a jogada
@param e Apontador para o estado
@param c A coordenada
@returns 0 se o jogo prosseguir; 1 se o Jogador1 ganhar; 2 se o Jogador2 ganhar; 3 se a jogada for inválida
*/
int jogar(ESTADO *e, COORDENADA c);

/**
\brief Devolve o vencedor do jogo
@param e Apontador para o estado
@param c A coordenada
@returns 1 se o jogador 1 for o vencedor; 2 se o jogador 2 for o vencedor; 0 se o jogo não tiver chegado ao fim
*/
int ganha_casa (ESTADO *e, COORDENADA c);

/**
\brief Devolve o vencedor do jogo
@param e Apontador para o estado
@param c A coordenada
@returns 1 se o jogador 1 for o vencedor; 2 se o jogador 2 for o vencedor; 0 se o jogo não tiver chegado ao fim
*/
int ganha_invalido (ESTADO *e, COORDENADA c);

/**
\brief Devolve o vencedor do jogo
@param e Apontador para o estado
@param c A coordenada
@returns 1 se o jogador 1 for o vencedor; 2 se o jogador 2 for o vencedor; 0 se o jogo não tiver chegado ao fim
*/
int vencedor (ESTADO *e, COORDENADA c);

/**
\brief Devolve uma lista com as coordenadas candidatas
@param e Apontador para o estado
@param c A coordenada
@returns Apontador da lista criada
*/
LISTA lista_cand(ESTADO *e, COORDENADA c);

/**
\brief Devolve uma coordenada 
@param e Apontador para o estado
@returns Uma coordenada selecionada pela heurística da aleatoriedade 
*/
COORDENADA jog(ESTADO *e);

/**
\brief Devolve uma coordenada 
@param e Apontador para o estado
@returns Uma coordenada consoante a heurística da distância menor segundo o algoritmo Flood Fill 
COORDENADA jog2(ESTADO *e)
*/
COORDENADA jog2(ESTADO *e);

#endif //PROJETO_LOGICA_H
