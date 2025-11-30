#include <stdio.h>
#include <stdlib.h>

void seq_fibonacci(int n) {
    int n1 = 0, n2 = 1, aux = 0;
    printf("%d - ", n1);
    printf("%d - ", n2);
    
    for (int i = 0; i < n; i++) {
        printf("%d - ", n1 + n2);
        aux = n1;
        n1 = n2;
        n2 = aux + n2;
    }
}

int main() {
    int input = 0;
    printf("Digite um número 'n' > 2 no qual será mostrado a sequência de fibonacci até ele: ");
    
    scanf("%d", &input);
    while (input <= 2) {
        printf("n < 2 -> Digite novamente:");
        scanf("%d", &input);
    }
    
    // Ponteiro para funções
    void (*pf_fb) (int) = &seq_fibonacci;
    (*pf_fb)(input);

    return 0;
}
