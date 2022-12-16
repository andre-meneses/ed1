#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/queue.h>
#include <unistd.h>


/*************************************
 * Fila para navegacao por niveis
 *************************************/

struct entry {
  struct noAvl *raiz;
  TAILQ_ENTRY(entry) entries;
};

/*************************************/

struct noAvl {
  struct noAvl *esq;
  int val, altura, bf;
  struct noAvl *dir;
};

void add_to_queue(struct noAvl *raiz);
void imprimir(struct noAvl *raiz);
struct noAvl *alocarNo(int val);
void atualizar(struct noAvl *raiz);
struct noAvl *rotDireita(struct noAvl *raiz);
struct noAvl *rotEsquerda(struct noAvl *raiz);
struct noAvl *rebalancEsqEsq(struct noAvl *raiz) ;
struct noAvl *rebalancEsqDir(struct noAvl *raiz) ;
struct noAvl *rebalancDirDir(struct noAvl *raiz) ;
struct noAvl *rebalancDirEsq(struct noAvl *raiz) ;
struct noAvl *rebalanceamento(struct noAvl *raiz) ;
void inserir(struct noAvl **raiz, int val) ;
bool buscar(struct noAvl *raiz, int val) ;
int minIt(struct noAvl *raiz);
int minRec(struct noAvl *raiz); // raiz eh local
int maxBST(struct noAvl *raiz); // raiz eh local
int max(int a, int b);
int altura(struct noAvl *raiz);
void navNivel(struct noAvl *raiz);
void navPreOrdem(struct noAvl *raiz);
void navEmOrdem(struct noAvl *raiz);
void navPosOrdem(struct noAvl *raiz);
struct noAvl *remover(struct noAvl *raiz, int val);
