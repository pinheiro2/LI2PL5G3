#include "Dados.h"
#include <stdio.h>
#include "Logica.h"

 int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    set_casa (e, e -> ultima_jogada, PRETA);
    set_casa (e, c, BRANCA);
    e-> ultima_jogada = c;
    return 1;
}