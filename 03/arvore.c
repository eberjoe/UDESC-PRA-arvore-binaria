#include <stdlib.h>
#include <stdio.h>
#include "arvore.h"

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
    if (!pai) {
        arvore->raiz = no;
    }
    return no;
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

int custo_busca(Arvore *arvore, int chave) {
    int custo = 1;
    if (!arvore_vazia(arvore)) {
        No *no = arvore->raiz;
        if (no->valor == chave)
            return custo;
        while ((no->esquerda || no->direita) && no->valor != chave) {
            custo++;
            if (chave > no->valor && no->direita)
                no = no->direita;
            else if (no->esquerda)
                no = no->esquerda;
        }
        if (no->valor == chave)
            return custo;
        else
            return -1;
    }
    return 0;
}

void limpa_subarvore(Arvore *arvore, No *no) {
    if (no) {
        limpa_subarvore(arvore, no->esquerda);
        limpa_subarvore(arvore, no->direita);
        remove_no(arvore, no);
    }
}