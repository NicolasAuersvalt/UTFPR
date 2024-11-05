#include "stdinc.hpp"

#include "CarrinhoDeCompras.hpp"

int main()
{
  cout.precision(2);
  // Criamos o carrinho de compras
  CarrinhoDeCompras carrinho = CarrinhoDeCompras();
  // Criamos alguns items
  Item notebook = Item("Notebook", 1000, 2);
  Item telefone = Item("Telefone", 500, 5);
  Item tablet = Item("Tablet", 200, 6);
  Item sticker = Item("Sticker", 10.5, 100);
  // Adicionamos todos os items
  carrinho.adicionarItem(notebook);
  carrinho.adicionarItem(telefone);
  carrinho.adicionarItem(tablet);
  carrinho.adicionarItem(sticker);
  // Verificamos o total
  // OBS: o std::fixed é para formatar a saída
  cout << "Total carrinho: " << std::fixed << carrinho.getValorTotal() << endl;
  // Removemos alguns items
  carrinho.removerItem(notebook);
  carrinho.removerItem(tablet);
  // Verificamos o total
  cout << "Total carrinho: " << std::fixed << carrinho.getValorTotal() << endl;

  return 0;
}