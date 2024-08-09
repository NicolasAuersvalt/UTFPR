#include <stdio.h>

int main(void) {

  float peso;
  int idade;
  int cod;
  
// scanf(, &argumento1, &argumento);
// Nota-se que, para todo argumento, deve-se
// vir precedido de & ("endereço")
  // especificadores de formato (%d, %f) devem ser combinados,
  // respectivamente, com os argumentos
  
  scanf("%d %d %f", &idade, &cod, &peso);

  // Para limitar as casas após a vírgula %.2d

  // .3
  printf(" %.3d\n", idade); // 216516

  // .20
  printf(" %.20d\n", idade); // 000000000000000056161
 
  // .020
  printf(" %.020d\n", idade); // 000000000000000056161

  // 0.20
  printf(" %0.20d", idade); // 000000000000000056161

  
  return 0;
}