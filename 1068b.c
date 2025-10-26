#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct expressao{
    char caractere;
    struct expressao *proximo;
} expressao;
int estaVazia(expressao *topoDaPilha) {
    return topoDaPilha == NULL;
}
void inserir(expressao **topoDaPilha, char c){
    
    expressao *novocaractere = (expressao*) malloc(sizeof(expressao));
    if(novocaractere == NULL){
        return;
    }

    novocaractere -> caractere = c;
    novocaractere -> proximo = *topoDaPilha;

    *topoDaPilha = novocaractere;
}
void remover(expressao **topoDaPilha){
    expressao *temp = *topoDaPilha;
    *topoDaPilha = (*topoDaPilha) -> proximo;
    free(temp);
}
void liberarPilha(expressao **topoDaPilha) {
    while (!estaVazia(*topoDaPilha)) {
        remover(topoDaPilha); 
    }
}
int verificar(char *ptr){
    ptr[strcspn(ptr, "\n")] = 0;

    expressao *minhaPilha = NULL;

    int verifica = 0;

    for(int i = 0; ptr[i] != '\0'; i++) {
        if(ptr[i] == '(') {
            inserir(&minhaPilha, '(');
        }else if(ptr[i] == ')') {
            if (estaVazia(minhaPilha)) {
                verifica = -1;
                break;
            } else {
                
                remover(&minhaPilha);
            }
        }
    }
    if (verifica == 0 && !estaVazia(minhaPilha)) {
        verifica = -1;
    }

    liberarPilha(&minhaPilha);
    
    return verifica;
}
int main() {

    char expressao[1001], *ptr;
    int verificador;
    while(fgets(expressao, sizeof(expressao), stdin) != NULL){
        
        ptr = expressao;

        verificador = verificar(ptr);
        if(verificador == 0){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
    }

    return 0;
    
}
