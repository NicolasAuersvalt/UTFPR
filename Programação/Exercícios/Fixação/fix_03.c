#include<stdio.h>
#include<math.h>
/*
==============================
1
==============================

1. Considerando a = 10, b = 20 e c = 10, qual o resultado das operações abaixo?
a) b >= a
R: True

b) b < 5
R:False

c) b + c != a
R: True

d) a + c == b * 2 - 2 * a
20 == 20 * 2 - 2 * 10
20 == 40 - 20
R: True



==============================
2
==============================

2. Escreva um programa que leia um valor real do teclado. Caso ele seja positivo, mostre sua raiz quadrada.
Caso contrário, mostre uma mensagem informando que não foi possível calcular. Dica: use a função sqrt,
declarada no arquivo math.h.

*/
/*


int main(){

  // Ler real teclado -> se for Positivo
  // mostra a raiz

  float valor;

  printf("Digite um valor");
  scanf("%f", &valor);

  if(valor>0){ // Se o valor for maior que 0
    printf("Sua raiz é %.3f", sqrt(valor)); // Exibe sua raíz
  }
  else
  {
  printf("Não foi possível calcular no plano dos reais"); // Exibe uma impossibilidade
  }
  
  
  return 0;
}
*/
/*
==============================
3
==============================

 Escreva um programa que leia um valor inteiro do teclado e depois mostre seu valor absoluto. Exemplos:
Entrada: Saída:
5 5
-5 5
-4 4
Não use nenhuma função de biblioteca! Desafio: procure resolver este exercício usando apenas o if, ou
seja, sem o else.

  */

/*
int main(){

  int valor;
  
  printf("Digite um valor %d", valor);

  if(valor < 0){
    valor = valor * -1;
  }

  printf("\nO valor absoluto é: %d", valor);
  
  return 0;
}
*/

/*

Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual, e mostre a sua
idade ao final do ano atual. O programa deve também informar a sua classe eleitoral:
- Não eleitor (abaixo de 16 anos). //
- Eleitor obrigatório (com idade no intervalo [18, 65) anos).
- Eleitor facultativo (com idade no intervalo [16, 18) ou com 65 anos ou mais).

*/
/*
int main(){

  int nasc, atual;

  // Escaneamento das datas
  
  printf("Digite a data de nascimento: \n");
  scanf("%d", &nasc);

  printf("Digite o ano atual: \n");
  scanf("%d", &atual);

  // Extrai a idade atual
  int idade = atual - nasc;

  if(idade<=65) // Se não for veio
  { 
    if(idade<16) // Adolescente
    { 
      printf("Sua classe para a idade %d é Não Eleitor", idade);
    }
    else // Eleitor 
    {
      printf("Sua classe para a idade %d é Eleitor", idade);
    }
  }
  else // Se for veio
  {
    printf("Sua classe para a idade %d é Facultativo", idade);
  }
  
  return 0;
}
*/
/*
=====================================================

5. Escreva um programa que receba a velocidade máxima em uma avenida e a velocidade com que
um motorista estava dirigindo nela. Calcule a multa que o motorista vai receber, considerando que são
pagos 50 reais para cada km/h que estiver acima da velocidade permitida (considere apenas números
inteiros). Se a velocidade do motorista estiver dentro do limite, o programa deve informar que não há
multa. 

=====================================================


*/

int main(){

  int velMax, velMot;

  // Recebe entrada das velocidades  
  printf("Digite a velocidade máxima da rodovia: \n");
  scanf("%d", &velMax);

   printf("Digite a velocidade do motorista: \n");
  scanf("%d", &velMot);

  // Calcula a multa 50R$ - km/h acima
  int multa = velMax - velMot;

  if(multa == 0) // Não ultrapassou
  {
    printf("Não há multa a ser ponderada.");
  }  
  else{
    printf("O valor da multa é: %d", multa);
  }
  
  return 0;
}