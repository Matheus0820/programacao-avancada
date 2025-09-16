#include <stdio.h>
#include <stdlib.h>

// Função de ordenação
void func_ordena(int n, float *vecf) {
    for(int i = 0; i < n; i++) {
        printf("Valor %d: ", i+1);
        scanf("%f", &vecf[i]);
    }
  
    for (int i = 0; i < n-1; i++) {
        for(int j = 0; j < n; j++) {
            int aux = 0;
            if (vecf[i] > vecf[j] && i < j) {
                aux = vecf[i];
                vecf[i] = vecf[j];
                vecf[j] = aux;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        printf("%.2f - ", vecf[i]);
    }
} 

int main() {
    int input = 0;
    printf("Quantos valores de float você vai digitar? ");
    scanf("%d", &input);

    // Alocando memória para o vetor de float
    float *vetor = (float *) malloc(input * sizeof(float));
  
    // Ponteiro para funções
    void (*pf) (int, float *) = &func_ordena;
    (*pf)(input, vetor);

    // Liberando memória alocada
    free(vetor);

    return 0;
}
