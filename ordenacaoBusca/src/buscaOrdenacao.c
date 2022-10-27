#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
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
                int temp = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = temp;
                hasSwapped = true;
            }
        }
        if (!hasSwapped) return;
    }
}


int* countingSort(int *vetor, int size)
{
    int max,min = vetor[0];

    for(int i = 1; i < size; i++)
    {
        if(vetor[i] < min) min = vetor[i];
        if(vetor[i] > max) max = vetor[i];
    }

    int *frequencia = calloc(max-min + 1,sizeof(int));

    for(int i = 0; i < size; i++) frequencia[vetor[i]-1]++; 

    for(int i = 1; i < size; i++) frequencia[i] += frequencia[i-1];

    int *ordenado = calloc(size,sizeof(int));

    for(int i = size - 1; i >=0; i--)
    {
        ordenado[frequencia[vetor[i]-1]-1] = vetor[i];
        frequencia[vetor[i]-1]--;
    }

    return ordenado;
}


