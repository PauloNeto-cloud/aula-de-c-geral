void cadastrarAutor(struct Autor v[], int *qtd);
void imprimirAutores(struct Autor v[], int qtd);
void cadastrarLivro(struct Livro lv[], int *qtd, struct Autor au[], int qtdAutores);
void imprimirLivros(struct Livro lv[], int qtdLivros, struct Autor au[], int qtdAutores);
void ordenarPorTitulo(struct Livro lv[], int qtd);
void buscaBinariaPorResumo(struct Livro lv[], int qtd, char *chave);

int main() {
    struct Autor autores[TAM];
    struct Livro livros[TAM];
    int qtdAutores = 0, qtdLivros = 0;
    int opcao;
    char chave[256];

    do {
        printf("\n--- MENU ---\n");
        printf("1. Cadastrar autor\n");
        printf("2. Imprimir autores\n");
        printf("3. Cadastrar livro\n");
        printf("4. Imprimir livros\n");
        printf("5. Ordenar livros por título\n");
        printf("6. Buscar livro por resumo (binária)\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarAutor(autores, &qtdAutores);
                break;
            case 2:
                imprimirAutores(autores, qtdAutores);
                break;
            case 3:
                cadastrarLivro(livros, &qtdLivros, autores, qtdAutores);
                break;
            case 4:
                imprimirLivros(livros, qtdLivros, autores, qtdAutores);
                break;
            case 5:
                ordenarPorTitulo(livros, qtdLivros);
                printf("Livros ordenados com sucesso.\n");
                break;
            case 6:
                printf("Digite o resumo para busca: ");
                scanf(" %[^\n]", chave);
                buscaBinariaPorResumo(livros, qtdLivros, chave);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}

void cadastrarAutor(struct Autor v[], int *qtd) {
    if (*qtd >= TAM) {
        printf("Limite de autores atingido.\n");
        return;
    }

    v[*qtd].codigo = *qtd + 1;
    printf("Digite o nome do autor: ");
    scanf(" %[^\n]", v[*qtd].nome);

    (*qtd)++;
}

void imprimirAutores(struct Autor v[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Código: %d | Nome: %s\n", v[i].codigo, v[i].nome);
    }
}

void cadastrarLivro(struct Livro lv[], int *qtd, struct Autor au[], int qtdAutores) {
    if (*qtd >= TAM) {
        printf("Limite de livros atingido.\n");
        return;
    }

    lv[*qtd].codigo = *qtd + 1;

    printf("Digite o título do livro: ");
    scanf(" %[^\n]", lv[*qtd].titulo);

    printf("Digite o resumo do livro: ");
    scanf(" %[^\n]", lv[*qtd].resumo);

    if (qtdAutores == 0) {
        printf("Não há autores cadastrados.\n");
        return;
    }

    printf("Autores disponíveis:\n");
    for (int i = 0; i < qtdAutores; i++) {
        printf("%d - %s\n", au[i].codigo, au[i].nome);
    }

    printf("Digite o código do autor: ");
    scanf("%d", &lv[*qtd].autor);

    printf("Digite o preço do livro: ");
    scanf("%f", &lv[*qtd].preco);

    (*qtd)++;
}

void imprimirLivros(struct Livro lv[], int qtdLivros, struct Autor au[], int qtdAutores) {
    for (int i = 0; i < qtdLivros; i++) {
        char nomeAutor[50] = "Desconhecido";
        for (int j = 0; j < qtdAutores; j++) {
            if (lv[i].autor == au[j].codigo) {
                strcpy(nomeAutor, au[j].nome);
                break;
            }
        }

        printf("Código: %d\n", lv[i].codigo);
        printf("Título: %s\n", lv[i].titulo);
        printf("Resumo: %s\n", lv[i].resumo);
        printf("Autor: %s\n", nomeAutor);
        printf("Preço: R$ %.2f\n\n", lv[i].preco);
    }
}

void ordenarPorTitulo(struct Livro lv[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(lv[j].titulo, lv[menor].titulo) < 0) {
                menor = j;
            }
        }

        if (menor != i) {
            struct Livro temp = lv[i];
            lv[i] = lv[menor];
            lv[menor] = temp;
        }
    }
}

void buscaBinariaPorResumo(struct Livro lv[], int qtd, char *chave) {
    int ini = 0, fim = qtd - 1;
    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int cmp = strcmp(chave, lv[meio].resumo);

        if (cmp == 0) {
            printf("Livro encontrado:\n");
            printf("Código: %d\nTítulo: %s\nResumo: %s\nPreço: R$ %.2f\n",
                   lv[meio].codigo, lv[meio].titulo, lv[meio].resumo, lv[meio].preco);
            return;
        } else if (cmp < 0) {
            fim = meio - 1;
        } else {
            ini = meio + 1;
        }
    }
    printf("Resumo não encontrado.\n");
}
