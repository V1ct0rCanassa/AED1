#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int M;
        scanf("%d", &M);

        int original[1005];
        int ordenado[1005];

        for (int i = 0; i < M; i++) {
            scanf("%d", &original[i]);
            ordenado[i] = original[i];
        }

        qsort(ordenado, M, sizeof(int), comparar);

        int count = 0;
        for (int i = 0; i < M; i++) {
            if (original[i] == ordenado[i]) {
                count++;
            }
        }

        printf("%d\n", count);
    }

    return 0;
}
