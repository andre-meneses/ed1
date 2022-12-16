#include "../header/avl.h"

const int INT_MIN = -2147483647;

TAILQ_HEAD(tailhead, entry) head;

void imprimir(struct noAvl *raiz) {
  if (raiz != NULL) {
    imprimir(raiz->esq);
    printf("%d (bf=%d), ", raiz->val, raiz->bf);
    imprimir(raiz->dir);
  }
}

struct noAvl* alocarNo(int val)
{
    struct noAvl *newNode = malloc(sizeof *newNode);
    newNode->altura = 0;
    newNode->bf = 0;
    newNode->dir = NULL;
    newNode->esq = NULL;
    newNode->val = val;

    return newNode;
}


void atualizar(struct noAvl *raiz)
{
    if(raiz != NULL)
    {
        int hesq = 0, hdir = 0;
        if(raiz->esq != NULL) hesq = raiz->esq->altura;
        if(raiz->dir != NULL) hdir = raiz->dir->altura;

        raiz->altura = 1 + (hesq > hdir? hesq : hdir);
        raiz->bf = hdir - hesq;
    }
}

struct noAvl* rotDireita(struct noAvl* raiz)
{
    struct noAvl* novaRaiz = raiz->esq;
    raiz->esq = novaRaiz->dir;
    novaRaiz->dir = raiz;

    atualizar(raiz);
    atualizar(novaRaiz);

    return novaRaiz;
}

struct noAvl* rotEsquerda(struct noAvl* raiz)
{
    struct noAvl* novaRaiz = raiz->dir;
    raiz->dir = novaRaiz->esq;
    novaRaiz->esq = raiz;

    atualizar(raiz);
    atualizar(novaRaiz);

    return novaRaiz;
}

struct noAvl *rebalancEsqEsq(struct noAvl *raiz)
{
    return rotDireita(raiz);
}

struct noAvl *rebalancEsqDir(struct noAvl* raiz)
{
    raiz->esq = rotEsquerda(raiz->esq);
    return rotDireita(raiz);
}


struct noAvl *rebalancDirDir(struct noAvl* raiz)
{
    return rotEsquerda(raiz);
}

struct noAvl *rebalancDirEsq(struct noAvl* raiz)
{
    raiz->dir = rotDireita(raiz->dir);
    return rotEsquerda(raiz);
}

struct noAvl *rebalanceamento(struct noAvl* raiz)
{
    if(raiz != NULL)
    {
        if(raiz->bf == -2)
        {
            if(raiz->esq != NULL && raiz->esq->bf <=0) raiz = rebalancEsqEsq(raiz);
            else raiz = rebalancEsqDir(raiz);
        }
        else if(raiz->bf == 2)
        {
            if(raiz->dir != NULL && raiz->dir->bf >= 0) raiz = rebalancDirDir(raiz);
            else raiz = rebalancDirEsq(raiz);
        }
    }
    return raiz;
}

void inserir(struct noAvl **raiz, int val)
{
    if((*raiz) == NULL) (*raiz) = alocarNo(val);
    else
    {
        if(val > (*raiz)->val) inserir(&(*raiz)->dir, val);
        else inserir(&(*raiz)->esq, val);
    }
    atualizar(*raiz);
    (*raiz) = rebalanceamento(*raiz);
}

void navEmOrdem(struct noAvl *raiz)
{
    if(raiz != NULL)
    {
        navEmOrdem(raiz->esq);
        printf("%d, ", raiz->val);
        navEmOrdem(raiz->dir);
    }
}

void navPreOrdem(struct noAvl *raiz)
{
    if(raiz != NULL)
    {
        printf("%d, ", raiz->val);
        navPreOrdem(raiz->esq);
        navPreOrdem(raiz->dir);
    }
}
