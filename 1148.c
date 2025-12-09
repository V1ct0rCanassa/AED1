#include <stdio.h>
#include <limits.h>

#define MAX 505
#define INF 99999999

int adj[MAX][MAX];
int dist[MAX];
int visitado[MAX];
int N, E;

int dijkstra(int origem, int destino) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }

    dist[origem] = 0;

    for (int i = 1; i <= N; i++) {
        int u = -1;
        int min_dist = INF;

        for (int j = 1; j <= N; j++) {
            if (!visitado[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        if (u == -1 || dist[u] == INF) break;

        visitado[u] = 1;

        for (int v = 1; v <= N; v++) {
            if (adj[u][v] != INF) {
                if (dist[u] + adj[u][v] < dist[v]) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }

    return dist[destino];
}

int main() {
    int X, Y, H, K, O, D;

    while (1) {
        scanf("%d %d", &N, &E);
        if (N == 0 && E == 0) break;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = INF;
            }
            adj[i][i] = 0;
        }

        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &X, &Y, &H);
            adj[X][Y] = H;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adj[i][j] != INF && adj[j][i] != INF) {
                    adj[i][j] = 0;
                    adj[j][i] = 0;
                }
            }
        }

        scanf("%d", &K);
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &O, &D);
            int resultado = dijkstra(O, D);

            if (resultado == INF) {
                printf("Nao e possivel entregar a carta\n");
            } else {
                printf("%d\n", resultado);
            }
        }
        printf("\n");
    }

    return 0;
}
