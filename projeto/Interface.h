/**
@file Interface.h
Aspeto visual do tabuleiro/comandos
*/

#ifndef PROJETO_INTERFACE_H
#define PROJETO_INTERFACE_H
#include "Dados.h"

/**
\brief Desenha o tabuleiro consoante o ESTADO
@param estado Apontador para o estado
*/
void mostrar_tabuleiro(ESTADO *estado);

/**
\brief Grava o estado atual do jogo
@param e Apontador para o estado
@param nome O nome do ficheiro a guardar
*/
void gr_ficheiro(ESTADO *e, char *nome);

/**
\brief Mostra o tabuleiro guardado
@param e Apontador para o estado
@param nome O nome do ficheiro a ler
*/
void ler_ficheiro(ESTADO *e, char *nome);

/**
\brief Mostra o número de comandos, o jogador atual e número da jogada
@param e Apontador para o estado
*/
void prompt(ESTADO *e);

/**
\brief Mostra o todas as jogadas realizadas até ao momento
@param e Apontador para o estado
*/
void mostrar_movs (ESTADO *e);

/**
\brief Permite andar n jogadas consante o max_jogadas
@param e Apontador para o estado
@param n Número de jogadas a andar, para frente ou para trás
*/
void pos (ESTADO *e, int n);

/**
\brief Permite realizar todos as funções necessárias numa jogada
@param e Apontador para o estado
@param quit Apontador para o número que determina se o jogo acaba ou continua, se quit == 0 o jogo continua, caso quit == 1 o jogo acaba
*/
int interpretador (ESTADO *e,int *quit);

#endif //PROJETO_INTERFACE_H