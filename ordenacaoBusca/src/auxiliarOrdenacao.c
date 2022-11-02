#include <limits.h>
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
    return min + rand() / (RAND_MAX / (max - min) + 1);
}

int particiona(int *vetor, int ini, int fim)
{
    int pIndex = ini;
    int rIndex = randomValue(ini,fim);
    int pivo = vetor[rIndex];

    for(int i = ini; i < fim; i++){
        if(vetor[i] <= pivo)
        {
            swap(vetor, i, pIndex);
            pIndex++;
        }
    }

    swap(vetor,pIndex,rIndex);

    return pIndex;
}
