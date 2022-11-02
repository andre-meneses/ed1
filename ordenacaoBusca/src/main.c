#include <stdio.h>
#include <stdlib.h>
#include "../header/buscaOrdenacao.h"
#include "../header/auxiliarOrdenacao.h"

int main()
{
    int v[7] = {10,5,3,21,0,4,5};
    /* int *ord = countingSort(v,7); */ 
    mergeSort(v,0,6);

    for(int i = 0; i < 7; i++) printf("%d ", v[i]);
    /* for(int i = 0; i < 10; i++) printf("%d\n", randomValue(5,10)); */
    return 0;
}
