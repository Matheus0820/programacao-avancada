#include <stdio.h>

int main() {
  int pulo[5] = {0, 1, 2, 3, 4};
  *(pulo + 2); // Resposta -> Esse referência o valor do terceiro elemento de 'pulo[]'. *(pulo + 2) = pulo[2]
  *(pulo + 4);
  pulo + 4;
  pulo + 2; 

  return 0;
}
