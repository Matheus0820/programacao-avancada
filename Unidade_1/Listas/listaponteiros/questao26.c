#include <stdio.h>
int main(){
  int a, b;
  int x, y, z;
  scanf("%d %d", &a, &b);
  x = a; y = b; z = a + b;
  while (a) { 
    x = x | b; 
     /*
    loop 1: x = 10 e b = 1 => x = 1010 e b = 0001 => x = x | b => x = 1011 = 11
    loop 2: x = 11 e b = 2 => x = 1011 e b = 0010 => x = x | b => x = 1011 = 11 
    loop 3: x = 11 e b = 4 => x = 1011 e b = 0100 => x = x | b => x = 1111 = 15 
    loop 4: x = 11 e b = 8 => x = 1111 e b = 1000 => x = x | b => x = 1111 = 15
    */
    
    y = y ^ a;
     /*
    loop 1: y = 1 e a = 10 => y = 0001 e a = 1010 => y = y ^ a => y = 1011 = 11
    loop 2: y = 11 e a = 5 => y = 1011 e a = 0101 => y = y ^ a => y = 1110 = 14
    loop 3: y = 14 e a = 2 => y = 1110 e a = 0010 => y = y ^ a => y = 1100 = 12
    loop 4: y = 12 e a = 1 => y = 1100 e a = 0001 => y = y ^ a => y = 1101 = 13
    */
    
    z = z & (a+b);
     /*
    loop 1: z = 11 e a = 10 e b = 1 => z = 1011 e a = 1010 e b = 0001 => z = z & (a+b) => z = 1011 & 1011 = 1011 => z = 11
    loop 2: z = 11 e a = 5 e b = 2 => z = 1011 e a = 0101 e b = 0010 => z = z & (a+b) => z = 1011 & 0111 = 0011 => z = 3
    loop 3: z = 3 e a = 2 e b = 4 => z = 0011 e a = 0010 e b = 0100 => z = z & (a+b) => z = 0011 & 0110 = 0010 => z = 2
    loop 4: z = 2 e a = 1 e b = 8 => z = 0010 e a = 0001 e b = 1000 => z = z & (a+b) => z = 0010 & 1001 = 0000 => z = 0
    */

    
    a = a >> 1; // 10 = 1010 => a >> 1 = deslocar todos os bits para a direita 1 vez a cada execulção -> Com isso 'a' será igual a zero após a 4° execulção => loop vai parar
    b = b << 1; // 1 = 0001 => b << 1 = desloca todos os bits para a esquerda 1 vez a cada execulção
    /*
    loop 1: 0010 => b = 2;
    loop 2: 0100 => b = 4;
    loop 3: 1000 => b = 8;
    loop 4: 0000 => b = 0;
    */
  }
  printf ("%d %d %d\n", x, y, z); // Saída: x = 15; y = 13; z = 0
  return 0;
}

/*
Resposta: 
O operador '&' faz a operação de 'and' bit a bit nos dois elemento => Retorna 1 apenas se ambos forem iguais
O operador '|' faz a operação de 'or' bit a bit nos dois elementos => Retorna 1 se pelo menos um dos dois bit analisados forem igual a 1
O operador '^' faz a operação de 'XOR' bit a bit nos dois elementos => Retorna 1 apenas se os dois elementos forem diferentes entre si
*/
