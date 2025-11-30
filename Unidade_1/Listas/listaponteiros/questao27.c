#include <stdio.h>
#define TAM 10
int funcao1(int vetor[], int v){
  int i;
  for (i = 0; i < TAM; i++){
    if (vetor[i] == v)
      return i;
  }
  return -1;
}
int funcao2(int vetor[], int v, int i, int f){
  int m = (i + f) / 2;
  if (v == vetor[m])
    return m;
  if (i >= f)
    return -1;
  if (v > vetor[m])
    return funcao2(vetor, v, m+1, f);
  else
    return funcao2(vetor, v, i, m-1);
}
  int main(){
  int vetor[TAM] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
  printf("%d - %d", funcao1(vetor, 15), funcao2(vetor, 15, 0, TAM-1));
  return 0;
}

/*
Resposta: a. I, apenas

Justificativa:
o retorno da funcao1 é 7 pois vetor[7] = 15 = v;
O retorno da funcao2 é 7 pois a funcao2 vai ficar buscando a posição no vetor m, onde m = (i + f) / 2, que vetor[m] == v = 15 e isso só ocorre na posição 7 do vetor 
*/
