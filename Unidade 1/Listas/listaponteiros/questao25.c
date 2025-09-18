/*
Resposta: 
A única com Mamory leak é o trecho de código 'C', pois ele recebe uma string no argumento da função, 'data', no qual ela pode ser maior que 50 caracteres.
Se a string recebida for maior que 50 caracteres a função retornará '-1' e não liberará a memória causando assim o Memory Leak. 
*/

//(C)
int
f(char *data){
  void *s;
  s = malloc(50);
  int size= strlen(data);
  if (size > 50)
    return(-1);
  free(s);
  return 0;
}
