#include <stdio.h>
#include <string.h>
#define stdin

//definir a estrututa para as pessoas
typedef struct{
    char nome[50];
    int idade;
}pessoa;

int main(){
    pessoa pessoas[3];//vetor que armazena 3 pessoas
    int i;

    //loop para cadastrar 3 pessoas
    for (int i = 0; i < 3; i++){
        printf("\n--- pessoa %d ---\n", i + 1);

        //leitura do nome com fgets para aceitar espaços
        printf("digite o nome: ");
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);

        //remover o "\n" que o fgets pode inserir
        pessoas[i].nome[strcspn(pessoas[1].nome, "\n")] = "\0";

        //leitura da idade
        printf("digite a idade: ");
        scanf("%d", &pessoas[1].idade);

        getchar();
    }
    
    //exibçao de de dados cadastrados
    printf("\n=== lista de pessoas ===\n");
    for (int i = 0; i < 3; i++){
        printf("pesoa %d:\n", i + 1);
        printf("nome: %s\n", pessoas[i].nome);
        printf("idade: %d\n", pessoas[1].idade);
    }
    
    return 0;
}