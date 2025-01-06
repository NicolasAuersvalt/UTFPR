#ifndef EMAIL_H
#define EMAIL_H

class Assunto;
class Mensagem;

class EMail{

	private:
		Assunto* reuniao;
		Mensagem* mensagem;

	public:
		EMail();
		~EMail();
		void setConteudoAssunto(Assunto* assunto);
		void addTextoMensagem(Mensagem* mensagem);
		void mostraDados();

};

#endif
