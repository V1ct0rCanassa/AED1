#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char info;
    struct No *esquerda;
    struct No *direita;
} No;

No* cria_no(char valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) exit(1);
    novo->info = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

No* insere(No *raiz, char valor) {
    if (raiz == NULL) {
        return cria_no(valor);
    }
    if (valor < raiz->info) {
        raiz->esquerda = insere(raiz->esquerda, valor);
    } else if (valor > raiz->info) {
        raiz->direita = insere(raiz->direita, valor);
    }
    return raiz;
}

int pesquisa(No *raiz, char valor) {
    if (raiz == NULL) return 0;
    if (valor == raiz->info) return 1;
    if (valor < raiz->info) return pesquisa(raiz->esquerda, valor);
    return pesquisa(raiz->direita, valor);
}

// O contador evita o espaço antes do primeiro elemento.
void infixa(No *raiz, int *contador) {
    if (raiz != NULL) {
        infixa(raiz->esquerda, contador);
        
        if (*contador > 0) printf(" ");
        printf("%c", raiz->info);
        (*contador)++; 
        
        infixa(raiz->direita, contador);
    }
}

void prefixa(No *raiz, int *contador) {
    if (raiz != NULL) {
        if (*contador > 0) printf(" ");
        printf("%c", raiz->info);
        (*contador)++;
        
        prefixa(raiz->esquerda, contador);
        prefixa(raiz->direita, contador);
    }
}

void posfixa(No *raiz, int *contador) {
    if (raiz != NULL) {
        posfixa(raiz->esquerda, contador);
        posfixa(raiz->direita, contador);
        
        if (*contador > 0) printf(" ");
        printf("%c", raiz->info);
        (*contador)++;
    }
}

int main() {
    No *raiz = NULL;
    char linha[15]; 
    char valor;
    
    while (scanf("%s", linha) != EOF) {
        
        if (strcmp(linha, "I") == 0) {
            scanf(" %c", &valor);
            raiz = insere(raiz, valor);
            
        } else if (strcmp(linha, "P") == 0) {
            scanf(" %c", &valor);
            if (pesquisa(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }
            
        } else {
            int contador_elementos = 0; 

            if (strcmp(linha, "INFIXA") == 0) {
                infixa(raiz, &contador_elementos);
            } else if (strcmp(linha, "PREFIXA") == 0) {
                prefixa(raiz, &contador_elementos);
            } else if (strcmp(linha, "POSFIXA") == 0) {
                posfixa(raiz, &contador_elementos);
            }
            
            // Garante a quebra de linha após a travessia
            printf("\n"); 
        }
    }
    
    return 0;
}
