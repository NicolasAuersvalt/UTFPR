#ifndef C_CARRINHO_DE_COMPRAS
#define C_CARRINHO_DE_COMPRAS

#include "stdinc.hpp"
#include "Item.hpp"

class CarrinhoDeCompras
{
private:
  list<Item> items;

public:
  CarrinhoDeCompras();
  ~CarrinhoDeCompras();
  void adicionarItem(const Item &i);
  void removerItem(const Item &i);
  const double &getValorTotal() const;
};

#endif