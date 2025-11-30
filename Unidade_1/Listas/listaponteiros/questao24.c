#include <stdio.h>
#include <stdlib.h>

void multiplica_matrizes(int **A, int **B, int **C, int lin_A, int col_A, int col_B) {

    for(int i = 0; i < lin_A; i++) {
        for(int j = 0; j < col_B; j++) {
            C[i][j] = 0;
            for(int w = 0; w < col_A; w++) {
                C[i][j] = C[i][j] + (A[i][w] * B[w][j]);
            }
        }
    }
}

int main() {

    int lin_A = rand() % 6; // lin_A = lin_C
    int col_A = rand() % 6; // col_A = lin_B
    int col_B = rand() % 6; // col_B = col_C
    
    // Alocando mememória e definindo valores para a matriz A e a exibindo
    int **A = (int **) malloc(lin_A * sizeof(int*));
    printf("Matriz A: \n");
    for (int i = 0; i < lin_A; i++) {
        A[i] = (int *) malloc(col_A * sizeof(int));
        
        for (int j = 0; j < col_A; j++) {
            A[i][j] = rand() % 100;
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    
    // Alocando memória e definindo valores para a matriz B
    int **B = (int **) malloc(col_A * sizeof(int*));
    printf("\nMatriz B: \n");
    for (int i = 0; i < col_A; i++) {
        B[i] = (int *) malloc(col_B * sizeof(int));
        
        for (int j = 0; j < col_B; j++) {
            B[i][j] = rand() % 100;
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    
    // Alocando memória para a matriz C
    int **C = (int **) malloc(lin_A * sizeof(int*));
    for (int i = 0; i < lin_A; i++) {
        C[i] = (int *) malloc(col_B * sizeof(int));   
    }
    
    // Chamando função de multiplicação
    multiplica_matrizes(A, B, C, lin_A, col_A, col_B);
    
    // Mostrando a matriz C = AxB
    printf("\nMatriz C = AxB: \n");
    for(int i = 0; i < lin_A; i++) {
        for (int j = 0; j < col_B; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    
    // Liberando memória
    for (int i = 0; i < lin_A; i++) {
        free(A[i]);
    }
    free(A);
    for (int i = 0; i < col_A; i++) {
        free(B[i]);
    }
    free(B);
    for (int i = 0; i < lin_A; i++) {
        free(C[i]);
    }
    free(C);
    

    return 0;
}
