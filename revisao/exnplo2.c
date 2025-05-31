#include <stdio.h>
#include <string.h>

int main() {
    char nome[100]

    //leitura do nomes com espaços
    printf("digite seu nome completo: ");

    fgets(nome, sizeof(nome), stdin);

    //remove o caractere "\n" que pode vir no final
    nome[strcspn(nome, "\n")] = "\0";

    //calcula o tamanho da string(sem contar "\0")
    int tamanho = strlen(nome);

    printf("o nome digitado tem %d caracteres.\n", tamanho);
    return 0;
}