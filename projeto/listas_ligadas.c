#include "listas_ligadas.h"
#include <stdlib.h>

LISTA criar_lista(){
    return NULL;
}

LISTA insere_cabeca(LISTA L, void *valor){
    LISTA aux;
    if (L == NULL) {
        aux = (LISTA) malloc(sizeof(lista));
        aux -> cabeca = valor;
        aux -> cauda = NULL;
    }
    else{
        aux = (LISTA) malloc(sizeof(lista));
        aux -> cabeca = valor;
        aux -> cauda = L;
    }
    return aux;
}

LISTA proximo(LISTA L){
    return (L -> cauda);
}

void *devolve_cabeca(LISTA L){
    void *head;
    head = L -> cabeca;
    return head;
}

LISTA remove_cabeca(LISTA L){
    LISTA aux = L -> cauda;
    free (L);
    return aux;
}
int lista_esta_vazia(LISTA L){
    if (L == NULL)
        return 1;
    else
        return 0;
}

void limpar_lista (LISTA L){
    while (!lista_esta_vazia (L))
        L = remove_cabeca (L);
}

int conta_listas (LISTA L){
	int n = 0;
	if (L = NULL)
		return 0;
	else 
		n = 1 + conta_listas (L->cauda);

}
