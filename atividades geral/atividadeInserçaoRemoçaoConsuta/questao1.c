#include <stdio.h>

#define MAX 50

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para buscar um elemento via busca binária
int buscaBinaria(int vetor[], int tamanho, int valor) {
    int esquerda = 0, direita = tamanho - 1, meio;

    while (esquerda <= direita) {
        meio = (esquerda + direita) / 2;
        if (vetor[meio] == valor) {
            return meio; // Elemento encontrado
        } else if (vetor[meio] < valor) {
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    return -1; // Elemento não encontrado
}

// Função para remover um elemento do vetor
void removerElemento(int vetor[], int *tamanho, int valor) {
    int pos = buscaBinaria(vetor, *tamanho, valor);
    if (pos != -1) {
        for (int i = pos; i < *tamanho - 1; i++) {
            vetor[i] = vetor[i + 1]; // Desloca os elementos à direita
        }
        (*tamanho)--; // Diminui o tamanho do vetor
        printf("Elemento %d removido.\n", valor);
    } else {
        printf("Elemento %d não encontrado no vetor.\n", valor);
    }
}

// Função para inserir um elemento de forma ordenada no vetor
void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    if (*tamanho == MAX) {
        printf("O vetor já está cheio. Não é possível adicionar mais elementos.\n");
        return;
    }

    int i;
    for (i = *tamanho - 1; i >= 0 && vetor[i] > valor; i--) {
        vetor[i + 1] = vetor[i]; // Desloca os elementos para a direita
    }
    vetor[i + 1] = valor;
    (*tamanho)++; // Aumenta o tamanho do vetor
    printf("Elemento %d inserido.\n", valor);
}

int main() {
    int vetor[MAX], tamanho, opcao, valor;

    // Solicita o tamanho do vetor
    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > 50);

    // Preenchimento inicial do vetor
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor para a posição %d: ", i + 1);
        scanf("%d", &valor);
        vetor[i] = valor;
    }

    // Ordena o vetor após o preenchimento inicial
    for (int i = 1; i < tamanho; i++) {
        valor = vetor[i];
        int j = i - 1;
        while (j >= 0 && vetor[j] > valor) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = valor;
    }

    // Menu de opções
    do {
        printf("\nMenu:\n");
        printf("1. Imprimir todo o vetor\n");
        printf("2. Consultar posição de um elemento\n");
        printf("3. Remover um elemento\n");
        printf("4. Inserir um elemento\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;

            case 2:
                printf("Digite o elemento que deseja consultar: ");
                scanf("%d", &valor);
                int posicao = buscaBinaria(vetor, tamanho, valor);
                if (posicao != -1) {
                    printf("Elemento %d encontrado na posição %d.\n", valor, posicao);
                } else {
                    printf("Elemento %d não encontrado.\n", valor);
                }
                break;

            case 3:
                printf("Digite o elemento que deseja remover: ");
                scanf("%d", &valor);
                removerElemento(vetor, &tamanho, valor);
                break;

            case 4:
                printf("Digite o valor que deseja inserir: ");
                scanf("%d", &valor);
                inserirOrdenado(vetor, &tamanho, valor);
                break;

            case 5:
                printf("Saindo do programa.\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
