#include "Mensagem.hpp"

Mensagem::Mensagem() : texto("")
{
}

Mensagem::~Mensagem()
{
}

void Mensagem::addMensagem(const string &texto)
{
  this->texto = texto;
}

const string &Mensagem::getMensagem() const
{
  return this->texto;
}
