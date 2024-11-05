#include "CarrinhoDeCompras.hpp"

CarrinhoDeCompras::CarrinhoDeCompras() : items()
{
}

CarrinhoDeCompras::~CarrinhoDeCompras()
{
}

void CarrinhoDeCompras::adicionarItem(const Item &i)
{
  this->items.emplace_back(i);
}

void CarrinhoDeCompras::removerItem(const Item &i)
{
  this->items.remove(i);
}

const double &CarrinhoDeCompras::getValorTotal() const
{
  double total = 0.f;
  list<Item>::const_iterator it = this->items.begin();
  while (it != this->items.end())
  {
    total += (*it).getValorTotal();
    it++;
  }
  return total;
}