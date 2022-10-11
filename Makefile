all: fila.c fila.h pilha.c pilha.h main.c
    gcc -o main main.c fila.c pilha.c
    
run: main
    ./main
