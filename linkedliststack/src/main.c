#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>
#include "../header/linkedliststack.h"

int main()
{
    struct linkedstack *pilha = NULL;
    for(int i = 0; i < 5; i++) empilhar(&pilha,i+3);
    exibirPilha(pilha);
    printf("\n%d\n",desempilharRetornando(pilha));
    return 0;
}
