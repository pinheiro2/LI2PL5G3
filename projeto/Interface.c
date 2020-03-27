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
        printf("%c", 96 + i);
    putchar('\n');
}

void gr_ficheiro(ESTADO *e, char *nome) {
    FILE *fp;
    fp = fopen(nome, "w");
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
    fp = fopen(nome, "r");
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

void mostrar_movs (ESTADO *e){
    JOGADAS j = get_jogadas (e);
    int n = get_num_jogadas, i=0;
    int c1,l1,c2,l2;
    for (i = 0; i < n; i++){
        if (i < 9)
            printf("0%d: ", i+1);
        else
            printf("%d: ", i+1);
        c1 = j[i].jogador1.coluna + 96;
        c2 = j[i].jogador2.coluna + 96;
        l1 = j[i].jogador1.linha;
        l2 = j[i].jogador2.linha;
        printf ("%c%d %c%d\n",c1,l1,c2,l2 );

    }
}

int interpretador(ESTADO *e, int *quit) {
    int cont;
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
        cont = jogar(e, coord);
        if (cont == 3)
            printf ("Jogada Inválida\n");
        if (cont == 2)
            printf ("Parabens jogador 2\n");
        if (cont == 1)
            printf ("Parabens jogador 1\n");
        if (cont == 0)
            mostrar_tabuleiro(e);

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
