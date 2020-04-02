
#ifndef PROJETO_INTERFACE_H
#define PROJETO_INTERFACE_H
#include "Dados.h"

/**
\brief Desenha o tabuleiro consoante o ESTADO
@param c Apontador para o estado
*/
void mostrar_tabuleiro(ESTADO *estado);

/**
\brief Grava o estado atual do jogo
@param c Apontador para o estado
@param nome a String
*/
void gr_ficheiro(ESTADO *e, char *nome);

/**
\brief Mostra o tabuleiro guardado
@param c Apontador para o estado
@param nome a String
*/
void ler_ficheiro(ESTADO *e, char *nome);

/**
\brief Mostra o número de comandos, o jogador atual e número da jogada
@param c Apontador para o estado
*/
void prompt(ESTADO *e);

/**
\brief Mostra o todas as jogadas realizadas até ao momento
@param c Apontador para o estado
*/
void mostrar_movs (ESTADO *e);


int interpretador (ESTADO *e,int *quit);
#endif //PROJETO_INTERFACE_H
