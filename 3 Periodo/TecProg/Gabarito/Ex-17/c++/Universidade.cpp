#include "Universidade.hpp"

Universidade::Universidade() : nome("")
{
}

Universidade::~Universidade()
{
}

const string &Universidade::getNome() const
{
  return this->nome;
}

void Universidade::setNome(const string &nome)
{
  this->nome = nome;
}