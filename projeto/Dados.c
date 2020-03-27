#include "Dados.h"
#include <stdlib.h>

COORDENADA coord(int col, int lin) {
    COORDENADA c;
    c.coluna = col;
    c.linha = lin;
    return c;
}

void set_casa(ESTADO *e, COORDENADA c, CASA V){
    e -> tab [(c.linha) - 1] [(c.coluna) - 1] = V;
}

CASA get_casa(ESTADO *e, COORDENADA c){
    CASA r;
    r = e -> tab [(c.linha) - 1] [(c.coluna) - 1];
    return r;
}

void troca_jogador (ESTADO *e){
    if (e -> jogador_atual == 1)
        e -> jogador_atual = 2;
    else
        e -> jogador_atual = 1;
}

int get_jogador (ESTADO *e){
    int r;
    r = e -> jogador_atual;
    return r;
}

int get_num_jogadas (ESTADO *e){
    int r;
    r = e -> num_jogadas;
    return r;
}

int get_num_comando (ESTADO *e) {
    int r;
    r = e->num_comando;
    return r;
}

ESTADO *inicializar_estado() {
    ESTADO *e = (ESTADO *) malloc(sizeof(ESTADO));
    e -> jogador_atual = 1;
    e -> num_jogadas = 0;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            set_casa(e, coord(j,i), VAZIO);
    set_casa(e, coord(5, 5), BRANCA);
    set_casa(e,coord(1, 1),UM);
    set_casa(e, coord(8, 8), DOIS);
    e -> ultima_jogada.linha = 5;
    e -> ultima_jogada.coluna = 5;
    e -> num_comando = 1;
    return e;
}