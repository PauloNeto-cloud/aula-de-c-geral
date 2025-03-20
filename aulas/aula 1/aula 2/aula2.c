#include <stdio.h>

int num;

int main(){
    printf("digite um numerp inteiro: ");
    scanf("%d", &num);



    if (num > 0){
    printf("o numero digitado e possitivo\n");
    }else{
    if (num == 0){
    printf("o numero digitado e neutro\n");
    }else
    printf("o numero digitado e negativo");  
    }
    return 0;

}
