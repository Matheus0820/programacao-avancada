#include <stdio.h>

int main() {
  int mat[4], *p, x;

  p = mat + 1; // Válida -> Guarda em 'p' o endereço do segundo elemento de 'mat', o elemento 'mat[1]'.
  p = mat++; 
  p = ++mat;
  x = (*mat); // Válida -> Guarda em 'x' o primeiro valor do array 'mat', o valor 'mat[0]'
  
  return 0;
}
/*
Resposta:
  p = mat++; -> É inválida pois tenta modificar o endereço guardado do primeiro endereço do array 'mat'. Ou seja, p = mat++ => mat = mat + 1 = p
  p = ++mat; -> É inválida pois tenta modificar o endereço guardado do primeiro endereço do array 'mat'. Ou seja, p = mat++ => mat = mat + 1 = p
*/
