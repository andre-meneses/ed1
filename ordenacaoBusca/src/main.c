#include <stdio.h>
#include <stdlib.h>
#include "../header/buscaOrdenacao.h"

int main()
{
    int vetorTeste[10];

    for(int i = 0; i < 10; i++) vetorTeste[i] = i;

    printf("%d\n",buscaBinaria(vetorTeste,5,10));
}
