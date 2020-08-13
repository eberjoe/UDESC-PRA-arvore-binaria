typedef struct no {
    struct no *pai;
    struct no *esquerda;
    struct no *direita;
    int valor;
} No;

typedef struct arvore {
    struct no *raiz;
} Arvore;

void inicializa_arvore(Arvore *arvore);
int arvore_vazia(Arvore *arvore);
No* adiciona_no(Arvore *arvore, No *pai, int valor);
void remove_no(Arvore *arvore, No *no);
void percorrer_InOrder(No *no, void (*callback) (int));
void percorrer_PreOrder(No *no, void (*callback) (int));
void percorrer_PosOrder(No *no, void (*callback) (int));
int custo_busca(Arvore *arvore, int chave);
void limpa_subarvore(Arvore *arvore, No *no);