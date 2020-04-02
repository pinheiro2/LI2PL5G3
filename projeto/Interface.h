
#ifndef PROJETO_INTERFACE_H
#define PROJETO_INTERFACE_H
#include "Dados.h"

void mostrar_tabuleiro(ESTADO *estado);
void gr_ficheiro(ESTADO *e, char *nome);
void ler_ficheiro(ESTADO *e, char *nome);
void prompt(ESTADO *e);
void mostrar_movs (ESTADO *e);
int interpretador (ESTADO *e,int *quit);
#endif //PROJETO_INTERFACE_H
