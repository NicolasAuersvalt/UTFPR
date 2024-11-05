#ifndef C_MENSAGEM
#define C_MENSAGEM
#include "stdinc.hpp"

class Mensagem
{
private:
  string texto;

public:
  Mensagem();
  ~Mensagem();
  void addMensagem(const string &texto);
  const string &getMensagem() const;
};

#endif