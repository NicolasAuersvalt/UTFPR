#include "Assunto.hpp"

Assunto::Assunto() : texto("")
{
}

Assunto::Assunto(const string &texto) : texto(texto)
{
}

Assunto::~Assunto()
{
}

void Assunto::setTexto(const string &texto)
{
  this->texto = texto;
}

const string &Assunto::getTexto() const
{
  return this->texto;
}
