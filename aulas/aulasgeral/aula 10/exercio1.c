#include <stdio.h>

void zeros(int qtdLinhas, int qtdColunas, int matriz[qtdLinhas][qtdColunas]){
    for(int i = 1; i < qtdLinhas; i++){
        for(int j = i - 1; j > -1; j--){
            matriz[i][j] = 0;
        }
    }
}