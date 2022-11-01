#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "../header/testeDesempenho.h"

int* testeOrdenacaoInPlace(int (*ordenar)(int *vetor, int size))
{
    clock_t begin = clock();
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    int tempo[5];
}

int* testeOrdenacaoOutofPlace(void (*ordenar)(int *vetor, int size));

int* gerarVetorAleatorio(int size)
{
    srand(time(NULL));
    int *vetor = malloc(size * sizeof(int));
    
    for(int i=0; i<size; i++) vetor[i] = rand();

    return vetor;
}

int* gerarVetorOrdenado(int size, int flag)
{

    int *vetor = malloc(size * sizeof(int));
    
    if(flag == 0)
        for(int i=0; i<size; i++) vetor[i] = i;
    else
        for(int i=size-1; i>=0; i--) vetor[i] = i;

    return vetor;
}
