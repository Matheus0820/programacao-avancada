#include <stdio.h>
void main(){
  int const *x = 3;
  printf("%d", ++(*x)); 
}

/* 
Resposta: 
O código estar errado. Está se tentando atribuir o valor inteiro a um ponteiro para inteiro.
O certo a se fazer é definir uma variável inteira que receberá o valor 3 e após isso atribuir o valor dela
ao ponteiro constante para inteiro 'x'.
Resumindo, a saída do código será um erro.
*/
