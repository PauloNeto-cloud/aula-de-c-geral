#include <stdio.h>
#include <string.h>

#define ESTADOS 26

typedef struct {
    char nome[30];
    int veiculos;
    int acidentes;
} Estado;

// (a) Coletar dados dos estados
void coletarDados(Estado estados[]) {
    char nomesEstados[ESTADOS][30] = {
        "Acre", "Alagoas", "Amapa", "Amazonas", "Bahia", "Ceara", "Distrito Federal",
        "Espirito Santo", "Goias", "Maranhao", "Mato Grosso", "Mato Grosso do Sul",
        "Minas Gerais", "Para", "Paraiba", "Parana", "Pernambuco", "Piaui",
        "Rio de Janeiro", "Rio Grande do Norte", "Rio Grande do Sul", "Rondonia",
        "Roraima", "Santa Catarina", "Sao Paulo", "Sergipe"
    };

    for (int i = 0; i < ESTADOS; i++) {
        strcpy(estados[i].nome, nomesEstados[i]);
        printf("Estado: %s\n", estados[i].nome);
        printf("  Veiculos em 2007: ");
        scanf("%d", &estados[i].veiculos);
        printf("  Acidentes em 2007: ");
        scanf("%d", &estados[i].acidentes);
    }
}

// (b) Maior e menor número de acidentes
void maiorMenorAcidentes(Estado estados[], int *maior, int *menor) {
    *maior = 0;
    *menor = 0;
    for (int i = 1; i < ESTADOS; i++) {
        if (estados[i].acidentes > estados[*maior].acidentes)
            *maior = i;
        if (estados[i].acidentes < estados[*menor].acidentes)
            *menor = i;
    }
}

// (c) Percentual de veículos envolvidos em acidentes
float percentualAcidentes(Estado estado) {
    if (estado.veiculos == 0) return 0.0;
    return (estado.acidentes * 100.0) / estado.veiculos;
}

// (d) Média de acidentes
float mediaAcidentes(Estado estados[]) {
    int total = 0;
    for (int i = 0; i < ESTADOS; i++) {
        total += estados[i].acidentes;
    }
    return total / (float)ESTADOS;
}

// (e) Estados acima da média de acidentes
void estadosAcimaDaMedia(Estado estados[], float media) {
    printf("\nEstados com acidentes acima da média nacional (%.2f):\n", media);
    for (int i = 0; i < ESTADOS; i++) {
        if (estados[i].acidentes > media) {
            printf("  %s - Acidentes: %d\n", estados[i].nome, estados[i].acidentes);
        }
    }
}

int main() {
    Estado estados[ESTADOS];
    int indiceMaior, indiceMenor;

    coletarDados(estados);
    
    maiorMenorAcidentes(estados, &indiceMaior, &indiceMenor);
    
    printf("\nMaior número de acidentes:\n  %s - %d acidentes\n", 
           estados[indiceMaior].nome, estados[indiceMaior].acidentes);
    printf("Menor número de acidentes:\n  %s - %d acidentes\n", 
           estados[indiceMenor].nome, estados[indiceMenor].acidentes);

    printf("\nPercentual de acidentes por estado:\n");
    for (int i = 0; i < ESTADOS; i++) {
        float perc = percentualAcidentes(estados[i]);
        printf("  %s: %.2f%%\n", estados[i].nome, perc);
    }

    float media = mediaAcidentes(estados);
    printf("\nMédia de acidentes no país: %.2f\n", media);

    estadosAcimaDaMedia(estados, media);

    return 0;
}