#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

static int num_nos;

void criar_pilha(t_pilha *pilha) {
	pilha->topo = NULL;
	num_nos = 0;
}

int empilhar(t_pilha *pilha, t_elemento elemento) {

	t_apontador novo = (t_apontador) malloc(sizeof(t_no_pilha));
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
	int retorno = aux;
	free(aux);

	num_nos--;

	return retorno;

}

t_no topo(t_pilha *pilha) {
	//TODO
	/*if (vazia(pilha))
		return NO_VAZIO;*/ 
	return *(pilha->topo);
}

int vazia(t_pilha *pilha) {
	if(pilha->topo == NULL)
		return 1;
	else
		return 0;
}

void limpa_pilha(t_pilha *pilha){
	for(int i = num_nos; i > 0; i--){
		desempilhar(pilha);
	}
}
