#include <stdio.h>

int main() {
    int par[5], impar[5], numero;
    int i_par = 0, i_impar = 0;

    // Lê 15 números
    for (int i = 0; i < 15; i++) {
        scanf("%d", &numero);

        // Verifica se é par
        if (numero % 2 == 0) {
            par[i_par] = numero;
            i_par++;

            // Se o vetor par estiver cheio, imprime e reseta
            if (i_par == 5) {
                for (int j = 0; j < 5; j++) {
                    printf("par[%d] = %d\n", j, par[j]);
                }
                i_par = 0;  // Reseta o índice do vetor par
            }
        } 
        // Caso seja ímpar
        else {
            impar[i_impar] = numero;
            i_impar++;

            // Se o vetor impar estiver cheio, imprime e reseta
            if (i_impar == 5) {
                for (int j = 0; j < 5; j++) {
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                i_impar = 0;  // Reseta o índice do vetor impar
            }
        }
    }

    // Imprime os números ímpares restantes
    for (int j = 0; j < i_impar; j++) {
        printf("impar[%d] = %d\n", j, impar[j]);
    }

    // Imprime os números pares restantes
    for (int j = 0; j < i_par; j++) {
        printf("par[%d] = %d\n", j, par[j]);
    }

    return 0;
}
