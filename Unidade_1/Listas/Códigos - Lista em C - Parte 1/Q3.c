#include <stdio.h>

int main() {
    float anos_como_fumante;
    float num_cigarros_dia;
    float preco_carteira;
    float valor_medio_gasto;
    
    printf("Quantos anos como fumante? ");
    scanf("%f", &anos_como_fumante);
    
    printf("Qual é o número de cigarros que são fumados por dia? ");
    scanf("%f", &num_cigarros_dia);
    
    printf("Qual é o preço médio de uma carteira de cigarro? ");
    scanf("%f", &preco_carteira);
    
    // Segundo pesquisas na Internet uma carteira de cigarro tem 20 cigarros
    valor_medio_gasto = ((num_cigarros_dia * (anos_como_fumante * 365))/20) * preco_carteira;
    
    printf("O valor médio gasto em %0.f ano(s) é de R$ %.2f", anos_como_fumante, valor_medio_gasto);
    
}