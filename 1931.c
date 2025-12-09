#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF 999999999
#define MAX_C 10005
#define MAX_E 100005

typedef struct {
    int v, w, next;
} Edge;

Edge edges[MAX_E * 2];
int head[MAX_C];
int edge_idx;

int dist[MAX_C][2];

typedef struct {
    int d, u, p;
} HeapNode;

HeapNode heap[MAX_E * 4];
int heap_size;

void add_edge(int u, int v, int w) {
    edges[edge_idx].v = v;
    edges[edge_idx].w = w;
    edges[edge_idx].next = head[u];
    head[u] = edge_idx++;
}

void push(int d, int u, int p) {
    heap_size++;
    int i = heap_size;
    while (i > 1) {
        int p_idx = i / 2;
        if (heap[p_idx].d <= d) break;
        heap[i] = heap[p_idx];
        i = p_idx;
    }
    heap[i].d = d;
    heap[i].u = u;
    heap[i].p = p;
}

HeapNode pop() {
    HeapNode ret = heap[1];
    HeapNode last = heap[heap_size--];
    int i = 1;
    while (i * 2 <= heap_size) {
        int child = i * 2;
        if (child != heap_size && heap[child + 1].d < heap[child].d) child++;
        if (last.d <= heap[child].d) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
    return ret;
}

int dijkstra(int C) {
    for (int i = 1; i <= C; i++) {
        dist[i][0] = INF;
        dist[i][1] = INF;
    }

    dist[1][0] = 0;
    heap_size = 0;
    push(0, 1, 0);

    while (heap_size > 0) {
        HeapNode top = pop();
        int d = top.d;
        int u = top.u;
        int p = top.p;

        if (d > dist[u][p]) continue;

        for (int i = head[u]; i != -1; i = edges[i].next) {
            int v = edges[i].v;
            int w = edges[i].w;
            int next_p = 1 - p;

            if (dist[u][p] + w < dist[v][next_p]) {
                dist[v][next_p] = dist[u][p] + w;
                push(dist[v][next_p], v, next_p);
            }
        }
    }

    return dist[C][0];
}

int main() {
    int C, V, C1, C2, G;

    scanf("%d %d", &C, &V);

    for (int i = 0; i <= C; i++) head[i] = -1;
    edge_idx = 0;

    for (int i = 0; i < V; i++) {
        scanf("%d %d %d", &C1, &C2, &G);
        add_edge(C1, C2, G);
        add_edge(C2, C1, G);
    }

    int res = dijkstra(C);

    if (res == INF) printf("-1\n");
    else printf("%d\n", res);

    return 0;
}
