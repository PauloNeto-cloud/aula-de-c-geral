//Imprimir elementos de um vetor
//Escreva um programa que leia 5 números inteiros do usuário e armazene-os em um vetor. Em seguida, imprima todos os elementos do vetor.

#include <stdio.h>
#include <stdlib.h>

const int QTD_MAX = 5; // Constante global para definir o tamanho do vetor

// Função para preencher o vetor
void prenchevetor(int v[], int tamanho) { // Parâmetro corrigido para `tamanho`
    for (int i = 0; i < tamanho; i++) {
        printf("Digite o valor de v[%d]: ", i + 1);
        scanf("%d", &v[i]);
    }
}

// Função para imprimir o vetor
void imprimirvetor(int v[], int tamanho) { // Parâmetro corrigido para `tamanho`
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", v[i]); // Adicionado espaço para melhor visualização
    }
    printf("\n"); // Nova linha após imprimir todos os elementos
}

int main() {
    int numeros[QTD_MAX]; // Corrigido: `numeros` deve ser um vetor, não uma variável inteira

    // Passando o vetor e o tamanho correto para as funções
    prenchevetor(numeros, QTD_MAX);
    imprimirvetor(numeros, QTD_MAX);

    return 0; // `return 0;` deve estar dentro do `main()`
}

/*
### Erros corrigidos:
1. **`int numeros;` não é um vetor**  
   - O código original declara `numeros` como uma variável inteira, mas ele precisa ser um vetor (`int numeros[QTD_MAX];`).

2. **Parâmetro `QTD_MAX` nas funções**  
   - No código original, `prenchevetor` e `imprimirvetor` recebem `QTD_MAX` como parâmetro, mas ele foi passado incorretamente.  
   - O nome do parâmetro foi alterado para `tamanho` para evitar confusão com a constante global `QTD_MAX`.

3. **Faltavam argumentos ao chamar `prenchevetor()` e `imprimirvetor()`**  
   - No código original, `prenchevetor(numeros);` e `imprimirvetor(numeros);` não passavam o tamanho do vetor como argumento.

4. **`printf("%d", v[i]);` deveria ter um espaço**  
   - Para melhor formatação, foi adicionado um espaço entre os números ao imprimir.

5. **`return 0;` estava fora do `main()`**  
   - O `return 0;` deve estar dentro do `main()`, não solto no código.

Agora o código está corrigido e funcionando corretamente.
*/ 
