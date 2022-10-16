//pila ou filha
//Giancarlo Malfate Caprino, nUSP: 12725025
//Henrique Gualberto Marques, nUSP: 13692380
//Pedro Henrique Cruz da Silva, nUSP: 11833236
//Rafael Scalon Peres Conti, nUSP: 11871181

#include<stdio.h>
#include<stdlib.h>
#include"fila.h"
#include"pilha.h"

int main(){
    int quant_teste;
    scanf("%d", &quant_teste);
    int quant_op;
    char op;
    t_elemento elemento;
    int flag_pilha, flag_fila;

    //for para percorrer todas as linhas da entrada (testes)
    for(int i = 0; i < quant_teste; i++){
        //flags recebem valor 1 para iniciar o teste
        flag_fila = 1;
        flag_pilha = 1;
        scanf("%d ", &quant_op);
        t_fila fila;
        criar_fila(&fila);
        
        t_pilha pilha;
        criar_pilha(&pilha);

        for(int j = 0; j < quant_op; j++){
            scanf("%c %d ", &op, &elemento.chave);
            if(op == 'i'){
                enfileirar(&fila, elemento);
                empilhar(&pilha, elemento);
            } else if(op == 'r'){
                int testa_fila = desenfileirar(&fila);
                if(testa_fila != elemento.chave){
                    flag_fila = 0;
                }

                int testa_pilha = desempilhar(&pilha);
                if(testa_pilha != elemento.chave){
                    flag_pilha = 0;
                }
            }
        }

        limpa_fila(&fila);
        limpa_pilha(&pilha);

        //tratamento de saidas
        if(flag_pilha = 0 && flag_fila == 1){
            printf("fila\n");
        } else if(flag_pilha == 1 && flag_fila == 0){
            printf("pilha\n");
        } else if(flag_pilha == 1 && flag_fila == 1){
            printf("indefinido\n");
        } else if(flag_pilha == 0 && flag_fila == 0){
            printf("impossivel\n");
        }
    }
    return 0;
}
