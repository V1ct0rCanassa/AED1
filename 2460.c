#include <stdio.h>
#include <string.h>

#define MAX_N 50005
#define MAX_ID 100005

int main() {
    int n, m, id_temp;
    int fila[MAX_N];
    int saiu[MAX_ID];

    memset(saiu, 0, sizeof(saiu));

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &fila[i]);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &id_temp);
        saiu[id_temp] = 1;
    }

    int primeiro = 1;
    for (int i = 0; i < n; i++) {
        if (!saiu[fila[i]]) {
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");

    return 0;
}
