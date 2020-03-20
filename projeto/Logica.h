
#ifndef PROJETO_LOGICA_H
#define PROJETO_LOGICA_H

int check_tabuleiro (COORDENADA c);
int check_proximidade (ESTADO *e, COORDENADA c);
int check_casa (ESTADO *e, COORDENADA c);
int jogada_valida (ESTADO *e, COORDENADA c);
int jogar(ESTADO *e, COORDENADA c);
int ganha_casa (ESTADO *e, COORDENADA c);
int ganha_invalido (ESTADO *e, COORDENADA c);
int vencedor (ESTADO *e, COORDENADA c);

#endif //PROJETO_LOGICA_H
