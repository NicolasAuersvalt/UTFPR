### 16 - Elaborar um programa em Java com as seguintes características:
*  1 classe *Cliente*, contendo:  
atributos: nome e CPF do cliente  
métodos: construtora para iniciar os atributos, *gerarRelatorio()* para retornar uma *String* com relatório do cliente e *aplicarRecursos()* que recebe um inteiro como parâmetro.

* 1 classe *Conta*, contendo:  
atributos: número e saldo  
métodos: construtora para iniciar o número, *sacar()*, *depositar()*,
*getSaldo()* e *getNumero()*.
* *Cliente* e *Conta* possuem relação de associação, com as seguintes características:
  *  1 *Cliente* pode ser titular de até 3 *Conta*
  *  1 *Conta* é de até 2 *Cliente*
  *  associação é unidirecional de *Cliente* para *Conta*
  *  atributo do link na classe *Cliente* se chama contas