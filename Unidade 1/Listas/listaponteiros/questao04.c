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
printf("%c \n", *p3); // Retorno: 

/* (f) */
p3 = p3 + 4;
printf("%c \n", *p3);

/* (g) */
p3--;
printf("%c \n", *p3);

/* (h) */
vetor[0] = 31;
vetor[1] = 45;
vetor[2] = 27;
p4 = vetor;
idade = *p4;
printf("%d \n", idade);

/* (i) */
p5 = p4 + 1;
idade = *p5;
printf("%d \n", idade);

/* (j) */
p4 = p5 + 1;
idade = *p4;
printf("%d \n", idade);

/* (l) */
p4 = p4 - 2;
idade = *p4;
printf("%d \n", idade);

/* (m) */
p5 = &vetor[2] - 1;
printf("%d \n", *p5);

/* (n) */
p5++;
printf("%d \n", *p5);
return(0);
