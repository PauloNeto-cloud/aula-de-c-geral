#include <stdio.h>

int main(){
    int num1 = 8, num2 = 23, num3 = 456;
    int status;
    FILE *arq = fopen("numeros.bin", "wb");
    if (arq == NULL){
        printf("nao conseguir abrir o arquivo");
        return 1;

    }

    status = fwrite(&num1)

    if(fclose(arq)== 0){
        printf("arquivo fechado com sucesso");
    }else{
        printf("erro ao fechar o arquivo");
    }
}