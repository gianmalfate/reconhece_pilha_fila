#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

static int num_nos;

int criar(t_fila *fila) {
	fila->primeiro = NULL;
	fila->ultimo = NULL;
	num_nos = 0;
}

int enfileirar(t_fila *fila, t_elemento elemento) {

	t_apontador novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;
	novo->proximo = NULL;
	
	if (vazia(fila)) {
		fila->primeiro = novo;
	} else {
		fila->ultimo->proximo = novo;
	}
	fila->ultimo = novo;
	num_nos++;

	return SUCESSO;

}


int desenfileirar(t_fila *fila) {

	if (vazia(fila)) 
		return NAO_ENCONTROU;

	if (fila->primeiro == fila->ultimo) // unitaria
		fila->ultimo = NULL;

	t_apontador aux = fila->primeiro;
	fila->primeiro = fila->primeiro->proximo;
	free(aux);

	num_nos--;

	return SUCESSO;

}
