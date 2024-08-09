/*
Estruturas condicionais

Operadores Lógicos:
devem produzir (verdadeiro ou falso)

Ou - ||
E - &&
NOT (negação) - !


Algumas equivalências:

!(a==b) é equivalente a a!=b

!(a&&b) é equivalente a !a||!b
No A e B <=> No a ou B (resultado será NO msm)

Devemos utilizar a estrutura mais simples

0 - Falso
1 - Verdadeiro

Devemos tomar cuidado que qualquer coisa diferente de 0 é
interpretada como VERDADEIRO.

"if(foo==1)" não é equivalente a "if(foo)"
Se foo tiver qualquer outro valor armazenado, será
dado como True.

*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!

Nas combinações relacionais, a ordem é sempre da esquerda 
para a direita!

if(18 <= idade <= 60)

Ou seja, 18 <= idade resultará em 0 ou 1, ficando assim:

if(1<=60) ou
if(0<=60)

*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!

Forma correta:

if(18<= idade && idade <= 60)

*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!

Ordem dos Operadores:

1° !
2° * / %
3° + -
4° < > <= >=
5° == !=
6° &&
7° ||

*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!*!

Essa ordem só pode ser quebrada com o uso de parênteses.

Por exemplo:
NÃO ((A>B) OU (A+B<C) E (C<D))

R1 (A>B)
R2 (A+B)
R3 (A+B<C)
R4 (C<D)
R5 ((A+B<C) E (C<D))
R6 ((A>B) OU (A+B<C) E (C<D))
R7 (NÃO ((A>B) OU (A+B<C) E (C<D)))

Notemos que NÃO ficou por último mesmo com sua ordem,
isso se dá pois temos parênteses, e ele quebra a ordem.


Alguns compiladores já fazem até o seu resultado ser reconhecido

A || ((b>10) && c)

Se A for 1, não precisa verificar o resto, pois já será verdadeiro
independente do resto.


Tomar cuidado com a verificação e legibilidade, pois

EXP1 || (EXP2 && EXP3)

é tranquilo de ler e facilidade a legibilidade geral,
porém redunda pois && será realizado antes de ||

(EXP1 || EXP2) && EXP3

Já aqui é necessário se for o caso de verificar || antes.

*/

#include <stdio.h>

int main(){

  
  
  
  return 0;
}

