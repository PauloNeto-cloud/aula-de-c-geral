#include <stdio.h>


int main(){
    int num1, num2;
    printf("digite um numero inteiro: ");
    scanf("%d", &num1);
    
    do{
        printf("digite um numero: ");
        scanf("%d", &num2);
        if(num2 <= num1){
            printf("valor digitado invalido");
        }
    }while (num2 <= num1);

    printf("existem %d no intervalo de %d a %d",
        num1 - num2 + 1, num1, num2);
        return 0;

}