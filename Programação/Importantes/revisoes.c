/* 
Fixação 9
3. Ajuste o programa anterior para que, em vez de mostrar um quadrado, ele mostre uma pirâmide,
como exemplificado abaixo. Dica: se a sua solução para a questão anterior for eficiente, a mudança é
muito simples!
Exemplo para n = 3:
AAA
AA
A
Exemplo para n = 5:
AAAAA
AAAA
AAA
AA
A

*/
/*
#include <stdio.h>

int main() {

  int n, m;

  scanf("%d", &n);
  m = n;

  // Linha (tomando i como Linha)
  for (int i = 0; i < n; i++) { //  1, 2

  Supondo que foi tomado 1 como valor

    // Coluna (tomando j como Coluna)
    for (int j = 0; j < m; j++) { // 1, 2

    Aqui será tomado 1 também. Logo, A somará com 1 nessa linha
    mudando os caracteres.

      printf("A");
    }
    // Diminuimos a flag para formar a pirâmide
    m--;

    Quebramos linha para a pirâmide
    printf("\n");

    Após isso, será percorrido o loop (i) novamente, mas
    tomando o 2 como valor, ou seja, linha 2.
  }
  
  return 0;
}

*/
/*
4. Escreva um programa que, dado um valor n informado pelo usuário, mostre as n primeiras letras
maiúsculas do alfabeto. Considere que 1 ≤ n ≤ 26 (não precisa testar!). Dicas:
- Lembre-se que caracteres são números.
- Lembre-se que, na tabela ASCII, as letras maiúsculas estão na sua ordem alfabética.
- Você NÃO precisa (e nem deve) olhar valores da tabela ASCII. Use caracteres constantes!
Exemplo para n = 3: ABC
Exemplo para n = 5: ABCDE
*/

/*
#include <stdio.h>

int main() {

  int n;
  char caract = 'A';

  // Entrada de dados
  scanf("%d", &n);
  printf("\n%c \n", caract);

  // Abre o primeiro loop, esse que percorrerá o alfabeto
  for (int i = 0; i < n; i++) { 
  
    caract++; // Soma o A com 1 toda vez que percorre o loop
    
    printf("%c \n", caract);
  }

  return 0;
}
*/