/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
1. Escreva um programa que lê números inteiros e mostra a mensagem ECO x, onde x
é o último número lido. O programa deve permanecer em execução somente enquanto
os valores informados estiverem no intervalo [10, 20], e não deve mostrar a
mensagem quando o valor estiver fora do intervalo, mesmo se for o primeiro
valor.
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
#include <stdio.h>

int main() {

  int n, flag;

  printf("Digite um valor: \n");
  scanf("%d", &n);

  for (int i = 0; i < 20 && flag != 1; i++) {
    if (i == n) {
      printf("Echo %d", n);
      flag = 1;
    }
  }

  return 0;
}
