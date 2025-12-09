#include <stdio.h>
#include <string.h>

#define MAX 1000005

int pilha_val[MAX];
int pilha_min[MAX];
int topo = 0;

int main() {
    int N, valor;
    char operacao[10];

    scanf("%d", &N);

    while (N--) {
        scanf("%s", operacao);

        if (strcmp(operacao, "PUSH") == 0) {
            scanf("%d", &valor);
            
            pilha_val[topo] = valor;
            
            if (topo == 0) {
                pilha_min[topo] = valor;
            } else {
                if (valor < pilha_min[topo - 1]) {
                    pilha_min[topo] = valor;
                } else {
                    pilha_min[topo] = pilha_min[topo - 1];
                }
            }
            topo++;
        }
        else if (strcmp(operacao, "POP") == 0) {
            if (topo == 0) {
                printf("EMPTY\n");
            } else {
                topo--;
            }
        }
        else { 
            if (topo == 0) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", pilha_min[topo - 1]);
            }
        }
    }

    return 0;
}
