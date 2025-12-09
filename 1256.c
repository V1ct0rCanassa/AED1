#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} No;

void inserir(No **tabela, int chave, int tamanho) {
    int indice = chave % tamanho;
    
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = chave;
    novo->prox = NULL;

    if (tabela[indice] == NULL) {
        tabela[indice] = novo;
    } else {
        No *atual = tabela[indice];
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

int main() {
    int N, M, C, chave;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &M, &C);

        if (i > 0) printf("\n");

        No *tabela[M];
        for (int j = 0; j < M; j++) {
            tabela[j] = NULL;
        }

        for (int j = 0; j < C; j++) {
            scanf("%d", &chave);
            inserir(tabela, chave, M);
        }

        for (int j = 0; j < M; j++) {
            printf("%d -> ", j);
            No *atual = tabela[j];
            while (atual != NULL) {
                printf("%d -> ", atual->valor);
                atual = atual->prox;
            }
            printf("\\\n");
        }
    }

    return 0;
}
