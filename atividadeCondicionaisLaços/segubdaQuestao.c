#include <stdio.h>
// Função para calcular o desconto da categoria
float calcularDescontoCategoria(int categoria) {
if (categoria == 1) {
return 0.10; // 10%
} else if (categoria == 2) {
return 0.15; // 15%
} else if (categoria == 3) {
return 0.08; // 8%
} else {
printf("Categoria inválida!\n");
return 0.0;
}
}
// Função para calcular o desconto pela quantidade
float calcularDescontoQuantidade(int quantidade) {
if (quantidade <= 2) {
return 0.02; // 2%
} else if (quantidade <= 10) {
return 0.05; // 5%
} else {
return 0.10; // 10%
}
}
int main() {
int categoria, quantidade;
float precoProduto, precoFinal, descontoCategoria, descontoQuantidade,
valorEconomizado;
// Entrada de dados
printf("Digite a categoria do produto (1, 2 ou 3): ");
scanf("%d", &categoria);
printf("Digite o preço do produto: ");
scanf("%f", &precoProduto);
printf("Digite a quantidade comprada: ");
scanf("%d", &quantidade);
// Validação de categoria
if (categoria < 1 || categoria > 3) {
printf("Categoria inválida!\n");
return 1;
}
// Cálculo dos descontos
descontoCategoria = calcularDescontoCategoria(categoria);
descontoQuantidade = calcularDescontoQuantidade(quantidade);
// Cálculo do valor final com os descontos
precoFinal = precoProduto * (1 - descontoCategoria) * (1 - descontoQuantidade);
// Cálculo do valor economizado
valorEconomizado = precoProduto * quantidade - precoFinal * quantidade;
// Exibição dos resultados
printf("Preço original por produto: R$ %.2f\n", precoProduto);
printf("Desconto da categoria: %.2f%%\n", descontoCategoria * 100);
printf("Desconto pela quantidade: %.2f%%\n", descontoQuantidade * 100);
printf("Preço final por produto: R$ %.2f\n", precoFinal);
printf("Valor total da compra: R$ %.2f\n", precoFinal * quantidade);
printf("Você economizou: R$ %.2f\n", valorEconomizado);
return 0;
}