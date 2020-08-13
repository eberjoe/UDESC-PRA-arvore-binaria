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
void percorrer_largura(No *no, void (*callback) (int));
