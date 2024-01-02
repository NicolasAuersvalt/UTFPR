/*
  Escreva um programa que calcule o fatorial de um número dado.
  */
/*
#include <stdio.h>

int main() {

  int valor, valor_desc, fatorial;

  printf("Digite um valor: \n");
  scanf("%d", &valor);

  fatorial = valor;

  for (int n=1; n < valor; n++) { // Para cada n, n-1, n-2

    // Quando o n não é declarado no for(), ele é chamado "lixo"

    valor_desc = valor - n; // Valor - n para progredir no fatorial
    fatorial *= valor_desc; // Fatorial vai armazenar o valor e multiplicar no
final
  }
  printf("O valor %d ", valor);
  printf("possui como fatorial: %d \n", fatorial);
  return 0;
}
*/

/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

2. Escreva um programa que leia n números (com n informado pelo usuário) e diga
se eles formam uma sequência crescente, decrescente, ou nenhum dos casos.


=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
/*
#include<stdio.h>

int main(){

    int valor, proximo, crescente=1,
    qtd, decrescente=1;

    printf("Digite uma quantidade\n");
    scanf("%d", &qtd);

    printf("Digite o valor\n");
    scanf("%d", &valor);

    for(int n=0; n < qtd-1; n++){ // Loop de 1 a n

      printf("Digite o valor\n");
      scanf("%d", &proximo);

      if(proximo > valor){ // flag 0 - DECRESCE
        decrescente = 0;  // Decrescente ou nenhum
      }
      else{
        crescente = 1; // Crescente
      }

      valor = proximo; // Atual será o próximo valor

    }
    if(crescente == 1){
      printf("\nÉ crecente.");
    }
    else if (decrescente == 1){
      printf("\nÉ decrescente.");
    }
  else{ /// Nenhum dos casso 0 e 0
    printf("Nenhum dos dois.");
  }


  return 0;
}
*/

/*

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
4. Escreva um programa que lê um inteiro positivo e um dígito. O programa deve
verificar se o número dado contém o dígito em qualquer posição. Não é preciso
dizer qual a posição, apenas indicar se o dígito está ou não presente.
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

*/
/*
#include <stdio.h>

int main() {

  int valor, flag = 0, num_des, n = 1, inicial, loop = 0;

  printf("Digite um valor: \n");
  scanf("%d", &valor);

  printf("Digite o valor desejado: \n");
  scanf("%d", &num_des);

  inicial = valor;

  while (flag == 0) {

    // Divisões
    int rest = valor % 10;
    printf("Resto %d \n", rest);
    int div = valor / 10;
    printf("Divisão %d \n", loop);

    // Divido ser igual ao valor ou resto ser
    if ((num_des == div) || (num_des == rest)) {
      flag = 1;
      printf("Tem o %d em %d\n", num_des, inicial);
    }
    if (div == 0 && rest == 0) {
      break;
    }

    valor = div;
    loop++;
    printf("Loopado %d vezes \n", loop);
  }

  // Não tem o 1 e acabou a divisão
  if (flag == 0)
    printf("Nao tem o %d em %d\n", num_des, inicial);

  return 0;
}
*/
/*
Escreva um programa que calcule o quociente e o resto da divisão de dois números inteiros
positivos dados, usando apenas as operações de soma e/ou subtração.
*/
#include<stdio.h>

int valor;

int main(){

  // Entrada de dados
  printf("Digite o primeiro valor: \n");
  scanf("%d", &valor);
  
  printf("Digite o segundo valor: \n");
  scanf("%d", &valor);

  for(int n=1; n<; n += )
  
  for(int n; n<)
  return 0;
}