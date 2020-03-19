#include "Dados.h"
#include <stdio.h>
#include <stdlib.h>
#include "Logica.h"

 int check_proximidade (ESTADO *e, COORDENADA c) {
    COORDENADA a = e -> ultima_jogada;
    if ((abs(a.linha - c.linha)) <= 1 && (abs(a.coluna - c.coluna)) <= 1)
        return 1;
    else
        return 0;
}

 int check_tabuleiro (COORDENADA c) {
    if (c.linha >= 1 && c.linha <= 8 && c.coluna >= 1 && c.coluna <= 8)
        return 1;
    else
        return 0;
}

 int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    set_casa (e, e -> ultima_jogada, PRETA);
    set_casa (e, c, BRANCA);
    e-> ultima_jogada = c;


    if (e -> jogador_atual == 1) {
        e -> jogador_atual = 2;
        e -> jogadas [e -> num_jogadas].jogador1 = c;

    }
    else {
        e -> jogador_atual = 1;
        e -> jogadas [e -> num_jogadas].jogador2 = c;
        e -> num_jogadas++;
    }

    return 1;
}