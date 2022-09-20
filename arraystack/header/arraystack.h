#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct arraystack {
    int* elementos;
    int tamanho;    //tam do array
    int qtdade;     //qtdade de elementos no array
};

struct arraystack* inicializar(int tamArray);

void duplicarCapacidade(struct arraystack* pilha);

void empilhar(struct arraystack** pilha, int valor);

bool vazia(struct arraystack* pilha);

void desempilhar(struct arraystack* pilha);

int desempilharRetornando(struct arraystack* pilha);

int topo(struct arraystack* pilha);

void imprimir(struct arraystack* pilha);
