#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PALAVRAS 5005
#define MAX_TAM 205

char dicionario[MAX_PALAVRAS][MAX_TAM];
int total = 0;

int comparar(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

void tentar_adicionar(char *buffer) {
    for (int i = 0; i < total; i++) {
        if (strcmp(dicionario[i], buffer) == 0) {
            return; 
        }
    }
    strcpy(dicionario[total], buffer);
    total++;
}

int main() {
    char c;
    char buffer[MAX_TAM];
    int tam = 0;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            buffer[tam++] = tolower(c);
            buffer[tam] = '\0';
        } else {
            if (tam > 0) {
                tentar_adicionar(buffer);
                tam = 0;
            }
        }
    }

    if (tam > 0) {
        tentar_adicionar(buffer);
    }

    qsort(dicionario, total, sizeof(dicionario[0]), comparar);

    for (int i = 0; i < total; i++) {
        printf("%s\n", dicionario[i]);
    }

    return 0;
}
