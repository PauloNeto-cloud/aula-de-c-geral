#include <stdio.h>

int main() {
    int X[10];

    // Leitura dos 10 valores inteiros
    for (int i = 0; i < 10; i++) {
        scanf("%d", &X[i]);
    }

    // Substituindo valores nulos (0) e negativos por 1
    for (int i = 0; i < 10; i++) {
        if (X[i] <= 0) {
            X[i] = 1;
        }
    }

    // Exibindo o vetor com as modificações
    for (int i = 0; i < 10; i++) {
        printf("X[%d] = %d\n", i, X[i]);
    }

    return 0;
}
