struct node{
    int val;
    struct node *prox;
};

struct linkedstack {
    struct node* topo;
    int qtdade;
};

struct linkedstack* inicializar(); 
struct node* alocarNovoNo(int valor);
bool vazia(struct linkedstack* pilha); 
void empilhar(struct linkedstack** pilha, int valor);
void desempilhar(struct linkedstack* pilha);
int desempilharRetornando(struct linkedstack* pilha);
int topo(struct linkedstack* pilha);
void exibirPilha(struct linkedstack* pilha);
