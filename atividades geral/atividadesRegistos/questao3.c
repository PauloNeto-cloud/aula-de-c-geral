#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_CONTAS 100
#define TAM_NOME 50
#define TAM_CPF 15
#define TAM_TEL 15
#define BUFFER_SIZE 100

typedef struct {
    int numero;
    char nome[TAM_NOME];
    char cpf[TAM_CPF];
    char telefone[TAM_TEL];
    float saldo;
} Conta;

// Protótipos das funções
int buscarConta(Conta cadastro[], int tamanho, int numeroConta);
void cadastrarConta(Conta cadastro[], int *tamanho, const char *tipo);
void consultarSaldo(Conta cadastro[], int tamanho, const char *tipo);
void fazerDeposito(Conta cadastro[], int tamanho, const char *tipo);
void fazerSaque(Conta cadastro[], int tamanho, const char *tipo);
void exibirContas(Conta cadastro[], int tamanho, const char *tipo);
void toUpperString(char *str);
int lerInteiro();
float lerFloat();
void lerString(char *dest, int tamanho);
int selecionarTipoConta();

int main() {
    Conta contasCorrente[MAX_CONTAS];
    Conta contasPoupanca[MAX_CONTAS];
    int qtdCorrente = 0, qtdPoupanca = 0;
    char buffer[BUFFER_SIZE];
    int opcao;

    do {
        printf("\n===== BANCO DINHEIRO CERTO =====\n");
        printf("1. Cadastrar nova conta\n");
        printf("2. Consultar saldo\n");
        printf("3. Fazer deposito\n");
        printf("4. Fazer saque\n");
        printf("5. Exibir contas\n");
        printf("6. Sair\n");
        printf("===============================\n");
        printf("Opcao: ");
        
        fgets(buffer, BUFFER_SIZE, stdin);
        opcao = atoi(buffer);

        switch (opcao) {
            case 1: {
                int tipo = selecionarTipoConta();
                if (tipo == 1) {
                    cadastrarConta(contasCorrente, &qtdCorrente, "CORRENTE");
                } else if (tipo == 2) {
                    cadastrarConta(contasPoupanca, &qtdPoupanca, "POUPANCA");
                }
                break;
            }
            case 2: {
                int tipo = selecionarTipoConta();
                if (tipo == 1) {
                    consultarSaldo(contasCorrente, qtdCorrente, "CORRENTE");
                } else if (tipo == 2) {
                    consultarSaldo(contasPoupanca, qtdPoupanca, "POUPANCA");
                }
                break;
            }
            case 3: {
                int tipo = selecionarTipoConta();
                if (tipo == 1) {
                    fazerDeposito(contasCorrente, qtdCorrente, "CORRENTE");
                } else if (tipo == 2) {
                    fazerDeposito(contasPoupanca, qtdPoupanca, "POUPANCA");
                }
                break;
            }
            case 4: {
                int tipo = selecionarTipoConta();
                if (tipo == 1) {
                    fazerSaque(contasCorrente, qtdCorrente, "CORRENTE");
                } else if (tipo == 2) {
                    fazerSaque(contasPoupanca, qtdPoupanca, "POUPANCA");
                }
                break;
            }
            case 5: {
                int tipo = selecionarTipoConta();
                if (tipo == 1) {
                    exibirContas(contasCorrente, qtdCorrente, "CORRENTE");
                } else if (tipo == 2) {
                    exibirContas(contasPoupanca, qtdPoupanca, "POUPANCA");
                }
                break;
            }
            case 6:
                printf("\nEncerrando sistema...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 6);

    return 0;
}

// Função para selecionar tipo de conta
int selecionarTipoConta() {
    char buffer[BUFFER_SIZE];
    int tipo;
    
    do {
        printf("\nTipo de conta:\n");
        printf("1. Conta Corrente\n");
        printf("2. Conta Poupanca\n");
        printf("Selecione: ");
        
        fgets(buffer, BUFFER_SIZE, stdin);
        tipo = atoi(buffer);
        
        if (tipo < 1 || tipo > 2) {
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (tipo < 1 || tipo > 2);
    
    return tipo;
}

// Funções auxiliares para leitura
int lerInteiro() {
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    return atoi(buffer);
}

float lerFloat() {
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, stdin);
    return atof(buffer);
}

void lerString(char *dest, int tamanho) {
    fgets(dest, tamanho, stdin);
    dest[strcspn(dest, "\n")] = '\0';
}

// (a) Função de busca
int buscarConta(Conta cadastro[], int tamanho, int numeroConta) {
    if (tamanho == 0) return -1;
    
    for (int i = 0; i < tamanho; i++) {
        if (cadastro[i].numero == numeroConta) {
            return i;
        }
    }
    return -2;
}

// (b) Procedimento para cadastrar nova conta
void cadastrarConta(Conta cadastro[], int *tamanho, const char *tipo) {
    if (*tamanho >= MAX_CONTAS) {
        printf("\nLimite de contas %s atingido!\n", tipo);
        return;
    }

    printf("\n--- CADASTRO DE CONTA %s ---\n", tipo);
    
    printf("Numero da conta: ");
    int numero = lerInteiro();
    
    int pos = buscarConta(cadastro, *tamanho, numero);
    if (pos >= 0) {
        printf("\nErro: Conta ja cadastrada!\n");
        return;
    }

    cadastro[*tamanho].numero = numero;
    
    printf("Nome do cliente: ");
    char nome[TAM_NOME];
    lerString(nome, TAM_NOME);
    toUpperString(nome);
    strcpy(cadastro[*tamanho].nome, nome);
    
    printf("CPF: ");
    char cpf[TAM_CPF];
    lerString(cpf, TAM_CPF);
    strcpy(cadastro[*tamanho].cpf, cpf);
    
    printf("Telefone: ");
    char telefone[TAM_TEL];
    lerString(telefone, TAM_TEL);
    strcpy(cadastro[*tamanho].telefone, telefone);
    
    cadastro[*tamanho].saldo = 0.0;
    
    (*tamanho)++;
    printf("\nConta %s cadastrada com sucesso!\n", tipo);
}

// (c) Procedimento para consultar saldo
void consultarSaldo(Conta cadastro[], int tamanho, const char *tipo) {
    if (tamanho == 0) {
        printf("\nNenhuma conta %s cadastrada!\n", tipo);
        return;
    }
    
    printf("\n--- CONSULTA DE SALDO (%s) ---\n", tipo);
    printf("Numero da conta: ");
    int numero = lerInteiro();
    
    int pos = buscarConta(cadastro, tamanho, numero);
    if (pos == -1) {
        printf("\nNenhuma conta %s cadastrada!\n", tipo);
    } else if (pos == -2) {
        printf("\nConta nao encontrada no cadastro %s!\n", tipo);
    } else {
        printf("\nSaldo: R$ %.2f\n", cadastro[pos].saldo);
    }
}

// (d) Procedimento para fazer depósito
void fazerDeposito(Conta cadastro[], int tamanho, const char *tipo) {
    if (tamanho == 0) {
        printf("\nNenhuma conta %s cadastrada!\n", tipo);
        return;
    }
    
    printf("\n--- DEPOSITO (%s) ---\n", tipo);
    printf("Numero da conta: ");
    int numero = lerInteiro();
    
    int pos = buscarConta(cadastro, tamanho, numero);
    if (pos < 0) {
        printf(pos == -1 ? "\nNenhuma conta %s cadastrada!\n" : "\nConta nao encontrada no cadastro %s!\n", tipo);
        return;
    }
    
    printf("Valor do deposito: R$ ");
    float valor = lerFloat();
    
    if (valor <= 0) {
        printf("\nValor invalido!\n");
        return;
    }
    
    cadastro[pos].saldo += valor;
    printf("\nDeposito realizado com sucesso!\nNovo saldo: R$ %.2f\n", cadastro[pos].saldo);
}

// (e) Procedimento para fazer saque
void fazerSaque(Conta cadastro[], int tamanho, const char *tipo) {
    if (tamanho == 0) {
        printf("\nNenhuma conta %s cadastrada!\n", tipo);
        return;
    }
    
    printf("\n--- SAQUE (%s) ---\n", tipo);
    printf("Numero da conta: ");
    int numero = lerInteiro();
    
    int pos = buscarConta(cadastro, tamanho, numero);
    if (pos < 0) {
        printf(pos == -1 ? "\nNenhuma conta %s cadastrada!\n" : "\nConta nao encontrada no cadastro %s!\n", tipo);
        return;
    }
    
    printf("Valor do saque: R$ ");
    float valor = lerFloat();
    
    if (valor <= 0) {
        printf("\nValor invalido!\n");
        return;
    }
    
    if (valor > cadastro[pos].saldo) {
        printf("\nSaldo insuficiente!\n");
        return;
    }
    
    cadastro[pos].saldo -= valor;
    printf("\nSaque realizado com sucesso!\nNovo saldo: R$ %.2f\n", cadastro[pos].saldo);
}

// (f) Procedimento para exibir contas
void exibirContas(Conta cadastro[], int tamanho, const char *tipo) {
    if (tamanho == 0) {
        printf("\nNenhuma conta %s cadastrada!\n", tipo);
        return;
    }
    
    printf("\n--- CONTAS %s ---\n", tipo);
    printf("%-10s %-30s %-15s %-10s\n", "CONTA", "TITULAR", "TELEFONE", "SALDO");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%-10d %-30s %-15s R$ %-8.2f\n", 
               cadastro[i].numero, 
               cadastro[i].nome, 
               cadastro[i].telefone,
               cadastro[i].saldo);
    }
}

// Função para converter string para maiúsculas
void toUpperString(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}