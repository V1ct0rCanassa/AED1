#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor; 
    struct No *proximo;
} No;

typedef struct Fila {
    No *inicio;    
    No *fim;       
    int tamanho;   
} Fila;


Fila* criarfila() { 
    Fila *f = (Fila*) malloc(sizeof(Fila)); 
    if (f != NULL) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}


void inserir(Fila *f, int valor) {
    if (f == NULL) {
        return;
    }
    No *novo = (No*) malloc(sizeof(No));
    if (novo == NULL) {
        return;
    }
    
    novo->valor = valor;
    novo->proximo = NULL;

    if (f->tamanho == 0) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->proximo = novo;
        f->fim = novo;
    }
    f->tamanho++;
}

int remover(Fila *f) {
    if (f->tamanho == 0) {
        return -1; 
    }
    No *temp = f->inicio;
    int valorRemovido = temp->valor;

    f->inicio = f->inicio->proximo;
    f->tamanho--;

    if (f->tamanho == 0) {
        f->fim = NULL;
    }
    free(temp);
    return valorRemovido;
}

int main() {
    int n;

    
    while (scanf("%d", &n) == 1 && n != 0) {
        
        Fila *cartas = criarfila();
        
        for (int i = 1; i <= n; i++) {
            inserir(cartas, i);
        }
        
        int descartadas[51], cont_desc = 0; 

        while (cartas->tamanho > 1) {
            int cartafora = remover(cartas);
            descartadas[cont_desc] = cartafora;
            
            cont_desc++; 
            int carta_mover = remover(cartas);
            inserir(cartas, carta_mover);
        }
        
        int restante = 0;
        if (cartas->tamanho == 1) {
            restante = remover(cartas);
        }
        
        printf("Discarded cards:");
        
        if (cont_desc > 0) { 
            printf(" %d", descartadas[0]);
            for (int i = 1; i < cont_desc; i++) {
                printf(", %d", descartadas[i]);
            }
        }
        printf("\n");
        printf("Remaining card: %d\n", restante);
        
        free(cartas);
    }
    
    return 0;
}
