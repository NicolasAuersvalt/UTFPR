#include <iostream>

using namespace std;

#include <stdio.h>
#include <stdlib.h> //exit()
#include "include\Caixa.h"

int main()
{
    double a, l, p;

    //1. Criar 2 caixas
    //Não necessita de new como é feito em Java
    Caixa cA, cB;

   //2. pedir valores da caixa cA
   printf("Digite altura de cA:");
   scanf("%lf", &a);
   bool res = cA.setAltura(a);
   if (res == false)
   {
       printf("\r\nValor inválido!");
       exit(0); //sai do programa
   }

   printf("Digite largura de cA:");
   scanf("%lf", &l);
   res = cA.setLargura(l);
   if (res == false)
   {
       printf("\r\nValor inválido!");
       exit(0); //sai do programa
   }

   printf("Digite profundidade de cA:");
   scanf("%lf", &p);
   res = cA.setProfundidade(p);
   if (res == false)
   {
       printf("\r\nValor inválido!");
       exit(0); //sai do programa
   }

   //3. pedir valores da caixa cA
   printf("Digite altura de cB:");
   scanf("%lf", &a);
   res = cB.setAltura(a);
   if (res == false)
   {
       printf("\r\nValor inválido!");
       exit(0); //sai do programa
   }

   printf("Digite largura de cB:");
   scanf("%lf", &l);
   res = cB.setLargura(l);
   if (res == false)
   {
       printf("\r\nValor inválido!");
       exit(0); //sai do programa
   }

   printf("Digite profundidade de cB:");
   scanf("%lf", &p);
   res = cB.setProfundidade(p);
   if (res == false)
   {
       printf("\r\nValor inválido!");
       exit(0); //sai do programa
   }

   //4. calcular área ext e volume
   printf("\r\nA área da cA é %lf",
          cA.calcularAreaExt());
    printf("\r\nA área da cB é %lf",
          cB.calcularAreaExt());
    printf("\r\nO volume da cA é %lf",
          cA.calcularVolume());
    printf("\r\nO volume da cB é %lf",
          cB.calcularVolume());

    return 0;
}
