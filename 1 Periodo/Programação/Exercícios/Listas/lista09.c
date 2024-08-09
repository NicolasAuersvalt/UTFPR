/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
a) Escreva um programa que mostre todos os resultados possíveis quando
arremessamos 2 dados de 6 faces. A ordem aqui é relevante, portanto 1, 2 é um
resultado diferente de 2, 1, e ambos devem ser mostrados. Dica 1: se achar muito
difícil, escreva em algum lugar todas as combinações e veja se existe algum
padrão. Dica 2: se ainda assim achar muito difícil, comece mostrando somente
todos os resultados possíveis quando arremessamos um único dado!

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

#include <stdio.h>

int main() {

  int n, i;

  printf("Dado 1 | Dado 2\n");

  // 1°
  for (n = 1; n <= 6; n++) {

    // 2°
    for (i = 1; i <= 6; i++) {

      printf("%d, %d\n", n, i);
    }
  }
  return 0;
}



#include <stdio.h>

int main() {

  int n, i, j;

  printf("Dado 1 | Dado 2\n");

  // 1°
  for (n = 1; n <= 6; n++) {

    // 2°
    for (i = 1; i <= 6; i++) {

      // 3°
      for (j = 1; j <= 6; j++) {
        printf("%d, %d, %d\n", n, i, j);
      }
    }
  }
  return 0;
}


  */

/*

#include <stdio.h>

int main() {

  int n, i, j;

  printf("Dado 1 | Dado 2\n");

  // 1°
  for (n = 1; n <= 6; n++) {

    // 2°
    for (i = n; i <= 6; i++) {

      // 3°
      for (i = j; j <= 6; j++) {

        printf("%d, %d, %d\n", n, i, j);
      }
    }
  }

  return 0;
}
*/
/*

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
2. Um número positivo é primo se for divisível somente por 1 e por ele mesmo.
Escreva um programa que calcula a soma dos N primeiros números primos, onde N é
uma constante declarada em uma macro. Por exemplo, como os 5 primeiros números
primos são: 2, 3, 5, 7 e 11, para N = 5 a soma será 28.

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
/*
#include <stdio.h>
#define N 5

int main() {

  int cont, flag, div, v;

  // cont menor que o Valor definido
  while (cont <= N) {
    flag = 1;

    for (div = 2; div < v; div++) {
    }

    if (v % div == 0)
      flag = 0;

    if (flag == 1)
      cont++;
  }

  printf("%d", div);

  v++;

  return 0;
}
*/

/*
3. Escreva um programa que recebe como entrada um número positivo n e mostra
qual é o menor número que é divisível por todos os números de 1 a n. Por
exemplo, para n = 10, o programa deve mostrar o número 2520, que é divisível por
todos os números entre 1 e 10.
*/

//  Qual é o menor número que é divisível por todos os números de 1 a n

// n = 10 -> 2520 é divisível por todos os números entre 1 e 10.

/*
#include <stdio.h>

int main() {

  int intervalo;

  printf("Digite um intervalo: \n");
  scanf("%d", &intervalo);

  for (int valor = 1; valor != 0; valor++) {
    int flag = 1;

    for (int n = 1; n < intervalo; n++) {

      if ((valor % n) != 0) {
        break;
      }
    }

    if (flag == 1) {
      printf("%d", valor);
      valor = 0;
    }
  }

  return 0;
}


#include <stdio.h>

int main() {

  int n;
  char caract = 'A'; // A ou A B C D E

  printf("Digite um valor: \n");
  scanf("%d", &n);

  while (n >= 0) {
    for (int i = 0; i <= n; i++) {
      printf("%c ", i + caract);
    }
    printf("\n");
    n--;
  }
  return 0;
}


#include <stdio.h>

int main() {

  int n;
  char caract = 'A'; // A ou A B C D E

  printf("Digite um valor: \n");
  scanf("%d", &n);

  while (n >= 0) {
    for (int i = 0; i <= n; i++) {
      printf("%c ", i + caract);
    }
    printf("\n");
    n--;
    caract++;
  }
  return 0;
}


#include <stdio.h>

int main() {

  int n;
  char caract = 'A'; // A ou A B C D E

  printf("Digite um valor: \n");
  scanf("%d", &n);

  while (n >= 0) {
    for (int i = 0; i <= n; i++) {
      printf("%c ", caract);
    }
    printf("\n");
    n--;
    caract++;
  }
  return 0;
}

*/

#include <stdio.h>

int main() {

  char caract;
  int val_1, val_2;

  printf("Digite um Caractere: ");
  scanf("%c", &caract);

  printf("Digite um valor: ");
  scanf("%d", &val_1);

  for (int i; i < val_1; i++) {
    for (int j; j < val_1; j++) {
    }
  }

  return 0;
}