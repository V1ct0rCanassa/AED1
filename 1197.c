#include <stdio.h>

int main() {
    int V, T;
    while (scanf("%d %d", &V, &T) != EOF) {
        int D = 2 * V * T;
        printf("%d\n", D);
    }
    return 0;
}
