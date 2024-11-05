### 22 - Fazer um programa para:
* Criar a classe *Item*, que pretende representar um item sendo comprado em um site de e-commerce.
  * o Atributos: nome do item, valor unitário e quantidade
  * o Métodos:
    * construtora que recebe como parâmetro e ajusta os valores dos atributos
    * *getNome()*
    * *getValorTotal()*
* Criar a classe *CarrinhoDeCompras*, que permite criar uma lista de compras em um site de e-commerce.
  * o Atributos: array de *Item*. Ou seja, existe uma relação de agregação entre *CarrinhoDeCompras* e *Item*.
  * o Métodos:
    * *adicionarItem(Item i)*
    * *removerItem(Item i)*
    * *getValorTotal()*
* Criar a classe *Principal*, com o objetivo de criar itens, uma lista de compras e exercitar os métodos.