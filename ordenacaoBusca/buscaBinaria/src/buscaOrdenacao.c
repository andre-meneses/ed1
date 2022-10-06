#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../header/buscaOrdenacao.h"

int buscaBinaria(int *vetor, int valor, int tamanho)
{
   return buscaBinariaAux(vetor, valor, 0, tamanho-1); 
}

int buscaBinariaAux(int *vetor, int valor, int inicio, int fim)
{
    if(inicio - fim > 0) return INT_MAX; 

    int meio = (inicio + fim)/2;

    if(vetor[meio] == valor) return meio;

    if(vetor[meio] > valor) return buscaBinariaAux(vetor,valor,inicio,meio-1);
    else return buscaBinariaAux(vetor,valor,meio+1,fim);
}

