#include <stdio.h>
#include "../header/binaryTree.h"

int main()
{
    struct bst *arvore = alocarBst();
    inserir(arvore,12,true);
    inserir(arvore,8,true);
    inserir(arvore,1,true);
    inserir(arvore,15,true);
    inserir(arvore,4,true);
    inserir(arvore,3,true);
    inserir(arvore,20,true);
    inserir(arvore,14,true);
    inserir(arvore,5,true);
    int h = altura(arvore->raiz);
    int mi = min(arvore->raiz);
    int ma = max(arvore->raiz);
    /* printf("%d\n", h); */
    /* printf("%d\n", mi); */
    /* printf("%d\n", ma); */
    /* printf("%d\n", buscar(arvore,12,false)); */
    /* printf("%d\n", buscar(arvore,20,false)); */
    /* printf("%d\n", buscar(arvore,4,false)); */
    /* printf("%d\n", buscar(arvore,22,false)); */
    removerRec(arvore->raiz, 15);
    navNivel(arvore->raiz);
    return 0;
}
