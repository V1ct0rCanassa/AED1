#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int altura;
    int qtd;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int h) {
    No* novo = (No*)malloc(sizeof(No));
    novo->altura = h;
    novo->qtd = 1;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

No* inserir(No* raiz, int h) {
    if (raiz == NULL) return criarNo(h);

    if (h == raiz->altura) {
        raiz->qtd++;
    } else if (h < raiz->altura) {
        raiz->esq = inserir(raiz->esq, h);
    } else {
        raiz->dir = inserir(raiz->dir, h);
    }
    return raiz;
}


int primeiro;

void emOrdem(No* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esq);
        
        for (int i = 0; i < raiz->qtd; i++) {
            if (!primeiro) printf(" ");
            printf("%d", raiz->altura);
            primeiro = 0;
        }

        emOrdem(raiz->dir);
    }
}

void liberarArvore(No* raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esq);
        liberarArvore(raiz->dir);
        free(raiz);
    }
}

int main() {
    int nc, n, h;

    scanf("%d", &nc);

    while (nc--) {
        scanf("%d", &n);
        
        No* raiz = NULL;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &h);
            raiz = inserir(raiz, h);
        }

        primeiro = 1;
        emOrdem(raiz);
        printf("\n");

        liberarArvore(raiz);
    }

    return 0;
}
