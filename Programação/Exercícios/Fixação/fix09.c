/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

1. Escreva um programa que imprima as tabuadas do 1 ao 10. Importante: use loops
aninhados, não escreva 10 vezes o código que imprime a tabuada de um número!!!

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

*/

// 1 x 1
// 1 x 2

/*

#include <stdio.h>

int tabuada = 0;

int main() {

  printf("A tabuada é: \n");

  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      tabuada = i * j;
      printf("%d x %d = %d \n", i, j, tabuada);
    }
    printf("\n");
  }

  return 0;
}

*/
/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====



=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

*/

// n = 2
/*
#include<stdio.h>

int main(){

  int n;

  scanf("%d", &n);

  for(int i=0; i<n; i++){ //  1, 2

    for(int j=0; j<n; j++){ // 1, 2
      printf("A");
    }
    printf("\n");
  }

  return 0;
}
*/
/*
#include <stdio.h>

int main() {

  int n, m;

  scanf("%d", &n);
  m = n;

  // Coluna
  for (int i = 0; i < n; i++) { //  1, 2

    // Linha
    for (int j = 0; j < m; j++) { // 1, 2
      printf("A");
    }
    m--;
    printf("\n");
  }

  return 0;
}
*/

#include <stdio.h>

int main() {

  int n;
  char caract = 'A';

  scanf("%d", &n);

  printf("\n%c \n", caract);

  for (int i = 0; i < n; i++) {
    caract++;
    printf("%c \n", caract);
  }

  return 0;
}