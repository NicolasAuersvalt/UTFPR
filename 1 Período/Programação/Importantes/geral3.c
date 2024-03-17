/*
=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
Aula 9

Quando temos loops aninhados, cuidado ao atribuir variáveis
dentro de um laço

for(i=0, condição){ // Loop 1


  for(m=0, condição){  // Loop 2

  }

}

Note que ao repetir o loop 1, o dois tomará m = 0 novamente.

=====/=====/=====/=====/

  n = n + algo

  n é chamada VARIÁVEL ACUMULADORA.

=====/=====/=====/=====/

Teste de Mesa - DICAS USANDO TABELA.

|#|  Intrução  |  Total  |  x  |

 1   total = 0      0
 2   for:x=0;       0       0

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

Na tabela ASCII, inicia-se o alfabeto em:
65 - A
66 - B
...
90 - Z

Para as minúsculas:
97 - a
98 - b
...
122 - z

Se pegarmos e somarmos 'A' com 1, teremos:

(65) + 1 = 66
e 66 corresponde a B, então teremos B como resposta.

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

No caso de ser necessário a utilização do valor final de um for,
isto é:

for(int i=0; i<10; i++)

o resultado final ficará com i = 10, então depois do for podemos
trabalhar sobre essa variável.

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====

O Break é utilizado para loops (exceto o if), estando dentro de seu escopo faz
a quebra DO LOOP

for(i)
  for(j)
    for(k)
    break // Quebra APENAS o for(k)

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
Utilizamos como variável de teste de um loop as seguintes letras:
i, j, k

for(i)
if(j)
while(k)

=====/=====/=====/=====/=====/=====/=====/=====/=====/=====
*/