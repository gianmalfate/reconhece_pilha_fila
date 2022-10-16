//pila ou filha
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181

#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

static int num_nos;

void criar_pilha(t_pilha *pilha) {
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

int vazia_pilha(t_pilha *pilha) {
	if(pilha->topo == NULL)
		return 1;
	else
		return 0;
}

int desempilhar(t_pilha *pilha) {

	if (vazia_pilha(pilha)) 
		return NAO_ENCONTROU;

	t_apontador aux = pilha->topo;
	int valor = aux->elemento.chave;
	pilha->topo = pilha->topo->proximo;
	free(aux);

	num_nos--;

	return valor;

}

t_no topo(t_pilha *pilha) {
	//TODO
	/*if (vazia(pilha))
		return NO_VAZIO;*/ 
	return *(pilha->topo);
}

void limpa_pilha(t_pilha *pilha){
	for(int i = num_nos; i > 0; i--){
		desempilhar(pilha);
	}
}
