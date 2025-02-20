#include <stdio.h>

int main(){
    int num1, num2;
    printf("digite um numero inteiro: ");
    scanf("%d", &num1);

    printf("digite um numero inteiro maior do que %d\n",num1);
    scanf("%d", &num2);
    
    while(num2 <= num1){
        printf("digite um numero maior que %d\n");
        scanf("%d", &num2);
    }
    printf("existem %d valores no intervalo de %d a %d",
        num1 - num2 + 1, num1, num2);
        return 0;

}