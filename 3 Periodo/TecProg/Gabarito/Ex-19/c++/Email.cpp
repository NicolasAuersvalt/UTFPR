#include "Email.hpp"
Email::Email() : assunto(),
                 mensagem()
{
}

Email::Email(const Assunto &assunto, const Mensagem &mensagem) : assunto(assunto),
                                                                 mensagem(mensagem)
{
}

Email::~Email()
{
}

void Email::setConteudoAssunto(const string &assunto)
{
  this->assunto.setTexto(assunto);
}

void Email::addTextoMensagem(const string &mensagem)
{
  this->mensagem.addMensagem(mensagem);
}

void Email::mostraDados() const
{
  cout << "Assunto: " << this->assunto.getTexto() << endl;
  cout << "Mensagem: " << endl
       << this->mensagem.getMensagem() << endl;
}