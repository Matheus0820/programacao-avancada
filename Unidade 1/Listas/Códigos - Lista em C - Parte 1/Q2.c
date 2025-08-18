#include <stdio.h>

float lerNota() {
    float nota;
    
    scanf("%f", &nota);
    
    return nota;
}

int main() {
    
    float somatorio_notas = 0;
    float media;
    
    printf("Digite a nota 1: ");
    somatorio_notas += lerNota();
    
    printf("Digite a nota 2: ");
    somatorio_notas += lerNota();
    
    printf("Digite a nota 3: ");
    somatorio_notas += lerNota();
    
    media = somatorio_notas/3;
    printf("Média do Aluno: %f\n", media);
    printf("Situação: ");
    if (media >= 7) printf("Aprovado");
    else if (media > 5) printf("Recuperação");
    else printf("Reprovado");
    
    return 0;
}