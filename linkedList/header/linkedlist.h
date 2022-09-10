#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node *prox;
};

struct linkedlist {
    struct node *head;
    struct node *tail;
    int size;
};

struct linkedlist *inicializar();
void imprimirLista(struct linkedlist* lista);
void inserirElementoNoFim(struct linkedlist* lista, int valor);
void inserirElementoNoInicio(struct linkedlist* lista, int valor);
void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao);
int obterElementoEmPosicao(struct linkedlist* lista, int posicao);
void removerElementoEmPosicao(struct linkedlist* lista, int posicao);
struct node* buscarPosicao(struct linkedlist *lista, int posicao);
