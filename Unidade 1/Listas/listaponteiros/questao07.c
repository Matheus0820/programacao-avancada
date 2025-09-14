#include <stdio.h>
int main(void){
  float vet[5] = {1.1,2.2,3.3,4.4,5.5};
  float *f;
  int i;
  f = vet;
  printf("contador/valor/valor/endereco/endereco\n");
  for(i = 0 ; i <= 4 ; i++){
    printf("i = %d",i); // Retornará o número do contador -> 'i' pertence a {0, 1, 2, 3, 4}
    printf(" vet[%d] = %.1f",i, vet[i]); // Retonará o valor do array "vet" na posição 'i'
    printf(" *(f + %d) = %.1f",i, *(f+i)); // Retornará o valor do array 'vet' na posição i -> *(f + i) = vet[i]
    printf(" &vet[%d] = %X",i, &vet[i]); // Retornará o endereço do valor de 'vet' na posição i
    printf(" (f + %d) = %X",i, f+i); // Retornará o endereço do valor 'vet' na posição i -> f + i = &vet[i]
    printf("\n");
  }
}

/*
Resposta: Foram obtidas as resposta esperadas. No código foi usado um ponteiro para float 'f', no qual ele guarda
o primeiro valor do vetor 'vet'. Ou seja f = &vet[0]. Por esse motivo, usando manipulação de ponteiros foi possível 
acessar os dados acessados no laço de repetição.
*/
