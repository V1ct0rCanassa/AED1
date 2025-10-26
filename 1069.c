#include <stdio.h>
#include <string.h>

int verificar(char *ptr) {
    ptr[strcspn(ptr, "\n")] = 0;

    int aberto = 0, cont = 0;

    for(int i = 0; ptr[i] != '\0'; i++) {
        if(ptr[i] == '<'){
            aberto++;
        }else if(ptr[i] == '>') {
            if(aberto > 0){
                cont++;
                aberto--;
            }
        }
    }
    return cont;
}
int main() {

    int n;
    scanf("%d", &n);
    getchar();

    char expressao[1001], *ptr;
    
    for(int i = 0; i < n; i++) {
        int verificador = 0;

        if (fgets(expressao, sizeof(expressao), stdin) == NULL) {
            break; 
        }
        ptr = expressao;
        
        verificador = verificar(ptr);

        printf("%d\n", verificador);
    }
}
