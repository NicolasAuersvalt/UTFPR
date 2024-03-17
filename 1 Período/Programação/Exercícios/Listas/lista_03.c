#include<stdio.h>
// Fixação 03
// ==============================
// 1
// ==============================
/*
A Companhia de Táxi Tabajara (CTT) é uma das maiores empresas de transporte do país.
Possui uma vasta frota de carros e opera em todas as grandes cidades. Recentemente a CTT
modernizou a sua frota, adquirindo um lote de 500 carros bicombustíveis (carros que podem utilizar
como combustível tanto álcool quanto gasolina). Além do maior conforto para os passageiros e o
menor gasto com manutenção, com os novos carros é possível uma redução adicional de custo: como
o preço da gasolina está sujeito a variações muito bruscas, pode ser vantagem, em certos momentos,
utilizar álcool como combustível. Entretanto, os carros possuem um melhor desempenho utilizando
gasolina, ou seja, em geral, um carro percorre mais quilômetros por litro de gasolina do que por litro de
álcool. 

Escreva um programa que recebe o preço do litro de álcool, o preço do litro de gasolina e os
quilômetros por litro que um carro bicombustível realiza com cada um desses combustíveis. O
programa deve informar se é mais econômico abastecer os carros da CTT com álcool ou com
gasolina. No caso de não haver diferença de custo entre abastecer com álcool ou gasolina, a CTT
prefere utilizar gasolina.
*/

/*

int main(){

  // gasolina, alcool, km_g, km_a
    
  float gas, alc, km_g, km_a;

  // Entrada Gasolina
  printf("Digite o preço da gasolina(l): ");
  scanf("%f", &gas);

  // Entrada Alcool
  printf("Digite o preço do alcool(l): ");
  scanf("%f", &alc);

  // Entrada km_Gasolina
  printf("Digite o rendimento da gasolina (km/l): ");
  scanf("%f", &km_g);

  // Entrada km_Alcool
  printf("Digite o rendimento do alcool (km/l): ");
  scanf("%f", &km_a);

  // Rendimento -> 1 km por litro 
  
  // Função Rendimento Gasolina (km / valor)
  float rend_g = (km_g/gas);
  
  // Função Rendimento Alcool (km / valor)
  float rend_a = (km_a/alc);

  // Qual é mais rentável
  if(rend_g<rend_a){ // Alcool rende mais (km por real)
 
    // Exibe na tela o rendimento 
    printf("Opte por abastecer com Gasolina, cujo rendimento é:");
    printf("\n%.2f real para cada km", rend_g);
    printf("Enquanto que para o Alcool é de:");
    printf("\n%.2f real para cada km", rend_a);
  
  }else if (rend_g>rend_a){ // Gasolina rende mais (km por real)
    // Exibe na tela o rendimento 
    printf("Opte por abastecer com Alcool, cujo rendimento é:");
    printf("\n%f real para cada km", rend_a);
    printf("Enquanto que para a Gasolina é de:");
    printf("\n%.2f real para cada km", rend_g);
    
  }else{ // Dois rendimentos iguais
    // Pergunta os km
    printf("Os rendimentos são iguais, porém recomendamos a gasolina.");
    printf("\n%f real para cada km", rend_a);
    
  }
    
  return 0; // Retorna concluída a função
}
*/

/*
=======================
2
=======================

Escreva um programa que atribua um número entre 100 e 999 a uma variável e o imprima
invertido, na ordem UDC (Unidade Dezena Centena) - por exemplo, se a entrada é 123, a saída é 321.
Zeros à esquerda não devem ser mostrados, então se a entrada é 180 a saída é 81. Atenção: os
dígitos não devem ser informados separadamente.

*/

// **  o resto sera semptr a unidade


/*
int main(){

  // Atribua  um valor entre 100 e 999

  // O retorno deve ser esse valor com os algarismos
  // invertidos  (321) => (123)

  // zero não deve ser imprimido (180) => (81)
  
  int valor;

  printf("Digite um valor: ");
  scanf("%d", &valor);

  // Função inversa (Unidade(u), Dezenas(d), Centenas(c))

  // Unidade
  int  u = (valor%10); // 100/10 = 10; 9/10 = 0
  printf("\nO unidade é %d", u); 

  // Dezena
  int d = ((valor%100)/10); 
  printf("\nA dezena é, %d", d);

  // Centena
  int c = (valor/100);

  printf("\nA centena é, %d", c);

  // Junção dos valores

  int inverso = (c*100) + (d*10) + c;

  printf("\nO inverso é: %d", inverso);
  
    return 0;
}

*/

