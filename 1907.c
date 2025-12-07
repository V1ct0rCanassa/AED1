#include <stdio.h>
#include <stdlib.h>

char **grid;
int **visited;
int N, M; 

#define MAX_QUEUE 1048576 
int queue_r[MAX_QUEUE];
int queue_c[MAX_QUEUE];
int head, tail;

int is_valid(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < M);
}

void free_memory() {
    if (grid) {
        for (int i = 0; i < N; i++) {
            if (grid[i]) free(grid[i]);
        }
        free(grid);
    }
    if (visited) {
        for (int i = 0; i < N; i++) {
            if (visited[i]) free(visited[i]);
        }
        free(visited);
    }
}

void bfs(int r_start, int c_start) {
    head = 0;
    tail = 0;

    queue_r[tail] = r_start;
    queue_c[tail] = c_start;
    tail++;
    visited[r_start][c_start] = 1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (head != tail) {
        int r = queue_r[head];
        int c = queue_c[head];
        head++;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (is_valid(nr, nc) && grid[nr][nc] == '.' && visited[nr][nc] == 0) {
                visited[nr][nc] = 1;
                queue_r[tail] = nr;
                queue_c[tail] = nc;
                tail++;
            }
        }
    }
}

int main() {
    if (scanf("%d %d", &N, &M) != 2) return 0;
    
    grid = (char**)malloc(N * sizeof(char*));
    visited = (int**)malloc(N * sizeof(int*));
    if (!grid || !visited) {
        free_memory(); 
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        grid[i] = (char*)malloc((M + 1) * sizeof(char));
        visited[i] = (int*)calloc(M, sizeof(int));
        if (!grid[i] || !visited[i]) {
            free_memory();
            return 1;
        }
        
        if (scanf("%s", grid[i]) != 1) {
            free_memory();
            return 0;
        }
    }

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            
            if (grid[i][j] == '.' && visited[i][j] == 0) {
                count++;
                bfs(i, j);
            }
        }
    }

    printf("%d\n", count);

    free_memory();

    return 0;
}
