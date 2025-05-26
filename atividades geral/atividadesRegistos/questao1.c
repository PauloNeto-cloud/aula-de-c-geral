#include <stdio.h>
#include <string.h>

#define ESTADOS 26

typedef struct {
    char nome[30];
    int veiculos;
    int acidentes;
} Estado;

void coletarDados(Estado estados[]) {
    for (int i = 0; i < ESTADOS; i++) {
        printf("\nEstado %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", estados[i].nome);
        printf("Número de veículos: ");
        scanf("%d", &estados[i].veiculos);
        printf("Número de acidentes: ");
        scanf("%d", &estados[i].acidentes);
    }
}

void maiorMenorAcidentes(Estado estados[], int *indiceMaior, int *indiceMenor) {
    *indiceMaior = *indiceMenor = 0;
    for (int i = 1; i < ESTADOS; i++) {
        if (estados[i].acidentes > estados[*indiceMaior].acidentes)
            *indiceMaior = i;
        if (estados[i].acidentes < estados[*indiceMenor].acidentes)
            *indiceMenor = i;
    }
}

float percentualAcidentes(Estado estado) {
    if (estado.veiculos == 0) return 0;
    return ((float) estado.acidentes / estado.veiculos) * 100;
}

float mediaAcidentes(Estado estados[]) {
    int soma = 0;
    for (int i = 0; i < ESTADOS; i++) {
        soma += estados[i].acidentes;
    }
    return (float)soma / ESTADOS;
}

void exibirAcimaMedia(Estado estados[], float media) {
    printf("\nEstados com acidentes acima da média (%.2f):\n", media);
    for (int i = 0; i < ESTADOS; i++) {
        if (estados[i].acidentes > media) {
            printf("- %s (%d acidentes)\n", estados[i].nome, estados[i].acidentes);
        }
    }
}

int main() {
    Estado estados[ESTADOS];
    int maior, menor;

    coletarDados(estados);
    maiorMenorAcidentes(estados, &maior, &menor);

    printf("\nMaior número de acidentes: %d em %s", estados[maior].acidentes, estados[maior].nome);
    printf("\nMenor número de acidentes: %d em %s", estados[menor].acidentes, estados[menor].nome);

    printf("\n\nPercentual de veículos envolvidos em acidentes:\n");
    for (int i = 0; i < ESTADOS; i++) {
        printf("%s: %.2f%%\n", estados[i].nome, percentualAcidentes(estados[i]));
    }

    float media = mediaAcidentes(estados);
    printf("\nMédia de acidentes no país: %.2f\n", media);

    exibirAcimaMedia(estados, media);

    return 0;
}