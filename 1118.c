#include <stdio.h>

int main() {
    double nota, soma;
    int validas;
    int opcao;

    while (1) {
        soma = 0;
        validas = 0;

        while (validas < 2) {
            scanf("%lf", &nota);
            if (nota >= 0.0 && nota <= 10.0) {
                soma += nota;
                validas++;
            } else {
                printf("nota invalida\n");
            }
        }

        printf("media = %.2lf\n", soma / 2.0);

        opcao = 0;
        while (opcao != 1 && opcao != 2) {
            printf("novo calculo (1-sim 2-nao)\n");
            scanf("%d", &opcao);
        }

        if (opcao == 2) break;
    }

    return 0;
}
