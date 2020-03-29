#ifndef PROJETO_DADOS_H
#define PROJETO_DADOS_H


typedef enum {VAZIO = '.',
              BRANCA = '*',
              PRETA = '#',
              UM = '1',
              DOIS = '2'
        } CASA;

typedef struct {
    int coluna;
    int linha;
} COORDENADA;

typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

typedef JOGADA JOGADAS[32];

/**
\brief Tipo de dados para o estado
*/

typedef struct {
    /** O tabuleiro */
    CASA tab[8][8];
    /** As jogadas */
    JOGADAS jogadas;
    /** O número das jogadas, usado no prompt */
    int num_jogadas;
    /** O jogador atual */
    int jogador_atual;
    /** O nº de comando, usado no prompt */
    int num_comando;
    /** A coordenada da última jogada */
    COORDENADA ultima_jogada;
} ESTADO;

/**
\brief Devolve o valor de uma coordenada
@param col O inteiro correspondente à coluna
@param lin O inteiro correspondente à linha
@returns A coordenada
*/
COORDENADA coord(int col, int lin);

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

void troca_jogador (ESTADO *e);
int get_jogador (ESTADO *e);
int get_num_jogadas (ESTADO *e);
int get_num_comando (ESTADO *e);
COORDENADA str_to_coord(char *s);
void armazenar_jogada(ESTADO *e, JOGADA j, int num_jog);
ESTADO *inicializar_estado();

#endif //PROJETO_DADOS_H
