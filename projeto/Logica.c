#include "Dados.h"
#include <stdio.h>
#include <stdlib.h>
#include "Logica.h"

int check_tabuleiro (COORDENADA c) {
    if (c.linha >= 1 && c.linha <= 8 && c.coluna >= 1 && c.coluna <= 8)
        return 1;
    else
        return 0;
}

int check_proximidade (ESTADO *e, COORDENADA c) {

    COORDENADA a = e -> ultima_jogada;
    if ((abs(a.linha - c.linha)) <= 1 && (abs(a.coluna - c.coluna)) <= 1)
        return 1;
    else
        return 0;
}

int check_casa (ESTADO *e, COORDENADA c) {
    if (get_casa(e, c) == PRETA)
        return 0;
    else
    if (get_casa(e, c) == BRANCA)
        return 0;
    else
        return 1;
}

int jogada_valida (ESTADO *e, COORDENADA c) {
    if (check_tabuleiro(c))
        if (check_casa(e, c))
            if (check_proximidade(e, c))
                return 1;
    return 0;
}

int ganha_casa (ESTADO *e, COORDENADA c) {
    int r = 0;
    if (get_casa (e, c) == UM)
        r = 1;
    if (get_casa (e, c) == DOIS)
        r = 2;
    return r;
}

int ganha_invalido (ESTADO *e, COORDENADA c) {
    int i, j;
    int r = 0;
    int p = get_jogador(e);
    for (i = -1; i < 2; i++)
        for (j = -1; j < 2; j++) {
            if (c.coluna + i > 0 && c.coluna + i < 9 && c.linha + i > 0 && c.coluna + i < 9) {
                CASA h = get_casa(e, coord(c.coluna + i, c.linha + j));
                if (h == VAZIO || h == UM || h == DOIS) {
                    return 0;
                } else
                    r = p;
            }
        }
    return r;
}

int vencedor (ESTADO *e, COORDENADA c){
    int v;
    if (ganha_casa (e, c) != 0)
        v = ganha_casa(e, c);
    else
        v = ganha_invalido (e, c);
    return v;
}

int jogar(ESTADO *e, COORDENADA c) {
    int r = 0;
    if (jogada_valida(e, c)) {
        r = vencedor(e,c);
        set_casa(e, e->ultima_jogada, PRETA);
        set_casa(e, c, BRANCA);
        e->ultima_jogada = c;

        if (get_jogador(e) == 1) {
            e->num_jogadas++;
            e -> max_jogadas = e -> num_jogadas;
            e->jogadas[(e->num_jogadas) - 1].jogador1 = c;
        }
        else {
            e->jogadas[(e->num_jogadas) - 1].jogador2 = c;
            e -> max_jogadas = e -> num_jogadas;
        }
        if (r == 0)
            r = vencedor(e, c);
        troca_jogador(e);
    }
    else
        r = 3;
    return r;
}
