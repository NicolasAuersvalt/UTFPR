### 24 - Fazer um sistema de calculadora simples, composto das seguintes classes:
*CalcControle*: controle da calculadora (“processador”), com os seguintes
métodos:
* public *void executar()* – faz a calculadora funcionar por meio dos seguintes passos:
  * Recebe primeiro operando do usuário através de *CalcInterface* e armazena no objeto de *CalcDados*
  * Recebe segundo operando do usuário através de *CalcInterface* e armazena no objeto de *CalcDados*
  * Recebe operação do usuário através de *CalcInterface* e armazena no objeto de *CalcDados*. Se a operação for igual a ‘s’, finaliza o programa (*System.exit(0)* ).
  * Executa a operação (método *operar*) e mostra o resultado através de *CalcInterface*.
  * Armazena resultado como primeiro operando para a próxima operação e volta para o segundo passo
* *private double operar(double opn1, double opn2, char op)* - executa a operação desejada e retorna o resultado.

*CalcDados*: implementa a parte da calculadora que armazena os dados (operandos e operação) para o seu funcionamento (“memória”). Possui as seguintes
características:

Atributos: dois números do tipo *double* para armazenar os operandos e um dado do tipo char para armazenar a operação.
Métodos:

* *public void setOperando(int i, double valor)* – armazena o i-ésimo operando com o valor expresso em valor
* *public double getOperando(int i)* – retorna o valor do i-ésimo operando
* *public void setOperacao(char op)* – armazena o caracter op como sendo a operação atual
* *public char getOperacao()* – retorna o valor da operação atual
  
*CalcInterface*: implementa a parte da calculadora que coleta e exibe informações ao usuário (display e teclado da calculadora). Possui os métodos:
* *public double recebeOperando(int i)* – recebe o operando i da operação (i vale 1 ou 2) e retorna.
* *public char recebeOperacao()* – recebe um char representando uma operação válida (+, -, * ou /) e retorna.
* *public void mostraResultado(double res)* – mostra o resultado recebido como parâmetro.
  
Criar a classe *Principal*, cujo único objetivo é instanciar os objetos de controle, dados e interface e criar os vínculos (associações) entre eles. Todas as classes citadas devem possuir, além dos atributos citados, outros atributos que representem as referências para os outros objetos (criando as associações entre eles). Desenhar o diagrama de classes em UML para este sistema.