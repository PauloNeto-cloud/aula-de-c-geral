#include <stdio.h>
#include <stdlib.h>

void insercaoDireta(float v[], int n){
    int i,j;
    float chave;

    for (i = 1; i <= n-1; i++){
        chave = v[i];
        j = i -1;
        while(j >= 0 && v[i] > chave){
            v[j +1] = v[j];
            j = j -1;

        }
        v[j+1] = chave;
    }
    
}
