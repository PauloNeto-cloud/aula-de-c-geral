#include <stdio.h>
#include <ctype.h>
#define NUM_ESTADOS 26

typedef struct {
    char nome[50];
    int veiculos;
    int acidentes;
} Estado;

void coletarDados(Estado estados[]) {
    for(int i = 0; i < NUM_ESTADOS; i++) {
        scanf(" %[^\n]s", estados[i].nome);
        scanf("%d", &estados[i].veiculos);
        scanf("%d", &estados[i].acidentes);
    }
}

void encontrarExtremos(Estado estados[], int *ind_maior, int *ind_menor) {
    *ind_maior = 0;
    *ind_menor = 0;
    for(int i = 1; i < NUM_ESTADOS; i++) {
        if(estados[i].acidentes > estados[*ind_maior].acidentes) *ind_maior = i;
        if(estados[i].acidentes < estados[*ind_menor].acidentes) *ind_menor = i;
    }
}

float calcularPercentual(Estado estados[], int indice) {
    if(estados[indice].veiculos == 0) return 0.0;
    return (float)estados[indice].acidentes * 100 / estados[indice].veiculos;
}

float calcularMedia(Estado estados[]) {
    int total = 0;
    for(int i = 0; i < NUM_ESTADOS; i++) total += estados[i].acidentes;
    return (float)total / NUM_ESTADOS;
}

void exibirAcimaDaMedia(Estado estados[], float media) {
    printf("\nEstados com acidentes acima da media nacional:\n");
    for(int i = 0; i < NUM_ESTADOS; i++) {
        if(estados[i].acidentes > media) {
            printf("- %s: %d acidentes\n", estados[i].nome, estados[i].acidentes);
        }
    }
}

int main() {
    Estado estados[NUM_ESTADOS];
    int indice_maior, indice_menor;
    
    printf("Informe os dados (Estado, Veiculos, Acidentes) para os 26 estados:\n");
    coletarDados(estados);
    
    encontrarExtremos(estados, &indice_maior, &indice_menor);
    
    printf("\n=== RESULTADOS DA PESQUISA ===\n");
    printf("Estado com MAIS acidentes: %s (%d acidentes)\n", 
           estados[indice_maior].nome, estados[indice_maior].acidentes);
    printf("Estado com MENOS acidentes: %s (%d acidentes)\n", 
           estados[indice_menor].nome, estados[indice_menor].acidentes);
    
    printf("\nPercentual de veiculos envolvidos em acidentes por estado:\n");
    for(int i = 0; i < NUM_ESTADOS; i++) {
        printf("- %s: %.2f%%\n", estados[i].nome, calcularPercentual(estados, i));
    }
    
    float media = calcularMedia(estados);
    printf("\nMedia nacional de acidentes: %.2f\n", media);
    
    exibirAcimaDaMedia(estados, media);
    
    return 0;
}