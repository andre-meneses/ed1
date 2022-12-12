#include <stdbool.h>

struct bst {
    struct noBst* raiz;
    int tam;
};

struct noBst {
    int val;
    struct noBst* esq;
    struct noBst* dir;
};

struct bst* alocarBst();
struct noBst* alocarNovoNo(int val);
void inserirNoRec(struct noBst** raiz, struct noBst* novoNo);
void inserirNoIt(struct noBst* raiz, struct noBst* novoNo);
void inserir(struct bst* bst, int val, bool rec);
bool buscarRec(struct noBst* raiz, int val);
bool buscarIt(struct noBst* raiz, int v);
bool buscar(struct bst* bst, int val, bool rec);
void navEmOrdem(struct noBst* raiz);
void navPreOrdem(struct noBst* raiz);
void navPosOrdem(struct noBst* raiz);
int min(struct noBst* raiz);
int max(struct noBst* raiz);
int altura(struct noBst* raiz);
struct noBst* removerRec(struct noBst* raiz, int val);
void remover(struct bst* bst, int val);

