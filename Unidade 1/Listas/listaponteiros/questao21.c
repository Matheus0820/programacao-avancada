#include <stdio.h>
#include <stdlib.h>

int func_compt(int n1, int n2) { // Função de comparação
    
    if (n1 > n2) return 1;
    else if (n1 < n2) return -1;
    else return 0; 
}

// Função de ordenação
void my_qsort(int *vetor, int size, int (*pf_c)(int, int)) { // Recebe um vetor inteiro, o tamanho do vetor e o ponteiro para função da função de comparação

    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if ((*pf_c)(vetor[i], vetor[j]) == 1) {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    int vt[5] = {1, 5, 3, 9, 2};
    
    // Exibindo vetor antes da ordenação
    printf("Vetor antes da ordenação: \n");
    for(int i = 0; i < 5; i++) {
        printf("%d - ", vt[i]);
    }
    
    
    int (*pf_comp)(int a, int b) = &func_compt;
    my_qsort(vt, 5, pf_comp);
    
    // Exibindo vetor depois da ordenação
    printf("\n\nVetor após a ordenação: \n");
    for(int i = 0; i < 5; i++) {
        printf("%d - ", vt[i]);
    }

    return 0;
}
