#include <stdio.h>
#include "arvore.h"

void mostrar(int valor);

int main() {
    int in;
    Arvore a;
    inicializa_arvore(&a);
    do {
        printf("Insira o valor do próximo nó, ou 'fim' para terminar: ");
        if (scanf("%d", &in)) {
            adiciona_no(&a, in);
        } else {
            break;
        }
    } while (1);

    return 1;
}

void mostrar(int valor) {
    printf("%d ", valor);
}
