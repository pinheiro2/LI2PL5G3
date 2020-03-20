#include "Dados.h"
#include "Interface.h"
#include "Logica.h"
#include <stdio.h>

int main() {
    ESTADO *e = inicializar_estado();
    interpretador(e);
    return 0;
}
