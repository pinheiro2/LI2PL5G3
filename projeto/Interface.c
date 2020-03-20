#include "Interface.h"
#include "Dados.h"
#include <stdio.h>

void mostrar_tabuleiro(ESTADO estado) {
    for (int i = 8; i >= 1; i--) {
        printf("%d  ", i + 1);
        for (int j = 1; j <= 8; j++) {
            COORDENADA c = {j,i};
            if (i == 8 && j == 8)
                printf("1 ");
            else if (i == 1 && j == 1)
                printf("2 ");
            else if (get_casa(estado, c) == VAZIO)
                printf(". ");
            else if (get_casa(estado, c) == BRANCA)
                printf("* ");
            else
                printf("# ");
        }
        putchar('/n');
    }
    for (int i = 1; i <= 8; i++)
        printf("   %c", 96 + i);
    putchar('\n');
}


