/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
Um ano é bissexto se for divisível por 400, ou se for divisível por 4 mas não
por 100. Escreva uma função que retorna 1 se um ano dado é bissexto ou 0 do
contrário. A função deve ter o seguinte protótipo: int ehBissexto (int ano);

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/

#include <stdio.h>

int ano;

int ehBissexto(ano) {
  if (((ano % 400) == 0 || (((ano % 4) == 0) && (ano % 100) != 0))) {
    printf("eh bissexto");
    return 0;
  } else {
    printf("nao eh");
    return 0;
  }
}

int main() {

  printf("Digite um ano: ");
  scanf("%d", &ano);

  ehBissexto(ano);
}