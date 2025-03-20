#include <stdio.h>
#define MAX_NUMEROS 1000
// Função para preencher o vetor com 1000 números
void preencherNumeros(int numeros[]) {
for (int i = 0; i < MAX_NUMEROS; i++) {
printf("Digite o número %d: ", i + 1);
scanf("%d", &numeros[i]);
}
}
// Função para contar os números que terminam em cada dígito de 0 a 9
void contarTerminais(int numeros[], int contagem[]) {
for (int i = 0; i < MAX_NUMEROS; i++) {
int ultimoDigito = numeros[i] % 10;
contagem[ultimoDigito]++;
}
}
int main() {
int numeros[MAX_NUMEROS];
int contagem[10] = {0}; // Vetor para armazenar a contagem de números que terminam em 0, 1, ..., 9
preencherNumeros(numeros);
contarTerminais(numeros, contagem);
// Exibindo a contagem
printf("Contagem de números que terminam em:\n");
for (int i = 0; i < 10; i++) {
printf("%d: %d\n", i, contagem[i]);
}
return 0;
}