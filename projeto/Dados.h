#ifndef PROJETO_DADOS_H
#define PROJETO_DADOS_H

/**
\brief Tipos de CASA
*/
typedef enum {VAZIO = '.',
              BRANCA = '*',
              PRETA = '#',
              UM = '1',
              DOIS = '2'
        } CASA;

/**
\brief Coordenadas do tabuleiro
*/
typedef struct {
    int coluna;
    int linha;
} COORDENADA;

/**
\brief Conjunto das jogadas de cada jogador na ronda
*/
typedef struct {
    COORDENADA jogador1;
    COORDENADA jogador2;
} JOGADA;

/**
\brief Conjunto de todas as JOGADA realizadas
*/
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

/**
\brief Troca o jogador atual
@param e Apontador para o estado
*/
void troca_jogador (ESTADO *e);

/**
\brief Devolve o jogador atual
@param e Apontador para o estado
@returns O jogador atual
*/
int get_jogador (ESTADO *e);

/**
\brief Devolve numero de jogadas
@param e Apontador para o estado
@returns O numero de jogadas
*/
int get_num_jogadas (ESTADO *e);

/**
\brief Devolve o numero de comandos
@param e Apontador para o estado
@returns O numero de comandos
*/
int get_num_comando (ESTADO *e);

/**
\brief Tranforma uma string num array de int
@param s A string
@returns Coordenada
*/
COORDENADA str_to_coord(char *s);

/**
\brief
@param e Apontador para o estado
@param j Jogada
@param num_jog Numero de jogadas
*/
void armazenar_jogada(ESTADO *e, JOGADA j, int num_jog);

void set_jogador_atual (ESTADO *e, int player);

void clean_estado(ESTADO *e);
/**
\brief Cria o estado inicial do jogo
 @returns Estado inicial do jogo
*/
ESTADO *inicializar_estado();

#endif //PROJETO_DADOS_H
