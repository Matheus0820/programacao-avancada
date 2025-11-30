#include <stdio.h>
int main(){
  unsigned int x[4][3] = {{1, 2, 3}, {4, 5, 6},
  {7, 8, 9}, {10, 11, 12}};
  printf("%u, %u, %u", x+3, *(x+3), *(x+2)+3); // Retornará o mesmo endereço, em formato unsigned int, que será do primeiro elemento da quarta linha em 
}
/*
Resposta: 
Note que 'x' é um ponteiro para ponteiro para inteiro, onde guarda o endereço do primeiro elemento
da promeira linha da matriz.

-> x + 3 -> Endereço do primeiro elemento do array da 4 linha da matriz 'x'

-> *(x+3) -> Endereço do primeiro elemento do array da 4 linha da matriz 'x'. Isso ocorre pois 'x' é ponteiro
para ponteiro de inteiro, pegando o valor de (x + 3), também será o endereço do primeiro elemento da linha 4.

-> *(x+2)+3 -> x+2 leva pra o endereço do primeiro elemento da terceira linha da matriz. *(x+2) também representa
o endereço do primeiro elemento da terceira linha da matriz, mas agora no contexto do array armazenado nessa linha. 
Fazendo *(x+2)+3 será o endereço do primeiro elemento da terceira linha. Somando 3 ele andará elemento a elemento no array
até chegar no primeiro elemento da quarta linha da matriz.
*/
