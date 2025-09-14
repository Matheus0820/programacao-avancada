/* Programa 1 */
// Esse programa retorna todos os valores do vetor 'vet[]'.
#include <stdio.h>
int main(){
  int vet[] = {4, 9, 13};
  int i;
  for(i=0;i<3;i++){
  printf("%d ", *(vet+i));
  }
}

/* Programa 2 */
// Esse programa retorna todos os endereços, em hexadécimal e em maiúsculos, onde são guardados os valores do vetor 'vet[]'.
#include <stdio.h>
int main(){
  int vet[] = {4, 9, 13};
  int i;
  for(i=0;i<3;i++){
  printf("%X ",vet+i);
  }
}
