
#ifndef PROJETO_LOGICA_H
#define PROJETO_LOGICA_H

int check_tabuleiro (COORDENADA c);
int check_proximidade (ESTADO *e, COORDENADA c);
int check_casa (ESTADO *e, COORDENADA c);
int jogada_valida (ESTADO *e, COORDENADA c);
int jogar(ESTADO *e, COORDENADA c);
/**
\brief Devolve o vencedor do jogo
@param e Apontador para o estado
@param c A coordenada
@returns 1 se o jogador 1 for o vencedor; 2 se o jogador 2 for o vencedor; 0 se o jogo não tiver chegado ao fim
int ganha_casa (ESTADO *e, COORDENADA c)
*/
int ganha_casa (ESTADO *e, COORDENADA c);
/**
\brief Devolve o vencedor do jogo
@param e Apontador para o estado
@param c A coordenada
@returns 1 se o jogador 1 for o vencedor; 2 se o jogador 2 for o vencedor; 0 se o jogo não tiver chegado ao fim
int ganha_invalido (ESTADO *e, COORDENADA c)
*/
int ganha_invalido (ESTADO *e, COORDENADA c);
/**
\brief Devolve o vencedor do jogo
@param e Apontador para o estado
@param c A coordenada
@returns 1 se o jogador 1 for o vencedor; 2 se o jogador 2 for o vencedor; 0 se o jogo não tiver chegado ao fim
int vencedor (ESTADO *e, COORDENADA c)
*/
int vencedor (ESTADO *e, COORDENADA c);

#endif //PROJETO_LOGICA_H
