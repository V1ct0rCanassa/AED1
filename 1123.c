#include <stdio.h>
#include <limits.h>

#define MAX 255
#define INF 99999999

int adj[MAX][MAX];
int dist[MAX];
int visitado[MAX];
int N, M, C, K;

int dijkstra(int origem, int destino) {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }

    dist[origem] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1;
        int min_dist = INF;

        for (int j = 0; j < N; j++) {
            if (!visitado[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) break;

        visitado[u] = 1;

        if (u < C - 1) {
            if (adj[u][u + 1] != INF) {
                if (dist[u] + adj[u][u + 1] < dist[u + 1]) {
                    dist[u + 1] = dist[u] + adj[u][u + 1];
                }
            }
        } else {
            for (int v = 0; v < N; v++) {
                if (adj[u][v] != INF) {
                    if (dist[u] + adj[u][v] < dist[v]) {
                        dist[v] = dist[u] + adj[u][v];
                    }
                }
            }
        }
    }

    return dist[destino];
}

int main() {
    int U, V, P;

    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = INF;
            }
            adj[i][i] = 0;
        }

        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &U, &V, &P);
            if (P < adj[U][V]) {
                adj[U][V] = P;
                adj[V][U] = P;
            }
        }

        printf("%d\n", dijkstra(K, C - 1));
    }

    return 0;
}
