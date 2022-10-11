#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

static int num_nos;

int criar(t_pilha *pilha) {
	pilha->topo = NULL;
	num_nos = 0;
}

int empilhar(t_pilha *pilha, t_elemento elemento) {

	t_apontador novo = (t_apontador) malloc(sizeof(t_no));
	if (novo == NULL)
		return ERRO_CHEIA;

	novo->elemento = elemento;

	novo->proximo = pilha->topo;
	pilha->topo = novo;
	
	num_nos++;

	return SUCESSO;

}


int desempilhar(t_pilha *pilha) {

	if (vazia(pilha)) 
		return NAO_ENCONTROU;

	t_apontador aux = pilha->topo;
	pilha->topo = pilha->topo->proximo;
	free(aux);

	num_nos--;

	return SUCESSO;

}
