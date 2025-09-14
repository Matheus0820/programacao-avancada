/* Código com erro */
#include <stdio.h>
struct teste{
  int x = 3;
  char nome[] = "jose";
};
main(){
  struct teste *s;
  printf("%d", s->x);
  printf("%s", s->nome);
}

/* Código corrigido */
#include <stdio.h>
#include <string.h>

struct teste{
  int x;
  char nome[30];
};
int main(){
  struct teste teste1;
  teste1.x = 3;
  strcpy(teste1.nome, "jose");
  
  struct teste *s;
  s = &teste1;
  
  printf("%d", s->x);
  printf("%s", s->nome);
  
  return 0;
}

/*
Erros encontrados: 
1 - Struct definido de forma errada -> Foi tentado atribuir valores as variáveis dentro do struct, isso não pode
2 - A definição do tipo da função 'main'
3 - Faltou criar uma variavel do tipo struct, definir valores a ele e atribuir o endereço dele ao ponteiro para Struct
*/
