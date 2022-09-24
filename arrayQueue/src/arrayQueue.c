#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../header/arrayQueue.h"

struct arrayqueue* inicializar(int tamArray) {
    struct arrayqueue *fila = (struct arrayqueue*) malloc(sizeof *fila);

    fila->elementos = (int*) calloc(tamArray,sizeof (int));
    fila->tamanho = tamArray;
    fila->qtdade = 0;
    fila->frente = -1;
    fila->tras = -1;

    return fila;
}

//se a fila estiver nula, instancie a fila com tamanho 10
//por causa da possibilidade de instanciacao usamos struct arrayqueue**
//se a fila encher, simplesmente não enfileire
void enfileirar(struct arrayqueue** fila, int val) {

    if(fila == NULL) (*fila) = inicializar(10);

    int proxTras = ((*fila)->tras + 1) % (*fila)->tamanho;

    if(proxTras != (*fila)->frente)
    {
        (*fila)->elementos[proxTras] = val;
        (*fila)->tras = proxTras;  
        (*fila)->qtdade++;
    }
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int desenfileirar(struct arrayqueue* fila) {
    if(fila->qtdade == 0 || fila == NULL) return INT_MIN;
    
    int val = frente(fila);
    fila->frente = (fila->frente + 1) % fila->tamanho;  
    fila->qtdade--;

    return val;
    
}

//retorne a constante INT_MIN se a fila for nula ou vazia
int frente(struct arrayqueue* fila) {
    if(fila->qtdade == 0 || fila == NULL) return INT_MIN;

    return fila->elementos[fila->frente];
}
