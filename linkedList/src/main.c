#include "../header/linkedlist.h"

int main()
{
    struct linkedlist *lista = inicializar();
    struct linkedlist *lista2 = inicializar();
    
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

    for (int i = 0; i < 5; i++) inserirElementoEmPosicao(lista2,i,i);
    //imprimirLista(lista2);

    /*for (int i = 0; i < 100; i++) 
    {
        printf("%d, ",obterElementoEmPosicao(lista2,i));
    }
    printf("\n");*/

    printf("%d \n", obterElementoEmPosicao(lista,0));
    printf("%d \n", obterElementoEmPosicao(lista,8));
    printf("%d \n", obterElementoEmPosicao(lista,2));
    printf("%d \n", obterElementoEmPosicao(lista,14));
    printf("%d \n", lista->size);

    removerElementoEmPosicao(lista,0);
    imprimirLista(lista);

    removerElementoEmPosicao(lista,3);
    imprimirLista(lista);

    removerElementoEmPosicao(lista,lista->size-1);
    imprimirLista(lista);



    return 0;    
}
