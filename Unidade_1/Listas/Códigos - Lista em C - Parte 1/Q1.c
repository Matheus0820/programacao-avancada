#include <stdio.h>

int main() {
    int num;
    
    printf("Digite um número: ");
    scanf("%d", &num);
    printf("O sucessor de %d é %d", num, num+1);
    
    return 0;
}