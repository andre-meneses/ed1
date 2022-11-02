#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "../header/buscaOrdenacao.h"
#include "../header/auxiliarOrdenacao.h"

int buscaBinaria(int *vetor, int valor, int tamanho)
{
   return buscaBinariaAux(vetor, valor, 0, tamanho-1); 
}

void selectionSort(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
       int menor = vetor[i];

       for(int j = i; j < tamanho; j++)
       {
            if(vetor[j] < menor)
            {
                vetor[i] = vetor[j];
                vetor[j] = menor;
                menor = vetor[i];
            }
       }
    }
}

void bubbleSort(int *vetor, int size)
{
    for (int sweep = 0; sweep < size-1; sweep++)
    {
        bool hasSwapped = false;
        for(int i = 0; i < size-sweep-1;i++)
        {
            if(vetor[i] > vetor[i+1])
            {
                swap(vetor,i,i+1);
                hasSwapped = true;
            }
        }
        if (!hasSwapped) return;
    }
}


int* countingSort(int *vetor, int size)
{
    int max = vetor[0];
    int min = vetor[0];

    for(int i = 1; i < size; i++)
    {
        if(vetor[i] < min) min = vetor[i];
        if(vetor[i] > max) max = vetor[i];
    }

    int *frequencia = calloc(max-min + 1,sizeof(int));

    for(int i = 0; i < size; i++) frequencia[vetor[i]-min]++; 

    for(int i = 1; i < max-min+1; i++) frequencia[i] += frequencia[i-1];

    int *ordenado = calloc(size,sizeof(int));

    for(int i = size - 1; i >=0; i--)
    {
        ordenado[frequencia[vetor[i] - min]-1] = vetor[i];
        frequencia[vetor[i]-min]--;
    }

    return ordenado;
}


void quickSort(int *vetor, int ini, int fim)
{
    if(fim > ini)
    {
        int indexPivo = particiona(vetor,ini,fim);
        quickSort(vetor, ini, indexPivo-1);
        quickSort(vetor, indexPivo + 1, fim);
    }
}

void mergeSort(int *vetor, int ini, int fim)
{
    if(fim > ini)
    {
        int meio = (fim + ini)/2;
        mergeSort(vetor,ini,meio);
        mergeSort(vetor,meio + 1,fim);
        merge(vetor, ini, meio + 1, fim, fim - ini + 1);
    }
}

