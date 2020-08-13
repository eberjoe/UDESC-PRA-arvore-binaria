#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

void inicializa_arvore(Arvore *arvore) {
    arvore->raiz = NULL;
}

int arvore_vazia(Arvore *arvore) {
    return arvore->raiz == NULL;
}

int adiciona_no(Arvore *arvore, int valor) {
    No *no = malloc(sizeof(No));
    if (!no)
        return 0;
    no->valor = valor;
    no->esquerda = NULL;
    no->direita = NULL;
    if (arvore_vazia(arvore)) {
        no->pai = NULL;
        arvore->raiz = no;
        return 1;
    } else {
        No *i = arvore->raiz;
        do {
            if (i->valor == valor) {
                free(no);
                return ERRO_CHAVE_REPETIDA;
            } else if (valor < i->valor) {
                if (!i->esquerda) {
                    no->pai = i;
                    i->esquerda = no;
                    return 1;
                } else {
                    i = i->esquerda;
                }
            } else {
                if (!i->direita) {
                    no->pai = i;
                    i->direita = no;
                    return 1;
                } else {
                    i = i->direita;
                }
            }
        } while (1);
    }        
}

void remove_no(Arvore *arvore, No *no) {
    if (no->esquerda) {
        remove_no(arvore, no->esquerda); 
    }
    if (no->direita) {
        remove_no(arvore, no->direita);
    }
    if (!no->pai) {
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

void percorrer_InOrder(No *no, void (*callback) (int)) {
    if (no) {
        percorrer_InOrder(no->esquerda, callback);
        callback(no->valor);
        percorrer_InOrder(no->direita, callback);
    }
}

void percorrer_PreOrder(No *no, void (*callback) (int)) {
    if (no) {
        callback(no->valor);
        percorrer_PreOrder(no->esquerda, callback);
        percorrer_PreOrder(no->direita, callback);
    }
}

void percorrer_PosOrder(No *no, void (*callback) (int)) {
    if (no) {
        percorrer_PosOrder(no->esquerda, callback);
        percorrer_PosOrder(no->direita, callback);
        callback(no->valor);
    }
}

void limpa_subarvore(Arvore *arvore, No *no) {
    if (no) {
        limpa_subarvore(arvore, no->esquerda);
        limpa_subarvore(arvore, no->direita);
        remove_no(arvore, no);
    }
}