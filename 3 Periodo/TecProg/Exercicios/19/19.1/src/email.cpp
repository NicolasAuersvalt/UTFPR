#include"email.h"
#include <iostream>
using namespace std;

EMail::EMail():cronograma(new Mensagem), reuniao(new Assunto){
}

EMail::~EMail(){
	delete cronograma;
	delete reuniao;
}

void EMail::setConteudoAssunto(string assunto){
	
	reuniao->setTexto(assunto);
	
}

void EMail::addTextoMensagem(string mensagem){

	cronograma->addMensagem(mensagem);
	

}

void EMail::mostraDados(){
	cout << reuniao->getTexto() << endl;
	cout << cronograma->getMensagem() << endl;
}
