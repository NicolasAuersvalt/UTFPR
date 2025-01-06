#ifndef EMAIL_H
#define EMAIL_H

#include "assunto.h"
#include "mensagem.h"

class Assunto;
class Mensagem;

class EMail{

	private:
		Assunto* reuniao;
		Mensagem* cronograma;

	public:
		EMail();
		~EMail();
		void setConteudoAssunto(string assunto);
		void addTextoMensagem(string mensagem);
		void mostraDados();

};

#endif
