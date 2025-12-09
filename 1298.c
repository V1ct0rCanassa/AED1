#include <stdio.h>
#include <stdbool.h>

#define MAX 1205

bool dir[MAX][MAX], esq[MAX][MAX], cima[MAX][MAX], baixo[MAX][MAX];
bool visitado[MAX][MAX];
int N;

typedef struct {
    int i, j;
} Ponto;

Ponto pilha[MAX * MAX];
int topo = 0;

void busca(int i_inicial, int j_inicial) {
    topo = 0;
    pilha[topo].i = i_inicial;
    pilha[topo].j = j_inicial;
    topo++;
    
    visitado[i_inicial][j_inicial] = true;

    while (topo > 0) {
        topo--;
        int i = pilha[topo].i;
        int j = pilha[topo].j;

        if (i > 1 && !visitado[i-1][j] && cima[i][j]) {
            visitado[i-1][j] = true;
            pilha[topo].i = i - 1;
            pilha[topo].j = j;
            topo++;
        }

        if (i < 2 * N && !visitado[i+1][j] && baixo[i][j]) {
            visitado[i+1][j] = true;
            pilha[topo].i = i + 1;
            pilha[topo].j = j;
            topo++;
        }

        if (j > 1 && !visitado[i][j-1] && esq[i][j]) {
            visitado[i][j-1] = true;
            pilha[topo].i = i;
            pilha[topo].j = j - 1;
            topo++;
        }

        if (j < 2 * N + 1 && !visitado[i][j+1] && dir[i][j]) {
            visitado[i][j+1] = true;
            pilha[topo].i = i;
            pilha[topo].j = j + 1;
            topo++;
        }
    }
}

int main() {
    char c;
    int x, y;

    while (scanf("%d", &N) != EOF) {
        
        for (int i = 1; i <= 2 * N; i++) {
            for (int j = 1; j <= 2 * N + 1; j++) {
                dir[i][j] = (j < 2 * N + 1);
                esq[i][j] = (j > 1);
                cima[i][j] = (i > 1);
                baixo[i][j] = (i < 2 * N);
                visitado[i][j] = false;
            }
        }

        for (int i = 1; i <= 2 * N - 1; i++) {
            for (int j = 1; j <= N; j++) {
                scanf(" %c", &c);
                
                x = i;
                if (i % 2 == 0) y = 2 * j;
                else y = 2 * j - 1;

                bool h = (c == 'H');
                bool v = (c == 'V');

                if (h) {
                    dir[x][y] = true;
                    dir[x+1][y] = true;
                    esq[x][y+1] = true;
                    esq[x+1][y+1] = true;
                    
                    cima[x+1][y] = false;
                    cima[x+1][y+1] = false;
                    baixo[x][y] = false;
                    baixo[x][y+1] = false;
                }
                
                if (v) {
                    cima[x+1][y] = true;
                    cima[x+1][y+1] = true;
                    baixo[x][y] = true;
                    baixo[x][y+1] = true;
                    
                    dir[x][y] = false;
                    dir[x+1][y] = false;
                    esq[x][y+1] = false;
                    esq[x+1][y+1] = false;
                }
            }
        }

        int componentes = 0;
        for (int i = 1; i <= 2 * N; i++) {
            for (int j = 1; j <= 2 * N + 1; j++) {
                if (!visitado[i][j]) {
                    componentes++;
                    busca(i, j);
                }
            }
        }

        printf("%d\n", componentes - 1);
    }

    return 0;
}
