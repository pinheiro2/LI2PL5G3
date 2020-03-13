#include "Dados.h"
#include <stdio.h>
#include "Logica.h"

 int jogar(ESTADO *e, COORDENADA c) {
    printf("jogar %d %d\n", c.coluna, c.linha);
    e->tab [(c.linha)-1] [(c.coluna)-1] = BRANCA;
    return 1;
}