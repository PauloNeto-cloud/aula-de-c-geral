#include <stdio.h>
#define TAMANHO 100
// Função para preencher o vetor
void preencherVetor(int vetor[]) {
for (int i = 0; i < TAMANHO; i++) {
printf("Digite o valor para a posição %d: ", i + 1);
scanf("%d", &vetor[i]);
}
}
// Função para calcular o somatório dos valores pares
int somatorioPares(int vetor[]) {
int soma = 0;
for (int i = 0; i < TAMANHO; i++) {
if (vetor[i] % 2 == 0) {
soma += vetor[i];
}
}
return soma;
}
// Função para calcular o produtório dos valores ímpares
int produtorioImpares(int vetor[]) {
int produto = 1;
for (int i = 0; i < TAMANHO; i++) {
if (vetor[i] % 2 != 0) {
produto *= vetor[i];
}
}
return produto;
}
// Função para encontrar o menor valor do vetor
int menorValor(int vetor[]) {
int menor = vetor[0];
for (int i = 1; i < TAMANHO; i++) {
if (vetor[i] < menor) {
menor = vetor[i];
}
}
return menor;
}
int main() {
int vetor[TAMANHO];
preencherVetor(vetor);
int somaPares = somatorioPares(vetor);
int produtoImpares = produtorioImpares(vetor);
int menor = menorValor(vetor);
printf("Somatório dos valores pares: %d\n", somaPares);
printf("Produtório dos valores ímpares: %d\n", produtoImpares);
printf("Menor valor do vetor: %d\n", menor);

return 0;
}