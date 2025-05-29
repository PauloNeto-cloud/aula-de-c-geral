#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 40

typedef struct {
    int codigo;
    char descricao[50];
    float valorUnitario;
    int quantidade;
} Produto;

// Protótipos das funções
void cadastrarProduto(Produto produtos[], int *n);
void alterarValorUnitario(Produto produtos[], int n, int codigo);
float obterValorUnitario(Produto produtos[], int n, int codigo);
int obterQuantidadeEstoque(Produto produtos[], int n, int codigo);
void venderProduto(Produto produtos[], int n, int codigo, int quantidade);
void atualizarEstoque(Produto produtos[], int n, int codigo, int novaQuantidade);
void exibirTodosProdutos(Produto produtos[], int n);
void exibirProdutosEstoqueZero(Produto produtos[], int n);
int buscarIndicePorCodigo(Produto produtos[], int n, int codigo);

// Função para limpar completamente o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao, codigo, quantidade, novaQuantidade;
    char buffer[100];  // Buffer para leitura segura

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
        printf("Opcao: ");
        
        // Leitura segura da opção
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            break;
        }
        opcao = atoi(buffer);

        switch (opcao) {
            case 1: {
                printf("\n--- CADASTRAR PRODUTO ---\n");
                
                // Código
                printf("Codigo: ");
                fgets(buffer, sizeof(buffer), stdin);
                codigo = atoi(buffer);
                
                // Descrição
                printf("Descricao: ");
                fgets(produtos[totalProdutos].descricao, 50, stdin);
                produtos[totalProdutos].descricao[strcspn(produtos[totalProdutos].descricao, "\n")] = '\0';
                
                // Valor
                printf("Valor unitario: ");
                fgets(buffer, sizeof(buffer), stdin);
                produtos[totalProdutos].valorUnitario = atof(buffer);
                
                // Quantidade
                printf("Quantidade em estoque: ");
                fgets(buffer, sizeof(buffer), stdin);
                produtos[totalProdutos].quantidade = atoi(buffer);
                
                produtos[totalProdutos].codigo = codigo;
                totalProdutos++;
                printf("\nSUCESSO: Produto cadastrado!\n");
                break;
            }
            case 2: {
                printf("\n--- ALTERAR VALOR UNITARIO ---\n");
                printf("Codigo do produto: ");
                fgets(buffer, sizeof(buffer), stdin);
                codigo = atoi(buffer);
                alterarValorUnitario(produtos, totalProdutos, codigo);
                break;
            }
            case 3: {
                printf("\n--- CONSULTAR VALOR UNITARIO ---\n");
                printf("Codigo do produto: ");
                fgets(buffer, sizeof(buffer), stdin);
                codigo = atoi(buffer);
                float valor = obterValorUnitario(produtos, totalProdutos, codigo);
                if (valor >= 0) {
                    printf("Valor unitario: R$ %.2f\n", valor);
                }
                break;
            }
            case 4: {
                printf("\n--- CONSULTAR ESTOQUE ---\n");
                printf("Codigo do produto: ");
                fgets(buffer, sizeof(buffer), stdin);
                codigo = atoi(buffer);
                int estoque = obterQuantidadeEstoque(produtos, totalProdutos, codigo);
                if (estoque >= 0) {
                    printf("Quantidade em estoque: %d\n", estoque);
                }
                break;
            }
            case 5: {
                printf("\n--- REALIZAR VENDA ---\n");
                printf("Codigo do produto: ");
                fgets(buffer, sizeof(buffer), stdin);
                codigo = atoi(buffer);
                printf("Quantidade desejada: ");
                fgets(buffer, sizeof(buffer), stdin);
                quantidade = atoi(buffer);
                venderProduto(produtos, totalProdutos, codigo, quantidade);
                break;
            }
            case 6: {
                printf("\n--- ATUALIZAR ESTOQUE ---\n");
                printf("Codigo do produto: ");
                fgets(buffer, sizeof(buffer), stdin);
                codigo = atoi(buffer);
                printf("Nova quantidade em estoque: ");
                fgets(buffer, sizeof(buffer), stdin);
                novaQuantidade = atoi(buffer);
                atualizarEstoque(produtos, totalProdutos, codigo, novaQuantidade);
                break;
            }
            case 7: {
                exibirTodosProdutos(produtos, totalProdutos);
                break;
            }
            case 8: {
                exibirProdutosEstoqueZero(produtos, totalProdutos);
                break;
            }
            case 9: {
                printf("\nEncerrando sistema...\n");
                break;
            }
            default: {
                printf("\nOpcao invalida!\n");
                break;
            }
        }

    } while (opcao != 9);

    printf("Volte sempre!\n");
    return 0;
}

