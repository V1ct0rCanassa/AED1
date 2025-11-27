#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int target[1005];
    int stack[1005];
    int top;

    while (scanf("%d", &n) && n != 0) {
        while (1) {
            scanf("%d", &target[0]);
            if (target[0] == 0) {
                printf("\n");
                break;
            }

            for (int i = 1; i < n; i++) {
                scanf("%d", &target[i]);
            }

            int current = 1;
            top = 0;
            int possible = 1;

            for (int i = 0; i < n; i++) {
                int wanted = target[i];

                while (current <= n && (top == 0 || stack[top - 1] != wanted)) {
                    stack[top++] = current++;
                }

                if (top > 0 && stack[top - 1] == wanted) {
                    top--;
                } else {
                    possible = 0;
                    break;
                }
            }

            if (possible) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
