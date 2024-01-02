#include <stdio.h>

/*
//===================================================
// 1
//===================================================

  1. Tia Maria vai precisar de um recipiente auxiliar para colocar o conteúdo de
um dos copos. Pode ser outro copo que tenha pelo menos o mesmo tamanho dos copos
das crianças, ou até uma das jarras.
Basta então ela colocar o conteúdo do copo
de Mariazinha (suco de melancia) no recipiente auxiliar, o conteúdo do copo do
Joãozinho (suco de abacaxi) no copo de Mariazinha, e o conteúdo que estava no
recipiente auxiliar (suco de melancia) no copo de Joãozinho. Se precisar, ela
pode lavar os copos entre as operações.
O conteúdo dos copos fica assim:

Início: Joãozinho: abacaxi Mariazinha: melancia Auxiliar: nada

1 troca: Joãozinho: abacaxi Mariazinha: nada Auxiliar: melancia
2 trocas Joãozinho: nada Mariazinha: abacaxi Auxiliar: melancia
3 trocas Joãozinho: melancia Mariazinha: abacaxi Auxiliar: nada


int main(){

  // j - Joãozinho; a - Abacaxi
  // m - Mariazinha; me - Melancia
  // a - Auxiliar; n - Nada
  int j, a, m, me, n=0;

  // 1 Troca
  j = a; // Joãozinho: Abacaxi
  m = n; // Mariazinha: Nada
  a = me; // Auxiliar: Melancia

  // 2 Troca

  j = n; // Joãozinho: Nada
  m = a; // Mariazinha: Abacaxi
  a = me; // Auxiliar: Melancia

  // 3 Troca

  j = me; // Joãozinho: Melancia
  m = a; // Mariazinha: Abacaxi
  a = n; // Auxiliar: Nada
}
*/
/*
//===================================================
// 1
//===================================================

2. Dado T o número total de segundos:
- O número D de dias é dado pela parte inteira da divisão T/86400 (86400 é o
número de segundos em um dia: 60 x 60 x 24).
- O número H de horas é dado pela parte inteira da divisão (T-86400D)/3600 (3600
é o número de segundos em uma hora: 60 x 60).
- O número M de minutos é dado pela parte inteira da divisão
(T-86400D-3600H)/60.
- O número S de segundos é dado por T-86400D-3600H-60M.

*/

int main() {

  // d - Dia; h - Hora; m - Minuto; s - Segundo
  // O objetivo disso é fazer a conversão de um tempo
  // t, em segundos, em vários outros formatos de tempo.

  int t; // Número total de segundos

  // O intuito aqui é descobrir, em inteiros, quantos dias cabem nessa
  // quantidade de segundos
  // Aqui pega o total e divide por 86400 para descobrir os quantos dias
  // resultará dividindo pela quantidade de segundos de um dia
  int d = t / 86400; // Divisão Inteira pelo número de segundos em um dia

  // O intuito aqui é descobrir quantas horas sobram de 24h, isto é,
  // o extra. Porém, está em segundos, então precisa ser feita a
  // conversão para horas dividindo por 3600.
  // Aqui é feita a subtração do tempo por 86400 e depois multiplicado
  // por d (quantos dias tinha naqueles segundos) e dividido por
  // 3600 = segundos em uma hora.
  int h = ((t - 86400) * d) / 3600; // 3600 é segundos em uma hora 60x60

  // (conferir dps) O intuito aqui é descobrir os minutos excedentes
  // Aqui se repete a fórmula de h para descobrir as horas extras, e
  // depois se subtrai essas horas extras por uma quantidade de horas
  int m = (((t - 86400) * d) - (3600 * h)) / 60;

  // E o intuito aqui é descobrir os segundos excedentes
  int s = t - (86400 * d) - (3600 * h) - (60 * m);
}