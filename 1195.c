#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *esq, *dir;
} celula;

celula *inserir(celula *raiz, int valor) {
    if (raiz == NULL) {
        celula *novo = (celula *)malloc(sizeof(celula));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

void prefixo(celula *raiz, int *cont) {
    if (raiz != NULL) {
        if ((*cont)++) printf(" ");
        printf("%d", raiz->valor);
        prefixo(raiz->esq, cont);
        prefixo(raiz->dir, cont);
    }
}

void infixo(celula *raiz, int *cont) {
    if (raiz != NULL) {
        infixo(raiz->esq, cont);
        if ((*cont)++) printf(" ");
        printf("%d", raiz->valor);
        infixo(raiz->dir, cont);
    }
}

void posfixo(celula *raiz, int *cont) {
    if (raiz != NULL) {
        posfixo(raiz->esq, cont);
        posfixo(raiz->dir, cont);
        if ((*cont)++) printf(" ");
        printf("%d", raiz->valor);
    }
}

void liberar(celula *raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    int C, N, valor, i;
    scanf("%d", &C);
    for (int caso = 1; caso <= C; caso++) {
        celula *raiz = NULL;
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
        }

        printf("Case %d:\n", caso);

        int cont = 0;
        printf("Pre.: ");
        prefixo(raiz, &cont);
        printf("\n");

        cont = 0;
        printf("In..: ");
        infixo(raiz, &cont);
        printf("\n");

        cont = 0;
        printf("Post: ");
        posfixo(raiz, &cont);
        printf("\n\n");

        liberar(raiz);
    }
    return 0;
}
