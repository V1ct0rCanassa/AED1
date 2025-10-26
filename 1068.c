#include <stdio.h>
#include <string.h>

int verificar(char *ptr) {
    int aberto = 0;
    ptr[strcspn(ptr, "\n")] = 0;
    
    for(int i = 0; ptr[i] != '\0'; i++) {
        if(ptr[i] == '(') {
            aberto++;
        }else if(ptr[i] == ')') {
            aberto--;
        }
        if(aberto < 0){
            return -1;
        }
    }
    return aberto;
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
