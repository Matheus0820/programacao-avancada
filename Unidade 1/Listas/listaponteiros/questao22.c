#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int func_compt(const void *n1, const void *n2) {
    int valor1 = *(const int*)n1; 
    int valor2 = *(const int*)n2;
    
    if (valor1 > valor2) return 1;
    else if (valor1 < valor2) return -1;
    else return 0;
}

int my_func_compt(int n1, int n2) { // Função de comparação
    
    if (n1 > n2) return 1;
    else if (n1 < n2) return -1;
    else return 0; 
}

void my_qsort(int *vetor, int size, int (*pf_c)(int, int)) { // Recebe um vetor inteiro, o tamanho do vetor e o ponteiro para função da função de comparação

    for (int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            if ((*pf_c)(vetor[i], vetor[j]) == -1) {
                int aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}

int main() {
    clock_t inicio, final;
    double tempo_total;
    int vetor1[5] = {20, 2, 5, 1, 6};
    int vetor2[5] = {30, 28, 31, 2, 1};
    
    printf("Vetor1 antes da ordenação pela função qsort(): \n");
    for(int i = 0; i < 5; i++) {
        printf("%d - ", vetor1[i]);
    }
     printf("\nVetor2 antes da ordenação pela função criada: \n");
    for(int i = 0; i < 5; i++) {
        printf("%d - ", vetor2[i]);
    }
    
    // Ponteiro para função de comparação
    int (*pf)(const void *a, const void *b) = &func_compt;
    
    // Iniciando o contador de tempo
    inicio = clock();
    // Ordenando vetor pela função qsort
    qsort(vetor1, 5, sizeof(float), pf);
    // Finalizando contador de tempo
    final = clock();
    
    //Calculando e exibindo tempo usado pela função
    tempo_total = (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("\n\nTempo de execulção da função qsort(): %fs\n", tempo_total);
    
    
    int (*pf_comp)(int a, int b) = &my_func_compt;
    
    // Iniciando o contador de tempo
    inicio = clock();
    // Ordenando vetor pela função de ordenação criada
    my_qsort(vetor2, 5, pf_comp);
    // Finalizando contador de tempo
    final = clock();
    
    //Calculando e exibindo tempo usado pela função
    tempo_total = (double)(final - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execulção da função criada: %fs\n", tempo_total);
    
     printf("\nVetor1 após a ordenação pela função qsort(): \n");
    for(int i = 0; i < 5; i++) {
        printf("%d - ", vetor1[i]);
    }
     printf("\nVetor2 após a ordenação pela função criada: \n");
    for(int i = 0; i < 5; i++) {
        printf("%d - ", vetor2[i]);
    }
    
    return 0;
}


/*
Saida:
  Tempo de execulção da função qsort(): 0.000003s
  Tempo de execulção da função criada: 0.000001s

Análise: 
É bem evidente que a função criada é bem mais eficiênte, isso deve se dar por o fato de a função criada usar elemento nativos, como operadores, enquanto  
a função 'qsort()' deve usar outras funções para tal tarefa, implicando em um maior tempo de execulção da função.
*/
