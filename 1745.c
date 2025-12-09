#include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    long long total = 0;
    int qtd_restos[3] = {1, 0, 0}; 
    int soma_atual = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            int digito = c - '0';
            
            soma_atual = (soma_atual + digito) % 3;
            
            total += qtd_restos[soma_atual];
            qtd_restos[soma_atual]++;
        } 
        else {
            soma_atual = 0;
            qtd_restos[0] = 1;
            qtd_restos[1] = 0;
            qtd_restos[2] = 0;
        }
    }

    printf("%lld\n", total);

    return 0;
}
