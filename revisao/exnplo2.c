#include <stdio.h>
#include <string.h>

#define TAM 100

struct Diretor {
    int codigo;
    char nome[50];
};

struct Filme {
    int codigo;
    char titulo[100];
    char sinopse[200];
    int diretor;
    float nota;
};

void cadastrarDiretor(struct Diretor v[], int *qtd) {
    if (*qtd >= TAM) {
        printf("\nLimite de diretores atingido!\n");
        return;
    }
    v[*qtd].codigo = *qtd + 1;
    printf("\nDigite o nome do diretor: ");
    fflush(stdin);
    fgets(v[*qtd].nome, 50, stdin);
    v[*qtd].nome[strcspn(v[*qtd].nome, "\n")] = 0;
    (*qtd)++;
}

void imprimirDiretores(struct Diretor v[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\nCodigo: %d | Nome: %s", v[i].codigo, v[i].nome);
    }
    printf("\n");
}

void cadastrarFilme(struct Filme f[], int *qtd, struct Diretor d[], int qtdDiretores) {
    if (*qtd >= TAM) {
        printf("\nLimite de filmes atingido!\n");
        return;
    }
    f[*qtd].codigo = *qtd + 1;
    printf("\nTitulo: ");
    fflush(stdin);
    fgets(f[*qtd].titulo, 100, stdin);
    f[*qtd].titulo[strcspn(f[*qtd].titulo, "\n")] = 0;

    printf("Sinopse: ");
    fgets(f[*qtd].sinopse, 200, stdin);
    f[*qtd].sinopse[strcspn(f[*qtd].sinopse, "\n")] = 0;

    printf("Nota (0.0 a 10.0): ");
    scanf("%f", &f[*qtd].nota);

    printf("Codigo do diretor: ");
    scanf("%d", &f[*qtd].diretor);

    int valido = 0;
    for (int i = 0; i < qtdDiretores; i++) {
        if (d[i].codigo == f[*qtd].diretor) {
            valido = 1;
            break;
        }
    }

    if (!valido) {
        printf("\nDiretor nao encontrado. Filme nao cadastrado.\n");
        return;
    }

    (*qtd)++;
}

char* obterNomeDiretor(struct Diretor d[], int qtd, int cod) {
    for (int i = 0; i < qtd; i++) {
        if (d[i].codigo == cod) return d[i].nome;
    }
    return "Desconhecido";
}

void imprimirFilmes(struct Filme f[], int qtdFilmes, struct Diretor d[], int qtdDiretores) {
    for (int i = 0; i < qtdFilmes; i++) {
        printf("\nCodigo: %d", f[i].codigo);
        printf("\nTitulo: %s", f[i].titulo);
        printf("\nSinopse: %s", f[i].sinopse);
        printf("\nDiretor: %s", obterNomeDiretor(d, qtdDiretores, f[i].diretor));
        printf("\nNota: %.1f/10\n", f[i].nota);
    }
}

void ordenarFilmesPorTitulo(struct Filme f[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        int min = i;
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(f[j].titulo, f[min].titulo) < 0) {
                min = j;
            }
        }
        if (min != i) {
            struct Filme aux = f[i];
            f[i] = f[min];
            f[min] = aux;
        }
    }
}

void buscaBinariaPorSinopse(struct Filme f[], int qtd, char *chave) {
    int inicio = 0, fim = qtd - 1;
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(f[meio].sinopse, chave);
        if (cmp == 0) {
            printf("\nFilme encontrado:\nTitulo: %s\nSinopse: %s\nNota: %.1f\n", f[meio].titulo, f[meio].sinopse, f[meio].nota);
            return;
        } else if (cmp < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    printf("\nFilme nao encontrado.\n");
}

void exibirFilmesAcimaDaMedia(struct Filme f[], int qtd) {
    float soma = 0;
    for (int i = 0; i < qtd; i++) soma += f[i].nota;
    float media = soma / qtd;
    printf("\nNota media: %.2f\n", media);
    for (int i = 0; i < qtd; i++) {
        if (f[i].nota > media) {
            printf("\nTitulo: %s | Nota: %.1f\n", f[i].titulo, f[i].nota);
        }
    }
}

int main() {
    struct Diretor diretores[TAM];
    struct Filme filmes[TAM];
    int qtdDiretores = 0, qtdFilmes = 0;

    // Exemplo simples para testar (menu pode ser adicionado depois)
    cadastrarDiretor(diretores, &qtdDiretores);
    cadastrarFilme(filmes, &qtdFilmes, diretores, qtdDiretores);
    imprimirDiretores(diretores, qtdDiretores);
    imprimirFilmes(filmes, qtdFilmes, diretores, qtdDiretores);
    ordenarFilmesPorTitulo(filmes, qtdFilmes);

    char busca[200];
    printf("\nDigite a sinopse para busca binaria: ");
    fflush(stdin);
    fgets(busca, 200, stdin);
    busca[strcspn(busca, "\n")] = 0;
    buscaBinariaPorSinopse(filmes, qtdFilmes, busca);

    exibirFilmesAcimaDaMedia(filmes, qtdFilmes);

    return 0;
}
