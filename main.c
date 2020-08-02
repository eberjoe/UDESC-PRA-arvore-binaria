#include <stdio.h>
#include "arvore.h"

void mostrar(int valor);

int main() {
    Arvore* a = cria_arvore();

    No* no4 = adiciona_no(a, NULL, 4);
    
    No* no2 = adiciona_no(a, no4, 2);
    no4->esquerda = no2;

    No* no6 = adiciona_no(a, no4, 6);
    no4->direita = no6;

    No* no1 = adiciona_no(a, no2, 1);
    no2->esquerda = no1;

    No* no3 = adiciona_no(a, no2, 3);
    no2->direita = no3;

    No* no5 = adiciona_no(a, no6, 5);
    no6->esquerda = no5;

    No* no7 = adiciona_no(a, no6, 7);
    no6->direita = no7;

    printf("In-order: ");
    percorrer_InOrder(a->raiz, mostrar);
    printf("\nPre-order: ");
    percorrer_PreOrder(a->raiz, mostrar);
    printf("\nPos-order: ");
    percorrer_PosOrder(a->raiz, mostrar);
    printf("\n");
    return 1;
}

void mostrar(int valor) {
    printf("%d ", valor);
}
