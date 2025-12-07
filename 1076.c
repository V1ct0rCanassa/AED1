#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int destino;
    struct Node *prox;
} Node;

Node **lista_adj;
int *visitado;

Node* cria_no(int destino) {
    Node *novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        exit(EXIT_FAILURE);
    }
    novo->destino = destino;
    novo->prox = NULL;
    return novo;
}

void adiciona_aresta(int u, int v) {
    Node *novo = cria_no(v);
    novo->prox = lista_adj[u];
    lista_adj[u] = novo;
}

void libera_memoria(int V) {
    for (int i = 0; i < V; i++) {
        Node *atual = lista_adj[i];
        Node *temp;
        while (atual != NULL) {
            temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    if (lista_adj != NULL) free(lista_adj);
    if (visitado != NULL) free(visitado);
}

int dfs(int u) {
    int total_arestas = 0;
    
    visitado[u] = 1;

    Node *atual = lista_adj[u];
    while (atual != NULL) {
        int v = atual->destino;
        
        if (visitado[v] == 0) {
            total_arestas += 1;
            total_arestas += dfs(v);
        }
        atual = atual->prox;
    }
    
    return total_arestas;
}

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;

    while (T--) {
        int N, V, E;
        if (scanf("%d %d %d", &N, &V, &E) != 3) {
            continue; 
        }

        lista_adj = (Node**)malloc(V * sizeof(Node*));
        if (lista_adj == NULL) exit(EXIT_FAILURE);
        
        for (int i = 0; i < V; i++) {
            lista_adj[i] = NULL;
        }

        visitado = (int*)calloc(V, sizeof(int));
        if (visitado == NULL) exit(EXIT_FAILURE);
        
        for (int i = 0; i < E; i++) {
            int u, v;
            if (scanf("%d %d", &u, &v) != 2) continue;
            
            adiciona_aresta(u, v);
            adiciona_aresta(v, u);
        }

        int arestas_componente = dfs(N);
        
        int total_movimentos = arestas_componente * 2;
        printf("%d\n", total_movimentos);

        libera_memoria(V);
    }

    return 0;
}
