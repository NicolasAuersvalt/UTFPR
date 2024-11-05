### 20 - Adaptar a classe *Pessoa*, implementada em exercício anterior, para substituir os atributos de dia, mês e ano de nascimento por um objeto da classe *Calenda* (ver http://java.sun.com/javase/6/docs/api para referência). Ou seja, existe uma relação de composição entre Pessoa e *Calendar*.
* Dicas:
  * o *Calendar.getInstance()* deve ser chamado para obter um objeto novo da classe *Calendar* (este método é estático)
  * o *set()* permite ajustar os valores de dia, mês e ano para este objeto
  * o *get()* permite obter os valores para efetuar os cálculos de idade