#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
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

void inserirNoRec(struct noBst** raiz, struct noBst* novoNo) {
    if((*raiz) == NULL) (*raiz) = novoNo;
    else if(novoNo->val > (*raiz)->val) inserirNoRec(&(*raiz)->dir,novoNo);
    else inserirNoRec(&(*raiz)->esq,novoNo);
}

void inserirNoIt(struct noBst* raiz, struct noBst* novoNo) {
    if (raiz == NULL) raiz = novoNo;
    else if(novoNo->val > raiz->val) inserirNoIt(raiz->dir, novoNo);
    else inserirNoIt(raiz->esq,novoNo);
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

/* void navEmOrdem(struct noBst* raiz) { */
/*     //IMPLEMENTAR */
/* } */

/* void navPreOrdem(struct noBst* raiz) { */
/*     //IMPLEMENTAR */
/* } */

/* void navPosOrdem(struct noBst* raiz) { */
/*     //IMPLEMENTAR */
/* } */

/* int min(struct noBst* raiz) { */
/*     //IMPLEMENTAR */
/* } */

/* int max(struct noBst* raiz) { */
/*     //IMPLEMENTAR */
/* } */

/* int altura(struct noBst* raiz) { */
/*     //IMPLEMENTAR */
/* } */

/* struct noBst* removerRec(struct noBst* raiz, int val) { */
/*     //IMPLEMENTAR */
/* } */

/* void remover(struct bst* bst, int val) { */
/*     //IMPLEMENTAR */
/* } */
