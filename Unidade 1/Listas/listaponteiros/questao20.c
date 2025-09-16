#include <stdio.h>
#include <stdlib.h>

int func_compt(const void *n1, const void *n2) { // Recebe ponteiros genéricos

// Transforma os ponteiros de tipo generico no tipo do valor do array e depois pega seu valor - desreferência
    float valor1 = *(const float*)n1; 
    float valor2 = *(const float*)n2;
    
    if (valor1 > valor2) return 1; // Retorna 1 se o valor1 vinher depois do valor
    else if (valor1 < valor2) return -1; // Retorna -1 se o valor1 vinher antes do valor2
    else return 0; // Retorna 0 se ambos foram iguais
}

int main() {
    int input = 0;
    printf("Quantos valores de float você vai digitar? ");
    scanf("%d", &input); // Recebe o tamanho da amostra a ser lida
    
    // Aloca a memeória do array 'vetor'
    float *vetor = (float *) malloc(input * sizeof(float));
    
    for(int i = 0; i < input; i++) {
        printf("Valor %d: ", i+1);
        scanf("%f", &vetor[i]); // Ler cada valor digitado pelo usuário e guarda dentro de uma posição do vetor
    }
    
    // Ponteiro para função comparar
    int (*pf)(const void *a, const void *b) = &func_compt;
    
    // Ordenando Vetor com o 'qsort()'
    qsort(vetor, input, sizeof(float), pf); // O primeiro parametro é o array que será ordenado, o segundo é o tamanho do array, o terceiro o tamanho em bytes de cada valor do vetor e o quarto é a função de comparação
    
    // Exibindo vetor
    for(int i = 0; i < input; i++) {
        printf("%.2f - ", vetor[i]);
    }

    // Liberando memória com o free 
    free(vetor);

    return 0;
}
