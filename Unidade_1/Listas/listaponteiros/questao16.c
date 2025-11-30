#include <stdio.h>

int main() {
  float aloha[10], coisas[10][5], *pf, value = 2.2;
  int i=3;

  aloha[2] = value; // Válido
  scanf("%f", &aloha); // Válido
  aloha = "value"; // Inválido
  printf("%f", aloha); // Inválido -> Retornará o endereço do primeiror elemento de 'aloha', 'aloha[0]', em formato float
  coisas[4][4] = aloha[3]; // Válido
  coisas[5] = aloha; // Inválido 
  pf = value; // Inválido -> Tipos diferentes
  pf = aloha; // Váido

}