// =======================
// 3
// =======================
/*
Escreva um programa que use a estrutura condicional para mostrar qual entre 3 números
inteiros dados é o maior. Os números devem ser informados uma única vez, e armazenados em 3
variáveis.
]
*/
/*
int main(){
  int a, b, c;
  
  scanf("%d", &a);
  scanf("%d", &b);
  scanf("%d", &c);

  if(a>b){
    if(a>c){
    printf("O valor %d é maior.", a);
    } else {
    printf("O valor %d é maior.", c);
    }
  else if(b>a){
    if(b>c){
      printf("O valor %d é maior.", b);
    } else{
      printf("O valor %d é maior.", c);
    }
  } 
  else if(c>b){
    if (c>a){
      printf("O valor %d é maior.", c);
    } else{
      printf("O valor %d é maior.", a);
    }

  return 0;
  }
  }
}
*/

// =========================
// 4
// =========================
/*
Escreva um programa que leia a hora inicial e a hora final de um jogo (apenas a hora, sem os
minutos, com valor entre 0 e 23). 
A seguir, calcule a duração do jogo, sabendo que o mesmo pode
começar em um dia e terminar em outro, tendo uma duração mínima de 1 hora e máxima de 24 horas.
Considere que as entradas informadas são sempre válidas.
*/
/*
int main(){
  
  int tmp_f, tmp_i, duracao;

  printf("Hora inicial? ");
  scanf("%d", &tmp_i);

  printf("Hora final? ");
  scanf("%d", &tmp_f);
  
  // 23h - 3h
  // 24h - 23
  // + 3h

  // 1h - 4h
  // tmp_f>tmp_i


  if (tmp_f>tmp_i){ // Final do dia para o outro
    int dur_1 = 24 - tmp_f;
    int duracao = dur_1 + tmp_i;
  }
  else if (tmp_i>tmp_f){
    int duracao = tmp_f - tmp_i;
  }
  printf("A duração é de: %d", &duracao);

  return 0;
  
}
*/
// ========================
// 5
// ========================

/*

#include <stdio.h>
int main ()
{
int n1, n2, n3, aux;
scanf ("%d %d %d", &n1, &n2, &n3);
if (n2 >= n3)
{
aux = n2;
n2 = n3;
n3 = aux;
}
if (n1 >= n2)
{
aux = n1;
n1 = n2;
n2 = aux;
if (n2 >= n3)
{
aux = n2;
n2 = n3;
n3 = aux;
}
}
printf ("%d %d %d\n", n1, n2, n3);
return (0);
}

Sem executar o programa, responda:
a) Qual será a saída se a entrada for 1 2 3?
R: Não acontecerá nada

b) Qual será a saída se a entrada for 20 10 30?
R: Passará no segundo if(n1>=n2), Depois n1 troca com n2
Porém, não acontecerá nada, pois n2 = 20 e n3 = 3-0.

c) O que o programa faz, exatamente? Explique o funcionamento do algoritmo.
R: Compara valores atribuidos e se caso passar, troca os valores através de uma variável de apoio. Por fim, ele imprime os valores (trocados ou não).

*/

// ==============================
// 6
// ==============================
/* 
  Escreva um programa que leia 2 valores reais (x e y), os quais representam as coordenadas de
um ponto em um plano cartesiano. A seguir, determine a qual quadrante pertence o ponto. Analise
também se o ponto está sobre um dos eixos cartesianos ou na origem (x = y = 0).

*/

int main(){

  float x, y; 
  printf("Digite o x: \n");
  scanf("%f", &x);
  printf("Digite o Y: \n");
  scanf("%f", &y);

  // x>0 e y>0 - 1 Quadrante
  if(x>0.0){ // 1-4 Quadrante
    if(y>0.0){
      printf("Primeiro quadrante"); // Primeiro
    } else if(y==0.0){
      printf("Eixo OX Positivo"); // OX
    }
    else if(y<0.0){
      printf("Quarto quadrante"); // Quarto
    }
    else if(x<0.0){ // 2-3 Quadrantes
      if(y>0.0){ // Segundo Quadrante
        printf("Segundo quadrante"); // Segundo
      } else if (y==0.0){
        printf("Eixo OX Negativo"); // OX
      } 
    } else if(y<0.0) {
        printf("Terceiro quadrante"); // Terceiro
      }
    }
    else if(x==0.0){ // X == 0
      if(y>0.0){
        printf("Eixo OY Positivo");
      } else if(y<0.0){
        printf("Eixo Oy Negativo");
      }
      else if(y==0.0){
        printf("Origem");
      }
    }
    }
  // x<0 e y>0 - 2 Quadrante
  // x<0 e y<0 - 3 Quadrante
  // x>0 e y<0 - 4 Quadrante