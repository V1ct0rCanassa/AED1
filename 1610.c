#include <stdio.h>
#include <stdlib.h>

#define max_n 10005
#define max_m 30005

int cabeca[max_n];
int M[max_m];
int prox[max_m];
int cont;

int visitou[max_n];

void iniciar(int n) {
    for(int i = 0; i <= n; i++) {
        cabeca[i] = -1;
        visitou[i] = 0;
    }
    cont = 0;
}

void adicionar(int u, int v) {
    M[cont] = v;
    prox[cont] = cabeca[u];
    cabeca[u] = cont;
    cont++;
}

int foi(int u) {
    visitou[u] = 1;
    
    for(int jornal = cabeca[u]; jornal != -1; jornal = prox[jornal]) {
        int v = M[jornal];
        
        if(visitou[v] == 1) {
            return 1; 
        }
        
        if(visitou[v] == 0) {
            if(foi(v)) return 1;
        }
    }
    
    visitou[u] = 2;
    return 0;
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++) {
        scanf("%d %d", &n, &m);
        
        iniciar(n);
        
        int v, u;
        for(int j = 0; j < m; j++) {
            scanf("%d %d", &v, &u);
            adicionar(u, v);
        }
        
        int tem_ciclo = 0;
        
        for(int k = 1; k <= n; k++) {
            if(visitou[k] == 0) {
                if(foi(k)) {
                    tem_ciclo = 1;
                    break;
                }
            }
        }
        
        if(tem_ciclo) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
