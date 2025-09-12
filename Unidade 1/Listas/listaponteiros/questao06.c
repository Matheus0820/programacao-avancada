#include <stdio.h>
void funcao(char **p){
  char *t;
  t = (p += sizeof(int))[-1];
  printf("%s\n", t);
}
int main(){
  char *a[] = { "ab", "cd", "ef", "gh", "ij", "kl"};
  funcao(a);
  return 0;
}

/*
Resposta: 
O retorno será "gh", pois a função 'funcao' criará um ponteiro para char "t" e guardará nele o seguinte valores: 
t = endereço de p (que guarda o endereço do primeiro termo da vetor de string 'a[0] = "ab"') + 4 (tamanho de um inteiro) - 1 = 3. 
Isso implica que 't' igual ao endereço de 'a[0]' deslocado 3 termos => t = a[3] = "gh".
*/
