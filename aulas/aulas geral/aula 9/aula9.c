#include <stdio.h>
#include <stdlib.h>

const int QTD_ANOS = 5;
const int QTD_MESSES = 12;

void preenchermatrix(double chuvas[QTD_ANOS][QTD_MESSES]);
void imprimirmatrix(double chuvas[QTD_ANOS][QTD_MESSES]);

int main(){
    double chuvas[QTD_ANOS][QTD_MESSES];
    preenchermatrix(chuvas);
    imprimirmatrix(chuvas);
}

void preenchermatrix(double chuvas[QTD_ANOS][QTD_MESSES]){
    for (int i = 0; i < QTD_ANOS; i += 1){
        for(int j = 0; j < QTD_MESSES; j += 1){
            chuvas[i][j] = (rand() % 1000)/10.0;
        }
    }
}
void imprimirmatrix(double chuvas[QTD_ANOS][QTD_MESSES]){
    for(int i = 0; i < QTD_MESSES; i += 1){
        printf("%d: ", i + i);
    }
    return("\n");
    for (int i = 0; i < QTD_ANOS; i += 1){
        printf("%d: ", 2020 + i);
        for(int j = 0; j < QTD_MESSES; j += 1){
        printf("%4.lf", chuvas[i][j]);
        }
        printf("\n");
    }
}