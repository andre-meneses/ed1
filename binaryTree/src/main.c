#include <stdio.h>
#include "../header/binaryTree.h"

int main()
{
    struct bst *arvore = alocarBst();
    inserir(arvore,12,false);
    inserir(arvore,8,false);
    inserir(arvore,1,false);
    inserir(arvore,15,false);
    inserir(arvore,4,false);
    inserir(arvore,3,false);
    inserir(arvore,20,false);
    int h = altura(arvore->raiz);
    int mi = min(arvore->raiz);
    int ma = max(arvore->raiz);
    printf("%d\n", h);
    printf("%d\n", mi);
    printf("%d\n", ma);
    /* printf("%d\n", buscar(arvore,12,false)); */
    /* printf("%d\n", buscar(arvore,20,false)); */
    /* printf("%d\n", buscar(arvore,4,false)); */
    /* printf("%d\n", buscar(arvore,22,false)); */

    return 0;
}
