#include <stdio.h>
#include <string.h>

#define MAX_CONTAS 100

typedef struct {
    int numeroConta;
    char nome[50];
    char cpf[15];
    char telefone[20];
    float saldo;
} Conta;

// Função de busca (a)
int buscarConta(Conta cadastro[], int qtd, int numero) {
    if (qtd == 0)
        return -1;
    for (int i = 0; i < qtd; i++) {
        if (cadastro[i].numeroConta == numero)
            return i;
    }
    return -2;
}

// Procedimento para cadastrar conta (b)
void cadastrarConta(Conta cadastro[], int *qtd, int numero) {
    if (*qtd >= MAX_CONTAS) {
        printf("Cadastro cheio! Não é possível cadastrar mais contas.\n");
        return;
    }

    int pos = buscarConta(cadastro, *qtd, numero);
    if (pos == -2 || pos == -1) {
        cadastro[*qtd].numeroConta = numero;
        printf("Nome: ");
        scanf(" %[^\n]", cadastro[*qtd].nome);
        printf("CPF: ");
        scanf(" %[^\n]", cadastro[*qtd].cpf);
        printf("Telefone: ");
        scanf(" %[^\n]", cadastro[*qtd].telefone);
        printf("Saldo inicial: ");
        scanf("%f", &cadastro[*qtd].saldo);
        (*qtd)++;
        printf("Conta cadastrada com sucesso!\n");
    } else {
        printf("Número de conta já existente. Cadastro não permitido.\n");
    }
}

// Procedimento para consultar saldo (c)
void consultarSaldo(Conta cadastro[], int qtd, int numero) {
    int pos = buscarConta(cadastro, qtd, numero);
    if (pos >= 0) {
        printf("Saldo da conta %d: R$ %.2f\n", numero, cadastro[pos].saldo);
    } else if (pos == -1) {
        printf("Cadastro está vazio.\n");
    } else {
        printf("Conta não encontrada.\n");
    }
}

// Procedimento para fazer depósito (d)
void realizarDeposito(Conta cadastro[], int qtd, int numero) {
    int pos = buscarConta(cadastro, qtd, numero);
    if (pos >= 0) {
        float valor;
        printf("Valor a depositar: R$ ");
        scanf("%f", &valor);
        if (valor > 0) {
            cadastro[pos].saldo += valor;
            printf("Depósito realizado com sucesso!\n");
        } else {
            printf("Valor inválido!\n");
        }
    } else if (pos == -1) {
        printf("Cadastro está vazio.\n");
    } else {
        printf("Conta não encontrada.\n");
    }
}

// Procedimento para fazer saque (e)
void realizarSaque(Conta cadastro[], int qtd, int numero) {
    int pos = buscarConta(cadastro, qtd, numero);
    if (pos >= 0) {
        float valor;
        printf("Valor a sacar: R$ ");
        scanf("%f", &valor);
        if (valor <= 0) {
            printf("Valor inválido!\n");
        } else if (valor <= cadastro[pos].saldo) {
            cadastro[pos].saldo -= valor;
            printf("Saque realizado com sucesso!\n");
        } else {
            printf("Saldo insuficiente!\n");
        }
    } else if (pos == -1) {
        printf("Cadastro está vazio.\n");
    } else {
        printf("Conta não encontrada.\n");
    }
}

// Procedimento para exibir todas as contas (f)
void exibirContas(Conta cadastro[], int qtd) {
    if (qtd == 0) {
        printf("Cadastro está vazio.\n");
        return;
    }

    printf("\n--- Lista de Contas ---\n");
    for (int i = 0; i < qtd; i++) {
        printf("Conta: %d | Nome: %s | Telefone: %s\n", 
               cadastro[i].numeroConta, cadastro[i].nome, cadastro[i].telefone);
    }
}

int main() {
    Conta contasCorrente[MAX_CONTAS];
    Conta contasPoupanca[MAX_CONTAS];
    int qtdCorrente = 0, qtdPoupanca = 0;
    int tipo, opcao, numero;

    do {
        printf("\n--- Menu ---\n");
        printf("1 - Cadastrar conta\n");
        printf("2 - Consultar saldo\n");
        printf("3 - Depositar\n");
        printf("4 - Sacar\n");
        printf("5 - Exibir contas\n");
        printf("0 - Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 5) {
            printf("Tipo de conta (1-Corrente | 2-Poupança): ");
            scanf("%d", &tipo);
        }

        switch (opcao) {
            case 1:
                printf("Número da nova conta: ");
                scanf("%d", &numero);
                if (tipo == 1)
                    cadastrarConta(contasCorrente, &qtdCorrente, numero);
                else
                    cadastrarConta(contasPoupanca, &qtdPoupanca, numero);
                break;
            case 2:
                printf("Número da conta: ");
                scanf("%d", &numero);
                if (tipo == 1)
                    consultarSaldo(contasCorrente, qtdCorrente, numero);
                else
                    consultarSaldo(contasPoupanca, qtdPoupanca, numero);
                break;
            case 3:
                printf("Número da conta: ");
                scanf("%d", &numero);
                if (tipo == 1)
                    realizarDeposito(contasCorrente, qtdCorrente, numero);
                else
                    realizarDeposito(contasPoupanca, qtdPoupanca, numero);
                break;
            case 4:
                printf("Número da conta: ");
                scanf("%d", &numero);
                if (tipo == 1)
                    realizarSaque(contasCorrente, qtdCorrente, numero);
                else
                    realizarSaque(contasPoupanca, qtdPoupanca, numero);
                break;
            case 5:
                if (tipo == 1)
                    exibirContas(contasCorrente, qtdCorrente);
                else
                    exibirContas(contasPoupanca, qtdPoupanca);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 0);

    return 0;
}