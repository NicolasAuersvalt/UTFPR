/*

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
 (*) 2. Escreva uma função que retorna apenas a parte não-inteira de um número
dado. Por exemplo, se a função receber o valor 1.43, deve retornar 0.43. O
protótipo da função deve ser

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

*/

#include <stdio.h>

int naoInteiro(float antes) {

  int novo = antes;

  float nao_inteiro = novo - antes;

  printf("\nO não inteiro é: ");
  printf("%.3f", nao_inteiro);

  return 0;
}

int main() {

  float valor = 0.0;
  printf("Digite um valor: \n");
  scanf("%f", &valor);

  naoInteiro(valor);

  return 0;
}
