#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include "../header/linkedliststack.h"

struct linkedstack* inicializar() {
    struct linkedstack *pilha = (struct linkedstack*) malloc(sizeof *pilha);
    pilha->topo = NULL;
    pilha->qtdade = 0;
    return pilha;
}

struct node* alocarNovoNo(int valor){
    struct node *newNode = (struct node*) malloc(sizeof *newNode);
    newNode->val = valor;

    return newNode;
}

//retornar true se a pilha for nula ou vazia
bool vazia(struct linkedstack* pilha) {
    if(pilha == NULL || pilha->qtdade==0) return true;
    return false;
}

//se a pilha estiver nula, instancie a pilha
//por causa da possibilidade de instanciacao usamos struct linkedstack**
void empilhar(struct linkedstack** pilha, int valor){
    if((*pilha) == NULL) (*pilha) = inicializar();

    struct node *newNode = alocarNovoNo(valor);

    if((*pilha)->qtdade == 0) newNode->prox = NULL;
    else newNode->prox = (*pilha)->topo;
    
    (*pilha)->topo = newNode;
    (*pilha)->qtdade++;

}

//decrementar qtdade se a pilha não estiver nula ou vazia
void desempilhar(struct linkedstack* pilha) {
    if(pilha != NULL && pilha->qtdade > 0){
        struct node *newHead = pilha->topo->prox;
        free(pilha->topo);
        pilha->topo = newHead;
        pilha->qtdade--;
    } 
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int desempilharRetornando(struct linkedstack* pilha) {
    if(pilha == NULL || pilha->qtdade == 0) return INT_MIN;

    int valor = pilha->topo->val;
    desempilhar(pilha);

    return valor;
}

//retorne a constante INT_MIN se a pilha for nula ou vazia
int topo(struct linkedstack* pilha){
    if(pilha == NULL || pilha->qtdade == 0) return INT_MIN;
    
    return pilha->topo->val;
}

void exibirPilha(struct linkedstack* pilha) {
    //usamos o aux para percorrer a lista
    if (!vazia(pilha)) {
        struct node* aux = pilha->topo;
        //navega partindo do topo até chegar NULL
        printf("_\n");
        do {
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while (aux != NULL);
        printf("_");
    }
    else {
        printf("A pilha está vazia!");
    }
}
