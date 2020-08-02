#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

Arvore* cria_arvore() {
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int arvore_vazia(Arvore* arvore) {
    return arvore->raiz == NULL;
}

No* adiciona_no(Arvore* arvore, No* pai, int valor) {
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

void remove_no(Arvore* arvore, No* no) {
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

void percorrer_InOrder(No* no, void (callback) (int)) {
    if (no != NULL) {
        percorrer_InOrder(no->esquerda, callback);
        callback(no->valor);
        percorrer_InOrder(no->direita, callback);
    }
}

void percorrer_PreOrder(No* no, void (callback) (int)) {
    if (no != NULL) {
        callback(no->valor);
        percorrer_PreOrder(no->esquerda, callback);
        percorrer_PreOrder(no->direita, callback);
    }
}

void percorrer_PosOrder(No* no, void (callback) (int)) {
    if (no != NULL) {
        percorrer_PosOrder(no->esquerda, callback);
        percorrer_PosOrder(no->direita, callback);
        callback(no->valor);
    }
}