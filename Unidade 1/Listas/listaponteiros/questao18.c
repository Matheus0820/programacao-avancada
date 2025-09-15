/*
O que é um ponteiro para uma função?
Resposta: Ponteiro para função é, basicamente, uma variável no qual guarda o endereço da memória no qual estar armazenado
do bloco de código que é a função.
*/

#include <stdio.h>

void seq_fibonacci(int n) { // Definindo função do tipo void
    int n1 = 0, n2 = 1, aux = 0; // Criando variáveis
    printf("%d - ", n1); // Printanto os primeiros termos
    printf("%d - ", n2);
    
    for (int i = 0; i < n; i++) { // For que vai de 0 até n
        printf("%d - ", n1 + n2); // printa o próximo termo
        aux = n1; // Guarda o valor de n1 na variável aux
        n1 = n2; // Define o valor de n2 como sendo o de n1 
        n2 = aux + n2; // Define o valor de n2 como sendo o antigo valor de n1 mais o antigo de n2
    }
}

int main() {
    int input = 0; // Variavel inteira
    printf("Digite um número 'n' > 2 no qual será mostrado a sequência de fibonacci até ele: ");
    
    scanf("%d", &input); // Pegando valor do terminal e guardando no endereço de memroria que 'input' aponta
    while (input <= 2) { // Verifica se input > 2
        printf("n < 2 -> Digite novamente:");
        scanf("%d", &input); // Pergunta o novo valor de input
    }
    
    // Ponteiro para funções
    void (*pf_fb) (int) = &seq_fibonacci; // Declara o ponteiro para função guardando nela o endereço do bloco de memória da função 'seq_fibonacci'
    (*pf_fb)(input); // Chama a função por meio do ponteiro e coloca como paramentro o valor de 'input'

    return 0;
}
