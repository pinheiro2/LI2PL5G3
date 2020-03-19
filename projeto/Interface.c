#include "Interface.h"
#include "Dados.h"
#include <stdio.h>

void mostrar_tabuleiro(ESTADO estado) {
    for (int i = 7; i >= 0; i--) {
        printf("%d  ", i + 1);
        for (int j = 0; j < 8; j++)
            if (i == 7 && j == 7)
                printf("1 ");
            else if (i == 0 && j == 0)
                printf("2 ");
            else if (estado.tab[i][j] == VAZIO)
                printf(". ");
            else if (estado.tab[i][j] == BRANCA)
                printf("* ");
            else
                printf("# ");

        putchar('/n');
    }
    for (int i = 1; i <= 8; i++)
        printf("   %c", 96 + i);
    putchar('\n');
}


