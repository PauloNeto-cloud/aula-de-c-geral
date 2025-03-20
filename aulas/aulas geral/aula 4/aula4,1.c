#include <stdio.h>
#define MAX_NUM 10

int main(){
    int num;
    for (int num = 1; num <= MAX_NUM; ++num){
        printf("%d\n", num);
    }
    printf("valor final do num: %d\n", num);
    printf("os numeos impares\n");
    for (int num = 1; num <= MAX_NUM; num+= 2){
        printf("%d\n", num);
    }
    return 0;
}
