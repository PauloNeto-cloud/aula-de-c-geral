#include <stdio.h>

int main(){
    double vi, vf, p;

    printf("digite o valor inicial vi");
    scanf("%lf", &vi);
    printf("digite o valor final vf");
    scanf("%lf", &vf);

    p = ((vf - vi)/vi)* 100;

    printf("o persentual de aulmento e %.2f\n", p);

    return 0;
}