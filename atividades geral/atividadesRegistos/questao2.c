#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para atoi e atof

#define MAX_PRODUTOS 40

typedef struct {
    int codigo;
    char descricao[50];
    float valorUnitario;
    int quantidade;
} Produto;

// Protótipos das funções
void cadastrarProduto(Produto produtos[], int *n);
void alterarValorUnitario(Produto produtos[], int n, int codigo, float novoValor);
float obterValorUnitario(Produto produtos[], int n, int codigo);
int obterQuantidadeEstoque(Produto produtos[], int n, int codigo);
void venderProduto(Produto produtos[], int n, int codigo, int quantidade);
void atualizarEstoque(Produto produtos[], int n, int codigo, int novaQuantidade);
void exibirTodosProdutos(Produto produtos[], int n);
void exibirProdutosEstoqueZero(Produto produtos[], int n);
int buscarIndicePorCodigo(Produto produtos[], int n, int codigo);
int lerInteiro(const char* prompt);
float lerFloat(const char* prompt);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao, codigo, quantidade;

    do {
        printf("\n========== SISTEMA DE ESTOQUE ==========\n");
        printf("1. Cadastrar produto\n");
        printf("2. Alterar valor unitario\n");
        printf("3. Consultar valor unitario\n");
        printf("4. Consultar quantidade em estoque\n");
        printf("5. Realizar venda\n");
        printf("6. Atualizar estoque\n");
        printf("7. Exibir todos os produtos\n");
        printf("8. Exibir produtos com estoque zero\n");
        printf("9. Sair\n");
        printf("=======================================\n");
        
        opcao = lerInteiro("Opcao: ");

        switch (opcao) {
            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                break;
            case 2: {
                codigo = lerInteiro("\n--- ALTERAR VALOR ---\nCodigo: ");
                float novoValor = lerFloat("Novo valor: ");
                alterarValorUnitario(produtos, totalProdutos, codigo, novoValor);
                break;
            }
            case 3: {
                codigo = lerInteiro("\n--- CONSULTAR VALOR ---\nCodigo: ");
                float valor = obterValorUnitario(produtos, totalProdutos, codigo);
                if (valor >= 0) printf("Valor: R$ %.2f\n", valor);
                break;
            }
            case 4: {
                codigo = lerInteiro("\n--- CONSULTAR ESTOQUE ---\nCodigo: ");
                int estoque = obterQuantidadeEstoque(produtos, totalProdutos, codigo);
                if (estoque >= 0) printf("Estoque: %d\n", estoque);
                break;
            }
            case 5: {
                codigo = lerInteiro("\n--- REALIZAR VENDA ---\nCodigo: ");
                quantidade = lerInteiro("Quantidade: ");
                venderProduto(produtos, totalProdutos, codigo, quantidade);
                break;
            }
            case 6: {
                codigo = lerInteiro("\n--- ATUALIZAR ESTOQUE ---\nCodigo: ");
                int novaQuant = lerInteiro("Nova quantidade: ");
                atualizarEstoque(produtos, totalProdutos, codigo, novaQuant);
                break;
            }
            case 7:
                exibirTodosProdutos(produtos, totalProdutos);
                break;
            case 8:
                exibirProdutosEstoqueZero(produtos, totalProdutos);
                break;
            case 9:
                printf("\nEncerrando sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 9);

    printf("Volte sempre!\n");
    return 0;
}

// Funções auxiliares para leitura segura
int lerInteiro(const char* prompt) {
    char buffer[100];
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    return atoi(buffer);
}

float lerFloat(const char* prompt) {
    char buffer[100];
    printf("%s", prompt);
    fgets(buffer, sizeof(buffer), stdin);
    return atof(buffer);
}

// ========== FUNÇÕES PRINCIPAIS ========== //
int buscarIndicePorCodigo(Produto produtos[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    printf("Produto nao encontrado!\n");
    return -1;
}

void cadastrarProduto(Produto produtos[], int *n) {
    if (*n >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    printf("\n--- CADASTRAR PRODUTO ---\n");
    
    int codigo;
    while (1) {
        codigo = lerInteiro("Codigo: ");
        if (buscarIndicePorCodigo(produtos, *n, codigo) == -1) break;
        printf("Codigo ja existe! Tente outro.\n");
    }
    
    produtos[*n].codigo = codigo;
    
    printf("Descricao: ");
    fgets(produtos[*n].descricao, 50, stdin);
    produtos[*n].descricao[strcspn(produtos[*n].descricao, "\n")] = '\0';

    produtos[*n].valorUnitario = lerFloat("Valor unitario: ");
    produtos[*n].quantidade = lerInteiro("Quantidade em estoque: ");

    (*n)++;
    printf("Produto cadastrado com sucesso!\n");
}

void alterarValorUnitario(Produto produtos[], int n, int codigo, float novoValor) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    if (i != -1) {
        produtos[i].valorUnitario = novoValor;
        printf("Valor atualizado com sucesso!\n");
    }
}

float obterValorUnitario(Produto produtos[], int n, int codigo) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    return (i != -1) ? produtos[i].valorUnitario : -1.0;
}

int obterQuantidadeEstoque(Produto produtos[], int n, int codigo) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    return (i != -1) ? produtos[i].quantidade : -1;
}

void venderProduto(Produto produtos[], int n, int codigo, int quantidade) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    if (i == -1) return;

    if (quantidade <= 0) {
        printf("Quantidade invalida!\n");
        return;
    }

    if (produtos[i].quantidade < quantidade) {
        printf("Estoque insuficiente! Disponivel: %d\n", produtos[i].quantidade);
        return;
    }

    produtos[i].quantidade -= quantidade;
    printf("Venda realizada! Total: R$ %.2f\n", quantidade * produtos[i].valorUnitario);
}

void atualizarEstoque(Produto produtos[], int n, int codigo, int novaQuantidade) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    if (i == -1) return;

    if (novaQuantidade < 0) {
        printf("Quantidade invalida!\n");
        return;
    }

    produtos[i].quantidade = novaQuantidade;
    printf("Estoque atualizado com sucesso!\n");
}

void exibirTodosProdutos(Produto produtos[], int n) {
    printf("\n--- TODOS OS PRODUTOS ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nCodigo: %d", produtos[i].codigo);
        printf("\nDescricao: %s", produtos[i].descricao);
        printf("\nValor: R$ %.2f", produtos[i].valorUnitario);
        printf("\nEstoque: %d\n", produtos[i].quantidade);
    }
}

void exibirProdutosEstoqueZero(Produto produtos[], int n) {
    printf("\n--- PRODUTOS SEM ESTOQUE ---\n");
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (produtos[i].quantidade == 0) {
            printf("\nCodigo: %d", produtos[i].codigo);
            printf("\nDescricao: %s\n", produtos[i].descricao);
            count++;
        }
    }
    
    if (count == 0) {
        printf("Nenhum produto sem estoque!\n");
    } else {
        printf("\nTotal: %d produto(s)\n", count);
    }
}