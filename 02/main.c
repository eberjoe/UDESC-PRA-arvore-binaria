#include <stdio.h>
#include "arvore.h"

void mostrar(int valor);

int main() {
    Arvore a;
    inicializa_arvore(&a);

    No* no4 = adiciona_no(&a, NULL, 4);
    
    No* no2 = adiciona_no(&a, no4, 2);
    no4->esquerda = no2;

    No* no8 = adiciona_no(&a, no4, 8);
    no4->direita = no8;

    No* no1 = adiciona_no(&a, no2, 1);
    no2->esquerda = no1;

    No* no3 = adiciona_no(&a, no2, 3);
    no2->direita = no3;

    No* no6 = adiciona_no(&a, no8, 6);
    no8->esquerda = no6;

    No* no9 = adiciona_no(&a, no8, 9);
    no8->direita = no9;

    No* no5 = adiciona_no(&a, no6, 5);
    no6->esquerda = no5;

    No* no7 = adiciona_no(&a, no6, 7);
    no6->direita = no7;

    percorrer_largura(a.raiz, mostrar);
    printf("\n");
    
    return 1;
}

void mostrar(int valor) {
    printf("%d ", valor);
}
