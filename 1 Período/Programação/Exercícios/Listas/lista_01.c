/* 
Qual condição testa se o valor da variável nota está entre 0 e 10 (inclusive 0 e 10)?
10 pontos

if(0 <= nota <= 10)
F, pois partindo da esquerda para a direita e 
pela ordem:

0<=nota (True)

então teríamos:

if(1<=10)
e isso é true, impossibilitando uma possível
condicional


if(nota > 0 && nota < 10)
[0<nota<10]
Porém não testa para ser igual a 0 e 10


if(nota >=0 || nota <= 10)
Qualquer valor maior de 10 testará >=0
E qualquer valor menor que 10 testará <=10

if(nota>=0 && (nota < 10 || nota = 10)
1° (nota<10 ou nota = 10) pode ser -1, -2
2° nota>=0 limita.
[0<=nota]

if(nota >= 0 && nota <= 10) 
Nota teria que ser = 0 E = 10 ao mesmo tempo



if (num < 0 && num >= 10)
  printf("Oi!");

  Dados valores negativos e valores maiores ou iguais a 10

  Pois o valor precisaria ser menor que 0 E,
  ao mesmo tempo, maior ou igual a 10
*/

/*
if(a>0 && b>0 && c>0)
  prinf("+++");

if(a>0 && b>0 && c<0)
  prinf("++-");

if(a>0 && b<0 && c>0)
  prinf("+-+");

if(a>0 && b<0 && c<0)
  prinf("+--");

if(a<0 && b<0 && c<0)
  prinf("---");
*/

if (a>0){ // a>0
  if(b>0 && c>0)
   prinf("+++");

  else if(b>0 && c<0)
    prinf("++-");

  else if(b<0 && c>0)
    prinf("+-+");

  else()
   prinf("+--");

} else {
  if(a<0 && b<0 && c<0)
  prinf("---");
}





// 1° Comentar as lógicas acima de cada trecho importante;
// 2° Substituir alguns if por else if para evitar repetição de comparações
// 3° Declarar um if para verificar se "a" é maior que 0 e aninharia seus if respectivos. Logo, fecharia com com um else, pois há apenas uma condicional de a<0;
// 4° Trocar o último else if aninhado por else, pois seguirá a lógica, mas com menos código.