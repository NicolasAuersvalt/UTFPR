#ifndef C_ASSUNTO
#define C_ASSUNTO

#include "stdinc.hpp"

class Assunto
{
private:
  string texto;

public:
  Assunto();
  Assunto(const string &texto);
  ~Assunto();
  void setTexto(const string &text);
  const string &getTexto() const;
};

#endif