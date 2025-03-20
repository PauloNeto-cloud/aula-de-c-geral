#include <stdio.h>

int main() {
    int N[1000], T, i;

    // Lê o valor de T
    scanf("%d", &T);

    // Preenche o vetor N com a sequência repetida de 0 até T-1
    for (i = 0; i < 1000; i++) {
        N[i] = i % T;
        // Imprime a saída no formato pedido
        printf("N[%d] = %d\n", i, N[i]);
    }

    return 0;
}
