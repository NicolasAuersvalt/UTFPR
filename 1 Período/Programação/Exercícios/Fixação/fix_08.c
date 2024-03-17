/*

O programa abaixo deveria calcular o resultado da exponenciação de uma base por
um expoente, ambos inteiros e positivos

  #include <stdio.h>
 1
 2 int main ()
 3 {
 4    unsigned int base, expoente;
 5    unsigned long long total = 0;
 6
 7    scanf ("%u", &base);
 8    scanf ("%u", &expoente);
 9
 10    while (expoente > 0)
 11    {
 12        base *= base;
 13        expoente--;
 14    }
 15
 16    printf ("%llu\n", total);
 17
 18    return (0);
 19 }


  Este programa não funciona. O resultado impresso para qualquer entrada é 0.
 O que precisa ser feito para que o programa funcione corretamente? Você deve
modificar apenas 2 linhas do código. Dica: os erros são de lógica, e não
envolvem a sintaxe da linguagem C nem a formatação dos dados de E/S
*/
/*
 #include <stdio.h>
 1
 2 int main ()
 3 {
 4    unsigned int base, expoente; // inicializa base_1
 5    unsigned long long total = 0;
 6
 7    scanf ("%u", &base);
 8    scanf ("%u", &expoente);
 9
 10    while (expoente > 0)
 11    {
 12        base *= base; // Devemos alterar incluindo outra variável

          // base_1 = base_1 * base
          // ou inicializamos base_1 aqui

 13        expoente--;

 14    }

      // total = base, pois total é 0 e queremos exibir o valor.
 15
 16    printf ("%llu\n", total);
 17
 18    return (0);
 19 }
*/
/*

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

Zeca está organizando um bolão de futebol. Segundo suas regras, os apostadores
informam o placar do jogo e ganham 10 pontos se acertarem o vencedor ou se foi
empate, e ganham mais 5 pontos para o placar de cada time que acertarem. A
tabela a seguir dá um exemplo, considerando que o placar real foi 3x2:

 0x1   0   Não acertou o vencedor e nem o número de gols dos times.
 0x2   5   Não acertou o vencedor, mas acertou o número de gols do segundo time.
 3x5   5   Não acertou o vencedor, mas acertou o número de gols do primeiro
time. 1x0   10   Acertou o vencedor, mas não acertou o número de gols dos times.
 3x1   15   Acertou o vencedor e o número de gols do primeiro time.
 3x2   20   Acertou o vencedor e o número de gols de ambos os times.

 =====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/
#include <stdio.h>

int main() {

  int val1, val2, pontos = 0, apost1, apost2;

  printf("Digite a aposta: \n");
  scanf("%dx%d", &apost1, &apost2);

  printf("Digite o placar: \n");
  scanf("%dx%d", &val1, &val2);

  if (apost1 == apost2) {                       // Aposta Empate
    if ((apost1 == val1) && (apost2 == val2)) { // Placar Empate
      pontos = 10 + 5;
      printf("Empatou!\n");
    } else
      pontos = 0;
  } else if ((apost1 == val1) && (apost2 == val2)) { // Acertou o placar
    pontos = 10 + 5;
    printf("Acertou em Cheio!\n");
  }

  if (val1 > val2) {                            // Val1 Vencedor
    if ((apost1 >= val1) && (apost2 <= val2)) { // Acertou vencedor 1
      pontos = 10;
      printf("1 Ganhou!\n");
    }
    if ((apost1 < val1) || (apost2 > val2)) { // Errou o vencedor 1
      printf("Errou! 1 Ganhou\n");
    }

    if (val1 < val2) {                            // Val1 Vencedor // 0 X 3
      if ((apost1 <= val1) && (apost2 >= val2)) { // Acertou vencedor 1
        pontos = 10;
        printf("2 Ganhou!\n");
      }
      if (apost2 < val2) { // Errou o vencedor 1
        printf("Errou! 2 Ganhou\n");
      }
    }
    printf("Pontos finais: %d\n", pontos);

    return 0;
  }
}