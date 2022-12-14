#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/queue.h>
#include "../header/binaryTree.h"

struct bst* alocarBst() {
    struct bst *arvore = malloc(sizeof *arvore);
    arvore->raiz = NULL;
    arvore->tam = 0;

    return arvore;
}

struct noBst* alocarNovoNo(int val) {
    struct noBst *no = malloc(sizeof *no);
    no->esq = NULL;
    no->val = val;
    no->dir = NULL;

    return no;
}

//  Funções auxiliares
int maior(int a, int b)
{
    if(a > b) return a;
    else return b;
}

TAILQ_HEAD(tailhead, entry) head;

struct entry{
    struct noBst *raiz;
    TAILQ_ENTRY(entry) entries;
};

void add_to_queue(struct noBst *raiz)
{
    struct entry *elem = malloc(sizeof *elem);
    if (elem) elem->raiz = raiz;
    TAILQ_INSERT_TAIL(&head, elem, entries);
}

//---------------------------------------------

void inserirNoRec(struct noBst** raiz, struct noBst* novoNo) {
    if((*raiz) == NULL) (*raiz) = novoNo;
    else if(novoNo->val > (*raiz)->val) inserirNoRec(&(*raiz)->dir,novoNo);
    else inserirNoRec(&(*raiz)->esq,novoNo);
}

void inserirNoIt(struct noBst* raiz, struct noBst* novoNo) {
    struct noBst **rr = &raiz; 

    while(*rr != NULL)
    {
        if((*rr)->val > novoNo->val) rr = &(*rr)->esq;
        else rr = &(*rr)->dir;
    }
    *rr = novoNo;
}

void inserir(struct bst* bst, int val, bool rec) {
    if(bst->raiz == NULL) bst->raiz = alocarNovoNo(val); 
    else if(rec) inserirNoRec(&(bst->raiz),alocarNovoNo(val)); 
    else inserirNoIt(bst->raiz,alocarNovoNo(val));
    bst->tam++;
}

bool buscarRec(struct noBst* raiz, int val) {
    if(raiz == NULL) return false;
    else
    {
        if(raiz->val == val) return true;
        else if(raiz->val > val) return buscarRec(raiz->esq,val);
        else return buscarRec(raiz->dir, val);
    }
}

bool buscarIt(struct noBst* raiz, int v) {
    while(raiz != NULL)
    {
        if(raiz->val == v) return true;
        else if(raiz->val > v) raiz = raiz->esq;
        else raiz = raiz->dir;
    }
    return false;
}

bool buscar(struct bst* bst, int val, bool rec) {
    if(rec) return buscarRec(bst->raiz,val);
    return buscarIt(bst->raiz,val);
}

void navEmOrdem(struct noBst* raiz) {
    //Esq, raíz, direita
    if(raiz != NULL){
        navEmOrdem(raiz->esq);
        printf("%d, ", raiz->val);
        navEmOrdem(raiz->dir);
    } else return;
}

void navPreOrdem(struct noBst* raiz) {
    //Raíz, esq, dir
    if(raiz != NULL){
        printf("%d, ", raiz->val);
        navPreOrdem(raiz->esq);
        navPreOrdem(raiz->dir);
    } else return;
}

void navPosOrdem(struct noBst* raiz) {
    //esq,dir,raíz
    if(raiz != NULL){
        navPosOrdem(raiz->esq);
        navPosOrdem(raiz->dir);
        printf("%d, ", raiz->val);
    } else return;
}

void navNivel(struct noBst* raiz){
    TAILQ_INIT(&head);
    add_to_queue(raiz);

    struct entry *elem = head.tqh_first;
    while(elem != NULL)
    {
        struct noBst* noVisitado = elem->raiz;
        printf("%d, ", noVisitado->val);

        if(noVisitado->esq != NULL) add_to_queue(noVisitado->esq);
        if(noVisitado->dir != NULL) add_to_queue(noVisitado->dir);

        TAILQ_REMOVE(&head, elem, entries);
        free(elem);
        elem = head.tqh_first;
    }
}

int min(struct noBst* raiz) {
    if (raiz->esq == NULL) return raiz->val;
    else return min(raiz->esq);
}

int max(struct noBst* raiz) {
    if (raiz->dir == NULL) return raiz->val;
    else return max(raiz->dir);
}

int altura(struct noBst* raiz) {
    if(raiz == NULL) return -1;
    else return 1 + maior(altura(raiz->esq),altura(raiz->dir)); 
}

struct noBst* removerRec(struct noBst* raiz, int val) {
    if(raiz != NULL)
    {
        if(val < raiz->val) raiz->esq = removerRec(raiz->esq,val); 
        else if(val > raiz->val) raiz->dir = removerRec(raiz->dir,val);
        else
        {
            if(raiz->esq == NULL && raiz->dir == NULL)
            {
                free(raiz);
                raiz = NULL;
            }
            else if (raiz->esq == NULL)
            {
                struct noBst* temp = raiz->dir;
                free(raiz);
                raiz = temp;
            }
            else if(raiz->dir == NULL)
            {
                struct noBst* temp = raiz->esq;
                free(raiz);
                raiz = temp;
            }
            else
            {
                int maiorEsq = max(raiz->esq);
                raiz->val = maiorEsq;
                raiz->esq = removerRec(raiz->esq,maiorEsq);
            }
        }
    }
    return raiz;
}

/* void remover(struct bst* bst, int val) { */
/*     //IMPLEMENTAR */
/* } */
