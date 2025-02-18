#include <stdio.h>

int main() {
    double peso, altura, imc;

    printf("Digite seu peso (em kg): ");
    scanf("%lf", &peso);
    printf("Digite sua altura (em metros): ");
    scanf("%lf", &altura);

    imc = peso / (altura * altura);
    printf("Seu IMC é: %.2lf\n", imc);

    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else {
        if (imc >= 18.5 && imc <= 24.9) {
            printf("Peso normal\n");
    } else {
        if (imc >= 25 && imc <= 29.9) {
            printf("Sobrepeso\n");
    } else {
        if (imc >= 30 && imc <= 34.9) {
            printf("Obesidade grau 1\n");
    } else {
        if (imc >= 35 && imc <= 39.9) {
            printf("Obesidade grau 2\n");
    } else {
        printf("Obesidade grau 3\n");
                    }
                }
            }
        }
    }

    return 0;
}
