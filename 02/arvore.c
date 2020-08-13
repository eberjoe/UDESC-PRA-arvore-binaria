#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"
#include "lista.h"

void inicializa_arvore(Arvore *arvore) {
    arvore->raiz = NULL;
}

int arvore_vazia(Arvore *arvore) {
    return arvore->raiz == NULL;
}

No* adiciona_no(Arvore *arvore, No *pai, int valor) {
    No *no = malloc(sizeof(No));
    no->pai = pai;
    no->esquerda = NULL;
    no->direita = NULL;
    no->valor = valor;
    if (pai == NULL) {
        arvore->raiz = no;
    }
    return no;
}

void remove_no(Arvore *arvore, No *no) {
    if (no->esquerda != NULL) {
        remove_no(arvore, no->esquerda); 
    }
    if (no->direita != NULL) {
        remove_no(arvore, no->direita);
    }
    if (no->pai == NULL) {
        arvore->raiz = NULL;
    } else {
        if (no->pai->esquerda == no) {
            no->pai->esquerda = NULL;
        } else {
            no->pai->direita = NULL;
        }
    }
    free(no);
}

void percorrer_largura(No *no, void (*callback) (int)) {
    LDE fila;
    inicializa_LDE(&fila, sizeof(No*));
    insereNoFim(&fila, &no);
    while (!LDE_vazia(&fila)) {
        No *no;
        removeDoInicio(&fila, &no);
        if (no->esquerda) {
            insereNoFim(&fila, &no->esquerda);
        }
        if (no->direita) {
            insereNoFim(&fila, &no->direita);
        }
        callback(no->valor);
    }
}