#include <stdio.h>
#include <string.h>

#define TAM 40

typedef struct {
    int codigo;
    char descricao[50];
    float valor;
    int estoque;
} Produto;

void cadastrarProduto(Produto produtos[], int *quantidade) {
    if (*quantidade >= TAM) {
        printf("Limite de produtos atingido!\n");
        return;
    }
    printf("\nCadastro do produto:\n");
    printf("Código: ");
    scanf("%d", &produtos[*quantidade].codigo);
    printf("Descrição: ");
    scanf(" %[^\n]", produtos[*quantidade].descricao);
    printf("Valor unitário: ");
    scanf("%f", &produtos[*quantidade].valor);
    printf("Quantidade em estoque: ");
    scanf("%d", &produtos[*quantidade].estoque);
    (*quantidade)++;
}

void alterarValor(Produto produtos[], int qtd) {
    int codigo;
    printf("Informe o código do produto para alterar valor: ");
    scanf("%d", &codigo);
    for (int i = 0; i < qtd; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Novo valor: ");
            scanf("%f", &produtos[i].valor);
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

float consultarValor(Produto produtos[], int qtd, int codigo) {
    for (int i = 0; i < qtd; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i].valor;
        }
    }
    return -1;
}

int consultarEstoque(Produto produtos[], int qtd, int codigo) {
    for (int i = 0; i < qtd; i++) {
        if (produtos[i].codigo == codigo) {
            return produtos[i].estoque;
        }
    }
    return -1;
}

void realizarVenda(Produto produtos[], int qtd) {
    int codigo, quantidade;
    printf("Código do produto: ");
    scanf("%d", &codigo);
    for (int i = 0; i < qtd; i++) {
        if (produtos[i].codigo == codigo) {
            if (produtos[i].estoque == 0) {
                printf("Produto sem estoque.\n");
                return;
            }
            printf("Quantidade desejada: ");
            scanf("%d", &quantidade);
            if (quantidade <= produtos[i].estoque) {
                produtos[i].estoque -= quantidade;
                printf("Venda realizada. Valor total: R$%.2f\n", quantidade * produtos[i].valor);
            } else {
                printf("Estoque insuficiente. Deseja comprar os %d disponíveis? (1-Sim / 0-Não): ", produtos[i].estoque);
                int opcao;
                scanf("%d", &opcao);
                if (opcao == 1) {
                    printf("Venda realizada. Valor total: R$%.2f\n", produtos[i].estoque * produtos[i].valor);
                    produtos[i].estoque = 0;
                } else {
                    printf("Venda não realizada.\n");
                }
            }
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void atualizarEstoque(Produto produtos[], int qtd) {
    int codigo, nova_qtd;
    printf("Código do produto: ");
    scanf("%d", &codigo);
    for (int i = 0; i < qtd; i++) {
        if (produtos[i].codigo == codigo) {
            printf("Nova quantidade em estoque: ");
            scanf("%d", &nova_qtd);
            produtos[i].estoque = nova_qtd;
            return;
        }
    }
    printf("Produto não encontrado.\n");
}

void exibirProdutos(Produto produtos[], int qtd) {
    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d | Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
    }
}

void exibirEstoqueZero(Produto produtos[], int qtd) {
    printf("\nProdutos com estoque zerado:\n");
    for (int i = 0; i < qtd; i++) {
        if (produtos[i].estoque == 0) {
            printf("Código: %d | Descrição: %s\n", produtos[i].codigo, produtos[i].descricao);
        }
    }
}

int main() {
    Produto produtos[TAM];
    int qtd = 0, opcao;

    do {
        printf("\n1-Cadastrar\n2-Alterar Valor\n3-Consultar Valor\n4-Consultar Estoque\n5-Venda\n6-Atualizar Estoque\n7-Exibir Todos\n8-Exibir Estoque Zerado\n0-Sair\nOpção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: cadastrarProduto(produtos, &qtd); break;
            case 2: alterarValor(produtos, qtd); break;
            case 3: {
                int cod;
                printf("Código: "); scanf("%d", &cod);
                float val = consultarValor(produtos, qtd, cod);
                if (val >= 0)
                    printf("Valor: R$%.2f\n", val);
                else
                    printf("Produto não encontrado.\n");
                break;
            }
            case 4: {
                int cod;
                printf("Código: "); scanf("%d", &cod);
                int est = consultarEstoque(produtos, qtd, cod);
                if (est >= 0)
                    printf("Estoque: %d\n", est);
                else
                    printf("Produto não encontrado.\n");
                break;
            }
            case 5: realizarVenda(produtos, qtd); break;
            case 6: atualizarEstoque(produtos, qtd); break;
            case 7: exibirProdutos(produtos, qtd); break;
            case 8: exibirEstoqueZero(produtos, qtd); break;
        }
    } while (opcao != 0);

    return 0;
}