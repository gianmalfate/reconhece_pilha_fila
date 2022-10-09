//pila ou filha
//Rafael Scalon Peres Conti, nUSP: 11871181

#include<stdio.h>
#include<stdlib.h>

int main(){
    int quant_teste;
    scanf("%d", &quant_teste);
    int quant_op;
    char op;
    int elem;
    int flag_pilha, flag_fila;

    for(int i = 0; i < quant_teste; i++){
        flag_fila = 1;
        flag_pilha = 1;
        scanf("%d ", &quant_op);
        int possivel_pilha[quant_op];
        int possivel_fila[quant_op];
        int contador_pos_pilha = 0, contador_pos_fila = 0;
        int inicio_fila = 0;
        for(int j = 0; j < quant_op; j++){
            scanf("%c %d ", &op, &elem);
            if(op == 'i'){
                possivel_pilha[contador_pos_pilha] = elem;
                possivel_fila[contador_pos_fila] = elem;
                contador_pos_pilha++;
                contador_pos_fila++;
            } else if(op == 'r'){
                if(flag_pilha == 1){//se ainda puder ser pilha
                    flag_pilha = testa_FIFO();
                    if(flag_pilha == 1){
                        contador_pos_pilha--; //remover pela cauda
                    }
                }
                if(flag_fila == 1){//se ainda puder ser fila
                    flag_fila = testa_LIFO();
                    if(flag_fila == 1){
                        inicio_fila++; //remover pela cabeca
                    }
                }
            }
        }
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
