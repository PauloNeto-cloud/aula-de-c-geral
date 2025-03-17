#include <stdio.h>
int main() {
int valorInicial, incremento, quantidadeTermos;
// Entrada de dados
printf("Digite o valor inicial da PA: ");
scanf("%d", &valorInicial);
printf("Digite o valor do incremento: ");
scanf("%d", &incremento);
printf("Digite a quantidade de termos: ");
scanf("%d", &quantidadeTermos);
// Cálculo e exibição dos termos da PA
printf("Os termos da PA são:\n");
for (int i = 0; i < quantidadeTermos; i++) {
printf("%d ", valorInicial + i * incremento);
}
printf("\n");
return 0;
}