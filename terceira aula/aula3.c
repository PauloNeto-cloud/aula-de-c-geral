#include <stdio.h>
#define MAX_REPET 5

int main(){
    int num1, num2, qtdRepet = 1;
    printf("digite um numero inteiro: ");
    scanf("%d", &num1);

    printf("digite um numero inteiro maior do que %d: ",num1);
    scanf("%d", &num2);
    
    while(num2 <= num1 && qtdRepet <= MAX_REPET){
        qtdRepet = qtdRepet + 1;
        printf("valor digitado e invalido!\n");
        printf("digite um numero inteiro maior que %d\n", num1);
        scanf("%d", &num2);
    }
    if(qtdRepet <= MAX_REPET){
        printf("existem %d valores no intervalo de %d a %d",
            num1 - num2 + 1, num1, num2);
            return 0;
    }else{
        printf("acabou todas as repeticoes!\n");
        return 1;
        
    }
}