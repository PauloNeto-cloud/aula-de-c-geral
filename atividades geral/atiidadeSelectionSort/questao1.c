#include <stdio.h>
#include <string.h>

struct Produto {
    int codigo;
    char nome[50];
    double preco;
};

void selectionSortPreco(struct Produto p[], int n) {
    int i, j, minIndex;
    struct Produto temp;

    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (p[j].preco < p[minIndex].preco) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = p[i];
            p[i] = p[minIndex];
            p[minIndex] = temp;
        }
    }
}

// Função para exibir os produtos (opcional, útil para testes)
void exibirProdutos(struct Produto p[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Código: %d | Nome: %s | Preço: %.2lf\n", p[i].codigo, p[i].nome, p[i].preco);
    }
}

// Exemplo de uso (opcional)
int main() {
    struct Produto produtos[] = {
        {101, "Teclado", 89.90},
        {102, "Mouse", 49.50},
        {103, "Monitor", 1200.00},
        {104, "Webcam", 199.90}
    };
    int n = sizeof(produtos) / sizeof(produtos[0]);

    printf("Antes da ordenação:\n");
    exibirProdutos(produtos, n);

    selectionSortPreco(produtos, n);

    printf("\nApós a ordenação por preço:\n");
    exibirProdutos(produtos, n);

    return 0;
}