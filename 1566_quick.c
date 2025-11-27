#include <stdio.h>
#include <stdlib.h> 

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int NC;
    scanf("%d", &NC); 

    for (int c = 0; c < NC; c++) {
        int n;
        scanf("%d", &n); 

        int *alturas = (int*) malloc(n * sizeof(int));

        if (alturas == NULL) {
            return 1;
        }
        
        int contValidos = 0; 
        
        for (int i = 0; i < n; i++) {
            int h;
            scanf("%d", &h);
            
            if (h >= 20 && h <= 230) {
                alturas[contValidos] = h;
                contValidos++;
            } else {
                 i--; 
            }
        }
        
        qsort(alturas, contValidos, sizeof(int), comparar);

        for (int i = 0; i < contValidos; i++) {
            printf("%d", alturas[i]);
            if (i < contValidos - 1) {
                printf(" "); 
            }
        }
        printf("\n");
        
        free(alturas);
    }
    
    return 0;
}
