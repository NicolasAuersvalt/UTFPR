/*
0 Até 1.200,25
7,5% De 1.200.26 at ́e 2.300,50
15,0 % De 2.300,51 at ́e 3.500,75
22,5 % De 3.500,76 at ́e 4.000,00
27,5 % Acima de 4.000,00

O imposto  é calculado de forma que a al ́ıquota n ̃ao incide sobre o total dos
rendimentos, mas somente sobre a parcela que se encontra em determinada faixa.

Desta forma, um cidad ̃ao com rendimento de UT✓F 1.200,25
est ́a isento do pagamento do imposto. Por outro lado, um cidad ̃ao com rendimento
de UT✓F 1.201,25
*/
#include <stdio.h>

int main() {

  int aliq;

  if (aliq < 1200) { // Menor que 1200
    printf("Menor que 1200");
  } else {
    if (aliq < 2300) { // Menor que 2300
      printf("Maior que 1200 e menor que 2300");
    } else if ((aliq > 2300) && (aliq < 3500)) { // Menor que 3500
      printf("Maior que 1200 e menor que 3500");
    } else if ((aliq > 3500) && (aliq < 4000)) { // Menor que 4000
      printf("Maior que 3500 e menor que 4000");
    } else {
      printf("Maior que 4000");
    }
  }

  return 0;
}
