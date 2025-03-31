#include <stdio.h>

const int QTD_LINHAS = 100; // Número máximo de linhas da matriz
const int QTD_COLUNAS = 200; // Número máximo de colunas da matriz

// Função para preencher a matriz com os valores fornecidos pelo usuário
void preencherMatrizDigitacao(int m[][QTD_COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; i += 1) { // Percorre cada linha da matriz
    for (int j = 0; j < colunas; j += 1) { // Percorre cada coluna da matriz
      // Pede ao usuário para digitar o valor para a posição m[i][j]
      printf("Digite o valor de m[%d][%d]: ", i + 1, j + 1);
      scanf("%d", &m[i][j]);
    }
  }
}

// Função para imprimir a matriz na tela
void imprimirMatriz(int m[][QTD_COLUNAS], int linhas, int colunas) {
  for (int i = 0; i < linhas; i += 1) { // Percorre cada linha da matriz
    for (int j = 0; j < colunas; j += 1) { // Percorre cada coluna da matriz
      // Imprime o valor da posição m[i][j], com um espaço maior entre os números
      printf("%d\t", m[i][j]);
    }
    printf("\n"); // Nova linha após cada linha da matriz
  }
}

// Função para garantir que o usuário digite um número dentro de um intervalo
int digitarIntervalo(int min, int max) {
  int num;
  do {
    // Pede para o usuário digitar um número dentro do intervalo
    printf("Digite um valor entre %d e %d: ", min, max);
    scanf("%d", &num);
  } while (num < min || num > max); // Continua pedindo até o número ser válido
  return num; // Retorna o número válido
}

int main() {
  int matriz[QTD_LINHAS][QTD_COLUNAS]; // Declara a matriz com as dimensões máximas
  int qtdLinhas, qtdColunas;

  // Pede ao usuário para digitar o número de linhas e colunas
  printf("Digite o numero de linhas\n");
  qtdLinhas = digitarIntervalo(1, QTD_LINHAS); // Verifica se o número de linhas está entre 1 e 100
  printf("\nDigite o numero de colunas\n");
  qtdColunas = digitarIntervalo(1, QTD_COLUNAS); // Verifica se o número de colunas está entre 1 e 200
  
  printf("\nPreencha a matriz\n");
  preencherMatrizDigitacao(matriz, qtdLinhas, qtdColunas); // Preenche a matriz com os valores fornecidos pelo usuário

  printf("\n\nImpressao\n");
  imprimirMatriz(matriz, qtdLinhas, qtdColunas); // Imprime a matriz preenchida
}
