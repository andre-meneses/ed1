#include "../header/linkedlist.h"

int main()
{
    struct linkedlist *lista = malloc(sizeof *lista);
    
    for (int i = 0; i < 6; i++) inserirElementoNoFim(lista,i);

    imprimirLista(lista);
    
    for (int i = 0; i < 6; i++) inserirElementoNoInicio(lista,i+5);

    imprimirLista(lista);

    inserirElementoEmPosicao(lista,12,3);
    imprimirLista(lista);
    inserirElementoEmPosicao(lista,12,0);
    imprimirLista(lista);
    inserirElementoEmPosicao(lista,12,lista->size-1);
    imprimirLista(lista);

    removerElementoEmPosicao(lista,0);
    imprimirLista(lista);

    removerElementoEmPosicao(lista,3);
    imprimirLista(lista);

    removerElementoEmPosicao(lista,lista->size-1);
    imprimirLista(lista);


    printf("%d\n",obterElementoEmPosicao(lista,0));
    printf("%d\n",obterElementoEmPosicao(lista,lista->size-1));
    printf("%d\n",obterElementoEmPosicao(lista,3));

    return 0;    
}