// ========== FUNÇÕES ========== //

int buscarIndicePorCodigo(Produto produtos[], int n, int codigo) {
    for (int i = 0; i < n; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void alterarValorUnitario(Produto produtos[], int n, int codigo) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    if (i == -1) {
        printf("\nERRO: Produto nao encontrado!\n");
        return;
    }
    printf("Novo valor unitario: ");
    char buffer[50];
    fgets(buffer, sizeof(buffer), stdin);
    produtos[i].valorUnitario = atof(buffer);
    printf("\nSUCESSO: Valor atualizado!\n");
}

float obterValorUnitario(Produto produtos[], int n, int codigo) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    if (i == -1) {
        printf("\nERRO: Produto nao encontrado!\n");
        return -1.0;
    }
    return produtos[i].valorUnitario;
}

int obterQuantidadeEstoque(Produto produtos[], int n, int codigo) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    if (i == -1) {
        printf("\nERRO: Produto nao encontrado!\n");
        return -1;
    }
    return produtos[i].quantidade;
}

void venderProduto(Produto produtos[], int n, int codigo, int quantidade) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    if (i == -1) {
        printf("\nERRO: Produto nao encontrado!\n");
        return;
    }

    if (quantidade <= 0) {
        printf("\nERRO: Quantidade invalida!\n");
        return;
    }

    if (produtos[i].quantidade < quantidade) {
        printf("\nATENCAO: Estoque insuficiente (disponivel: %d)\n", produtos[i].quantidade);
        return;
    }

    produtos[i].quantidade -= quantidade;
    printf("\nSUCESSO: Venda realizada!");
    printf("\nTotal: R$ %.2f\n", quantidade * produtos[i].valorUnitario);
}

void atualizarEstoque(Produto produtos[], int n, int codigo, int novaQuantidade) {
    int i = buscarIndicePorCodigo(produtos, n, codigo);
    if (i == -1) {
        printf("\nERRO: Produto nao encontrado!\n");
        return;
    }

    if (novaQuantidade < 0) {
        printf("\nERRO: Quantidade invalida!\n");
        return;
    }

    produtos[i].quantidade = novaQuantidade;
    printf("\nSUCESSO: Estoque atualizado!\n");
}

void exibirTodosProdutos(Produto produtos[], int n) {
    printf("\n--- TODOS OS PRODUTOS (%d) ---\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nCodigo: %d", produtos[i].codigo);
        printf("\nDescricao: %s", produtos[i].descricao);
        printf("\nValor: R$ %.2f", produtos[i].valorUnitario);
        printf("\nEstoque: %d", produtos[i].quantidade);
        printf("\n----------------------------");
    }
    printf("\n");
}

void exibirProdutosEstoqueZero(Produto produtos[], int n) {
    printf("\n--- PRODUTOS COM ESTOQUE ZERO ---\n");
    int encontrados = 0;
    
    for (int i = 0; i < n; i++) {
        if (produtos[i].quantidade == 0) {
            printf("\nCodigo: %d", produtos[i].codigo);
            printf("\nDescricao: %s", produtos[i].descricao);
            printf("\n----------------------------");
            encontrados++;
        }
    }
    
    if (encontrados == 0) {
        printf("\nNenhum produto com estoque zero!\n");
    } else {
        printf("\nTotal: %d produto(s)\n", encontrados);
    }
}