#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

struct arrayqueue {
    int frente;
    int tras;
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array    
};

struct arrayqueue* inicializar(int tamArray);
void enfileirar(struct arrayqueue** fila, int val) ;
int desenfileirar(struct arrayqueue* fila) ;
int frente(struct arrayqueue* fila) ;
