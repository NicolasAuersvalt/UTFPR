#include "Item.hpp"

Item::Item(const string &nome, const double &valorUnitario, const double &quantidade) : nome(nome), valorUnitario(valorUnitario), quantidade(quantidade)
{
}

Item::~Item()
{
}

void Item::setNome(const string &nome)
{
  this->nome = nome;
}

const string &Item::getNome() const
{
  return this->nome;
}

void Item::setValorUnitario(const double &valorUnitario)
{
  this->valorUnitario = valorUnitario;
}

const double &Item::getValorUnitario() const
{
  return this->valorUnitario;
}

void Item::setQuantidade(const double &quantidade)
{
  this->quantidade = quantidade;
}

const double &Item::getQuantidade() const
{
  return this->quantidade;
}

const double &Item::getValorTotal() const
{
  return this->valorUnitario * this->quantidade;
}

bool Item::operator==(const Item item) const
{
  return this->getNome() == item.getNome() &&
         this->getValorUnitario() == item.getValorUnitario() &&
         this->getQuantidade() == item.getQuantidade();
}