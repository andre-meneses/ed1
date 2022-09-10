#include "../header/linkedlist.h" 

void imprimirLista(struct linkedlist* lista){
    //usamos o aux para percorrer a lista
    if (lista->head != NULL) {
        struct node* aux = lista->head;
        //navega partindo da cabeça até chegar NULL
        printf("[");
        do {
            printf("%d", aux->val);
            aux = aux->prox;
            if (aux != NULL) {
                printf(", ");
            }
        } while (aux != NULL);
        printf("]\n");
    }
    else {
        printf("A lista está vazia!");
    }
}

void inserirElementoNoFim(struct linkedlist* lista, int valor){
    struct node *newNode = malloc(sizeof *newNode);

    newNode->prox = NULL;
    newNode->val = valor;

    if(lista->size == 0)
    {
        lista->head = newNode;
        lista->tail = newNode;
    }
    else
    {
        lista->tail->prox = newNode;
        lista->tail = newNode;
    }

    lista->size++;
}
void inserirElementoNoInicio(struct linkedlist* lista, int valor){

    struct node *newNode = malloc(sizeof *newNode);

    newNode->val = valor;

    if(lista->size == 0)
    {
        newNode->prox = NULL;
        lista->head = newNode;
        lista->tail = newNode;
    }
    else
    {
        newNode->prox = lista->head;
        lista->head = newNode;
    }

    lista->size++;
}

void inserirElementoEmPosicao(struct linkedlist* lista, int valor, int posicao){
    if(posicao == 0) inserirElementoNoInicio(lista,valor); 
    else if (posicao == lista->size-1) inserirElementoNoFim(lista,valor);
    else if(posicao < lista->size && posicao > 0)
    {
        struct node *newNode = malloc(sizeof *newNode);
        struct node *foundNode = buscarPosicao(lista,posicao-1);

        newNode->val = valor;
        newNode->prox = foundNode->prox;
        foundNode->prox = newNode; 
        lista->size++;
    }
    else printf("Out of Bounds\n");
}

int obterElementoEmPosicao(struct linkedlist* lista, int posicao){
    if(posicao < lista->size && posicao >= 0) 
    {
        struct node *foundNode = buscarPosicao(lista,posicao);
        return foundNode->val;
    }
    else
    {
        printf("Out of Bounds\n");
        return 0;
    }
}

void removerElementoEmPosicao(struct linkedlist* lista, int posicao){
    if(posicao == 0)
    {
        struct node *newHead = lista->head->prox;
        free(lista->head);
        lista->head = newHead;
        lista->size--;
    }
    else if(posicao == lista->size-1)
    {
        struct node *newTail = buscarPosicao(lista,posicao-1);
        free(lista->tail);

        lista->tail = newTail;
        lista->tail->prox = NULL;
        lista->size--;
    }
    else if(posicao < lista->size-1 && posicao > 0)
    {
        struct node *foundNode = buscarPosicao(lista,posicao-1);
        struct node *newPosNode = foundNode->prox->prox;
        
        free(foundNode->prox);
        foundNode->prox = newPosNode;
        lista->size--;
    }
    else printf("Out of Bounds\n");
}

struct node* buscarPosicao(struct linkedlist *lista, int posicao)
{
    struct node *posNode = lista->head;
    
    for(int i = 0; i < posicao; i++) posNode = posNode->prox;

    return posNode;
}
