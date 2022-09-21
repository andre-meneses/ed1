#include <stdio.h>
#include "../header/arraystack.h"

int main()
{
    struct arraystack *pilha = inicializar(0);
    //for(int i = 0; i < 11;i++) empilhar(&pilha,i+2);
    //imprimir(pilha);
    printf("---------\n");
    printf("%d\n",desempilharRetornando(pilha));
    printf("---------\n");
    //printf("%d\n",topo(pilha));
    //imprimir(pilha);

    return 0;
}
