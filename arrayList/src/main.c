#include "../header/arraylist.h"

int main()
{
    struct arraylist* lista = inicializar(6);
    
    for (int i = 0; i < 6; i++) inserirElementoNoFim(lista,i);
    exibirLista(lista);
    
    int max = lista->capacidade/2;

    printf("%d \n", max);

    for(int i = 0; i < max; i++)
    {
        inserirElementoEmPosicao(lista,3,2);
    }

    exibirLista(lista);

    return 0;    
}


