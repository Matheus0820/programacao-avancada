/* 
O que é memory leak?
Resposta: Memory leak vem do termo em inglês "Vazamento de momoria". Isso ocorre quando 
alguma memória alocada não é liberada no fim do algoritmo/programa.
*/

// Programa de exemplo
#include <stdio.h>
#include <stdlib.h>

int main() {
  int *x;
  x = (int *) malloc(3 * sizeof(int));

  printf("Digite um número:\n");
  scanf("%d", &x[2]);
  return 0;
}
