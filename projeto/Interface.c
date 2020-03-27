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
            printf("%c",get_casa(estado, coord(j, i)));
        putchar('\n');
    }
    for (int i = 1; i <= 3; i++)
        putchar(' ');
    for (int i = 1; i <= 8; i++)
        printf("%c ", 96 + i);
    putchar('\n');
}

void gr_ficheiro(ESTADO *e, char *nome) {
    FILE *fp;
    fp = fopen("c:\test.txt", "w");
    for (int i = 8; i >= 1; i--) {
        fprintf(fp, "%d  ", i);
        for (int j = 1; j <= 8; j++)
            fprintf(fp, "%c ", get_casa(e, coord(j, i)));
        fputc('\n', fp);
    }
    for (int i = 1; i <= 3; i++)
        fputc(' ', fp);
    for (int i = 1; i <= 8; i++)
        fprintf(fp, "%c ", 96 + i);
    fputc('\n', fp);
    fclose(fp);
}

void ler_ficheiro(ESTADO *e, char *nome) {
    FILE *fp;
    int c;
    fp = fopen("c:\test.txt", "r");
    while(1) {
        c = fgetc(fp);
        if (feof(fp))
            break ;
        printf("%c", c);
    }
    fclose(fp);
}

void prompt(ESTADO *e) {
    if (get_num_comando(e) < 10)
        printf("# 0%d PL%d (%d)>", get_num_comando(e), get_jogador(e),get_num_jogadas(e));
    else
        printf("# %d PL%d (%d)>", get_num_comando(e), get_jogador(e),get_num_jogadas(e));
}

int interpretador(ESTADO *e, int *quit) {
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nomef[15];
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
            printf("Jogada Inválida\n");
    }
    if (sscanf(linha, "Q") == 1)
        *quit = 1;

    if (sscanf(linha, "ler %s", nomef) == strlen(nomef))
        ler_ficheiro(e, nomef);

    if (sscanf(linha, "gr %s", nomef) == strlen(nomef))
        gr_ficheiro(e, nomef);

    e-> num_comando++;
    prompt(e);
    return 1;
}
