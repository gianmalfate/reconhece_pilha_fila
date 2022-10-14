#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

static int num_nos;

void criar_fila(t_fila *fila) {
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
	int retorno = aux;
	free(aux);

	num_nos--;

	return retorno;

}

t_no frente(t_fila *fila) {
	//TODO
	/*if (vazia(fila))
		return NO_VAZIO;*/ 
	return *(fila->primeiro);
}

int vazia(t_fila *fila) {
	if(fila->primeiro == NULL &&
		fila->ultimo == NULL)
		return 1;
	else
		return 0;
}

void limpa_fila(t_fila *fila){
	for(int i = num_nos; i > 0; i--){
		desenfileirar(fila);
	}
}
