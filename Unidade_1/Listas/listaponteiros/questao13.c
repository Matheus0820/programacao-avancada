#include <stdio.h>

int tipoChar() {
  char x[4]; 
  printf("TIPO char \n");
  printf("x + 1 = %X\n", x + 1);
  printf("x + 2 = %X\n", x + 2);
  printf("x + 3 = %X\n\n", x + 3);

  return 0;
}
int tipoInt() {
  int x[4]; 
  printf("TIPO int \n");
  printf("x + 1 = %X\n", x + 1);
  printf("x + 2 = %X\n", x + 2);
  printf("x + 3 = %X\n\n", x + 3);

  return 0;
}
int tipoFloat() {
  float x[4]; 
  printf("TIPO float \n");
  printf("x + 1 = %X\n", x + 1);
  printf("x + 2 = %X\n", x + 2);
  printf("x + 3 = %X\n\n", x + 3);

  return 0;
}
int tipoDouble() {
  double x[4]; 
  printf("TIPO doble \n");
  printf("x + 1 = %X\n", x + 1);
  printf("x + 2 = %X\n", x + 2);
  printf("x + 3 = %X\n\n", x + 3);

  return 0;
}


int main() {
  tipoChar();
  /*
  x + 1 -> 4092 + 1 = 4093 
  x + 2 -> 4094
  x + 3 -> 4095
  */
  
  tipoInt();
  /*
  x + 1 -> 4092 + 2 = 4094 
  x + 2 -> 4096
  x + 3 -> 4098
  */
  
  tipoFloat();
  /*
  x + 1 -> 4092 + 4 = 4096 
  x + 2 -> 4100
  x + 3 -> 4104
  */
  
  tipoDouble();
  /*
  x + 1 -> 4092 + 8 = 4100 
  x + 2 -> 4108
  x + 3 -> 4116
  */

  return 0;
}
