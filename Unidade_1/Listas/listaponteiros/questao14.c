#include <stdio.h>
int f(int a, int *pb, int **ppc) {
  int b, c;
  **ppc += 1; // **ppc += 1 => **ppc = 5 + 1 = 6
  c = **ppc; // c = 6;
  *pb += 2; // *pb += 2 => *pb = 6 + 2 = 8
  b = *pb; // b = 8;
  a += 3; // a += 3 => a = 5 + 3 = 8
  return a + b + c; // 8 + 8 + 6 = 22
}
void main() {
  int c, *b, **a; // Define uma variavel inteira, ponteiro para inteiro e ponteiro para ponteiro para inteiro
  c = 5;
  b = &c; // Guarda o endereço de 'c' em 'b'
  a = &b; // Guarda o endereço do ponteiro 'b' em 'a'
  printf("%d\n", f(c, b, a)); // f(5, &c, &&c)
  getchar(); // Pega o valor de um único caractere
}
/*
Resposta: Os passos estão descritos no código como comentário em cada linha. Espero que contem como justificativa.
*/
