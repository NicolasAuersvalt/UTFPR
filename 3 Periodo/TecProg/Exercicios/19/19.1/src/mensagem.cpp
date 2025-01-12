#include"mensagem.h"
#include<stdlib.h>

using namespace std;

Mensagem::Mensagem():texto()
{
	
}

Mensagem::~Mensagem(){
	texto.erase();
}

void Mensagem::addMensagem(string texto){
	this->texto = texto;
}

string Mensagem::getMensagem(){
	return texto;
}
