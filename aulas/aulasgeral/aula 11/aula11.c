#include <stdio.h>
#include <string.h>

const int TAM = 10;

void lerstr(char *str, int count);
void myStrCpy(char *str1, char *str2); 

int main(){
    char nome[TAM];
    printf("digite o seu nome: ");
    lerstr(nome, TAM);

    printf("o nome digitado foi \"%s\" \n", nome);

    myStrCpy(nome, "maria jose");  // usando a função implementada
    printf("o nome foi alterado para \"%s\" \n", nome);

    return 0;
}

void lerstr(char *str, int count){
    fgets(str, count, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n'){
        str[tam - 1] = '\0';
    }
}

void myStrCpy(char *str1, char *str2){
    int i = 0;
    while (str2[i] != '\0'){
        str1[i] = str2[i];
        i++;
    }
    str1[i] = '\0';
}
