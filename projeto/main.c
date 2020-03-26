#include "Dados.h"
#include "Interface.h"
#include "Logica.h"
#include <stdio.h>

int main() {
    ESTADO *e = inicializar_estado();
    int quit = 0;
    while (quit = 0)
        interpretador(e, &quit);
    return 0;
}
