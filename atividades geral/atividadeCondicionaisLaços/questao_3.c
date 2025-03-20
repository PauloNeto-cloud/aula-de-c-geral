#include <stdio.h>
int main() {
int sexo, idade, totalPessoas = 0, totalHomensMenos30 = 0, totalMulheres = 0,
totalMulheresMenos50 = 0;
float peso, maiorPeso = 0, pesoTotalHomensMenos30 = 0, percentualMulheresMenos50;
int idadeMaisPesada = 0;
char continuar;
do {
// Entrada de dados
printf("Digite o sexo (1 para homem, 2 para mulher): ");
scanf("%d", &sexo);
printf("Digite a idade: ");
scanf("%d", &idade);
printf("Digite o peso (kg): ");
scanf("%f", &peso);
// Atualizar contagem de pessoas
totalPessoas++;
// Identificar a pessoa mais pesada
if (peso > maiorPeso) {
maiorPeso = peso;
idadeMaisPesada = idade;
}
// Média de peso dos homens com menos de 30 anos
if (sexo == 1 && idade < 30) {
pesoTotalHomensMenos30 += peso;
totalHomensMenos30++;
}
// Percentual de mulheres com menos de 50 kg
if (sexo == 2) {
totalMulheres++;
if (peso < 50) {
totalMulheresMenos50++;
}
}
// Perguntar se deseja continuar
printf("Deseja continuar? (S/N): ");
scanf(" %c", &continuar);
} while (continuar == 'S' || continuar == 's');
// Cálculo do percentual de mulheres com menos de 50kg
if (totalMulheres > 0) {
percentualMulheresMenos50 = (float)totalMulheresMenos50 / totalMulheres * 100;
} else {
percentualMulheresMenos50 = 0;
}
// Exibição dos resultados
printf("\nIdade da pessoa mais pesada: %d anos\n", idadeMaisPesada);
if (totalHomensMenos30 > 0) {
printf("Média de peso dos homens com menos de 30 anos: %.2f kg\n",
pesoTotalHomensMenos30 / totalHomensMenos30);
} else {
printf("Não há homens com menos de 30 anos.\n");
}
printf("Percentual de mulheres com menos de 50 kg: %.2f%%\n",
percentualMulheresMenos50);
return 0;
}