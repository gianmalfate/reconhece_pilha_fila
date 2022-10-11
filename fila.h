#ifndef FILA_H
#define FILA_H

#define NAO_ENCONTROU -1
#define ERRO_CHEIA 0
#define SUCESSO 1

//Defs gerais de t_chave, t_apontador e t_elemento (vale para pilha e fila)
typedef int t_chave;

typedef struct t_elemento{
	t_chave chave;
} t_elemento;

typedef struct t_no *t_apontador;
typedef struct t_no {
	t_elemento elemento;
	t_apontador proximo;
} t_no;

typedef struct {
	t_apontador primeiro;
	t_apontador ultimo;
} t_fila;

int criar(t_fila *fila);
int enfileirar(t_fila *fila, t_elemento elemento);
int desenfileirar(t_fila *fila);

#endif
