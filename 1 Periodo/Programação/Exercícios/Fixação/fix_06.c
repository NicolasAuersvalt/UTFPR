/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
1. Escreva um programa que mostra todos os números no intervalo [0, N), onde N é
uma constante definida com o uso da diretiva de pré-processamento #define. Faça
a sequência ser mostrada duas vezes, uma usando a estrutura de repetição while,
a outra o for.
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
/*
#define N 10

#include <stdio.h>
int n = 0;

int main() {

  while (n < N) {
    printf("%d, ", n);
    n++;
  }

  return 0;
}




#define N 10

#include <stdio.h>
int n = 0;

int main() {

  for (n = 0; n < N; n++) {
    printf("%d, ", n);
  }

  return 0;
}
*/
/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
2. O que o programa abaixo produz como saída? Responda somente analisando o
código, só execute- o para confirmar a sua resposta.

#include <stdio.h>
#define N 10
#define X 3
int main ()
{
int i;
for (i = 0; i < N*X; i += X)
printf ("%d\n", i);
return 0;
}
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
3 Escreva um programa que imprima a tabuada de um número n dado (1 x n até 10 x
n). Faça duas versões do programa, uma usando while e a outra for.
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
/*
#include <stdio.h>

int main() {

  int i = 0, o; // N de termos
  printf("Digite o valor: \n");
  scanf("%d", &o);

  while (i < o) {
    for (int m = 0; m < 10; m++) {
      printf("%d, ", o * m);
    }
    i++;
  }

  return 0;
}

*/
/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
Escreva um programa que imprima os 10 primeiros números inteiros maiores que um
n dado. Faça duas versões do programa, uma usando while e a outra for.
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
#include <stdio.h>

int main() {

  int n;

  printf("Digite um valor: \n");
  scanf("%d", &n);

  for (int m = n; m < n + 10; m++) {
    printf("%d \n", n);
  }

  return 0;
}
