#ifndef C_EMAIL
#define C_EMAIL

#include "stdinc.hpp"
#include "Assunto.hpp"
#include "Mensagem.hpp"

class Email
{
private:
  Assunto assunto;
  Mensagem mensagem;

public:
  Email();
  Email(const Assunto &assunto, const Mensagem &mensagem);
  ~Email();
  void setConteudoAssunto(const string &assunto);
  void addTextoMensagem(const string &mensagem);
  void mostraDados() const; // Função const por causa que não deve modificar nenhum atributo.
};
#endif