### 35 - Escrever a classe Empregado, que pretende representar um empregado em um sistema de RH.
* Atributos: nome (String), CPF (int) e cargo (String)
* Construtora que recebe nome, CPF e cargo como parâmetros e preenche os atributos
* Método *mostraDados()*, que mostra os dados do empregado no formato:  
    Nome: xxx, CPF: xxx, Cargo: xxx
* Método *calculaSalario()*, que recebe o número de horas trabalhadas como parâmetro e retorna 415,00.

Escrever a classe Faxineiro, derivada de *Empregado*:

* construtora que recebe nome e CPF e repassar os valores pra base
* método *mostraDados()*, que mostra os dados no formato:
    *Nome do faxineiro: xxx, CPF: xxx*
* método *calculaSalario()*, que recebe o número de horas trabalhadas e retorna: até 176 horas – 4,50/hora, hora extra – 6,00/hora

Escrever a classe *Gerente*, derivada de *Empregado*

* Atributos: bonus - int.
* construtora que recebe nome, CPF e bonus como parâmetros
* método *mostraDados()*, que mostra os dados no formato:
* *Nome do gerente: xxx, CPF: xxx, bonus: xxx*
* método *calculaSalario()*, que recebe o número de horas trabalhadas e retorna: até 176 horas – 30,00/hora + bonus, hora extra – não paga

Escrever uma classe de entrada para:

* Perguntar ao usuário se quer inserir os dados de um *Faxineiro*, *Empregado* ou *Gerente*.
* Instanciar o objeto correspondente
* Inserir o número de horas trabalhadas e mostrar os dados da pessoa, bem como o salário para aquele mês.