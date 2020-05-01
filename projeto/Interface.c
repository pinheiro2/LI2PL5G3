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
    int i;
    for (i = 8; i >= 1; i--) {
        for (int j = 1; j <= 8; j++)
            fprintf(fp, "%c", get_casa(e, coord(j, i)));
        fputc('\n', fp);
    }
    fputc('\n', fp);
    int n = get_num_jogadas(e);
    int c1,l1,c2,l2;
    for (i = 0; i < n; i++){
        if (i < 9)
            fprintf(fp,"0%d: ", i+1);
        else
            fprintf(fp,"%d: ", i+1);
        c1 = e->jogadas[i].jogador1.coluna + 96;
        c2 = e->jogadas[i].jogador2.coluna + 96;
        l1 = e->jogadas[i].jogador1.linha;
        l2 = e->jogadas[i].jogador2.linha;
        if (i == n - 1 && get_jogador(e) == 2)
            fprintf (fp,"%c%d\n",c1,l1);
        else
            fprintf (fp,"%c%d %c%d\n",c1,l1,c2,l2 );
    }
    fclose(fp);
}

void ler_ficheiro(ESTADO *e, char *nome) {
    FILE *fp;
    if (fopen(nome, "r") != NULL) {
        fp = fopen(nome, "r");
        clean_estado(e);
        int c;
        int c_enter = 0;
        int ncol = 1;
        int nlin = 8;
        int num_jog = 0;
        int num_pretas = 0;

        while (c_enter < 9) {
            c = fgetc(fp);
            if (c == '*') {
                set_casa(e, coord(ncol, nlin), BRANCA);
                e->ultima_jogada = coord(ncol, nlin);
            }
            if (c == '#') {
                set_casa(e, coord(ncol, nlin), PRETA);
                num_pretas++;
            }
            if (c == '.')
                set_casa(e, coord(ncol, nlin), VAZIO);
            if (c == '1')
                set_casa(e, coord(ncol, nlin), UM);
            if (c == '2')
                set_casa(e, coord(ncol, nlin), DOIS);
            if (c == '\n') {
                c_enter++;
                ncol = 1;
                nlin--;
            } else
                ncol++;
        }
        fgetc(fp);
        char linha[BUF_SIZE];
        while (fgets(linha, BUF_SIZE, fp) != NULL) {
            char jog1[BUF_SIZE];
            char jog2[BUF_SIZE];
            int num_tokens = sscanf(linha, "%d: %s %s", &num_jog, jog1, jog2);
            if (num_tokens == 3) {
                COORDENADA c1 = str_to_coord(jog1);
                COORDENADA c2 = str_to_coord(jog2);
                armazenar_jogada(e, (JOGADA) {c1, c2}, num_jog);
            } else {
                COORDENADA c1 = str_to_coord(jog1);
                COORDENADA c2 = {-1, -1};
                armazenar_jogada(e, (JOGADA) {c1, c2}, num_jog);
            }
        }
        if (num_pretas % 2 == 0)
            set_jogador_atual(e, 1);
        else
            set_jogador_atual(e, 2);
        e->num_jogadas = num_jog;
        e -> max_jogadas = e -> num_jogadas;
        fclose(fp);
        mostrar_tabuleiro(e);
    }
    else
        printf("Não foi possível encontrar o ficheiro \n");
}


void prompt(ESTADO *e) {
    if (get_num_comando(e) < 10)
        printf("# 0%d PL%d (%d)>", get_num_comando(e), get_jogador(e),get_num_jogadas(e));
    else
        printf("# %d PL%d (%d)>", get_num_comando(e), get_jogador(e),get_num_jogadas(e));
}

void mostrar_movs (ESTADO *e){
    int n = get_num_jogadas(e);
    int c1,l1,c2,l2;
    for (int i = 0; i < n; i++){
        if (i < 9)
            printf("0%d: ", i+1);
        else
            printf("%d: ", i+1);
        c1 = e->jogadas[i].jogador1.coluna + 96;
        c2 = e->jogadas[i].jogador2.coluna + 96;
        l1 = e->jogadas[i].jogador1.linha;
        l2 = e->jogadas[i].jogador2.linha;
        if (i == n - 1 && get_jogador(e) == 2)
            printf ("%c%d\n",c1,l1);
        else
            printf ("%c%d %c%d\n",c1,l1,c2,l2 );
    }
}


void pos (ESTADO *e, int n){
    int i;
    int k = e->num_comando;
    if (n < get_max_jogadas(e) && n >= 0) {
        clean_estado(e);
        for (i = 0; i < n; i++){
            if (i != n-1){
                set_casa(e,e->jogadas[i].jogador1, PRETA);
                set_casa(e,e->jogadas[i].jogador2, PRETA);
            }
            else {
                set_casa(e,e->jogadas[i].jogador1, PRETA);
                set_casa(e,e->jogadas[i].jogador2, BRANCA);
                e->ultima_jogada = e->jogadas[i].jogador2;
            }
        }
        e->num_jogadas = n;
        e->num_comando = k;
        if (n != 0)
            set_casa(e, coord(5,5), PRETA);
    }
    else
        printf("Impossível executar pos %d\n", n);

}

int interpretador(ESTADO *e, int *quit) {
    int cont;
    char linha[BUF_SIZE];
    char col[2], lin[2];
    char nomef[15];
    char comando [5];
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
        if (cont == 2) {
            mostrar_tabuleiro(e);
            printf("\nParabens jogador 2\n");
            *quit = 1;
        }
        if (cont == 1) {
            mostrar_tabuleiro(e);
            printf("\nParabens jogador 1\n");
            *quit = 1;
        }
        if (cont == 0)
            mostrar_tabuleiro(e);
    }
    else {
        if (sscanf(linha, "%s", comando) == 1) {
            if (strcmp(comando, "Q") == 0)
                *quit = 1;
            if (strcmp(comando, "movs") == 0)
                mostrar_movs(e);
            if (strcmp(comando, "jog") == 0) {
                COORDENADA b = jog(e);
                int sf = jogar(e, b);
                if (sf == 3)
                    printf ("Jogada Inválida\n");
                if (sf == 2) {
                    mostrar_tabuleiro(e);
                    printf("\nParabens jogador 2\n");
                    *quit = 1;
                }
                if (sf == 1) {
                    mostrar_tabuleiro(e);
                    printf("\nParabens jogador 1\n");
                    *quit = 1;
                }
                if (sf == 0)
                    mostrar_tabuleiro(e);
            }
            if (strcmp(comando, "jog2") == 0) {
                COORDENADA b = jog2(e);
                int sf = jogar(e, b);
                if (sf == 3)
                    printf ("Jogada Inválida\n");
                if (sf == 2) {
                    mostrar_tabuleiro(e);
                    printf("\nParabens jogador 2\n");
                    *quit = 1;
                }
                if (sf == 1) {
                    mostrar_tabuleiro(e);
                    printf("\nParabens jogador 1\n");
                    *quit = 1;
                }
                if (sf == 0)
                    mostrar_tabuleiro(e);
            }
        }
        if (sscanf(linha, "%s %s", comando, nomef) == 2) {
            if (strcmp(comando, "ler") == 0)
                ler_ficheiro(e, nomef);
            if (strcmp(comando, "gr") == 0)
                gr_ficheiro(e, nomef);
            if (strcmp(comando, "pos") == 0) {
                pos(e, *nomef - 48);
                mostrar_tabuleiro(e);
            }
        }
    }
    e-> num_comando++;
    if (*quit == 0)
        prompt(e);
    return 1;
}
