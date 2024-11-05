### 5 - Criar a classe Pessoa com as seguintes características:
* atributos: idade e dia, mês e ano de nascimento, nome da pessoa  
* métodos:  
  - o *calculaIdade()*, que recebe como parâmetro a data atual em dia, mês e ano e calcula e armazena no atributo *idade* a idade atual da pessoa,sem retornar valor
  - o *getIdade()*, que retorna o valor da idade
  - o *getNome()*, que retorna o nome da pessoa
  - o *setNome()*, que recebe o nome da pessoa como parâmetro e inicializa o atributo da classe
  - o *setDataDeNascimento()*, que recebe dia, mês e ano de nascimento como parâmetros e preenche nos atributos correspondentes do objeto.
* Fazer uma classe principal que crie dois objetos da classe *Pessoa*, um representando Albert Einstein (nascido em 14/3/1879) e o outro representando Isaac Newton (nascido em 4/1/1643). Em seguida, mostre quais seriam as idades de Einstein e Newton caso estivessem vivos.
* Exemplo de classe de entrada (*que está em Java permitindo perceber certa proximidade sintática com C++*):  
  

``` java
public class ExPessoa {
  public static void main(String[] args) {
    Pessoa p1, p2;

    p1 = new Pessoa();
    p2 = new Pessoa();

    p1.setNome("Isaac Newton");
    p1.setDataDeNascimento(4, 1, 1643);

    p2.setNome("Albert Einstein");
    p2.setDataDeNascimento(14, 3, 1879);

    p1.calculaIdade(30, 9, 2010);
    p2.calculaIdade(30, 9, 2010);

    int idadeP1 = p1.getIdade();
    int idadeP2 = p2.getIdade();
    
    System.out.println("Idade de p1: " + idadeP1);
    System.out.println("Idade de p2: " + idadeP2);
  }
}
```