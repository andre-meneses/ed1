#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int v[5] = {4,2,10,5,1};
    
    selectionSort(v,5);

    for(int i = 0; i < 5; i++) printf("%d, ", v[i]);
    
}
