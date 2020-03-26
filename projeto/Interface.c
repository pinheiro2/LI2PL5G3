#include "Interface.h"
#include "Dados.h"
#include "Logica.h"
#include <stdio.h>
#include <string.h>

#define BUF_SIZE 1024

void mostrar_tabuleiro(ESTADO *estado) {
    for (int i = 8; i >= 1; i--) {
        printf("%d  ", i);
        for (int j = 1; j <= 8; j++)
            printf("%c ",get_casa(estado, coord(j, i)));
        putchar('\n');
    }
    for (int i = 1; i <= 3; i++)
        putchar(' ');
    for (int i = 1; i <= 8; i++)
        printf("%c ", 96 + i);
    putchar('\n');
}

void prompt(ESTADO *e) {
    printf("# %d PL%d (%d)>", get_num_comando(e), get_jogador(e),get_num_jogadas(e));
}

int interpretador(ESTADO *e, int *quit) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    if (e-> num_comando == 1) {
        mostrar_tabuleiro(e);
        prompt(e);
    }
    if(fgets(linha, BUF_SIZE, stdin) == NULL)
        return 0;
    if(strlen(linha) == 3 && sscanf(linha, "%c%[0-9]", col, lin) == 2) {
        COORDENADA coord = {*col - 96, *lin - 48};
        if (jogada_valida(e,coord)) {
            jogar(e, coord);
            mostrar_tabuleiro(e);
        }
        else
            printf("Jogada Inválida");
    }
    e-> num_comando++;
    prompt(e);
    return 1;
}
