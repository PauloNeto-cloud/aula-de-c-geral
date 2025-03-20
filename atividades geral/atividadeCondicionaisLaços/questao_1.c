#include <stdio.h>
int main() {
float valorConta, valorMulta, jurosMensal, valorFinal;
int diasAtraso;
// Entrada de dados
printf("Digite o valor da conta: ");
scanf("%f", &valorConta);
printf("Digite o valor da multa (percentual): ");
scanf("%f", &valorMulta);
printf("Digite o valor dos juros mensal (percentual): ");
scanf("%f", &jurosMensal);
printf("Digite a quantidade de dias em atraso: ");
scanf("%d", &diasAtraso);
// Validação para dias de atraso
if (diasAtraso > 45) {
printf("O cálculo não pode ser realizado para contas com mais de 45 dias deatraso.\n");
} else {
// Cálculo da multa
valorMulta = valorConta * (valorMulta / 100);
// Cálculo dos juros proporcionais aos dias de atraso
float jurosPorDia = (jurosMensal / 30) * diasAtraso;
float valorJuros = valorConta * (jurosPorDia / 100);
// Cálculo final
valorFinal = valorConta + valorMulta + valorJuros;
// Exibição dos resultados
printf("Valor original da conta: R$ %.2f\n", valorConta);
printf("Valor da multa: R$ %.2f\n", valorMulta);
printf("Valor dos juros: R$ %.2f\n", valorJuros);
printf("Valor total da conta: R$ %.2f\n", valorFinal);
}
return 0;
}