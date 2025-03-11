#include <stdio.h>

// Definição de uma constante para o número de alunos
const int QTD_ALUNOS = 5;

// Função para preencher o array com as notas dos alunos
void preencherNotasTurma(double notas[QTD_ALUNOS]) {
  printf("Digitacao de todas as notas da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Digite a nota %d: ", i + 1);
    scanf("%lf", &notas[i]); // Lê a nota do aluno e armazena no array
  }
}

// Função para calcular a média das notas da turma
double calcularMediaTurma(double notas[QTD_ALUNOS]) {
  double somatorio = 0;
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    somatorio += notas[i]; // Soma todas as notas
  }
  return somatorio / QTD_ALUNOS; // Retorna a média das notas
}

// Função para imprimir todas as notas da turma
void imprimirNotasTurma(double notas[QTD_ALUNOS]) {
  printf("\nImpressao de todas as notas da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    printf("Nota %d: %.2f\n", i + 1, notas[i]); // Exibe cada nota com duas casas decimais
  }
}

// Função para imprimir apenas as notas acima da média da turma
void imprimirNotasAcimaMedia(
  double notas[QTD_ALUNOS], double media
) {
  printf("\nImpressao de todas as notas acima da media da turma\n");
  for (int i = 0; i < QTD_ALUNOS; i += 1) {
    if (notas[i] > media) { // Verifica se a nota é maior que a média
      printf("Nota %d: %.2f\n", i + 1, notas[i]); // Exibe a nota
    }
  }
}

// Função principal do programa
int main() {
  double notas[QTD_ALUNOS]; // Declaração do array que armazena as notas
  double media; // Variável que armazenará a média da turma

  preencherNotasTurma(notas); // Chama a função para preencher as notas
  media = calcularMediaTurma(notas); // Calcula a média da turma
  printf("\nMedia da turma: %.2f\n", media); // Exibe a média calculada

  imprimirNotasTurma(notas); // Chama a função para imprimir todas as notas
  imprimirNotasAcimaMedia(notas, media); // Chama a função para imprimir notas acima da média
  
  return 0; // Retorna 0 para indicar que o programa finalizou corretamente
}
