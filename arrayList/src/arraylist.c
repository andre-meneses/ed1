#include "../header/arraylist.h"
#include <stdlib.h>

struct arraylist* inicializar(int capacidade) {
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));
    lista->vetor = (int*)calloc(capacidade, sizeof(int));
    lista->qtdade = 0;
    lista->capacidade = capacidade;
    return lista;
}

void exibirLista(struct arraylist* lista) {
    printf("[");
    for (int i = 0; i < lista->qtdade; i++) {
        printf("%d", lista->vetor[i]);
        if (i < lista->qtdade - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int obterElementoEmPosicao(struct arraylist* lista, int posicao)
{
    if (posicao < lista->qtdade) return lista->vetor[posicao];

    printf("Out of Bounds \n"); 
    return -1;
}

void duplicarCapacidade(struct arraylist* lista)
{
    lista->vetor = (int*)realloc(lista->vetor, 2 * sizeof(int) * lista->capacidade);
    lista->capacidade *= 2;
}

void inserirElementoNoFim(struct arraylist* lista, int valor)
{
    inserirElementoEmPosicao(lista, valor, lista->qtdade);
}

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao)
{
    if (lista->qtdade + 1 >= lista->capacidade) duplicarCapacidade(lista);

    if (posicao <= lista->qtdade)
    {
        for(int i = lista->qtdade; i > posicao; i--) lista->vetor[i] = lista->vetor[i - 1];

        lista->vetor[posicao] = valor; 
        lista->qtdade++;
    }
    else
    {
        printf("Out of bounds \n");
    }

}

void atualizarElemento(struct arraylist* lista, int valor, int posicao)
{
    if(posicao < lista->qtdade)
    {
        lista->vetor[posicao] = valor;
    }
    else
    {
        printf("Out of Bounds");
    }
}

void removerElementoNoFim(struct arraylist* lista)
{
    removerElementoEmPosicao(lista,lista->qtdade - 1); 
}

void removerElementoEmPosicao(struct arraylist* lista, int posicao)
{
    if(posicao < lista->qtdade)
    {
        for (int i = posicao; i < lista->qtdade; i++) lista->vetor[i] = lista->vetor[i+1];
        lista ->qtdade--;

        if(lista->qtdade < lista->capacidade/2)
        {
            lista->vetor = (int*)realloc(lista->vetor, sizeof(int) * (int)lista->capacidade/2);
            lista->capacidade = (int) lista->capacidade/2;
        }
    }
    else
    {
        printf("Out of Bounds");
    }
}

