/* 
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

  Operadores de incremento e de decremento

  ++ e --

  foo = foo + 1

  subtituímos por:
  
  foo++

  foo = foo - 1

  subtituímos por:
  
  foo--


  Por exemplo

  foo = 5;
  if(foo++ > 5) // Falso!! Pois o valor será incrementado depois
  if(++foo > 5) // Verdadeiro!!

  Operadores:
  +=
  -=
  *=
  /=
  %=
  <<=
  >>=
  &=
  |=
  ^=

  # - Não é hashtag, é CERQUILHA

  #include -> cola o conteúdo de um arquivo e coloca no seu

  #define -> Define uma macro

  #define <NOME> <código>

  // A ideia é que a cada vez que ocorrer aquele NOME, ele substituirá pelo que 
  estiver à direita


  Estruturas de Repetição:


  1° Loops Determinados (quando conhecemos a quantidade de vezes a serem repetidas)

  2° Loops Indeterminados (quando não conhecemos, mas sabemos o objetivo)

  3° Repetições Aninhadas
  
  * Iteração = Repetição


  Loop While:

  while (condicao){
  something
  }

  if != while

  if - repete uma única vez se a condição for verdadeira
  while - se repete até a condição for falsa

  int i = 0; // DEVEMOS declarar antes a variável

  while(i<=5){
    i++;
  }


  para for:

  int i=0
  for(i;i<10;i=i++)

  for(inicialização; condição)

  Mas posso ter mais que uma inicialização:

  for(int i=0, b = 0, c = 0.)
  

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

*/
#include<stdio.h>

int main(){


  return 0;
}
