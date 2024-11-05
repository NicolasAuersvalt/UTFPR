#ifndef C_ITEM
#define C_ITEM
#include "stdinc.hpp"

class Item
{
private:
  string nome;
  double valorUnitario;
  double quantidade;

public:
  Item(const string &nome, const double &valorUnitario, const double &quantidade);
  ~Item();
  void setNome(const string &nome);
  const string &getNome() const;
  void setValorUnitario(const double &valorUnitario);
  const double &getValorUnitario() const;
  void setQuantidade(const double &quantidade);
  const double &getQuantidade() const;
  const double &getValorTotal() const;
  // Sobrecarregamos o operador == para facilitar a comparação de items
  bool operator==(const Item item) const;
};

#endif