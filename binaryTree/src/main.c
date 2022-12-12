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
    return 0;
}
