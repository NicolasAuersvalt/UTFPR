### 10 - Implementar a classe *Colaborador* com as seguintes características:

* atributos: nome, tempo de serviço na empresa em anos, tipo do vínculo (empregado, sócio ou estagiário), valor da hora de trabalho e número de horas que trabalha.
* métodos:
  - construtora que recebe o nome e o tipo do vínculo do colaborador e zera os demais atributos
  - métodos “setter” para cada um dos outros atributos
  - *calculaRendimentos()*, que calcula e retorna os rendimentos daquele colaborador. As regras para cálculo de rendimento são as seguintes:  
    -    i. Estagiários recebem o valor da hora vezes o número padrão de horas trabalhadas (80 por mês)  
    -    ii. Empregados recebem o número de horas trabalhadas vezes o valor da hora, sendo que este valor aumenta em 10% para cada ano de serviço na empresa. Caso o número de horas trabalhadas exceda 144, o empregado recebe 50% a mais por hora extra.  
    -    iii. Sócios recebem o valor da hora vezes o número de horas trabalhadas.  
  - *calculaCusto()*, que calcula e retorna quanto aquele colaborador custo mensalmente para a empresa. As regras para cálculo do custo são as seguintes:
    - i. Estagiários e sócios não apresentam nenhum custo adicional além dos rendimentos.
    - ii. Empregados custam o valor dos seus rendimentos mais 80%
relativos a encargos (impostos, INSS, etc).
  - *getNome()*, que retorna o nome do colaborador.  
  
Implementar um programa que:
  * receba do usuário os dados de 3 colaboradores.
  * calcule os rendimentos e custos de cada um e informe qual deles tem o maior rendimento e qual custa mais para a empresa.