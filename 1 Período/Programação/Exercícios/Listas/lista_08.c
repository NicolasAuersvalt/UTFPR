/*
Em 1937, o matemático Lothar Collatz propôs a seguinte conjetura, ainda não
provada: dado um número natural arbitrário a0, a sequência gerada por: ai =
ai-1/2, se ai-1 for par ou ai = 3·ai-1+1, se ai-1 for ímpar, em que ai-1 e ai
representam o último elemento produzido para a sequência e o próximo valor a ser
gerado, respectivamente, sempre chegará ao valor 1, independente do valor
inicial escolhido para a0. Por exemplo, a sequência de Collatz para a0 = 7 é: 7,
22, 11, 34, 17, 52, 26, 13, 40, 20, 10, 5, 16, 8, 4, 2 e 1. Escreva um programa
que leia o primeiro elemento de uma sequência de Collatz e imprima na tela a
sequência a partir do elemento dado, até que se alcance o valor 1. O programa
deve também mostrar o número de elementos da sequência gerada. Se o programa
receber o valor 7, por exemplo, deve mostrar os 17 elementos listados acima, e
dizer que gerou 17 elementos.
*/
/*

#include <stdio.h>

int main() {
  int valor = 0, flag = 0, qtd;
  printf("Digite um valor: \n");
  scanf("%d", &valor);
  printf("%d\n", valor);

  while (flag == 0) {
    if ((valor == 1) && (flag == 0)) { // Chegou a 1 e flag = 1
      printf("Chegou a 1.\n");
      printf("em %d vezes", qtd);
      flag = 1;
    } else if ((valor % 2 == 0) && (flag == 0)) { // Par
      valor = valor / 2;
      printf("%d\n", valor);
      qtd += 1;
    } else if ((valor % 2 != 0) && (flag == 0)) { // Ímpar
      valor = valor * 3 + 1;
      printf("%d\n", valor);
      qtd += 1;
    }
  }

  return 0;
}
*/
/*


(***) 2. (Adaptado da OBI 2015)
Alice e Bia criaram uma página na Internet com informações sobre o
Macaco-prego-de-peito-amarelo, uma espécie em extinção. A página mostra como
todos podem ajudar a manter o habitat natural para evitar que a espécie seja
extinta. Uma empresa gostou tanto da iniciativa de Alice e Bia que prometeu doar
um prêmio para que as duas amigas possam realizar outras iniciativas
semelhantes. A empresa decidiu que o prêmio seria dado quando a soma do número
de acessos à página chegasse a 1 milhão. Dada a lista de acessos diários que
ocorreram à página de Alice e Bia, escreva um programa para determinar quantos
dias foram necessários para a soma dos acessos chegar a 1 milhão e as amigas
ganharem o prêmio. O programa recebe como entrada um número inteiro N, que
indica o número de dias que a lista contém. Ele deve então ler N valores,
correspondentes ao número de acessos de cada dia: o primeiro número dado indica
o número de acessos no primeiro dia, o segundo número dado indica o número de
acessos no segundo dia, e assim por diante. O programa deve então mostrar na
saída o número de dias que foram necessários para a soma dos acessos à página de
Alice e Bia chegar a 1.000.000. Se a meta não for atingida, o programa deve
mostrar o valor de erro -1.


*/
/*
#include <stdio.h>
#define META 100

int main(){

  int n_dias, n, valor, dia,
  flag = 0;

  printf("Digite a quantidade de dias: \n");
  scanf("%d", &n_dias);

  for(int m=0; m<n_dias; m++){

    printf("Digite um valor: \n");
    scanf("%d", &valor);

    n += valor;

    if(n>=META && flag == 0){
      dia=m;
      flag = 1;
    }
  }
  if(n<META){
    printf("Erro -1");
  }
  else{
    printf("O número de dias necessários \n para atingir foi de %d", dia);

  }

  return 0;

}
*/

/*

3. A sequência de Fibonacci é uma sequência de números naturais na qual os
primeiros termos são 0 e 1, e cada termo subsequente é a soma dos dois termos
anteriores. Desta forma, o terceiro termo é 0+1=1, o quarto termo é 1+1=2, o
quinto termo é 1+2=3, o sexto termo é 2+3=5 e assim por diante. Os 10 primeiros
números da sequência são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34 Os números da
sequência de Fibonacci são usados em certos algoritmos para codificação,
compressão e ordenamento de dados. Eles também podem ser usados em computação
gráfica, na geração de transições suaves de cores e de objetos com aspecto
natural (por exemplo, em animações cinematográficas). Escreva um programa que
mostra os n primeiros números de Fibonacci, com n dado pelo usuário. Pressuponha
que n será sempre maior ou igual a 3, mas nunca grande o suficiente para causar
overflow em variáveis do tipo int.


*/

/*

#include<stdio.h>
#define MIN_TERMO 0.2
float somatorio = 0;

int main(){

  for(int n=1; (1.0/n) >= MIN_TERMO; n++){

    somatorio += 1.0/n;

    printf("O termo é: %f \n", 1.0/n);
    printf("cuja somatória é: %f", somatorio);
  }

  return 0;
}
*/
/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====


=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
/*

#include <stdio.h>

int a0 = 0, a1 = 1, qtd, an = 0;
#define LIM 20

int main() {

  printf("Digite uma quantidade: \n");
  scanf("%d", &qtd);

  if (qtd >= 3 && qtd <= LIM) {
    printf("%d \n", a0);
    printf("%d \n", a1);

    for (int i = 0; i <= qtd; i++) {
      an = a1 + a0;

      printf("%d \n", an);
      a0 = a1;
      a1 = an;
    }
  } else
    printf("Muito Grande.");

  return 0;
}
*/

/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====


=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/


#include <stdio.h>

int seq, qtd, ant, meio,
    prox, pico = 0;

int main() {

  // Solicita a quantidade
  printf("Digite uma quantidade: \n");
  scanf("%d", &qtd);

  // Solicita os dois primeiros valores referenciais
  printf("Digite o valor: \n");
  scanf("%d", &ant);
  printf("Digite o valor: \n");
  scanf("%d", &prox);

  // Armazenará os valores pelo loop
  for (int n = 0; n < qtd; n++) {

    // Solicita o valor a ser comparado
    printf("Digite o valor: \n");
    scanf("%d", &meio);

    // Se houver um vale
    if (meio < ant && meio > prox)
      printf("Há mais que um pico");

    // Logicamente haverá um pico apenas
    else
      printf("Há um pico");
  }

  return 0;
}


/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

6. Escreva um programa que recebe um número inteiro positivo digitado pelo
usuário e verifica e informa se ele é um número palíndromo ou não. Um número é
palíndromo se puder ser lido igualmente na ordem normal e de trás para a frente.
Alguns exemplos de números palíndromos: 12321, 123321, 101, 2, 9, 99.

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
/*
#include <math.h>
#include <stdio.h>

int valor, n, m, novo;

int main() {
  printf("Digite um valor: \n");
  scanf("%d", &valor);

  m = valor;

  for (int i = 0; (valor / (pow(10, i))) > 0; i++) {
    // printf("O valor %d\n", valor);

    novo = (novo * 10) + (valor % 10);
    // printf("O novo %d\n", novo);

    valor /= 10;
  }
  if (novo == m)
    printf("É um palindromo!");

  else
    printf("Não é um palindromo!");

  return 0;
}
*/
