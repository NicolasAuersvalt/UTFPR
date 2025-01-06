#include"gmail.h"
#include<iostream>
using namespace std;

Gmail::Gmail(string assunto, string mensagem):
	email()
{
	EMail* email = new EMail;

	email->setConteudoAssunto(assunto);

	email->addTextoMensagem(mensagem);

	email->mostraDados();

}

Gmail::~Gmail(){
	email = NULL;
}

int main(){

	Gmail Principal("Reuniao", "Urgente, agendar reuniao.");
}

