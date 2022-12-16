#include "../header/avl.h"

int main()
{
    struct noAvl* raiz = NULL; 

    for(int i = 0; i < 10; i++)
        inserir(&raiz, i);

    navPreOrdem(raiz);
    
    return 0;
}

