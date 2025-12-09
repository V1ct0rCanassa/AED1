#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[100];
    double preco;
} Produto;

int main() {
    int N, M, P, quantidade;
    char nome_busca[100];
    Produto produtos[1000];
    double total;

    scanf("%d", &N);

    while (N--) {
        scanf("%d", &M);
        for (int i = 0; i < M; i++) {
            scanf("%s %lf", produtos[i].nome, &produtos[i].preco);
        }

        scanf("%d", &P);
        total = 0.0;

        for (int i = 0; i < P; i++) {
            scanf("%s %d", nome_busca, &quantidade);
            
            for (int j = 0; j < M; j++) {
                if (strcmp(produtos[j].nome, nome_busca) == 0) {
                    total += produtos[j].preco * quantidade;
                    break;
                }
            }
        }

        printf("R$ %.2lf\n", total);
    }

    return 0;
}
