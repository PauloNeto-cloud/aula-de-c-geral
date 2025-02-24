#include <stdio.h>
#define MAX_NUM 10

int main(){
    int divisor;
    for (int num = 2; num <= MAX_NUM; ++num){
        divisor = 0;

    for(int i = 2; i <= num; i++){
        if(num % i == 0){
            divisor++;
        }
    }
    if (divisor == 0){
        printf("%d", num);

    }
}
printf("\n");
return 0;

}