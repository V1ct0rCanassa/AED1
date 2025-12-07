#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 10000
#define MAX_QUEUE 10001

int dist[MAX_NUM + 1]; 
int queue[MAX_QUEUE];

int reverse(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return reversed;
}

int bfs(int A, int B) {
    memset(dist, -1, sizeof(dist));

    int head = 0;
    int tail = 0;

    queue[tail] = A;
    dist[A] = 0;
    tail++;

    while (head < tail) {
        int u = queue[head];
        head++;

        if (u == B) {
            return dist[u];
        }

        int v_add = u + 1;
        if (v_add <= MAX_NUM && dist[v_add] == -1) {
            dist[v_add] = dist[u] + 1;
            queue[tail] = v_add;
            tail++;
        }

        int w_rev = reverse(u);
        if (w_rev <= MAX_NUM && dist[w_rev] == -1) {
            dist[w_rev] = dist[u] + 1;
            queue[tail] = w_rev;
            tail++;
        }
    }
    
    return -1; 
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int A, B;
        if (scanf("%d %d", &A, &B) != 2) continue;
        
        printf("%d\n", bfs(A, B));
    }

    return 0;
}
