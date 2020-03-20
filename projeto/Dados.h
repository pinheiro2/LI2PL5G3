#ifndef PROJETO_DADOS_H
#define PROJETO_DADOS_H


typedef enum {VAZIO, BRANCA, PRETA, UM, DOIS} CASA;

typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

typedef struct {
    CASA tab[8][8];
    COORDENADA ultima_jogada;
    JOGADAS jogadas;
    int num_jogadas;
    int jogador_atual;
} ESTADO;

/**
\brief Muda o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@param V O novo valor para a casa
*/
void set_casa(ESTADO *e, COORDENADA c, CASA V);

/**
\brief Devolve o valor de uma casa
@param e Apontador para o estado
@param c A coordenada
@returns O valor da casa
*/
CASA get_casa(ESTADO *e, COORDENADA c);

ESTADO *inicializar_estado();

#endif //PROJETO_DADOS_H
