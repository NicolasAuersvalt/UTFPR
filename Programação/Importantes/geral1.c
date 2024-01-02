/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

1-2° Aula

%d - Decimal
%f - Float
%c - char

Basta que um valor esteja em float para ter precisão (5/2.0 ou 5.0/2)

A alocação de %d é diferente de %f
%d != %f (5 != 5.0)

scanf(, &) // & é o endereço


Se colocar "%d oi", ele vai esperar digitar um inteiro + "oi"

Se colocar "%d, %d", ele vai esperar ler a vírgula

Se colocar "%d ", ele vai esperar ler um espaço

Deve-se atribuir um valor à variável antes de usá-la
O destino fica sempre à esquerda, e o valor a armazenar fica sempre à direita!
int = 1;


=====/=====/=====/=====/=====/=====/=====/=====

Usar nomes significativos:

int v, c, d; // NÃO

int val1, totalJan, totalFeb, dia_1;

=====/=====/=====/=====/=====/=====/=====/=====

NÃO devemos usar % com variáveis float:
float a, b, c; 
c = a % b; // INCORRETO

=====/=====/=====/=====/=====/=====/=====/=====

NÃO devemos usar 039 para atribuir:

int a = 039 

Isso é um número octal

=====/=====/=====/=====/=====/=====/=====/=====

Separação de Centenas, Dezenas e Unidades:

int a = 1234

Centena;

a / 100 // Quociente da divisão por 100 (Em inteiros)
R: 12

(a % 100) / 10   // Resto da divisão por 100 dividido por 10
a / 100 -> Resto = 34 -> 34 / 10 -> 3
R:3

a % 10 // Resto da divisão por 10
R:4

=====/=====/=====/=====/=====/=====/=====/=====

Se quisermos inverter os valores, basta pegar e somar os valores:

a = 123

a % 10
R:3

(a % 100) / 10
R:2

a / 100
R:1

Inverter é: (3 * 100) + (2*10) + 3

=====/=====/=====/=====/=====/=====/=====/=====

double = float

Porém, o double contém o dobro da capacidade de
armazenar decimais (15-16) em relação ao float (7)

long - +- 2 bilhões de números

long long - kkkk

short - +- 32.000

unsigned + tipo

unsigned faz com que a variável armazene apenas números não negativos

=====/=====/=====/=====/=====/=====/=====/=====

char representa um caractere

- PORÉM, ele não armazena o caractere, mas sim bytes

- Cada char é, na verdade, a posição de um caractere em uma tabela.

=====/=====/=====/=====/=====/=====/=====/=====

Para fazer operações com tipos de dados diferentes, é feita uma rápida conversão
apenas para realizar a operação.

A ordem é sempre

1° Maior capacidade / Representatividade

int a = 1
float b = 1.1
float c = a + b = 2.1

o type cast não muda o tipo da variável!

=====/=====/=====/=====/=====/=====/=====/=====

Para binários, vale a regra do tombamento
O 1 tomba no próximo

Real | Binário
1         1
2        10
3        11
4       100
5       101
6       110
7       111
8      1000
9      1001
10     1010
11     1011
12     1100

=====/=====/=====/=====/=====/=====/=====/=====

Para cálculos binários:

Temos

64 | 32 | 16 | 8 | 4 | 2 | 1

Dado um número 22. Para descobrir o binário:

1° Pegamos o maior valor que não seja maior que 22.

- 16 é o maior

2° Subraia 16 de 22:

- 22 - 16 = 6

Repita o processo:

- 4 é o maior

- 6 - 4 = 2

- 2 é o maior ou igual

- 2 - 2 = 0.

Note que usamos 16, 4 e 2. Pois 16 + 4 + 2 = 22

Agora para cada valor utilizado, colocamos um 1

64 | 32 | 16 | 8 | 4 | 2 | 1 |
          1    0   1   1   0

Joia?


=====/=====/=====/=====/=====/=====/=====/=====



\n - Nova linha
\t - Tabulação horizontal
\a - Sinal de alerta sonoro
\\ - Barra invertida

=====/=====/=====/=====/=====/=====/=====/=====

Se os dois argumentos forem inteiros, acontece a divisão
inteira. (10/2) = (5)

Se ao menos um dos dois argumentos for um valor real,
acontece a divisão de ponto flutuante. (10/2.0) = (5.000000)

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

3° Aula

  Os operadores relacionais retornam 0 para falso e 1 para verdadeiro

  == igual
  != diferente
  < menor
  <= menor ou igual
  > maior
  >= maior ou igual

  || - ou
  && - e
  ! - NOT

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====


  */