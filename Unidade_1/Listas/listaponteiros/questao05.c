#include <string.h>
#include <stdio.h>
#include <stdlib.h>
// Antigo Código:
void funcao(char** str){
  str++;
}
int main(){
  char *str = (void *)malloc(50*sizeof(char));
  strcpy(str, "Agostinho");
  funcao(&str);
  puts(str);
  free(str);
  return 0;
}

/*
Resposta: A função 'funcao' está recebendo o endeço da string 'str' por copia e esta descolando ele mais 1 espaço na memória. 
Uma forma de resolver isso é passar o endereço de 'str', e incrementalo mais 1 na sua dereferenciação, ficando da seguinte forma a função

// Nova função
void new_funcao(char** str) {
  (*str)++; // => str[0] = str[1] -> Agora 'str' começara a guardar o endereço seu segundo termo
}

No código principal deve-se criar um ponteiro auxíliar para gurdar o endereço do primeiro termo de str, ele será usado para destruir o ponteiro no 'free()'.
Desse modo ficaremos com o seguinte código:
*/

// Novo código:  
void new_funcao(char** str) {
  (*str)++; // => str[0] = str[1] -> Agora 'str' começara a guardar endereço seu segundo termo
}

int main(){
  char *str = (void *)malloc(50*sizeof(char));
  strcpy(str, "Agostinho");
  char *aux = str;
  new_funcao(&str);
  puts(str);
  free(aux);
  return 0;
}
