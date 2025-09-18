#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &n);
    
    // Criando vetores dinamicamente
    int *vet1 = (int *) malloc(n * sizeof(int));
    int *vet2 = (int *) malloc(n * sizeof(int)); 
    int *resultado = (int *) malloc(n  * sizeof(int));
    
    // Gerando valores aleatório nos vetores vet1 e vet2 e exibindo eles
    printf("vet1 | vet2\n");
    for (int i = 0; i < n; i++) {
        srand((int) clock()); // O clock pega o número de ticks consumidos dede o programa ser iniciado;
        vet1[i] = rand() % 100;
        printf("%d |", vet1[i]);
        
        srand((int)clock());
        vet2[i] = rand() % 100;
        printf(" %d\n", vet2[i]);
        
        // Somando os dois vetores
        resultado[i] = vet1[i] + vet2[i];
    
    }
    
    // Exibindo o vetor 'resultado'
    printf("Vetor soma: \n");
    for(int i = 0; i < n; i++) {
        printf("%d", resultado[i]);
        
        if (i < (n-1))  printf(" - ");
    }
    
    return 0;
}
