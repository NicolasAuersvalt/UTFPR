/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
Abstrair a representação física -> Não depende do suporte físico
(Depende apenas da forma que eu interpreto)

1 - Passa corrente
0 - Não passa

1 - Ranhura
0 - Liso


Representando números usandos 0 e 1 (inteiros)
Base 10 - 10 símbolos = 

0 1 2 3 4 5 6 7 8 9

Base 2 - 2 símbolos = 10²
0 1

Esses números não significam nada, devemos abstrair para
entender seu valor.

1 = 10^0
10 = 10¹
100 = 10²
1000 = 10³
10000 = 10^4

Qualquer número é uma soma de valores de 0 a 9 multiplicados por potências de 10:

1234 = 1 * 10³ + 2*10² + 3*10¹ + 4*10^0

Na base 2 é multiplicados por potências de 2 (On ou Off)

Quantos valores consigo representar usando N bits

1 bit:
2 possibilidades: 0,1

2 bits:
4 possibilidades: 00, 01, 10, 11

...
..
.

Overflow = Tentar representar um valor que não cabe na quantidade de bits

Tentar representar 300 com 2 bits

Byte = 8 bits

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/

#include<stdio.h>

int main(){


  return 0;
}
