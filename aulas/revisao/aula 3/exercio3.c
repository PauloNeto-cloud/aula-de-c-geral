#include <stab.h>

int main() {
    double salario;
    
    printf("CALCULO DO IMPOSTO DE RENDA\n\n");
    printf("Digite seu salario: ");
    scanf("%lf", &salario);
   
    if (salario <= 1903.98) {
        printf("isento de imposto de renda\n");
    } else {
        if (salario <= 2826.65) {
            printf("7,5%% de imposto de renda\n");
    } else {
        if (salario <= 3751.05) {
            printf("15%% de imposto de renda\n");
    } else {
        if (salario <= 4664.68) {
            printf("22,5%% de imposto de renda\n");
    } else {
        printf("27,5%% de imposto de renda");

                }
            }
        }
    }

    return 0;
}