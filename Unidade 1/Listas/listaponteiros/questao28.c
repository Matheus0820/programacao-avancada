#include <stdio.h>
char *a[] = {"AGOSTINHO", "MEDEIROS", "BRITO", "JUNIOR"};
char **b[] = {a + 3, a + 2, a + 1, a}; // b = {a[3], a[2], a[1], a[0]}
char ***c = b; // c = &b[0]
int main() {
  printf("%s ", **++c); /* 
  1 -> ++c = c + 1 =>
  c = &b[1] = a[2] = "BRITO" =>
  **++c = "BRITO" 
  */
  
  printf("%s ", *--*++c + 3); /* 
  ++c = c + 1 => c = &b[2] => 
  *++c =  b[2] = &a[1] => 
  --*++c => b[2] = &a[0] =>
  *--*++c = **b[2] = a[0] = "AGOSTINHO" =>
  (*--*++c) + 3 = a[0] + 3 = "STINHO" 
  */
  
  printf("%s ", *c[-2] + 3); /*
  c[-2] = c - 2 = c[0] - 2 = &b[2] - 2 = &b[0] =>
  *c[-2] = &b[0] = a[3] = "JUNIOR" =>
  *c[-2] + 3 = a[3] + 3 = "IOR"
  */
  
  printf("%s ", c[-1][-1] + 1); /*
  c[-1] = c - 1 = c[0] - 1 = b[2] - 1 = b[1] =>
  c[-1][-1] = b[1][-1] = *b[1] - 1 = a[3] - 1 = a[2] => *a[2] = "MEDEIROS" =>
  c[-1][-1] + 1 = *a[2] + 1 = a[2] + 1 = "EDEIROS"
  */
  
  return 0;
}

/*
Saida: BRITO STINHO IOR EDEIROS
*/
