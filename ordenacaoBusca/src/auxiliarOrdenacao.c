#include <limits.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../header/auxiliarOrdenacao.h"

int buscaBinariaAux(int *vetor, int valor, int inicio, int fim)
{
    if(inicio - fim > 0) return INT_MAX; 

    int meio = (inicio + fim)/2;

    if(vetor[meio] == valor) return meio;

    if(vetor[meio] > valor) return buscaBinariaAux(vetor,valor,inicio,meio-1);
    else return buscaBinariaAux(vetor,valor,meio+1,fim);
}

void swap(int *vetor, int i, int j)
{
    int temp = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = temp;
}

int randomValue(int min, int max)
{
    return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

int particiona(int *vetor, int ini, int fim)
{
    int pIndex = ini;
    int rIndex = randomValue(ini,fim);
    
    swap(vetor,fim,rIndex);

    int pivo = vetor[fim];

    for(int i = ini; i < fim; i++){
        if(vetor[i] <= pivo)
        {
            swap(vetor, i, pIndex);
            pIndex++;
        }
    }

    swap(vetor,pIndex,fim);

    return pIndex;
}

void merge(int *vetor, int ini, int meio, int fim, int tam)
{
    int i = ini, j = meio, k = 0;

    int *aux = malloc(tam * sizeof(int));

    while(i < meio && j <= fim)
    {
        if(vetor[i] < vetor[j]) aux[k++] = vetor[i++];
        else aux[k++] = vetor[j++];
    }

    while(i < meio) aux[k++] = vetor[i++];
    while(j <= fim) aux[k++] = vetor[j++];

    int count = 0;

    for(int i = ini; i <=fim; i++) vetor[i] = aux[count++];

    free(aux);
}
