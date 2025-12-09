#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOIAS 100005
#define TAM_MAX 100005

char *joias[MAX_JOIAS];

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    char *buffer = (char *)malloc(TAM_MAX * sizeof(char));
    int total = 0;

    while (scanf("%100000s", buffer) != EOF) {
        if (total >= MAX_JOIAS) break;

        joias[total] = (char *)malloc((strlen(buffer) + 1) * sizeof(char));

        if (joias[total]) {
            strcpy(joias[total], buffer);
            total++;
        }
    }

    if (total == 0) {
        printf("0\n");
        free(buffer);
        return 0;
    }

    qsort(joias, total, sizeof(char *), comparar);

    int distintos = 1;
    for (int i = 1; i < total; i++) {
        if (strcmp(joias[i], joias[i-1]) != 0) {
            distintos++;
        }
    }

    printf("%d\n", distintos);

    free(buffer);
    return 0;
}
