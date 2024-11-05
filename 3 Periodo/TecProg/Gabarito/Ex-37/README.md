37) Implementar um sistema de controle de uma conta bancária:
* Classe Conta: contém os seguintes membros:
    * Atributos: saldo (double) e número (int)
    * Métodos:
      * *depositar()*, que recebe um valor como parâmetro e adiciona ao saldo da conta
      * *getSaldo()*
      * *sacar()*, que recebe um valor como parâmetro, subtrai do saldo da conta se houver saldo suficiente e retorna *true*. Caso o saldo não seja suficiente, retorna *false*.
      * *aplicarJurosDiarios()* (abstrato), que recebe um número de dias como parâmetro e atualiza o saldo por meio da aplicação de juros diários na quantidade de dias informada.
* Classe *ContaCorrente*, derivada de *Conta*:
  * Implementa *aplicarJurosDiarios()* de 0,1% sobre o que exceder R$ 1.000,00.
* Classe *ContaPoupança*, derivada de *Conta*:
  * Implementa *aplicarjurosDiarios()* de 0,2%.
* Aplicação:
  * Menu com opções para: criar conta, ler saldo, depositar, sacar e atualizar saldo em função de dias de aplicação