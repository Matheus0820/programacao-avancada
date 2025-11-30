#include <stdio.h>
int main() {
  int valor;
  int *p1;
  float temp;
  float *p2;
  char aux;
  char *nome = "Ponteiros";
  char *p3;
  int idade;
  int vetor[3];
  int *p4;
  int *p5;
  /* (a) */ 
  valor = 10;
  p1 = &valor;
  *p1 = 20;
  printf("%d \n", valor); // Returno: 10 - O printf tá mostrando o valor da variavel valor
  
  
  /* (b) */
  temp = 26.5;
  p2 = &temp;
  *p2 = 29.0;
  printf("%.1f \n", temp); // Retorno: 29.0 -> O printf tá mostrando o valor da variavel temp, onde anteriormente foi mudada atráves do seu ponteiro para 29.0
  
  /* (c) */
  p3 = &nome[0];
  aux = *p3;
  printf("%c \n", aux); // Retorno: P -> Retorna o valor guardado em aux, que é 'P', pois 'p3' é um ponteiro para char e recebe o primeiro valor do vetor para char, que é o valor retornado
  
  /* (d) */
  p3 = &nome[4];
  aux = *p3;
  printf("%c \n", aux); // Retorno: Retorna o valor guardado em aux, que é 'e', pois p3 é um ponteiro para char e recebe o quinto valor do vetor para char, que é o valor retornado
  
  /* (e) */
  p3 = nome;
  printf("%c \n", *p3); // Retorno: P -> "p3" vai guardar o endereço que "nome" guarda, como "nome" um ponteiro para array de char, esse endereço guardado é o da primeira letra do array.
  
  /* (f) */
  p3 = p3 + 4;
  printf("%c \n", *p3); // Retorno: e -> "p3" guarda o endereço do primeiro termo de 'nome', que é um ponteiro para array do tipo char, e somando mais 4 deslocará mais 4 termos, pegando o valor do indice 4, que é 'e'.
  
  /* (g) */
  p3--;
  printf("%c \n", *p3); // Retorno: t -> "p3" guarda o endereço do quinto valor de 'nome', que é um ponteiro para array do tipo char, e subtraindo 1 termos, que é o que operador '--' faz, 
  // onde pagará assim o valor do indice 3, que é 't'.
  
  /* (h) */
  vetor[0] = 31;
  vetor[1] = 45;
  vetor[2] = 27;
  p4 = vetor;
  idade = *p4;
  printf("%d \n", idade); // Retorno: 31 -> 'p4' guardará o endereço do primeiro valor da variavel 'vetor' (vetor[0]), pois ela é um array e referencia seus termos dessa forma
  
  /* (i) */
  p5 = p4 + 1;
  idade = *p5;
  printf("%d \n", idade); // Retorno: 45 -> 'p5' guardará o endereço de 'p4'+1 que corresponde ao valor do array vator[1]
  
  /* (j) */
  p4 = p5 + 1;
  idade = *p4;
  printf("%d \n", idade); // Retorno: 27 -> 'p4' guardará o endereço de 'p5'+1 que corresponde ao valor do array vator[2]
  
  /* (l) */
  p4 = p4 - 2;
  idade = *p4;
  printf("%d \n", idade); // Retorno: 31 -> 'p4' guardará o endereço de 'p4'-1 que corresponde ao valor do array vator[0]
  
  /* (m) */
  p5 = &vetor[2] - 1;
  printf("%d \n", *p5); // Retorno: 45 -> 'p5' está guardando o valor que estar em vetor[1], onde em 'p5' foi armazenado o endereço de vetor[2] - 1, que representa a mesma coisa de pegar o valor do indece anterior de 'vetor'
  
  /* (n) */
  p5++;
  printf("%d \n", *p5); // Retorno: 27 -> 'p5' anteiormente estava guardando o valor de 'vetor[1]', somando mais 1 ao endereço p5, teremos que p5 agora irá guardar o endereço de 'vetor[2]'
  return(0);
}
